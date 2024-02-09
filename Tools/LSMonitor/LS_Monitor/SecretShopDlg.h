#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CZoneDialog;
// CSecretShopDlg ��ȭ �����Դϴ�.

class CSecretShopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecretShopDlg)

public:
	CSecretShopDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSecretShopDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SECRETSHOP };

public:
	void Startup(CZoneDialog* parent);

protected:
	CZoneDialog* m_parent;

protected:
	void InsertItemCode(CString itemCode);
	void InsertItemCount(CString itemCount);
	
	void OnDropItemFiles(CString file);
	void OnDropItemCountFiles(CString file);

	void DeleteListItem(CListCtrl& m_List);

	void ReqeustCountChange(int itemCode, int itemCount);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_itemList;
	CListCtrl m_itemCount;

	afx_msg void OnBnClickedButtonInforeset();
	afx_msg void OnEnChangeEditItemcode();
	afx_msg void OnEnChangeEditItemcount();
	afx_msg void OnLvnItemchangedListItemcode(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListItemcount(NMHDR *pNMHDR, LRESULT *pResult);
	
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit m_editItemCode;
	CEdit m_editItemCount;
	afx_msg void OnBnClickedButtonInsert();
};
