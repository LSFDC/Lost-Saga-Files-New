#pragma once
#include "afxwin.h"


class CZoneDialog;

// CEventDlg ��ȭ �����Դϴ�.

class CEventDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEventDlg)

public:
	CEventDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEventDlg();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_eventEdit;
	afx_msg void OnBnClickedButtonEventApply();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
