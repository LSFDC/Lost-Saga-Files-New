#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CZoneDialog;
// CCompensationDlg ��ȭ �����Դϴ�.

class CCompensationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCompensationDlg)

public:
	CCompensationDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCompensationDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_COMPENSATION_DIALOG };

public:
	void Startup(CZoneDialog* parent);

protected:
	CZoneDialog* m_parent;

protected:
	void InsertItemCode(CString itemCode);
	void InsertEndDate(CString endDate);
	
	void OnDropItemFiles(CString file);
	void OnDropEndDateFiles(CString file);

	void DeleteListItem(CListCtrl& m_List);

	void ReqeustGiveCompensation(int type, int code, int value, int endDate);

	BOOL CheckDateType(CString endDate);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_compensationList;
	CListCtrl m_endDate;
	CEdit m_editCompensationCode;
	CEdit m_editEndDate;

	afx_msg void OnLvnItemchangedItemCompensation(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListEnddate(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedInsert();

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
