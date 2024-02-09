// MonitorListCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "WinMessage.h"
#include "ZoneDialog.h"
#include "MonitorListCtrl.h"

IMPLEMENT_DYNAMIC(CMonitorListCtrl, CListCtrl)

CMonitorListCtrl::CMonitorListCtrl()
: m_bCountryCount(false)
{
	InitToolTip();
}

CMonitorListCtrl::~CMonitorListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMonitorListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, &CMonitorListCtrl::OnNMLClick)
	ON_NOTIFY_REFLECT(NM_RCLICK, &CMonitorListCtrl::OnNMRClick)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CMonitorListCtrl::OnNMDblclk)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDrawList)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CMonitorListCtrl 메시지 처리기입니다.
void CMonitorListCtrl::Startup(CZoneDialog* parent, const int index)
{ 
	m_parent = parent;
	m_ctrlIndex = index; 

}

void CMonitorListCtrl::CreatePopup(const ServerTypes serverType)
{
	InitToolTip();

	switch(serverType)
	{
	case SERVER_TYPE_MAIN:
		{
			m_menu.DestroyMenu();
			m_menu.CreatePopupMenu();

			// 팝업메뉴
			CString menu;
			if(GetZone()->IsAdministrator())
			{
				menu = _T("Shutdown immediately");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINSAFECLOSE, (LPCTSTR)menu);

				m_menu.AppendMenu(MF_SEPARATOR);

				menu = _T("Shutdown all immediately");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GAMEQUICKCLOSEALL, (LPCTSTR)menu);

				menu = _T("Shutdown all safely");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GAMESAFECLOSEALL, (LPCTSTR)menu);

				m_menu.AppendMenu(MF_SEPARATOR);

				menu = _T("Reload gameserver INI");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINRELOADINI, (LPCTSTR)menu);

				menu = _T("Reload gameserver OPTION");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINRELOADOPTION, (LPCTSTR)menu);

				menu = _T("Reload closing INI");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_RELOAD_CLOSEINI, (LPCTSTR)menu);

				menu = _T("Reset the quantity of event shop");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINRESETEVENTSHOP, (LPCTSTR)menu);

				menu = _T("Reset the quantity of clover shop");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINRESETCLOVERSHOP, (LPCTSTR)menu);

				menu = _T("Reset the quantity of milege shop");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINRESETMILEGESHOP, (LPCTSTR)menu);

				menu = _T("Reset all record of the purchase");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAINRESETBUYLOG, (LPCTSTR)menu);

				menu = _T("Reset old record of the mission");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAIN_RESET_MISSION, (LPCTSTR)menu);
				
				m_menu.AppendMenu(MF_SEPARATOR);

				menu = _T("White-list on");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAIN_WHITELISTON, (LPCTSTR)menu);

				menu = _T("White-list off");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_MAIN_WHITELISTOFF, (LPCTSTR)menu);

				m_menu.AppendMenu(MF_SEPARATOR);

				//menu = _T("Tool CS-file");
				//m_menu.AppendMenu(MF_STRING, IDC_SERVICE_CSDIALOG, (LPCTSTR)menu);

				menu = _T("Operating tool");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_SHOWTOOL, (LPCTSTR)menu);
			}
			else if(GetZone()->IsOperator())
			{
				menu = _T("Operating tool");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_SHOWTOOL, (LPCTSTR)menu);
			}
			else
			{
				menu = _T("Authenticate");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_AUTHENTICATION, (LPCTSTR)menu);
			}
		}
		break;

	case SERVER_TYPE_LOGIN:
		{
			m_menu.DestroyMenu();
			m_menu.CreatePopupMenu();

			if(GetZone()->IsAdministrator())
			{
				// 팝업메뉴
				CString menu;

				menu = _T("Show panel");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGINSHOWPANEL, (LPCTSTR)menu);

				m_menu.AppendMenu(MF_SEPARATOR);

				menu = _T("Shutdown immediately");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGINQUICKEXIT, (LPCTSTR)menu);

				m_menu.AppendMenu(MF_SEPARATOR);

				menu = _T("White-list on");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGIN_WHITELISTON, (LPCTSTR)menu);

				menu = _T("White-list off");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_LOGIN_WHITELISTOFF, (LPCTSTR)menu);
			}
		}
		break;

	case SERVER_TYPE_GAME:
		{
			m_menu.DestroyMenu();
			m_menu.CreatePopupMenu();

			if(GetZone()->IsAdministrator())
			{
				// 팝업메뉴
				CString menu;

				menu = _T("Shutdown immediately");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GAMEQUICKCLOSE, (LPCTSTR)menu);

				menu = _T("Shutdown safely");
				m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GAMESAFECLOSE, (LPCTSTR)menu);

				UINT flag = GetZone()->GetRelayFlag(GetSelectedIndex()) ? MFS_CHECKED : MFS_UNCHECKED;
				menu = _T("Relayserver on/off");
				m_menu.AppendMenu(flag,IDC_SERVICE_RELAYSERVERCONTROL,(LPCTSTR)menu);
			}
		}
		break;

	case SERVER_TYPE_BILLING:
		{
			m_menu.DestroyMenu();
			m_menu.CreatePopupMenu();

			// 팝업메뉴
			CString menu;

			menu = _T("Reload billingsvr INI");
			m_menu.AppendMenu(MF_STRING, IDC_SERVICE_BILLINGRELOADINI, (LPCTSTR)menu);
			
			/*
			m_menu.AppendMenu(MF_SEPARATOR);
			
			menu = _T("Nexon PCRoom User Logout");
			m_menu.AppendMenu(MF_STRING, IDC_SERVICE_BILLINGNEXONLOGOUT, (LPCTSTR)menu);
			*/
		}
		break;
	}
}

void CMonitorListCtrl::InitToolTip()
{
	if (m_toolTip.m_hWnd == NULL) 
	{ 
		m_toolTip.Create(this); 
		m_toolTip.Activate(FALSE); 

		m_toolTip.SetDelayTime(TTDT_AUTOPOP, 3000);
	} 
}

void CMonitorListCtrl::SetToolTip(CString text)
{
	m_toolTip.DelTool(this, 0);
	m_toolTip.AddTool(this, text, NULL, 0);
}

int CMonitorListCtrl::GetSelectedIndex()
{
	int index = -1;
	for(int i = 0; i < GetItemCount(); i++)
	{
		if(LVIS_SELECTED == GetItemState(i, LVIS_SELECTED))
		{
			index = i;
			break;
		}
	}
	return index;
}

void CMonitorListCtrl::OnNMLClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPoint pos;
	GetCursorPos(&pos);

	int index = GetSelectedIndex();
	if(index != -1)
	{
		LVITEM item = {0};
		item.iItem	= index;
		item.mask	= LVIF_PARAM;
		this->GetItem( &item);

		ServerTypes serverType = (ServerTypes)item.lParam;

		CZoneDialog* dlg = (CZoneDialog*)GetParent();
		if(dlg)
		{
			if(!dlg->m_billingFlag)
			{
				CString servernName, serverIP;
				int serverPort; 
				//dlg->GetAddress((ServerTypes)item.lParam, item.iItem, servernName, serverIP, serverPort);

				CString toolTip;
// 				if(m_bCountryCount)
// 				{
// 					int strENG, strGER, strFRA, strITA, strPOL, strTUR, strETC;
// 					dlg->GetCCUINFO((ServerTypes)item.iItem, servernName, serverIP, serverPort, strENG, strGER, strFRA, strITA, strPOL, strTUR, strETC);
// 					if(servernName.Find("_") != -1)
// 						return;
// 					toolTip.Format(_T("%s(%s:%d) | ENG( %d), GER( %d), FRA( %d), ITA( %d), POL( %d), TUR( %d), ETC( %d)"), servernName, serverIP, serverPort, 
// 						strENG, strGER, strFRA, strITA, strPOL, strTUR, strETC);
// 				}
// 				else
				{
					dlg->GetAddress((ServerTypes)item.lParam, item.iItem, servernName, serverIP, serverPort);
					toolTip.Format(_T("%s(%s:%d)"), servernName, serverIP, serverPort);
				}
				SetToolTip(toolTip);

				m_toolTip.Activate(TRUE); 
			}
		}
	}

	*pResult = 0;
}

void CMonitorListCtrl::OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPoint pos;
	GetCursorPos(&pos);

	int index = GetSelectedIndex();
	if(index != -1)
	{
		//모니터링 끄기 기능은 현재 사용안함
		if( m_parent->m_billingFlag == TRUE )
		{
			LVITEM item = {0};
			item.iItem	= index;
			item.mask	= LVIF_PARAM;
			this->GetItem( &item);

			ServerTypes serverType = SERVER_TYPE_BILLING;

			BILLINGSERVERINFO* serverInfo = NULL;
			serverInfo = m_parent->GetBillingServerInfo( item.lParam );	//m_billingServerTable의 키값으로 서버 정보 찾음
			

			if( serverInfo != NULL && (serverInfo->billingServerState == SERVERSTATE_ON ) )
			{
				// 마우스 위치에 팝업메뉴를 출력한다.
				CreatePopup(serverType);
				m_menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pos.x, pos.y, this);
			}
		}
		else 
		{
			LVITEM item = {0};
			item.iItem	= index;
			item.mask	= LVIF_PARAM;
			this->GetItem( &item);

			ServerTypes serverType = (ServerTypes)item.lParam;
		
			// 마우스 위치에 팝업메뉴를 출력한다.
			CreatePopup(serverType);
			m_menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pos.x, pos.y, this);
		}
	}
	*pResult = 0;
}


BOOL CMonitorListCtrl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	int index = GetSelectedIndex();
	if(index != -1)
	{
		GetParent()->PostMessage(WM_COMMAND, wParam, index);
		return TRUE;
	}

	return CListCtrl::OnCommand(wParam, lParam);
}

void CMonitorListCtrl::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(GetZone()->IsAdministrator())
	{
		int index = GetSelectedIndex();
		if(index != -1)
		{
			LVITEM item = {0};
			item.iItem	= index;
			item.mask	= LVIF_PARAM;
			this->GetItem( &item);

			switch(item.lParam)
			{
			case SERVER_TYPE_MAIN:
				SendMessage(WM_COMMAND, IDC_SERVICE_MAININFO, NULL);
				break;
			case SERVER_TYPE_LOGIN:
				SendMessage(WM_COMMAND, IDC_SERVICE_LOGININFO, NULL);
				break;
			case SERVER_TYPE_GAME:
				SendMessage(WM_COMMAND, IDC_SERVICE_GAMEINFO, index);
				break;
			}
		}
	}
	else
	{
		int index = GetSelectedIndex();
		if(index != -1)
		{
			LVITEM item = {0};
			item.iItem	= index;
			item.mask	= LVIF_PARAM;
			this->GetItem( &item);

	
			if( m_parent->m_billingFlag == TRUE )
			{
				m_parent->RequestBillingServerLOG(item.lParam);	//(ServerTypes)변환필요없음
			}
		}
	}

	*pResult = 0;
}



BOOL CMonitorListCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_toolTip.RelayEvent(pMsg);

	return CListCtrl::PreTranslateMessage(pMsg);
}

void CMonitorListCtrl::OnCustomDrawList( NMHDR* pNMHDR, LRESULT* pResult )
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
	int iItemNum = static_cast<int>(pLVCD->iSubItem);
	//CString strName = GetItemText(iItemNum, pLVCD->iSubItem);
	//CString strName = GetItemText(pLVCD->iSubItem,0); //0번째 텍스트 가져오자!
	CString strName = GetItemText(pLVCD->nmcd.dwItemSpec,0); //0번째 텍스트 가져오자!
	if( !strName.IsEmpty() && strName.Find("#") != -1 )
	{
		CFont font;
		CRect rc;
		CClientDC dc(this);
		font.CreateFontA(10,0,0,0,0,FALSE,FALSE,FALSE, DEFAULT_CHARSET,0,0,0,DEFAULT_QUALITY,_T("굴림체"));
		dc.SelectObject(font);
		GetItemRect(pLVCD->nmcd.dwItemSpec ,&rc ,LVIR_BOUNDS);
		rc.left += 7; //위치 조정
		CString strNum;
		strNum.Format("%d", pLVCD->nmcd.dwItemSpec + 1);
		dc.SetBkMode( TRANSPARENT );
		DrawText( dc, strNum, 2, rc, DT_LEFT | DT_VCENTER | DT_SINGLELINE );
		font.DeleteObject();
	}
	
	COLORREF crText = NULL;
 
	if(strName.Find(CCU_ENG) != -1)			crText = CCU_RGB_ENG;
	else if(strName.Find(CCU_GER) != -1) 	crText = CCU_RGB_GER;
	else if(strName.Find(CCU_FRA) != -1) 	crText = CCU_RGB_FRA;
	else if(strName.Find(CCU_ITA) != -1) 	crText = CCU_RGB_ITA;
	else if(strName.Find(CCU_POL) != -1) 	crText = CCU_RGB_POL;
	else if(strName.Find(CCU_TUR) != -1) 	crText = CCU_RGB_TUR;
	else if(strName.Find(CCU_ETC) != -1) 	crText = CCU_RGB_ETC;
	else									crText = RGB(0,0,0);

	pLVCD->clrText = crText;

	*pResult = CDRF_NOTIFYITEMDRAW;

	//*pResult = CDRF_DODEFAULT;
}


