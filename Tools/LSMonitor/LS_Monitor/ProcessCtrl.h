#pragma once


class CProcessCtrl : public CWnd
{
public:
	CProcessCtrl();
	virtual ~CProcessCtrl();

public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID=NULL);

	void SetRange(UINT unLow, UINT unHigh);
	void SetGridColor(COLORREF color, BOOL redraw = FALSE);
	void SetAlertColor(COLORREF color, BOOL redraw = FALSE);
	void SetPlotColor(COLORREF color, BOOL redraw = FALSE);
	void SetBackgroundColor(COLORREF color, BOOL redraw = FALSE);
	void SetVertical(BOOL b) { m_vertical = b; }

	void GetRange(UINT& low, UINT& high);

	BOOL IsVertical()	{ return m_vertical; }

	void InvalidateCtrl();
	void DrawGraph( UINT unLevel );

	void InitToolTip();
	void SetToolTip(CString text);

	// Generated message map functions
protected:
	//{{AFX_MSG(COScopeCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy); 
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	BOOL PreTranslateMessage(MSG* pMsg);

private:
	BOOL	m_vertical;
	CRect	m_rectClient;
	CRect	m_rectPlot;
	CDC		m_dcGrid;
	CDC		m_dcPlot;
	CBitmap	*m_pbitmapOldGrid;
	CBitmap	*m_pbitmapOldPlot;
	CBitmap	m_bitmapGrid;
	CBitmap	m_bitmapPlot;

	COLORREF	m_crBackColor;        // background color
	COLORREF	m_crGridColor;        // grid color
	COLORREF	m_crAlertColor;       // alert color
	COLORREF	m_crPlotColor;        // data color  
  
	CPen	m_penPlot;
	CPen	m_penGrid;
	CPen	m_penAlert;
	CBrush	m_brushBack;

	CToolTipCtrl m_toolTip;

	int		m_clientHeight;
	int		m_clientWidth;
	int		m_plotHeight;
	int		m_plotWidth;

	UINT	m_lowLevel;
	UINT	m_highLevel;
	UINT	m_level;
};

