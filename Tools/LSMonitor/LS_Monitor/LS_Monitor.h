
// LS_Monitor.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLS_MonitorApp:
// See LS_Monitor.cpp for the implementation of this class
//
class CLS_MonitorDlg;
class CLS_MonitorApp : public CWinApp
{
public:
	CLS_MonitorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
private:
	CLS_MonitorDlg*	m_pMonitorDlg;
};

extern CLS_MonitorApp theApp;