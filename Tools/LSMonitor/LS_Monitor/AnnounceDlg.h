#pragma once
#include "afxwin.h"
#include "afxcmn.h"


class CZoneDialog;

// CAnnounceDlg ��ȭ �����Դϴ�.

class CAnnounceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAnnounceDlg)

public:
	CAnnounceDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAnnounceDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ANNOUNCE_DIALOG };

public:
	void Startup(CZoneDialog* parent);
	void InitList();

protected:
	void OnDropUserFiles(CString file);
	void OnDropAnnounceFiles(CString file);
	void InsertUserID(CString userId);
	void InsertAnnounce(CString announce);

	void DoAnnounce();

protected:
	CZoneDialog* m_parent;
	int m_count;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAnnounce();
	afx_msg void OnBnClickedButtonKickout();
	CEdit m_editAnnounce;
	CEdit m_editUserID;
	virtual BOOL OnInitDialog();
	CEdit m_interval;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CListCtrl m_userList;
	CListCtrl m_announceList;
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void DeleteListItem(CListCtrl& m_List);

	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnLvnItemchangedListKickuserid(NMHDR *pNMHDR, LRESULT *pResult);
};
