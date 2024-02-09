#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <list>

class CZoneDialog;

// CNoticeDlg 대화 상자입니다.

class CNoticeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNoticeDlg)

public:
	CNoticeDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CNoticeDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_NOTICEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_ListStartDate;
	CListCtrl m_ListInterval;
	CListCtrl m_ListEndDate;
	CListCtrl m_ListNotice;

	CEdit	m_EditStartDate;
	CEdit	m_EditInterval;
	CEdit	m_EditEndDate;
	CEdit	m_EditNotice;

protected:
	CZoneDialog* m_parent;

	enum eNoticeType
	{
		NOTICE_NONE,
		NOTICE_START_ON,
		NOTICE_START_BEFORE,
		NOTICE_START_AFTER,
		NOTICE_END,
		NOTICE_MAX		
	};

	struct IntervalData
	{
		eNoticeType eType;
		std::list<int> m_IntervalTimeList;

		IntervalData()
		{
			Init();
		}
		void Init()
		{
			eType = NOTICE_NONE;
			m_IntervalTimeList.clear();
		}
	};

	std::map< int, IntervalData > m_TimeNoticeMap;
	

protected:
	void InsertStartDate( CString startDate );
	void InsertInterval( CString interval);
	void InsertEndDate( CString endDate );
	void InsertNotice( CString notice );

	void TimeCheck();
	void DoAnnounceTime( int iSelected );

public:
	void Startup( CZoneDialog* parent );
	void InitList();
	void DeleteListItem( CListCtrl& AllList );

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonInput();
	afx_msg void OnBnClickedButtonAnnounceTime();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonClear();
	virtual BOOL PreTranslateMessage( MSG* pMsg );
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
