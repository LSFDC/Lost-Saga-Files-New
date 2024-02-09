// DisplayDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "DisplayDlg.h"
#include "afxdialogex.h"


// CDisplayDlg ��ȭ �����Դϴ�.

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

// CDisplayDlg �޽��� ó�����Դϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
