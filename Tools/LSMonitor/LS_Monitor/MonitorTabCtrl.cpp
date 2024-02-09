// MonitorTabCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "LS_MonitorDlg.h"
#include "ZoneDialog.h"
#include "MonitorTabCtrl.h"

// CMonitorTabCtrl

IMPLEMENT_DYNAMIC(CMonitorTabCtrl, CTabCtrl)

CMonitorTabCtrl::CMonitorTabCtrl()
{

}

BEGIN_MESSAGE_MAP(CMonitorTabCtrl, CTabCtrl)
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


int CMonitorTabCtrl::SetDialogIndex(CZoneDialog* arg)
{
	UINT index = GetItemCount();
	index -= 1;
	m_dialogs[index] = arg;
	
	return index;
}

void CMonitorTabCtrl::AddTab(CString& title, CString& main, CString& login, BOOL billingFlag, BILLINGSERVERTABLE& tempBillingServerMap, bool bCountryCode)
{
	this->InsertItem(GetItemCount(), title);
	
	// 다이얼로그 처리
	if(GetItemCount() == 1) // 최초 한번만 실행
	{
		CRect tabRect, itemRect;
		GetClientRect(&tabRect);
		GetItemRect(0, &itemRect);

		m_x			= itemRect.left;
		m_y			= itemRect.bottom+1;
		m_width		= tabRect.right - itemRect.left - 1;
		m_height	= tabRect.bottom - m_y - 1;
	}

	CZoneDialog* dlg = new CZoneDialog(this);
	dlg->Create(IDD_ZONEINFO_DIALOG, this);
	dlg->SetWindowPos(&wndTop, m_x, m_y, m_width, m_height, SWP_HIDEWINDOW);

	dlg->m_bCountryCode = bCountryCode;
	
	if( billingFlag == FALSE)
		dlg->CreateMonitor(title, main, login);	
	else
		dlg->CreateBillingMonitor(title, billingFlag, tempBillingServerMap);
	
	
	int index = -1;
	index  = SetDialogIndex(dlg);
	// 포커스 초기화 0으로..
	SetCurSel(index);
	SetFocus(index);
}

void CMonitorTabCtrl::ShowTab(const UINT index, const BOOL show)
{
	CZoneDialog* dlg = GetDialog(index);
	if(!dlg) return;
	
	if(show)
	{
		dlg->Show();

		SetCurSel(index);
		m_tabIndex = index;
	}
	else
	{
		dlg->Hide();
	}
}

CZoneDialog* CMonitorTabCtrl::GetDialog(const UINT index)
{
	SERVER_DIALOGS::iterator it = m_dialogs.find(index);
	if(it != m_dialogs.end())
	{
		return it->second;
	}
	return NULL;
}

void CMonitorTabCtrl::SetFocus(const UINT index)
{
	if(GetTabIndex() != index)
	{
		ShowTab(GetTabIndex(), FALSE);
		ShowTab(GetCurFocus(), TRUE);
	}
	else
	{
		ShowTab(GetTabIndex(), TRUE);
	}
}

void CMonitorTabCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetFocus(GetCurFocus());

	CTabCtrl::OnLButtonUp(nFlags, point);
}


void CMonitorTabCtrl::OnSize(UINT nType, int cx, int cy)
{
	CTabCtrl::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect client;
	GetClientRect(client);

	for(SERVER_DIALOGS::iterator it = m_dialogs.begin(); it != m_dialogs.end() ; ++it)
	{
		CZoneDialog* dlg = it->second;
		if(!dlg) continue;

		CRect rc;
		dlg->GetClientRect(rc);

		if(dlg->IsShow())
		{
			dlg->SetWindowPos(NULL, rc.left+2, rc.top+26, m_width, cy - 30, SWP_SHOWWINDOW);
		}
		else
		{
			dlg->SetWindowPos(NULL, rc.left+2, rc.top+26, m_width, cy - 30, SWP_HIDEWINDOW);
		}
	}
}

void CMonitorTabCtrl::OnDestroy()
{
	for(int i = 0; i < (int)m_dialogs.size(); i++)
		SAFEDELETE(m_dialogs[i]);
}

