#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ProcessCtrl.h"

// CPanelDialog 대화 상자입니다.

class CPanelDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPanelDialog)

public:
	CPanelDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CPanelDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PANEL_DIALOG };

public:
	void Startup(int serverId, CString title, CString serverIP, int serverPort, int blockState, int maxUser);

	void UpdateBegin();
	void UpdateEnd();
	void Update(int currentUser, int sendCount, int serverState);

	void CreatePopup();
	void UpdatePopup(int blockState);

	int GetServerID()	{ return m_serverId; }

protected:
	int m_maxValue;
	int m_current;

	CString m_serverName;
	CString m_serverIP;
	int m_serverId;
	int m_serverPort;
	int m_blockState;
	int m_serverState;

	CProcessCtrl m_graph;
	CMenu m_menu;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_title;
	virtual BOOL OnInitDialog();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
