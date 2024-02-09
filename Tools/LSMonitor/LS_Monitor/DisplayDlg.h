#pragma once
#include "afxwin.h"


class CZoneDialog;
// CDisplayDlg ��ȭ �����Դϴ�.

class CDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDisplayDlg)

public:
	CDisplayDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDisplayDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DISPLAY_DIALOG };

public:
	void Startup(CZoneDialog* dlg);
	void Show(int serverType, int index, CString& title, CString& text);

protected:
	void Refresh();

protected:
	int m_serverType;
	int m_index;
	CZoneDialog* m_parent;
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CEdit m_editCtrl;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
};
