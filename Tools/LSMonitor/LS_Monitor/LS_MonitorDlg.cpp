
// LS_MonitorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "LS_MonitorDlg.h"
#include "WinMessage.h"
#include "afxdialogex.h"
#include "Define.h"
#include "ServerTypes.h"
#include "IOSocket.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CLS_MonitorDlg::CLS_MonitorDlg(const TCHAR* parameter, CWnd* pParent /*=NULL*/)
	: CDialogEx(CLS_MonitorDlg::IDD, pParent)
{
	m_parameter = parameter;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLS_MonitorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_ZONES, m_zoneTabs);
}

BEGIN_MESSAGE_MAP(CLS_MonitorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_WM_DESTROY()
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

BEGIN_EASYSIZE_MAP(CLS_MonitorDlg)
	EASYSIZE(IDC_TAB_ZONES,ES_BORDER,ES_BORDER,ES_BORDER,ES_BORDER,ES_HCENTER)
	//EASYSIZE(IDC_RADIO1,ES_BORDER,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	//EASYSIZE(IDC_RADIO2,ES_BORDER,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	//EASYSIZE(IDC_STATUSFRAME,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	//EASYSIZE(IDC_STATUS,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	//EASYSIZE(IDC_MYICON2,ES_BORDER,ES_BORDER,IDC_TITLE,ES_KEEPSIZE,ES_HCENTER)
	//EASYSIZE(IDC_CONTENT,IDC_TITLE,ES_BORDER,ES_BORDER,ES_BORDER,0)
	//EASYSIZE(IDC_MIDFRAME,ES_BORDER,ES_BORDER,IDC_CONTENT,ES_BORDER,0)
	//EASYSIZE(IDC_MIDRECT,ES_BORDER,ES_BORDER,IDC_CONTENT,ES_BORDER,0)
	//EASYSIZE(IDC_MYICON1,IDC_MIDRECT,IDC_MIDRECT,IDC_MIDRECT,IDC_MIDRECT,ES_HCENTER|ES_VCENTER)
END_EASYSIZE_MAP

// CLS_MonitorDlg message handlers

BOOL CLS_MonitorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CString filePath = m_parameter;
	if(filePath.IsEmpty())
	{
		filePath = _T("config.ini");
	}

	LoadINI(filePath);
	LoadIP();
	 
	m_zoneTabs.ShowTab(0);  
	GetClientRect(m_clientRect);

	INIT_EASYSIZE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLS_MonitorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLS_MonitorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CLS_MonitorDlg::LoadBillingFromINI(const TCHAR* file, CString section, BILLINGSERVERTABLE &tempBillingServerTable)
{
	BOOL flag = FALSE;
	
	TCHAR buffer[512];
	TCHAR path[512];
	GetCurrentDirectory(sizeof(path), path);
	CString fullPath;
	CString defaultStr= "default";

	fullPath.Format(_T("%s\\%s"), path, file);
	CString name, billing;
	
	if(section == "")
		return FALSE;

	int i = 1;
	while(TRUE)
	{
		CString strNum;
		strNum.Format(_T("billing%d"), i);
		// name
		DWORD result= GetPrivateProfileString(
			section,		//zone
			strNum,			//billing
			defaultStr, 
			buffer, 
			_countof(buffer), 
			fullPath);

		buffer[result] = 0;
		if(defaultStr != buffer)
		{
			billing = buffer;

			i++;
			int curPos = 0;
			int count = tempBillingServerTable.size();		//count 값이 빌링 구분값

			BILLINGSERVERINFO* billingServer	= new BILLINGSERVERINFO;
			billingServer->serviceIP			= billing.Tokenize(_T(":"), curPos);	
			CString billingPort					= billing.Tokenize(_T(":"), curPos);
			billingServer->servicePort			= atoi(billingPort);		
			billingServer->billingServerState	= SERVERSTATE_OFF;
			billingServer->serverType			= SERVER_TYPE_BILLING;
			billingServer->serverKeyIndex		= count;
			
			tempBillingServerTable[count] = billingServer;
		}
		else
		{
			break;
		}
	}
	if( tempBillingServerTable.size() > 0 )
	{
		flag = TRUE;
	}
	return flag;
}

//. ini 에서 빌링서버옵션 읽을 수 있도록 추가 
void CLS_MonitorDlg::LoadINI(const TCHAR* file)
{
	BOOL billingFlag = FALSE;
	
	TCHAR buffer[512];
	TCHAR path[512];
	GetCurrentDirectory(sizeof(path), path);

	CString fullPath;
	fullPath.Format(_T("%s\\%s"), path, file);

	CString defaultStr= "default", section;
	CString name, main, login, billing;

	int nCode = false;

	int iReult = 0;
	for(int i = 1 ; ; i++)
	{
		section.Format(_T("zone%d"), i);
		billingFlag = FALSE;	//초기화

		// name
		DWORD result= GetPrivateProfileString(
			section,
			_T("name"), 
			defaultStr, 
			buffer, 
			_countof(buffer), 
			fullPath);
		buffer[result] = 0;
		if(defaultStr == buffer)
			break;

		name = buffer;
		
		// main
		result= GetPrivateProfileString(
			section,
			_T("main"), 
			defaultStr, 
			buffer, 
			_countof(buffer), 
			fullPath);
		buffer[result] = 0;

		main = buffer;		

		// login
		result= GetPrivateProfileString(
			section,
			_T("login"), 
			defaultStr, 
			buffer, 
			_countof(buffer), 
			fullPath);
		buffer[result] = 0;

		login = buffer;


		nCode = GetPrivateProfileInt(section, _T("countrycode"), 0, fullPath); // EU 국가별 동접 표시

		//빌링 추가
		BILLINGSERVERTABLE billingServerTable;
		billingFlag = LoadBillingFromINI(file, section, billingServerTable);
		
		if(billingFlag == TRUE)
		{
			int index = m_zoneTabs.GetItemCount();
			//m_zoneTabs.AddTab(name, TRUE, billingServerTable); 
			m_zoneTabs.AddTab(name, main, login, TRUE, billingServerTable, false); 
			m_zoneTabs.ShowTab(index, FALSE);
			
		}

		// 탭추가 
		if(billingFlag == FALSE)
		{
			int index = m_zoneTabs.GetItemCount();
			m_zoneTabs.AddTab(name, main, login, FALSE, billingServerTable, (bool)nCode);  
			m_zoneTabs.ShowTab(index, FALSE);
		}
		
	}
}

void CLS_MonitorDlg::LoadIP()
{
	TCHAR hostName[512];
	gethostname(hostName, sizeof(hostName));
	hostent* host = gethostbyname(hostName);

	struct in_addr addr;
	int i = 0;
    while (host->h_addr_list[i] != 0) 
	{
        addr.s_addr = *(u_long *) host->h_addr_list[i++];
		m_IP = inet_ntoa(addr);
		if(!m_IP.IsEmpty())
		{
			CString title;
			title.Format(_T("LostSaga Monitor - %s"), m_IP);
			SetWindowText(title);
			break;
		}
    }
}


void CLS_MonitorDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	UPDATE_EASYSIZE;
}


void CLS_MonitorDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int width = m_clientRect.Width()+16;
	pRect->right = pRect->left + width;

	EASYSIZE_MINSIZE(m_clientRect.Width()+16, m_clientRect.Height()+38, fwSide, pRect);
}


void CLS_MonitorDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//lpMMI->ptMaxSize.
	int width = m_clientRect.Width()+16;
	int spacing = lpMMI->ptMaxTrackSize.x - lpMMI->ptMaxSize.x;

	lpMMI->ptMaxSize.x = width;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


BOOL CLS_MonitorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CLS_MonitorDlg::UpdateTitle(const int currentUser, const int maxUser)
{
	CString title;
	title.Format(_T("LostSaga Monitor - %s(%d/%d)"), m_IP, currentUser, maxUser);
	SetWindowText(title);
}

void CLS_MonitorDlg::OnDestroy()
{
 	VERIFY(m_zoneTabs.DeleteAllItems());
}
