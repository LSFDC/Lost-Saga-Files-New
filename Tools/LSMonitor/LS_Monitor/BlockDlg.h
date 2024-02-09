#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CZoneDialog;

struct BlockInfo
{
	CString blockNote;
	CString limitTime;
	int level;

	BlockInfo()
	{
		Clear();
	}

	void Clear()
	{
		blockNote.Empty();
		limitTime.Empty();
		level = 0;
	}
};

// CBlockDlg 대화 상자입니다.

class CBlockDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBlockDlg)

public:
	CBlockDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBlockDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BLOCK_DIALOG };

public:
	void Startup(CZoneDialog* parent);

protected:
	void InitList();

	void InsertPublicID(CString publicID);
	void InsertBlockNote(CString note);
	void InsertBlockTime(CString limitTime);
	void InsertBlockLevel(CString level);

	void OnDropUserFiles(CString file);
	void OnDropNoteFiles(CString file);

	BlockInfo* GetSelectUserInfo(uint nIndex = 0);
	void SelectListItem(CListCtrl& list, CString item);

	void SetUserInfoNote(CString note);
	void SetUserInfoTime(CString limitTime);
	void SetUserInfoLevel(int level);

	void ResetUserInfoNote(CString note);

	void ResetNoteListCtrl();
	void ResetTimeComboBox()	{ m_timeCombo.SetCurSel( 0 ); }
	void ResetLevelComboBox()	{ m_levelCombo.SetCurSel( 0 ); }

	BOOL CheckBlockUserInfoList();
	
	int GetTime(CString limitTime);
	
protected:
	CZoneDialog* m_parent;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl	m_userList;
	CListCtrl	m_noteList;
	CComboBox	m_timeCombo;
	CComboBox	m_levelCombo;

	CEdit m_editPublicID;
	CEdit m_editBlockNote;
	
	BlockInfo m_blockUserInfo;

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnBnClickedButtonBlockReset();
	afx_msg void OnBnClickedButtonBlockBlock();
	afx_msg void OnBnClickedButtonBlockUnblock();
	afx_msg void OnLvnItemchangedListBlockNote(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeComboTime();
	afx_msg void OnCbnSelchangeComboLevel();
};
