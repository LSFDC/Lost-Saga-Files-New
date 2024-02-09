// TotalLogDl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "LogDlg.h"
#include "afxdialogex.h"


// CLogDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLogDlg, CDialogEx)

CLogDlg::CLogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogDlg::IDD, pParent)
{

}

CLogDlg::~CLogDlg()
{
}

void CLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control( pDX, IDC_LIST_LOG, m_logList );
}


BEGIN_MESSAGE_MAP(CLogDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOG_RESET, &CLogDlg::OnBnClickedButtonLogReset)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_LOG, &CLogDlg::OnLvnItemchangedListLog)
END_MESSAGE_MAP()


// CLogDlg �޽��� ó�����Դϴ�.
void CLogDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CLogDlg::InitList()
{
	m_logList.DeleteAllItems();
	m_logList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_logList.InsertColumn(0, _T("Time"),  LVCFMT_LEFT, 60);
	m_logList.InsertColumn(1, _T("Message"),  LVCFMT_LEFT, 375);

}

BOOL CLogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitList();

	return TRUE;
}

void CLogDlg::InsertLogText( CString text )
{
	if( text.IsEmpty() ) return;

	CTime	nowTime = CTime::GetCurrentTime();
	
	CString nowTimeText;
	nowTimeText.Format( _T(" %02d:%02d:%02d"),
						nowTime.GetHour(),
						nowTime.GetMinute(),
						nowTime.GetSecond() );

	int logCount = m_logList.GetItemCount();
	m_logList.InsertItem( logCount, nowTimeText );
	m_logList.SetItemText( logCount, 1, text );
	m_logList.EnsureVisible( m_logList.GetItemCount() - 1, TRUE );
}
void CLogDlg::ResetLogText()
{
	m_logList.DeleteAllItems();
}

void CLogDlg::OnBnClickedButtonLogReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ResetLogText();
}



void CLogDlg::OnLvnItemchangedListLog(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
