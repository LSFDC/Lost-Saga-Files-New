#pragma once

#include <vector>


class CPanelDialog;
class CZoneDialog;

// CLoginDialog 대화 상자입니다.

class CLoginDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDialog)

public:
	CLoginDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLoginDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOGIN_DIALOG };

public:
	void Startup(CString title, const int maxUser, const int maxServer, const int matrix, CZoneDialog* parent);
	void AddPanel(int serverId, CString name, CString IP, int port, int blockState);

	void UpdateBegin();
	void UpdateEnd(int CCU);
	void UpdatePanel(int index, int currentUser, int sendCount, int serverState);
	void UpdateTitle(int CCU);

protected:
	CPanelDialog* FindPanel(const int serverId);

	void AdjustWindow(int width, int height);
	void GeneratePos(const int matrix, const int index, RECT& rcPanel);

protected:
	int m_maxUser;
	int m_CCU;
	int m_maxPanel;
	int m_matrix;
	int m_curHeight;
	int m_scrollPos;
	int m_panelWidth, m_panelHeight;
	CRect m_window;

	typedef std::vector<CPanelDialog*> PANELS;
	PANELS m_panels;

	CString m_title;
	CZoneDialog* m_parent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
