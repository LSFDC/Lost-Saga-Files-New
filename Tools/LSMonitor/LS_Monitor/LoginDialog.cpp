// LoginDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "PanelDialog.h"
#include "ZoneDialog.h"
#include "LoginDialog.h"
#include "WinMessage.h"
#include "afxdialogex.h"
#include <algorithm>

enum LoginPanelTimerIDs
{
	PANEL_NONE = 0,
	PANEL_REFRESH,
	PANEL_END
};

// CLoginDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLoginDialog, CDialogEx)

CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDialog::IDD, pParent), m_maxUser(0), m_CCU(0), m_maxPanel(0), m_matrix(0), m_curHeight(0), m_scrollPos(0), m_panelWidth(0), m_panelHeight(0)
{

}

CLoginDialog::~CLoginDialog()
{
	for(int i = 0 ; i < (int)m_panels.size() ; i++)
	{
		delete m_panels[i];
		m_panels[i] = NULL;
	}
	//m_panels._Destroy()
}

void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_SIZING()
END_MESSAGE_MAP()


// CLoginDialog 메시지 처리기입니다.

BOOL CLoginDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	GetClientRect(m_window);
	m_scrollPos = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CLoginDialog::Startup(CString title, const int maxUser, const int maxServer, const int matrix, CZoneDialog* parent)
{
	m_title = title;
	SetWindowText(title);

	m_parent	= parent;
	m_maxUser	= maxUser;
	m_maxPanel	= maxServer;
	m_matrix	= matrix;
}

void CLoginDialog::AddPanel(int serverId, CString name, CString IP, int port, int blockState)
{
	if(FindPanel(serverId))
		return;

	int count = m_panels.size();

	RECT rcPanel;

	CPanelDialog * panelDlg = new CPanelDialog;
	panelDlg->Create(IDD_PANEL_DIALOG, this);
	panelDlg->Startup(serverId, name, IP, port, blockState, m_maxUser);
	panelDlg->ShowWindow(SW_SHOW);
	panelDlg->GetClientRect(&rcPanel);
	GeneratePos(m_matrix, count, rcPanel);

	panelDlg->MoveWindow(&rcPanel);
	panelDlg->SetWindowPos(&wndTopMost, 0 , 0 , 0 , 0 , SWP_NOMOVE|SWP_NOSIZE);
	panelDlg->ShowWindow(SW_SHOW);

	m_panels.push_back(panelDlg);

	if(m_panels.size() == 1)
	{
		m_panelWidth = rcPanel.right - rcPanel.left;
		m_panelHeight = rcPanel.bottom - rcPanel.top;
		AdjustWindow(rcPanel.right - rcPanel.left, rcPanel.bottom - rcPanel.top);

		MoveWindow(m_window);
	}
}

void CLoginDialog::UpdateBegin()
{
	int count = m_panels.size();
	for(int i = 0; i < count ; i++)
	{
		CPanelDialog * panelDlg = m_panels[i];
		if(!panelDlg) continue;

		panelDlg->UpdateBegin();
	}
}

void CLoginDialog::UpdateEnd(int CCU)
{
	int count = m_panels.size();
	for(int i = 0; i < count ; i++)
	{
		CPanelDialog * panelDlg = m_panels[i];
		if(!panelDlg) continue;

		panelDlg->UpdateEnd();
	}

	UpdateTitle(CCU);
}

void CLoginDialog::UpdatePanel(int index, int currentUser, int sendCount, int serverState)
{
	CPanelDialog* panelDlg = FindPanel(index);
	if(panelDlg)
	{
		panelDlg->Update(currentUser, sendCount, serverState);
	}
}

void CLoginDialog::UpdateTitle(int maxUser)
{
	if(maxUser != m_CCU)
	{
		m_CCU = maxUser;

		CString title;
		title.Format(_T("%s(CCU : %d)"), m_title, m_CCU);

		SetWindowText(title);
	}
}

CPanelDialog* CLoginDialog::FindPanel(const int serverId)
{
	int count = m_panels.size();
	for(int i = 0; i < count ; i++)
	{
		CPanelDialog * panelDlg = m_panels[i];
		if(!panelDlg) continue;

		if(panelDlg->GetServerID() == serverId)
			return panelDlg;
	}
	return NULL;
}

void CLoginDialog::AdjustWindow(int width, int height)
{
	int col = m_maxPanel % m_matrix;
	int row = (m_maxPanel / m_matrix) + (col ? 1 : 0);
	m_window.right  = m_window.left + (width * m_matrix) + 30;
	m_window.bottom	= m_window.top + (height * row) + 30;
}

void CLoginDialog::GeneratePos(const int matrix, const int index, RECT& rcPanel)
{
	int width = rcPanel.right - rcPanel.left;
	int height = rcPanel.bottom - rcPanel.top;

	int row = index / (matrix);
	int col = index % (matrix);

	rcPanel.left	= (col) * width;
	rcPanel.right	= rcPanel.left + width;
	rcPanel.top		= (row) * height;
	rcPanel.bottom	= rcPanel.top +  height;
}

void CLoginDialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int delta;
	int maxPos = m_window.Height() - m_curHeight;

	switch (nSBCode)
	{
	case SB_LINEDOWN:
		if (m_scrollPos >= maxPos)
			return;
		delta = min(max(maxPos/20,5),maxPos-m_scrollPos);
		break;

	case SB_LINEUP:
		if (m_scrollPos <= 0)
			return;
		delta = -min(max(maxPos/20,5),m_scrollPos);
		break;

	case SB_PAGEDOWN:
		if (m_scrollPos >= maxPos)
			return;
		delta = min(max(maxPos/20,5),maxPos-m_scrollPos);
		break;

	case SB_THUMBPOSITION:
		delta = (int)nPos - m_scrollPos;
		break;
	case SB_THUMBTRACK:
	case SB_PAGEUP:
		if (m_scrollPos <= 0)
			return;
		delta = -min(max(maxPos/20,5),m_scrollPos);
		break;

	default:
		return;
	}
	m_scrollPos += delta;
	SetScrollPos(SB_VERT,m_scrollPos,TRUE);
	ScrollWindow(0,-delta);

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CLoginDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_curHeight = cy;
 
	SCROLLINFO si;
	si.cbSize	= sizeof(SCROLLINFO);
	si.fMask	= SIF_ALL;
	si.nMin		= 0;
	si.nMax		= m_window.Height();
	si.nPage	= cy;
	si.nPos		= 0;
	SetScrollInfo(SB_VERT, &si, TRUE); 
}

BOOL CLoginDialog::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int maxPos = m_window.Height() - m_curHeight;

	if (zDelta<0)
	{
		if (m_scrollPos < maxPos)
		{
			zDelta = min(max(maxPos/10,5),maxPos-m_scrollPos);

			m_scrollPos += zDelta;
			SetScrollPos(SB_VERT,m_scrollPos,TRUE);
			ScrollWindow(0,-zDelta);
		}
	}
	else
	{
		if (m_scrollPos > 0)
		{
			zDelta = -min(max(maxPos/10,5),m_scrollPos);

			m_scrollPos += zDelta;
			SetScrollPos(SB_VERT,m_scrollPos,TRUE);
			ScrollWindow(0,-zDelta);
		}
	}


	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CLoginDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for(int i = 0; i < (int)m_panels.size() ; i++)
	{
		CPanelDialog* dlg = m_panels[i];
		dlg->ShowWindow(bShow);
	}

	CRect tmp;
	GetClientRect(&tmp);

	OnSizing(2, tmp);
	ShowScrollBar(SB_VERT, TRUE);

	if(bShow)
	{
		SetTimer(PANEL_REFRESH, 2900, NULL);
	}
	else
	{
		KillTimer(PANEL_REFRESH);
	}
}

void CLoginDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch(nIDEvent)
	{
	case PANEL_REFRESH:
		{
			m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINREFRESHPANEL);
		}
		break;

	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CLoginDialog::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	KillTimer(PANEL_REFRESH);

	CDialogEx::OnClose();
}


BOOL CLoginDialog::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch(wParam)
	{
	case IDC_SERVICE_LOGINBLOCK :
		{
			m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINBLOCK, lParam);
		}
		return TRUE;

	case IDC_SERVICE_LOGINUNBLOCK :
		{
			m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINUNBLOCK, lParam);
		}
		return TRUE;

	case IDC_SERVICE_LOGINBLOCKALL :
		{
			m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINBLOCKALL, lParam);
		}
		return TRUE;

	case IDC_SERVICE_LOGINUNBLOCKALL :
		{
			m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_LOGINUNBLOCKALL, lParam);
		}
		return TRUE;

	default :
		break;
	}

	return CDialogEx::OnCommand(wParam, lParam);
}


void CLoginDialog::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	pRect->right = pRect->left + m_window.Width();
	int height = pRect->bottom - pRect->top;
	if(height < (m_panelHeight+32))
	{
		pRect->bottom = pRect->top + m_panelHeight + 32;
	}
}


BOOL CLoginDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}
