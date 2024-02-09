#pragma once

class CZoneDialog;

// CLogDlg 대화 상자입니다.

class CLogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDlg)

public:
	CLogDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLogDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOG_DIALOG };

public:
	void Startup(CZoneDialog* parent);

protected:
	void InitList();

public:
	void InsertLogText( CString text );
	void ResetLogText();

protected:
	CZoneDialog* m_parent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl	m_logList;

	virtual BOOL OnInitDialog();


	afx_msg void OnBnClickedButtonLogReset();
	afx_msg void OnLvnItemchangedListLog(NMHDR *pNMHDR, LRESULT *pResult);
};
