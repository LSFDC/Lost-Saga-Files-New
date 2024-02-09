// NoticeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "NoticeDlg.h"
#include "afxdialogex.h"

using namespace std;

// CNoticeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CNoticeDlg, CDialogEx)

CNoticeDlg::CNoticeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNoticeDlg::IDD, pParent)
	, m_parent(NULL)
{
	m_TimeNoticeMap.clear();
}

CNoticeDlg::~CNoticeDlg()
{
	m_TimeNoticeMap.clear();
}

void CNoticeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_START_DATE, m_ListStartDate);
	DDX_Control(pDX, IDC_LIST_START_INTERVAL, m_ListInterval);
	DDX_Control(pDX, IDC_LIST_END_DATE, m_ListEndDate);
	DDX_Control(pDX, IDC_LIST_NOTICE, m_ListNotice);
	DDX_Control(pDX, IDC_EDIT_START_DATE, m_EditStartDate);
	DDX_Control(pDX, IDC_EDIT_INTERVAL, m_EditInterval);
	DDX_Control(pDX, IDC_EDIT_END_DATE, m_EditEndDate);
	DDX_Control(pDX, IDC_EDIT_NOTICE, m_EditNotice);
}


BEGIN_MESSAGE_MAP(CNoticeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CNoticeDlg::OnBnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_ANNOUNCE_TIME, &CNoticeDlg::OnBnClickedButtonAnnounceTime)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CNoticeDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CNoticeDlg::OnBnClickedButtonClear)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CNoticeDlg �޽��� ó�����Դϴ�.

void CNoticeDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

BOOL CNoticeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitList();

	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CNoticeDlg::InitList()
{
	m_ListStartDate.DeleteAllItems();
	m_ListStartDate.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_ListStartDate.InsertColumn(0, _T("StartTime"), LVCFMT_LEFT, 80);

	m_ListInterval.DeleteAllItems();
	m_ListInterval.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_ListInterval.InsertColumn(0, _T("Interval"), LVCFMT_LEFT, 56);

	m_ListEndDate.DeleteAllItems();
	m_ListEndDate.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_ListEndDate.InsertColumn(0, _T("EndTime"), LVCFMT_LEFT, 80);

	m_ListNotice.DeleteAllItems();
	m_ListNotice.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_ListNotice.InsertColumn(0, _T("Notice"), LVCFMT_LEFT, 300);
}

void CNoticeDlg::OnBnClickedButtonInput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CString strStartDate;
	m_EditStartDate.GetWindowText( strStartDate );

	CString strInterval;
	m_EditInterval.GetWindowText( strInterval );

	CString strEndDate;
	m_EditEndDate.GetWindowText( strEndDate );

	CString strNotice;
	m_EditNotice.GetWindowText( strNotice );

	if( strStartDate.GetLength() == 0 ||
		strInterval.GetLength() == 0 ||
		strEndDate.GetLength() == 0 ||
		strNotice.GetLength() == 0 )
		return;

	m_EditStartDate.SetWindowText( _T("") );
	InsertStartDate( strStartDate );

	m_EditInterval.SetWindowText( _T("") );
	InsertInterval( strInterval );

	m_EditEndDate.SetWindowText( _T("") );
	InsertEndDate( strEndDate );

	m_EditNotice.SetWindowText( _T("") );
	InsertNotice( strNotice );
}


void CNoticeDlg::OnBnClickedButtonAnnounceTime()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// �ռ� ������ ������ �����ְ�
	std::map< int, IntervalData >::iterator it = m_TimeNoticeMap.begin();
	for( ; it != m_TimeNoticeMap.end(); ++it )
	{
		KillTimer( it->first );
	}
	m_TimeNoticeMap.clear();

	TimeCheck();
}


void CNoticeDlg::OnBnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	std::map< int, IntervalData >::iterator it;

	UINT count = m_ListStartDate.GetSelectedCount();
	if(count > 0)
	{
		DeleteListItem( m_ListStartDate );		
		it = m_TimeNoticeMap.find( count );
		if( it != m_TimeNoticeMap.end() )
			KillTimer( count );
	}
	
	count = m_ListInterval.GetSelectedCount();
	if(count > 0)
	{
		DeleteListItem( m_ListInterval );
		it = m_TimeNoticeMap.find( count );
		if( it != m_TimeNoticeMap.end() )
			KillTimer( count );
	}

	count = m_ListEndDate.GetSelectedCount();
	if(count > 0)
	{
		DeleteListItem( m_ListEndDate );
		it = m_TimeNoticeMap.find( count );
		if( it != m_TimeNoticeMap.end() )
			KillTimer( count );
	}

	count = m_ListNotice.GetSelectedCount();
	if(count > 0)
	{
		DeleteListItem( m_ListNotice );
		it = m_TimeNoticeMap.find( count );
		if( it != m_TimeNoticeMap.end() )
			KillTimer( count );
	}
}


void CNoticeDlg::OnBnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_ListStartDate.DeleteAllItems();
	m_ListInterval.DeleteAllItems();
	m_ListEndDate.DeleteAllItems();
	m_ListNotice.DeleteAllItems();

	m_EditStartDate.SetWindowText( _T("") );
	m_EditInterval.SetWindowText( _T("") );
	m_EditEndDate.SetWindowText( _T("") );
	m_EditNotice.SetWindowText( _T("") );

	std::map< int, IntervalData >::iterator it = m_TimeNoticeMap.begin();
	for( ; it != m_TimeNoticeMap.end(); ++it )
	{
		KillTimer( it->first );
	}
	m_TimeNoticeMap.clear();
}


BOOL CNoticeDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	if( WM_KEYDOWN == pMsg->message )
	{
		if( VK_RETURN == pMsg->wParam )
		{
			if( m_EditStartDate.GetSafeHwnd() == pMsg->hwnd )
			{
				CString strStartDate;
				m_EditStartDate.GetWindowText( strStartDate );
				m_EditStartDate.SetWindowText( _T("") );

				InsertStartDate( strStartDate );
			}
			else if( m_EditInterval.GetSafeHwnd() == pMsg->hwnd )
			{
				CString strInterval;
				m_EditInterval.GetWindowText( strInterval );
				m_EditInterval.SetWindowText( _T("") );

				InsertInterval( strInterval );
			}
			else if( m_EditEndDate.GetSafeHwnd() == pMsg->hwnd )
			{
				CString strEndDate;
				m_EditEndDate.GetWindowText( strEndDate );
				m_EditEndDate.SetWindowText( _T("") );

				InsertEndDate( strEndDate );
			}
			else if( m_EditNotice.GetSafeHwnd() == pMsg->hwnd )
			{
				CString strNotice;
				m_EditNotice.GetWindowText( strNotice );
				m_EditNotice.SetWindowText( _T("") );

				InsertNotice( strNotice );
			}
			return TRUE;
		}
		else if( VK_DELETE == pMsg->wParam )
		{
			std::map< int, IntervalData >::iterator it;

			if( m_ListStartDate.GetSafeHwnd() == pMsg->hwnd )
			{
				UINT count = m_ListStartDate.GetSelectedCount();
				if(count > 0) 
				{
					DeleteListItem( m_ListStartDate );
					it = m_TimeNoticeMap.find( count );
					if( it != m_TimeNoticeMap.end() )
						KillTimer( count );
				}
			}
			else if( m_ListInterval.GetSafeHwnd() == pMsg->hwnd )
			{
				UINT count = m_ListInterval.GetSelectedCount();
				if(count > 0)
				{
					DeleteListItem( m_ListInterval );
					it = m_TimeNoticeMap.find( count );
					if( it != m_TimeNoticeMap.end() )
						KillTimer( count );
				}
			}
			else if( m_ListEndDate.GetSafeHwnd() == pMsg->hwnd )
			{
				UINT count = m_ListEndDate.GetSelectedCount();
				if(count > 0)
				{
					DeleteListItem( m_ListEndDate );
					it = m_TimeNoticeMap.find( count );
					if( it != m_TimeNoticeMap.end() )
						KillTimer( count );
				}
			}
			else if( m_ListNotice.GetSafeHwnd() == pMsg->hwnd )
			{
				UINT count = m_ListNotice.GetSelectedCount();
				if(count > 0)
				{
					DeleteListItem( m_ListNotice );
					it = m_TimeNoticeMap.find( count );
					if( it != m_TimeNoticeMap.end() )
						KillTimer( count );
				}
			}
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CNoticeDlg::InsertStartDate( CString startDate )
{
	if( startDate.GetLength() == 0 ) 
		return;

	m_ListStartDate.InsertItem( m_ListStartDate.GetItemCount(), startDate );
}


void CNoticeDlg::InsertInterval( CString interval )
{
	if( interval.GetLength() == 0 ) 
		return;

	m_ListInterval.InsertItem( m_ListInterval.GetItemCount(), interval );
}


void CNoticeDlg::InsertEndDate( CString endDate )
{
	if( endDate.GetLength() == 0 ) 
		return;

	m_ListEndDate.InsertItem( m_ListEndDate.GetItemCount(), endDate );
}


void CNoticeDlg::InsertNotice( CString notice )
{
	if( notice.GetLength() == 0 ) 
		return;

	m_ListNotice.InsertItem( m_ListNotice.GetItemCount(), notice );
}


void CNoticeDlg::DeleteListItem( CListCtrl& AllList )
{
	int index = -1;
	POSITION pos = AllList.GetFirstSelectedItemPosition();
	while( pos )
	{
		int index = AllList.GetNextSelectedItem( pos );
		AllList.DeleteItem( index );
		pos = AllList.GetFirstSelectedItemPosition();
	}
}


void CNoticeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	std::map< int, IntervalData >::iterator it;
	it = m_TimeNoticeMap.find( nIDEvent );
	if( it == m_TimeNoticeMap.end() )
	{
		KillTimer( nIDEvent );
		return;
	}

	CTime nowTime;
	nowTime = CTime::GetCurrentTime();

	CString strStartDate, strEndDate, strInterval;
	char chStartDate[16] = {0,}, chEndDate[16] = {0,}, chInterval[16] = {0,};
	int iStartDate = 0, iEndDate = 0, iInterval = 0;	

	char chNowDate[16] = {0,};
	int iNowDate = 0;

	sprintf_s( chNowDate, "%02d%02d%02d%02d", nowTime.GetMonth()
											, nowTime.GetDay()
											, nowTime.GetHour()
											, nowTime.GetMinute() );
	iNowDate = atoi( chNowDate );

	strEndDate = m_ListEndDate.GetItemText( nIDEvent, 0 );
	if( strEndDate.IsEmpty() )
	{
		KillTimer( nIDEvent );
		return;
	}

	sprintf_s( chEndDate, "%s", strEndDate );
	iEndDate = atoi( chEndDate );

	strStartDate = m_ListStartDate.GetItemText( nIDEvent, 0 );
	if( strStartDate.IsEmpty() )
	{
		KillTimer( nIDEvent );
		return;
	}

	sprintf_s( chStartDate, "%s", strStartDate );
	iStartDate = atoi( chStartDate );

	// ������ ���� �� Ÿ��
	if( it->second.eType == NOTICE_START_ON )
	{
		// ���� ȣ��
		DoAnnounceTime( nIDEvent );
	}

	// ���� ����
	if( iStartDate == iNowDate )
	{		
		if( it->second.eType == NOTICE_START_BEFORE )
		{
			it->second.eType = NOTICE_START_ON;
		}			

		// ���� ���� ���������� 1�� interval ����
		KillTimer( nIDEvent );

		// ���� ȣ��
		DoAnnounceTime( nIDEvent );

		strInterval = m_ListInterval.GetItemText( nIDEvent, 0 );
		if( strInterval.IsEmpty() )
			return;

		// ���� �ð� üũ
		sprintf_s( chInterval, "%s", strInterval );
		iInterval = atoi( chInterval );

		iInterval = iInterval * 60 * 1000;

		SetTimer( nIDEvent, iInterval, NULL );		
	}

	// ���� ����
	if( iEndDate == iNowDate )
	{
		m_TimeNoticeMap.erase( it );

		// ����
		KillTimer( nIDEvent );

		// ������ ���� ȣ��
		DoAnnounceTime( nIDEvent );

		return;
	}

	// ���� �ð��� ���� �ð� ���� ���� ���
	if( iStartDate < iNowDate )
	{
		if( it->second.eType == NOTICE_START_AFTER )
		{
			std::list<int> IntervalTimeList;
			IntervalTimeList = it->second.m_IntervalTimeList;

			std::list<int>::iterator iter = IntervalTimeList.begin();
			for( ; iter != IntervalTimeList.end(); ++iter )
			{
				// interval �ð����� ������ �� ����.
				if( iNowDate == *iter )
				{
					if( it->second.eType == NOTICE_START_BEFORE )
					{
						it->second.eType = NOTICE_START_ON;
					}			

					// ���� ���� ���������� 1�� interval ����
					KillTimer( nIDEvent );

					// ���� ȣ��
					DoAnnounceTime( nIDEvent );

					strInterval = m_ListInterval.GetItemText( nIDEvent, 0 );
					if( strInterval.IsEmpty() )
						return;

					// ���� �ð� üũ
					sprintf_s( chInterval, "%s", strInterval );
					iInterval = atoi( chInterval );

					iInterval = iInterval * 60 * 1000;

					SetTimer( nIDEvent, iInterval, NULL );

					return;
				}
			}
			
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CNoticeDlg::DoAnnounceTime( int iSelected )
{
	CString strNotice;

	strNotice = m_ListNotice.GetItemText( iSelected, 0 );
	if( !strNotice.IsEmpty() )
	{
		m_parent->RequestAnnounce( ANNOUNCE_TYPE_ALL, "", strNotice );
	}
}


void CNoticeDlg::TimeCheck()
{
	CTime nowTime;
	nowTime = CTime::GetCurrentTime();
	
	char chNowDate[16] = {0,};
	int iNowDate = 0;

	CString strStartDate, strEndDate, strInterval;
	char chStartDate[16], chEndDate[16], chInterval[16] = {0,};
	int iStartDate, iEndDate, iInterval = 0;	
	
	sprintf_s( chNowDate, "%02d%02d%02d%02d", nowTime.GetMonth()
											, nowTime.GetDay()
											, nowTime.GetHour()
											, nowTime.GetMinute() );
	iNowDate = atoi( chNowDate );

	// ����ð��� ���� Timer ���� ���� �׸� üũ
	int iCount = m_ListEndDate.GetItemCount();
	for( int i = 0; i < iCount; ++i )
	{
		strEndDate = m_ListEndDate.GetItemText( i, 0 );
		if( strEndDate.IsEmpty() )
			continue;

		sprintf_s( chEndDate, "%s", strEndDate );
		iEndDate = atoi( chEndDate );

		// ����ð� ���� ����
		if( iNowDate > iEndDate )
			continue;

		strStartDate = m_ListStartDate.GetItemText( i, 0 );
		if( strStartDate.IsEmpty() )
			continue;

		sprintf_s( chStartDate, "%s", strStartDate );
		iStartDate = atoi( chStartDate );

		strInterval = m_ListInterval.GetItemText( i, 0 );
		if( strInterval.IsEmpty() )
			continue;

		// ���� �ð� üũ
		sprintf_s( chInterval, "%s", strInterval );
		iInterval = atoi( chInterval );

		// ���� ����
		if( iStartDate == iNowDate )
		{
			iInterval = iInterval * 60 * 1000;

			SetTimer( i, iInterval, NULL );

			// ���� ȣ��
			DoAnnounceTime( i );

			IntervalData data;
			data.eType = NOTICE_START_ON;
			m_TimeNoticeMap.insert( pair< int, IntervalData > ( i, data ) );
		}
		else
		{
			IntervalData data;

			// ���� �ð� �� 
			// 1�и��� interval �� �ָ鼭 �ش� �ð��� �Ǿ��� �� ���õ� interval �� ��
			if( iStartDate > iNowDate )
			{
				data.eType = NOTICE_START_BEFORE;
				m_TimeNoticeMap.insert( pair< int, IntervalData > ( i, data ) );
			}

			// ���� �ð� ��
			// 1�и��� interval �� �ָ鼭 iNowDate �� �� ���� interval ��ŭ �� �������� ���� ������ ����
			else
			{
				int iIntervalTime	= iStartDate;
				data.eType			= NOTICE_START_AFTER;
				int iTemp			= 0;
				char chTemp[16]		= {0,};
				
				SYSTEMTIME sysTime;

				GetLocalTime( &sysTime );
				iTemp = iIntervalTime / 1000000;
				sysTime.wMonth = iTemp;
				iTemp = iIntervalTime / 10000 % 100;
				sysTime.wDay = iTemp;
				iTemp = iIntervalTime / 100 % 100;
				sysTime.wHour = iTemp;
				iTemp = iIntervalTime % 100;
				sysTime.wMinute = iTemp;
				CTime cTime( sysTime );				

				// Interval �ð� ���� �� ���� ����Ʈ�� ����
				while( iIntervalTime < iEndDate )
				{
					data.m_IntervalTimeList.push_back( iIntervalTime );

					cTime += CTimeSpan( iInterval * 60 );
					sprintf_s( chTemp, "%02d%02d%02d%02d", cTime.GetMonth()
						, cTime.GetDay(), cTime.GetHour(), cTime.GetMinute() );

					iIntervalTime = atoi( chTemp );
				}
				
				m_TimeNoticeMap.insert( pair< int, IntervalData > ( i, data ) );
			}				

			// �����ڴ� i. OnTimer ���� event ID �� ����.
			SetTimer( i, 1000, NULL );
		}	
	}	
}