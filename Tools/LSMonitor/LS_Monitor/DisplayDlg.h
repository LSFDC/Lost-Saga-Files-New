#pragma once
#include "afxwin.h"


class CZoneDialog;
// CDisplayDlg 대화 상자입니다.

class CDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDisplayDlg)

public:
	CDisplayDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDisplayDlg();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CEdit m_editCtrl;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
};
