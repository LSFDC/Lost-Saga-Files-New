#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CZoneDialog;
// CCompensationDlg 대화 상자입니다.

class CCompensationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCompensationDlg)

public:
	CCompensationDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCompensationDlg();

// 대화 상자 데이터입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
