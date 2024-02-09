#pragma once
#include "afxwin.h"

// CAuthDlg 대화 상자입니다.

class CAuthDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAuthDlg)

public:
	CAuthDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAuthDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_AUTH_DIALOG };

public:
	void GetText(CString& ID, CString& PWD);

protected:
	CString m_ID, m_PWD;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CEdit m_editID;
	CEdit m_editPWD;
	afx_msg void OnBnClickedButtonAuth();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
