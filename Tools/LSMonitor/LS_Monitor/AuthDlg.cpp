// AuthDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "AuthDlg.h"
#include "afxdialogex.h"


// CAuthDlg ��ȭ �����Դϴ�.

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


// CAuthDlg �޽��� ó�����Դϴ�.

void CAuthDlg::OnBnClickedButtonAuth()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
