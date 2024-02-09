#pragma once
#include "afxcmn.h"
#include "afxwin.h"


class CZoneDialog;

// CItemDlg ��ȭ �����Դϴ�.

class CItemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CItemDlg)

public:
	CItemDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CItemDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ITEM_DIALOG };

public:
	void Startup(CZoneDialog* parent);

protected:
	void InitList();

	void InsertUserID(CString userId);
	void InsertItemCode(CString itemCode);

	void OnDropUserFiles(CString file);
	void OnDropItemFiles(CString file);

	void ReqeustItemInsert(CString userId, int presentType, int value1, int value2, int ment = 1, int isPublicIDState =1);
	void DeleteListItem(CListCtrl& m_List);

protected:
	CZoneDialog* m_parent;
	int		 m_namePropertyRadio;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_itemList;
	CListCtrl m_userList;

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonItemInsert();
	CEdit m_editUserID;
	CEdit m_editItemCode;
	afx_msg void OnBnClickedButtonItemReset();
	afx_msg void OnLvnItemchangedListOpuserid(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_seal;
	afx_msg void OnBnClickedStaticIspublic();
	afx_msg void OnNamePropertyRadioCtrl(UINT uintID);
	afx_msg void OnBnClickedButtonItemreset2();
};
