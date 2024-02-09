#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CZoneDialog;
// CSecretShopDlg 대화 상자입니다.

class CSecretShopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecretShopDlg)

public:
	CSecretShopDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSecretShopDlg();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
