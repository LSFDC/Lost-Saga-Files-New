#pragma once
#include "afxwin.h"


class CZoneDialog;

// CEventDlg 대화 상자입니다.

class CEventDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEventDlg)

public:
	CEventDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEventDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EVENT_DIALOG };

public:
	void Startup(CZoneDialog* parent);

	void OnDropEventFiles(CString file);
	void Parse(CString text);

protected:
	CZoneDialog* m_parent;
	int m_values[64];
	int m_valueCount;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_eventEdit;
	afx_msg void OnBnClickedButtonEventApply();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
