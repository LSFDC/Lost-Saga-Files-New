// MainFrm.h : CMainFrame Ŭ������ �������̽�
//


#pragma once

#include "TrayIcon.h"
#include "SetupAndStart.h"
#include "ioErrorDlg.h"
#include "SetupFolderDlg.h"
#include "ioLoginDlg.h"
#include "ioLocalDlg.h"

#define  WM_ICON_NOTIFY  WM_USER+10
// Global ���ڸ� ���̸� ����� ��ȯ�� ������ ����Ǿ �ߺ� ������ ���� �Ѵ�.
#define APPMUTEXNAME         "Global\\_LOSTSAGA_WEBBROKER_38393848484839392029339312"
#define AUTOUPGRADEMUTEXNAME "Global\\_LOSTSAGA_AUTOUPGRADE_748569521365987415930392049"
#define CLIENTMUTEXNAME      "Global\\_LOSTSAGA_CLIENT_3894738393994848484939308770494"
#define	AUTOUPGRADENAME      "_LOSTSAGA_AUTOUPGRADE_"

class ioStringManager;
class ioLocalManager;
class ioLocalParent;
class HttpManager;

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

protected:
	enum 
	{
		ID_EXIT_TIMER = 1,
	};
protected:
	CTrayIcon      m_TrayIcon;
	CSetupAndStart m_SetupAndStart;

	ioErrorDlg     m_ErrorDlg;
	SetupFolderDlg m_SetupFolderDlg;
	ioLoginDlg     m_LoginDlg;
	ioLocalDlg		m_LocalDlg;
	ioLocalManager  *m_pLocalMgr;
	ioStringManager *m_pStringMgr;
	HttpManager     *m_pHttpMgr;

	HANDLE			m_h_mutex;

	int				m_nSubType;
	


protected:
	void LoadStartINI( OUT char *szLocal, IN int iLocalSize, OUT char *szURL, IN int iURLSize, OUT char *szReg, IN int iRegSize );

public:
	void SetWantExit();
	void ShowErrorDlg(const char* szErrorText, int iErrorNumber );
	void SetupAndStart(CString &rszClientPath);
	void ParseCmdAndStart( ioLocalParent *pLocal, const char* szRet = NULL );
	void ShowSetupFolderDlg();
	void SetLoginKey(LPCTSTR szKey);
	void SetLocalType(LPCTSTR szLocal);
	void SetSubLocalType(int nSubType) {m_nSubType = nSubType;}
	int GetSubLocalType() {return m_nSubType; }
	void DeleteClientDirectorys(const char* szFolder);
	bool SendLoginData(OUT char* szError, IN int iErrorSize, OUT int iErrorCode, const char* szID, const char* szPW, IN const char* szURL);


// Ư��
public:

// �۾�
public:

// ������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL DestroyWindow();
};
void LoadFileInResource(int name, const char * type, DWORD& size, const char*& data);
