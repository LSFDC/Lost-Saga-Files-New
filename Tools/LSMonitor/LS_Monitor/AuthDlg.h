#pragma once
#include "afxwin.h"

// CAuthDlg ��ȭ �����Դϴ�.

class CAuthDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAuthDlg)

public:
	CAuthDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAuthDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_AUTH_DIALOG };

public:
	void GetText(CString& ID, CString& PWD);

protected:
	CString m_ID, m_PWD;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CEdit m_editID;
	CEdit m_editPWD;
	afx_msg void OnBnClickedButtonAuth();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
