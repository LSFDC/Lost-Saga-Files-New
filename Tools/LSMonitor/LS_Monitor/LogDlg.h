#pragma once

class CZoneDialog;

// CLogDlg ��ȭ �����Դϴ�.

class CLogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDlg)

public:
	CLogDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLogDlg();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl	m_logList;

	virtual BOOL OnInitDialog();


	afx_msg void OnBnClickedButtonLogReset();
	afx_msg void OnLvnItemchangedListLog(NMHDR *pNMHDR, LRESULT *pResult);
};
