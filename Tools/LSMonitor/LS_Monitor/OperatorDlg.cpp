// OperatorDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "AnnounceDlg.h"
#include "ItemDlg.h"
#include "EventDlg.h"
#include "CSDialog.h"
#include "BlockDlg.h"
#include "LogDlg.h"
#include "OperatorDlg.h"
#include "NoticeDlg.h"
#include "SecretShopDlg.h"
#include "CompensationDlg.h"
#include "afxdialogex.h"


// COperatorDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COperatorDlg, CDialogEx)

COperatorDlg::COperatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COperatorDlg::IDD, pParent)
	, m_parent(NULL)
	, m_announceDlg(NULL)
	, m_itemDlg(NULL)
	, m_eventDlg(NULL)
	, m_csDlg(NULL)
	, m_blockDlg(NULL)
	, m_logDlg(NULL)
	, m_tablIndex(0)
	, m_NoticeDlg( NULL )
	, m_SecretShopDlg(NULL)
	, m_CompensationDlg(NULL)
{

}

COperatorDlg::~COperatorDlg()
{
	delete m_announceDlg;
	delete m_itemDlg;
	delete m_eventDlg;
	delete m_csDlg;
	delete m_blockDlg;
	delete m_logDlg;
	delete m_NoticeDlg;
	delete m_SecretShopDlg;
	delete m_CompensationDlg;
}

void COperatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_OPERATOR, m_operatorTab);
}


BEGIN_MESSAGE_MAP(COperatorDlg, CDialogEx)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// COperatorDlg 메시지 처리기입니다.
void COperatorDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;

	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	CreatePanel();
	m_announceDlg->ShowWindow(SW_SHOW);
}

void COperatorDlg::CreatePanel()
{
	CRect rc;
	m_operatorTab.GetClientRect(rc);

	TC_ITEM item;
	item.mask = TCIF_TEXT;
 
	item.pszText = _T("Common");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

	item.pszText = _T("Item");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

	item.pszText = _T("Event");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

	item.pszText = _T("CS");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

	item.pszText = _T("Block");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

	item.pszText = _T("Notice");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

	item.pszText = _T("SecretShop");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item);

	item.pszText = _T("Compensation");
	m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item);

	m_announceDlg = new CAnnounceDlg;
	m_announceDlg->Create(IDD_ANNOUNCE_DIALOG, &m_operatorTab);
	m_announceDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_announceDlg->Startup(m_parent);

	m_itemDlg = new CItemDlg;
	m_itemDlg->Create(IDD_ITEM_DIALOG, &m_operatorTab);
	m_itemDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_itemDlg->Startup(m_parent);

	m_eventDlg = new CEventDlg;
	m_eventDlg->Create(IDD_EVENT_DIALOG, &m_operatorTab);
	m_eventDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_eventDlg->Startup(m_parent);

	m_csDlg = new CCSDialog;
	m_csDlg->Create(IDD_CS_DIALOG, &m_operatorTab);
	m_csDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_csDlg->Startup(m_parent);

	m_blockDlg	= new CBlockDlg;
	m_blockDlg->Create( IDD_BLOCK_DIALOG, &m_operatorTab );
	m_blockDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_blockDlg->Startup(m_parent);


	m_logDlg = new CLogDlg;
	m_logDlg->Create( IDD_LOG_DIALOG, &m_operatorTab );
	m_logDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_logDlg->Startup(m_parent);

	m_NoticeDlg = new CNoticeDlg;
	m_NoticeDlg->Create( IDD_NOTICEDLG, &m_operatorTab );
	m_NoticeDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_NoticeDlg->Startup(m_parent);

	m_SecretShopDlg = new CSecretShopDlg;
	m_SecretShopDlg->Create(IDD_DIALOG_SECRETSHOP,  &m_operatorTab);
	m_SecretShopDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_SecretShopDlg->Startup(m_parent);

	m_CompensationDlg = new CCompensationDlg;
	m_CompensationDlg->Create(IDD_COMPENSATION_DIALOG,  &m_operatorTab);
	m_CompensationDlg->MoveWindow(rc.left+10, rc.top+30, rc.Width()-30, rc.Height()-35);
	m_CompensationDlg->Startup(m_parent);
}

void COperatorDlg::ShowTab(int index)
{
	if( GetZone()->IsAdministrator() )
	{
		switch(index)
		{
		case 0:
			m_announceDlg->ShowWindow(SW_SHOW);
			break;
		case 1:
			m_itemDlg->ShowWindow(SW_SHOW);
			break;
		case 2:
			m_eventDlg->ShowWindow(SW_SHOW);
			break;
		case 3:
			m_csDlg->ShowWindow(SW_SHOW);
			break;
		case 4:
			m_blockDlg->ShowWindow(SW_SHOW);
			break;
		case 5:
			m_logDlg->ShowWindow(SW_SHOW);
			break;
		case 6:
			m_NoticeDlg->ShowWindow(SW_SHOW);
			break;
		case 7:
			m_SecretShopDlg->ShowWindow(SW_SHOW);
			break;
		case 8:
			m_CompensationDlg->ShowWindow(SW_SHOW);
			break;
		}
	}
	else if( GetZone()->IsOperator() )
	{
		switch(index)
		{
		case 0:
			m_announceDlg->ShowWindow(SW_SHOW);
			break;
		case 1:
			m_blockDlg->ShowWindow(SW_SHOW);
			break;
		case 2:
			m_logDlg->ShowWindow(SW_SHOW);
			break;
		case 3:
			m_NoticeDlg->ShowWindow(SW_SHOW);
			break;
		}
	}
}

void COperatorDlg::HideTab(int index)
{
	if( GetZone()->IsAdministrator() )
	{
		switch(index)
		{
		case 0:
			m_announceDlg->ShowWindow(SW_HIDE);
			break;
		case 1:
			m_itemDlg->ShowWindow(SW_HIDE);
			break;
		case 2:
			m_eventDlg->ShowWindow(SW_HIDE);
			break;	
		case 3:
			m_csDlg->ShowWindow(SW_HIDE);
			break;	
		case 4:
			m_blockDlg->ShowWindow(SW_HIDE);
			break;
		case 5:
			m_logDlg->ShowWindow(SW_HIDE);
			break;
		case 6:
			m_NoticeDlg->ShowWindow(SW_HIDE);
			break;
		case 7:
			m_SecretShopDlg->ShowWindow(SW_HIDE);
			break;
		case 8:
			m_CompensationDlg->ShowWindow(SW_HIDE);
			break;
		}
	}
	else if( GetZone()->IsOperator() )
	{
		switch(index)
		{
		case 0:
			m_announceDlg->ShowWindow(SW_HIDE);
			break;
		case 1:
			m_blockDlg->ShowWindow(SW_HIDE);
			break;
		case 2:
			m_logDlg->ShowWindow(SW_HIDE);
			break;
		case 3:
			m_NoticeDlg->ShowWindow(SW_HIDE);
			break;
		}
	}
}

void COperatorDlg::ShowLogTab()
{
	// logDlog는 무조건 제일 뒤에 있도록 설정한다
	HideTab( m_tablIndex );
	m_tablIndex = m_operatorTab.GetItemCount() - 1;
	
	ShowTab( m_tablIndex );
	m_operatorTab.SetCurSel( m_tablIndex );

	m_logDlg->SetFocus();
}

void COperatorDlg::WriteLogDlg( CString text )
{
	if( !m_logDlg ) return;

	m_logDlg->InsertLogText( text );
}

BOOL COperatorDlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	LPNMHDR lpnmhdr = (LPNMHDR) lParam; 
	if(lpnmhdr->code==TCN_SELCHANGE)
	{
		HideTab(m_tablIndex);

		m_tablIndex = m_operatorTab.GetCurSel();
		ShowTab(m_tablIndex);
	}
	return CDialogEx::OnNotify(wParam, lParam, pResult);
}


void COperatorDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	if(bShow)
	{
		m_operatorTab.DeleteAllItems();

		if(GetZone()->IsAdministrator())
		{
			TC_ITEM item;
			item.mask = TCIF_TEXT;
 
			item.pszText = _T("Common");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Item");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Event");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("CS");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item);
			
			item.pszText = _T("Block");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Log");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Notice");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("SecretShop");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Compensation");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 
		}
		else if(GetZone()->IsOperator())
		{
			TC_ITEM item;
			item.mask = TCIF_TEXT;
 
			item.pszText = _T("Common");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Block");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Log");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 

			item.pszText = _T("Notice");
			m_operatorTab.InsertItem(m_operatorTab.GetItemCount(), &item); 
		}
	}

	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
