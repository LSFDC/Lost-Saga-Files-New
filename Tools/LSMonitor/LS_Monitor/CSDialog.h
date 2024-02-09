#pragma once
#include "afxwin.h"


class CZoneDialog;

// CCSDialog ��ȭ �����Դϴ�.

class CCSDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CCSDialog)

public:
	CCSDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCSDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CS_DIALOG };

public:
	void Startup(CZoneDialog* dlg);
	void Log(const char *format, ...);

	void GetVersion(CString& version, CString& change);

protected:
	CZoneDialog* m_parent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_csLog;
	CEdit m_changeVersion;
	CEdit m_version;
	afx_msg void OnBnClickedButtonLoadCS();
	afx_msg void OnBnClickedButtonShowCS();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
