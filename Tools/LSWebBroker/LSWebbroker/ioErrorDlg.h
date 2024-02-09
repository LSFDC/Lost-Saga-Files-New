#pragma once
#include "afxwin.h"
#include "resource.h"

// ioErrorDlg ��ȭ �����Դϴ�.
#include "skin/CDialogSK.h"
#include "skin/HoverButton.h"

class ioErrorDlg : public CDialogSK
{
public:
	ioErrorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ioErrorDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IOERRORDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit        m_Edit;
	CBrush       m_EditBGBrush;
	COLORREF     m_EditBGColor;
	COLORREF     m_EditTextColor;

	CHoverButton m_XBtn;
	CHoverButton m_SolutionBtn;
	CHoverButton m_ExitBtn;
	int          m_iErrorNumber;
	CFont        m_EditFont;

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	void ShowErrorDlg(CString szErrorText, int iErrorNumber );
	afx_msg void OnBnClickedSolution();
	afx_msg void OnBnClickedXbtn();
	afx_msg void OnBnClickedExitBtn();
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
};
