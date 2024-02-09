// PanelDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "PanelDialog.h"
#include "WinMessage.h"
#include "Define.h"
#include "afxdialogex.h"


// CPanelDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPanelDialog, CDialogEx)

CPanelDialog::CPanelDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPanelDialog::IDD, pParent), m_maxValue(0), m_current(0), m_serverId(0), m_serverPort(0), m_blockState(0), m_serverState(0)
{

}

CPanelDialog::~CPanelDialog()
{
}

void CPanelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TITLE_STATIC, m_title);
}


BEGIN_MESSAGE_MAP(CPanelDialog, CDialogEx)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CPanelDialog �޽��� ó�����Դϴ�.
BOOL CPanelDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CreatePopup();

	CRect rc;
	GetDlgItem(IDC_STATIC_MBAR)->GetWindowRect(rc);
	ScreenToClient(rc);

	m_graph.Create(WS_VISIBLE | WS_CHILD, rc, this); 
	m_graph.SetRange( 0, 100 );
	m_graph.SetPlotColor(RGB(128, 128, 128), FALSE);
	m_graph.SetBackgroundColor(RGB(128, 128, 128), TRUE);
	m_graph.InitToolTip();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CPanelDialog::Startup(int serverId, CString title, CString serverIP, int serverPort, int blockState, int maxUser)
{
	m_title.SetWindowText(title);
	m_graph.SetRange(0, maxUser);
	m_graph.DrawGraph(0);

	m_serverId		= serverId;
	m_serverName	= title;
	m_serverIP		= serverIP;
	m_serverPort	= serverPort;
	m_blockState	= blockState;

	CString tooltip;
	tooltip.Format(_T("%s(%s:%d) - %d/%d"), m_serverName, m_serverIP, m_serverPort, m_current, m_maxValue);
	m_graph.SetToolTip(tooltip);

	UpdatePopup(m_blockState);
}

void CPanelDialog::UpdateBegin()
{
	m_serverState = ESOCKET::LS_REQSERVERSTATE;
}

void CPanelDialog::UpdateEnd()
{
	switch(m_serverState)
	{
	case ESOCKET::LS_DISCONNECTED :
		m_blockState = 0;
		m_menu.CheckMenuItem(IDC_SERVICE_LOGINBLOCK, MF_UNCHECKED);
		m_graph.SetPlotColor(RGB(128, 128, 128), FALSE);
		m_graph.SetBackgroundColor(RGB(128, 128, 128), TRUE);
		break;
	
	case ESOCKET::LS_RESPSERVERSTATE :
		m_blockState = 0;
		m_menu.CheckMenuItem(IDC_SERVICE_LOGINBLOCK, MF_UNCHECKED);
		m_graph.SetPlotColor(RGB(128, 255, 128), FALSE);
		m_graph.SetBackgroundColor(RGB(0, 0, 0), TRUE);
		break;

	case ESOCKET::LS_ZOMBIESERVERSTATE :
		m_blockState = 0;
		m_menu.CheckMenuItem(IDC_SERVICE_LOGINBLOCK, MF_UNCHECKED);
		m_graph.SetPlotColor(RGB(255, 0, 0), FALSE);
		m_graph.SetBackgroundColor(RGB(0, 0, 0), TRUE);
		break;
	
	case ESOCKET::LS_BLOCKED :
		m_blockState = 1;
		m_menu.CheckMenuItem(IDC_SERVICE_LOGINBLOCK, MF_CHECKED);
		m_graph.SetPlotColor(RGB(128, 128, 128), FALSE);
		m_graph.SetBackgroundColor(RGB(0, 0, 0), TRUE);
		break;
	}
}

void CPanelDialog::Update(int currentUser, int sendCount, int serverState)
{
	m_current		= currentUser;
	m_serverState	= serverState;
	if(m_maxValue < m_current)
	{
		m_maxValue = m_current;
	}

	CString tooltip;
	tooltip.Format(_T("%s(%s:%d) - %d/%d"), m_serverName, m_serverIP, m_serverPort, m_current, m_maxValue);
	m_graph.SetToolTip(tooltip);
	m_graph.DrawGraph(currentUser);
}

void CPanelDialog::CreatePopup()
{
	// �˾��޴�
	m_menu.CreatePopupMenu();

	CString menu;
	menu = _T("Block");
	m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGINBLOCK, (LPCTSTR)menu);
	m_menu.AppendMenu(MF_SEPARATOR);
	menu = _T("ALL Block");
	m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGINBLOCKALL, (LPCTSTR)menu);
	menu = _T("ALL Unblock");
	m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGINUNBLOCKALL, (LPCTSTR)menu);
}

void CPanelDialog::UpdatePopup(int blockState)
{
	if(blockState == 1)
	{
		m_menu.CheckMenuItem(IDC_SERVICE_LOGINBLOCK, MF_CHECKED);
	}
	else
	{
		m_menu.CheckMenuItem(IDC_SERVICE_LOGINBLOCK, MF_UNCHECKED);
	}
}

void CPanelDialog::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPoint pos;
	GetCursorPos(&pos);

	m_menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pos.x, pos.y, this);

	CDialogEx::OnRButtonDown(nFlags, point);
}


BOOL CPanelDialog::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	switch(wParam)
	{
	case IDC_SERVICE_LOGINBLOCK :
		{
			if(m_blockState == 1)
			{
				UpdatePopup(0);
				GetParent()->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINUNBLOCK, m_serverId);
			}
			else
			{
				UpdatePopup(1);
				GetParent()->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINBLOCK, m_serverId);
			}
		}
		break;

	case IDC_SERVICE_LOGINBLOCKALL :
	case IDC_SERVICE_LOGINUNBLOCKALL :
		{
			GetParent()->PostMessage(WM_COMMAND, wParam, 0);
		}
		break;

	default :
		{
		}
		break;
	}

	return CDialogEx::OnCommand(wParam, lParam);
}


BOOL CPanelDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}
