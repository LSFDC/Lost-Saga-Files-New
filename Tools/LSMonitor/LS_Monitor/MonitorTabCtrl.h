#pragma once
#include "Define.h"
#include <map>

// CMonitorTabCtrl
class CZoneDialog;

class CMonitorTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMonitorTabCtrl)

public:
	CMonitorTabCtrl();

public:
	int  SetDialogIndex(CZoneDialog* arg);
	void AddTab(CString& title, CString& main, CString& login, BOOL bBilling, BILLINGSERVERTABLE& tempBillingServerMap, bool bCountryCode);
	void ShowTab(const UINT index, const BOOL show = TRUE);

	const UINT GetTabIndex() { return m_tabIndex; }

protected:
	typedef std::map<UINT, CZoneDialog*> SERVER_DIALOGS;		
	SERVER_DIALOGS m_dialogs;

	CZoneDialog* GetDialog(const UINT index);
	void SetFocus(const UINT index);

protected:
	int m_x, m_y, m_width, m_height;
	UINT m_tabIndex;

protected:
	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDestroy();
};


