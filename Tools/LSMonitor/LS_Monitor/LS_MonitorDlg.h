
// LS_MonitorDlg.h : header file
//

#pragma once

#include "afxcmn.h"
#include "MonitorTabCtrl.h"

// CLS_MonitorDlg dialog
class CLS_MonitorDlg : public CDialogEx
{
	DECLARE_EASYSIZE

// Construction
public:
	CLS_MonitorDlg(const TCHAR* parameter, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LS_MONITOR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public:
	CString GetIP()	{ return m_IP; }
	void UpdateTitle(const int currentUser, const int maxUser);
	
protected:
	BOOL LoadBillingFromINI(const TCHAR* file, CString section, BILLINGSERVERTABLE &tempBillingServerTable);
	void LoadINI(const TCHAR* file);
	void LoadIP();

	void AddTab(TCHAR* name, TCHAR* IP, const int port);

protected:
	CString m_IP;
	CRect m_clientRect;
	CString m_parameter;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

public:
	CMonitorTabCtrl m_zoneTabs;
	
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnDestroy();
};
