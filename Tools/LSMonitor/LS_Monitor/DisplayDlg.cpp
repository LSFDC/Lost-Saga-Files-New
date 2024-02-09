// DisplayDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "DisplayDlg.h"
#include "afxdialogex.h"


// CDisplayDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDisplayDlg, CDialogEx)

CDisplayDlg::CDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDisplayDlg::IDD, pParent), m_serverType(0), m_index(0), m_parent(NULL)
{

}

CDisplayDlg::~CDisplayDlg()
{
}

void CDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SHOWINFO, m_editCtrl);
}


BEGIN_MESSAGE_MAP(CDisplayDlg, CDialogEx)
END_MESSAGE_MAP()


void CDisplayDlg::Startup(CZoneDialog* dlg)
{
	m_parent = dlg;
	ShowWindow(SW_HIDE);
}

// CDisplayDlg 메시지 처리기입니다.
void CDisplayDlg::Show(int serverType, int index, CString& title, CString& text)
{
	SetWindowText(title);

	m_serverType	= serverType;
	m_index			= index;

	m_editCtrl.SetWindowText(text);
	m_editCtrl.SetSel(0, 0);
	m_editCtrl.SetFocus();
	ShowWindow(SW_SHOW);
}

void CDisplayDlg::Refresh()
{
	if(!m_parent->m_billingFlag)
		m_parent->RequestInfo(m_serverType, m_index);
	else
	{
		int billingKeyIndex = m_serverType;
		m_parent->RequestInfo(SERVER_TYPE_BILLING, billingKeyIndex);
	}
}

BOOL CDisplayDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch(pMsg->message)
	{
	case WM_KEYDOWN :
		{
			if(VK_F5 == pMsg->wParam)
			{
				Refresh();
				return FALSE;
			}
		}
		break;
	case WM_SYSKEYDOWN:
		{
		}
		break;
	}


	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CDisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
