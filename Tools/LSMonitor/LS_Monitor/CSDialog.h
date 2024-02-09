#pragma once
#include "afxwin.h"


class CZoneDialog;

// CCSDialog 대화 상자입니다.

class CCSDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CCSDialog)

public:
	CCSDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCSDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CS_DIALOG };

public:
	void Startup(CZoneDialog* dlg);
	void Log(const char *format, ...);

	void GetVersion(CString& version, CString& change);

protected:
	CZoneDialog* m_parent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
