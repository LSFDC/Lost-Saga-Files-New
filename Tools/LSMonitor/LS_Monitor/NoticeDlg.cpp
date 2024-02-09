// NoticeDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "NoticeDlg.h"
#include "afxdialogex.h"

using namespace std;

// CNoticeDlg 대화 상자입니다.

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


// CNoticeDlg 메시지 처리기입니다.

void CNoticeDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

BOOL CNoticeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitList();

	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 앞선 데이터 있으면 날려주고
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
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

	// 공지가 시작 된 타입
	if( it->second.eType == NOTICE_START_ON )
	{
		// 공지 호출
		DoAnnounceTime( nIDEvent );
	}

	// 공지 시작
	if( iStartDate == iNowDate )
	{		
		if( it->second.eType == NOTICE_START_BEFORE )
		{
			it->second.eType = NOTICE_START_ON;
		}			

		// 기존 시작 시점까지의 1분 interval 삭제
		KillTimer( nIDEvent );

		// 공지 호출
		DoAnnounceTime( nIDEvent );

		strInterval = m_ListInterval.GetItemText( nIDEvent, 0 );
		if( strInterval.IsEmpty() )
			return;

		// 간격 시간 체크
		sprintf_s( chInterval, "%s", strInterval );
		iInterval = atoi( chInterval );

		iInterval = iInterval * 60 * 1000;

		SetTimer( nIDEvent, iInterval, NULL );		
	}

	// 공지 종료
	if( iEndDate == iNowDate )
	{
		m_TimeNoticeMap.erase( it );

		// 종료
		KillTimer( nIDEvent );

		// 마지막 공지 호출
		DoAnnounceTime( nIDEvent );

		return;
	}

	// 현재 시각이 공지 시각 보다 뒤인 경우
	if( iStartDate < iNowDate )
	{
		if( it->second.eType == NOTICE_START_AFTER )
		{
			std::list<int> IntervalTimeList;
			IntervalTimeList = it->second.m_IntervalTimeList;

			std::list<int>::iterator iter = IntervalTimeList.begin();
			for( ; iter != IntervalTimeList.end(); ++iter )
			{
				// interval 시간값과 동일할 때 시작.
				if( iNowDate == *iter )
				{
					if( it->second.eType == NOTICE_START_BEFORE )
					{
						it->second.eType = NOTICE_START_ON;
					}			

					// 기존 시작 시점까지의 1분 interval 삭제
					KillTimer( nIDEvent );

					// 공지 호출
					DoAnnounceTime( nIDEvent );

					strInterval = m_ListInterval.GetItemText( nIDEvent, 0 );
					if( strInterval.IsEmpty() )
						return;

					// 간격 시간 체크
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

	// 종료시간을 보고 Timer 돌지 않을 항목 체크
	int iCount = m_ListEndDate.GetItemCount();
	for( int i = 0; i < iCount; ++i )
	{
		strEndDate = m_ListEndDate.GetItemText( i, 0 );
		if( strEndDate.IsEmpty() )
			continue;

		sprintf_s( chEndDate, "%s", strEndDate );
		iEndDate = atoi( chEndDate );

		// 종료시간 지난 공지
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

		// 간격 시간 체크
		sprintf_s( chInterval, "%s", strInterval );
		iInterval = atoi( chInterval );

		// 공지 시작
		if( iStartDate == iNowDate )
		{
			iInterval = iInterval * 60 * 1000;

			SetTimer( i, iInterval, NULL );

			// 공지 호출
			DoAnnounceTime( i );

			IntervalData data;
			data.eType = NOTICE_START_ON;
			m_TimeNoticeMap.insert( pair< int, IntervalData > ( i, data ) );
		}
		else
		{
			IntervalData data;

			// 시작 시각 전 
			// 1분마다 interval 을 주면서 해당 시각이 되었을 때 세팅된 interval 을 줌
			if( iStartDate > iNowDate )
			{
				data.eType = NOTICE_START_BEFORE;
				m_TimeNoticeMap.insert( pair< int, IntervalData > ( i, data ) );
			}

			// 시작 시각 후
			// 1분마다 interval 을 주면서 iNowDate 가 몇 번의 interval 만큼 더 해졌을때 값이 같을지 세팅
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

				// Interval 시간 증가 된 값들 리스트로 삽입
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

			// 구분자는 i. OnTimer 에서 event ID 로 들어간다.
			SetTimer( i, 1000, NULL );
		}	
	}	
}