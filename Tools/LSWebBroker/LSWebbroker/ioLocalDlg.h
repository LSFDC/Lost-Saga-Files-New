#pragma once
#include "afxwin.h"
#include "resource.h"

// ioLocalDlg ��ȭ �����Դϴ�.
#include "skin/CDialogSK.h"
#include "skin/HoverButton.h"

class ioLocalDlg : public CDialogSK
{
public:
	ioLocalDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ioLocalDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LOCAL_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int			m_nLocalCode;

	void LoadINI();
	void SetCheckedLocalBtn(int nLocalCode);
	bool SetupAndStartGame( bool bReadRegClientPath );

public:

	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	CHoverButton m_XBtn;
	CHoverButton m_English;
	CHoverButton m_Germany;
	CHoverButton m_French;
	CHoverButton m_Italian;
	CHoverButton m_Polish;
	CHoverButton m_Turkey;
	CHoverButton m_LocalStart;
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonEnglish();
	afx_msg void OnBnClickedButtonGermany();
	afx_msg void OnBnClickedButtonFrench();
	afx_msg void OnBnClickedButtonPolish();
	afx_msg void OnBnClickedButtonTurkey();
	afx_msg void OnBnClickedButtonItalian();
};
