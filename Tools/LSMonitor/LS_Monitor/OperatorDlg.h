#pragma once
#include "afxcmn.h"

class CZoneDialog;
class CAnnounceDlg;
class CItemDlg;
class CEventDlg;
class CCSDlg;
class CBlockDlg;
class CLogDlg;
class CNoticeDlg;
class CSecretShopDlg;
class CCompensationDlg;
// COperatorDlg 대화 상자입니다.

class COperatorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COperatorDlg)

public:
	COperatorDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COperatorDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_OPERATOR_DIALOG };
	
public:
	void Startup(CZoneDialog* parent);
	void CreatePanel();

	CCSDialog* GetCSDlg()	{ return m_csDlg; }

protected:
	void ShowTab(int index);
	void HideTab(int index);

	CZoneDialog* GetZone() { return m_parent; }
public:
	void ShowLogTab();

	void WriteLogDlg( CString text );

protected:
	CZoneDialog* m_parent;

	CAnnounceDlg* m_announceDlg;
	CItemDlg* m_itemDlg;
	CEventDlg* m_eventDlg;
	CCSDialog* m_csDlg;
	CBlockDlg* m_blockDlg;

	CLogDlg* m_logDlg;

	CNoticeDlg * m_NoticeDlg;

	CSecretShopDlg* m_SecretShopDlg;

	CCompensationDlg* m_CompensationDlg;

	int m_tablIndex;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CTabCtrl m_operatorTab;
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTcnSelchangeTabOperator(NMHDR *pNMHDR, LRESULT *pResult);
};
