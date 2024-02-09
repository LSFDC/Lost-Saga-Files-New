// AuthDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "AuthDlg.h"
#include "afxdialogex.h"


// CAuthDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CAuthDlg, CDialogEx)

CAuthDlg::CAuthDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAuthDlg::IDD, pParent)
{

}

CAuthDlg::~CAuthDlg()
{
}

void CAuthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_editID);
	DDX_Control(pDX, IDC_EDIT_PWD, m_editPWD);
}

BEGIN_MESSAGE_MAP(CAuthDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_AUTH, &CAuthDlg::OnBnClickedButtonAuth)
END_MESSAGE_MAP()


// CAuthDlg 메시지 처리기입니다.

void CAuthDlg::OnBnClickedButtonAuth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_editID.GetWindowText(m_ID);
	m_editPWD.GetWindowText(m_PWD);
	
	if(m_ID.IsEmpty() || m_PWD.IsEmpty())
	{
		EndDialog(IDCANCEL);
	}
	else
		EndDialog(IDOK);
}

void CAuthDlg::GetText(CString& ID, CString& PWD)
{
	ID	= m_ID;
	PWD = m_PWD;
}

BOOL CAuthDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(WM_KEYDOWN == pMsg->message )
	{
		if(VK_RETURN == pMsg->wParam)
		{
			OnBnClickedButtonAuth();
			return TRUE;
		}
	}

	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}
