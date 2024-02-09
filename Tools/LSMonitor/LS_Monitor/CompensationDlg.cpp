// CompensationDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "CompensationDlg.h"
#include "afxdialogex.h"
#include <atltime.h>
#include "ZoneDialog.h"


// CCompensationDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCompensationDlg, CDialogEx)

CCompensationDlg::CCompensationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCompensationDlg::IDD, pParent)
{

}

CCompensationDlg::~CCompensationDlg()
{
}

void CCompensationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ITEM_COMPENSATION, m_compensationList);
	DDX_Control(pDX, IDC_LIST_ENDDATE, m_endDate);
	DDX_Control(pDX, IDC_EDIT_COMPENSATION, m_editCompensationCode);
	DDX_Control(pDX, IDC_EDIT_ENDDATE, m_editEndDate);
}


BEGIN_MESSAGE_MAP(CCompensationDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_ITEM_COMPENSATION, &CCompensationDlg::OnLvnItemchangedItemCompensation)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ENDDATE, &CCompensationDlg::OnLvnItemchangedListEnddate)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CCompensationDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_INSERT, &CCompensationDlg::OnBnClickedInsert)
END_MESSAGE_MAP()


// CCompensationDlg 메시지 처리기입니다.

void CCompensationDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CCompensationDlg::OnLvnItemchangedItemCompensation(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CCompensationDlg::OnLvnItemchangedListEnddate(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CCompensationDlg::OnBnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_compensationList.DeleteAllItems();
	m_endDate.DeleteAllItems();
}

BOOL CCompensationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_compensationList.DeleteAllItems();
	m_compensationList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_compensationList.InsertColumn(0, _T("PresentType"), LVCFMT_LEFT, 60);
	m_compensationList.InsertColumn(1, _T("Value1"), LVCFMT_LEFT, 75);
	m_compensationList.InsertColumn(2, _T("Value2"), LVCFMT_LEFT, 75);

	m_endDate.DeleteAllItems();
	m_endDate.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_endDate.InsertColumn(0, _T("EndDate"), LVCFMT_LEFT, 180);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CCompensationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(WM_DROPFILES == pMsg->message)
	{
		if(m_compensationList.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropItemFiles( file );
			}
		}
		else if(m_endDate.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropEndDateFiles( file );
			}
		}
	}
	else if(WM_KEYDOWN == pMsg->message )
	{
		if(VK_RETURN == pMsg->wParam)
		{
			if(m_editCompensationCode.GetSafeHwnd() == pMsg->hwnd)
			{
				CString itemCode;
				m_editCompensationCode.GetWindowText(itemCode);
				m_editCompensationCode.SetWindowText(_T(""));

				InsertItemCode(itemCode);
			}
			else if(m_editEndDate.GetSafeHwnd() == pMsg->hwnd)
			{
				CString itemCount;
				m_editEndDate.GetWindowText(itemCount);
				m_editEndDate.SetWindowText(_T(""));

				InsertEndDate(itemCount);
			}
			return TRUE;
		}
		else if(VK_DELETE == pMsg->wParam)
		{
			if(m_compensationList.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_compensationList.GetSelectedCount();
				if(count > 0) //kyg 여기에 루프 추가 
				{ 
					DeleteListItem(m_compensationList);

				}
			}
			else if(m_endDate.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_endDate.GetSelectedCount();
				if(count > 0)
				{

					DeleteListItem(m_endDate);
				}
			}
			return TRUE;
		}
	}

	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CCompensationDlg::InsertItemCode(CString itemCode)
{
	if( itemCode.GetLength() == 0 || m_compensationList.GetItemCount() > 0 )
		return;
	
	if(itemCode.GetLength() == 0) return;

	int index = 0;
	CString presentType, value1, value2;
	presentType = itemCode.Tokenize(_T("."), index);
	if(presentType.IsEmpty()) return;

	if( atoi(presentType) != 3 && atoi(presentType) != 6 )
		return;

	value1 = itemCode.Tokenize(_T("."), index);
	if(value1.IsEmpty()) return;

	value2 = itemCode.Tokenize(_T("."), index);
	if(value2.IsEmpty()) return;

	int itemCount = m_compensationList.GetItemCount();
	m_compensationList.InsertItem(itemCount, presentType);
	m_compensationList.SetItemText(itemCount, 1, value1);
	m_compensationList.SetItemText(itemCount, 2, value2);
}

BOOL CCompensationDlg::CheckDateType(CString endDate)
{
	if( endDate.GetLength() != 10 )
		return FALSE;

	DWORD dwEndDate	= atoi(endDate);

	int iYear	= dwEndDate / 1000000;
	int iMonth	= (dwEndDate % 1000000) / 10000;
	int iDay	= (dwEndDate % 10000) / 100;
	int iHour	= (dwEndDate % 10000) % 100;

	if( iYear < 2015 )
		return FALSE;

	if( iMonth < 1 || iMonth > 12 )
		return FALSE;

	if( iHour < 0 || 24 < iHour )
		return FALSE;

	int checkDay	= 0;

	if( 2 == iMonth )
	{
		checkDay = 28;
        if ((iYear % 4 == 0 && iYear % 100 != 0) || (iYear % 100 == 0 && iYear % 400 == 0))
            checkDay = 29;
	}
	else if( (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11) )
	{
		checkDay	= 30;
	}
	else
	{
		checkDay	= 31;
	}

	if( checkDay < iDay )
		return FALSE;

	//현재보다 이전인지 체크
	CTime cCurTime = CTime::GetCurrentTime();
	CTime cEndDate( iYear, iMonth, iDay, iHour, 0, 0 );

	if( cCurTime > cEndDate )
		return FALSE;

	return TRUE;
}

void CCompensationDlg::InsertEndDate(CString endDate)
{
	if( endDate.GetLength() == 0 || m_endDate.GetItemCount() > 0 )
		return;

	//check
	if( !CheckDateType(endDate) )
		return;

	m_endDate.InsertItem(m_endDate.GetItemCount(), endDate);
}
	
void CCompensationDlg::OnDropItemFiles(CString file)
{
	m_compensationList.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertItemCode(line);
			}
		}
	}
}

void CCompensationDlg::OnDropEndDateFiles(CString file)
{
	m_endDate.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertEndDate(line);
			}
		}
	}
}

void CCompensationDlg::DeleteListItem(CListCtrl& m_List)
{
	int index = -1;
	POSITION pos = m_List.GetFirstSelectedItemPosition();
	while(pos)
	{
		int index = m_List.GetNextSelectedItem(pos);
		m_List.DeleteItem(index);
		pos = m_List.GetFirstSelectedItemPosition();
	}
}

void CCompensationDlg::OnBnClickedInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString presentType, value1, value2, endDate;

	presentType = m_compensationList.GetItemText(0, 0);
	value1 = m_compensationList.GetItemText(0, 1);
	value2 = m_compensationList.GetItemText(0, 2);
	endDate = m_endDate.GetItemText(0, 0);
	
	if( m_compensationList.GetItemCount() <= 0 || m_endDate.GetItemCount() <= 0 )
		return;


	ReqeustGiveCompensation(atoi(presentType), atoi(value1), atoi(value2), atoi(endDate));
}


void CCompensationDlg::ReqeustGiveCompensation(int type, int code, int value, int endDate)
{
	//CTime 값으로 변환
	int iYear	= endDate / 1000000;
	int iMonth	= (endDate % 1000000) / 10000;
	int iDay	= (endDate % 10000) / 100;
	int iHour	= (endDate % 10000) % 100;

	CTime cEndDate( iYear, iMonth, iDay, iHour, 0, 0 );
	m_parent->RequestCompensation(type, code, value, cEndDate.GetTime());
}