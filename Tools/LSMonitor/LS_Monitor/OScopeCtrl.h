// OScopeCtrl.h : header file
//

#pragma once

/////////////////////////////////////////////////////////////////////////////
// COScopeCtrl window

class COScopeCtrl : public CWnd
{
	// Construction
public:
//	COScopeCtrl(int iLine = 1);
	COScopeCtrl();
	virtual ~COScopeCtrl();

	// Attributes
public:
	double AppendPoint(bool bCCU, double dNewPoint);
	void AppendCCUPoint( double dNewGB,double dNewDE,double dNewFR,double dNewIT,double dNewPL,double dNewTR, double dNewETC);
	void SetToolTip(CString string);
	void SetRange(bool b, double dLower, double dUpper, int nDecimalPlaces=1);

	void SetXUnits(CString string);
	void SetYUnits(CString string);
	void SetGridColor(COLORREF color);
	void SetPlotColor(COLORREF color);
	void SetBackgroundColor(COLORREF color);

	void InitToolTip();
	void RefreshRange();
	void InvalidateCtrl();
	void InvalidateXUnits();
	void DrawPoint();
	void Reset();

	// Operations
public:
	int GetWidth();
	int GetRightPixel();
	int GetLeftPixel();
	BOOL PreTranslateMessage(MSG* pMsg);

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COScopeCtrl)
public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID=NULL);
	//}}AFX_VIRTUAL

	// Implementation
public:
	int m_nShiftPixels;          // amount to shift with each new point 
	int m_nYDecimals;

	CString m_strXUnitsString;
	CString m_strYUnitsString;

	COLORREF m_crBackColor;        // background color
	COLORREF m_crGridColor;        // grid color
	COLORREF m_crPlotColor;        // data color  
	COLORREF m_crCCUColor[CI_MAX];
  
	double m_dCurrentPosition;   // current position
	double m_dPreviousPosition;  // previous position
	//CCU Point
	double m_dCurCCUPosition[CI_MAX];   // current position
	double m_dPreCCUPosition[CI_MAX];	// previous position

	bool	m_bCountryCode;

	// Generated message map functions
protected:
	//{{AFX_MSG(COScopeCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy); 
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	int m_nHalfShiftPixels;
	int m_nPlotShiftPixels;
	int m_nClientHeight;
	int m_nClientWidth;
	int m_nPlotHeight;
	int m_nPlotWidth;

	double m_dLowerLimit;        // lower bounds
	double m_dUpperLimit;        // upper bounds
	double m_dRange;
	double m_dVerticalFactor;
  
	CRect  m_rectClient;
	CRect  m_rectPlot;
	CPen   m_penPlot;
	CPen	m_CCUpen[CI_MAX];
	CBrush m_brushBack;

	CDC     m_dcGrid;
	CDC     m_dcPlot;
	CDC     m_dcCCUPlot[CI_MAX];
	CBitmap *m_pbitmapOldGrid;
	CBitmap *m_pbitmapOldPlot;
	CBitmap *m_pbitmapCCUOldPlot[CI_MAX];
	CBitmap m_bitmapGrid;
	CBitmap m_bitmapPlot;
	CBitmap m_bitmapCCUPlot[CI_MAX];

	CToolTipCtrl m_toolTip;
};
