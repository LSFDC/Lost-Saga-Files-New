#pragma once

#include "OScopeCtrl.h"
#include <vector>

enum GraphTerms
{
	GRAPH_TERM_3SEC = 1,
	GRAPH_TERM_1MIN,
	GRAPH_TERM_10MIN,
	GRAPH_TERM_END
};

// CGraphDlg 대화 상자입니다.

class CGraphDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphDlg)

public:
	CGraphDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGraphDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GRAPH_DIALOG };

public:
	void Startup(CString title);
	void CreateMenu();
	void RefreshTitle();

	void SetRange(bool b, double dLower, double dUpper, int nDecimalPlaces=1);
	void AppendPoint(bool bCCU, int nPoint);
	void SetXUnits(CString string);

	double GetPCCU()	{ return m_PCCU; }
	CString GetTitle()	{ return m_title; }

	int GetTerm()		{ return m_terms; }

public:
	void Rearrange(const GraphTerms terms);
	void SetCountryCode(bool bCCU) { m_bCountryCode = bCCU; };
	void AppendCCUPoint(double dNewGB,double dNewDE,double dNewFR,double dNewIT,double dNewPL,double dNewTR, double dNewETC );
protected:	
	void CreateGraph();
	void ShowGraph(MSG* pMsg);
	void HideGraph(MSG* pMsg);
	void ProgressTime(MSG* pMsg);
	int GetTerm(const GraphTerms terms);

protected:
	typedef std::vector<int> POINTS;

	POINTS m_points;
	COScopeCtrl m_graphCCU;
	CString m_title;
	double m_PCCU;
	GraphTerms m_terms;
	CMenu m_menu;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	bool	m_bCountryCode;
};
