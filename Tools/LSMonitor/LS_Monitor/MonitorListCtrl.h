#pragma once

#include "ServerTypes.h"

class CZoneDialog;

// CMonitorListCtrl

class CMonitorListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMonitorListCtrl)

public:
	CMonitorListCtrl();
	virtual ~CMonitorListCtrl();

public:
	void Startup(CZoneDialog* parent, const int index);
	int GetControlID()			{ return m_ctrlIndex; }

	int GetSelectedIndex();

protected:
	void CreatePopup(const ServerTypes serverType);
	
	void InitToolTip();
	void SetToolTip(CString text);

	CZoneDialog* GetZone()	{ return m_parent; }

protected:
	CMenu m_menu;
	CToolTipCtrl m_toolTip;
	int m_ctrlIndex;

	CZoneDialog* m_parent;

protected:
	DECLARE_MESSAGE_MAP()

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

public:
	afx_msg void OnNMLClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult); 
	afx_msg void OnCustomDrawList(NMHDR* pNMHDR, LRESULT* pResult);
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	bool	m_bCountryCount;
};


