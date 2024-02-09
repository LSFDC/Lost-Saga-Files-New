// CProcessCtrl.cpp: implementation of the CProcessCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ProcessCtrl.h"


CProcessCtrl::CProcessCtrl() : m_vertical(TRUE)
{
	SetRange( 0, 100 );
	SetBackgroundColor(RGB(0, 0, 0));
	//SetPlotColor(RGB(255, 255, 0));
	SetPlotColor(RGB(128, 255, 128));
	SetGridColor(RGB(128, 255, 128));
	SetAlertColor(RGB(255, 64, 64));

	m_pbitmapOldGrid = NULL;
	m_pbitmapOldPlot = NULL;
}

CProcessCtrl::~CProcessCtrl()
{
}


BEGIN_MESSAGE_MAP(CProcessCtrl, CWnd)
  //{{AFX_MSG_MAP(CProcessCtrl)
  ON_WM_PAINT()
  ON_WM_SIZE()
  ON_WM_MOUSEMOVE()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CProcessCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	BOOL result;

	static CString className = AfxRegisterWndClass( CS_HREDRAW | CS_VREDRAW );

	result = CWnd::CreateEx(	
		WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 
		className, NULL, dwStyle, 
		rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
		pParentWnd->GetSafeHwnd(), 
		(HMENU)nID );
	
	if( result != 0 )	InvalidateCtrl();

	return result;
}

void CProcessCtrl::SetRange( UINT low, UINT high )
{
	m_lowLevel	= low;
	m_highLevel	= high;

	m_level		= low;
}

void CProcessCtrl::SetGridColor(COLORREF color, BOOL redraw)
{
	m_crGridColor = color;

	m_penGrid.DeleteObject();
	m_penGrid.CreatePen(PS_SOLID, 0, m_crGridColor);

	if(redraw)
		InvalidateCtrl();
}

void CProcessCtrl::SetAlertColor(COLORREF color, BOOL redraw)
{
	m_crAlertColor = color;

	m_penAlert.DeleteObject();
	m_penAlert.CreatePen(PS_SOLID, 0, m_crGridColor);

	if(redraw)
		InvalidateCtrl();
}

void CProcessCtrl::SetPlotColor(COLORREF color, BOOL redraw)
{
	m_crPlotColor = color;

	m_penPlot.DeleteObject();
	m_penPlot.CreatePen(PS_SOLID, 0, m_crPlotColor);

	if(redraw)
		InvalidateCtrl();
}

void CProcessCtrl::SetBackgroundColor(COLORREF color, BOOL redraw)
{
	m_crBackColor = color;

	m_brushBack.DeleteObject();
	m_brushBack.CreateSolidBrush(m_crBackColor);

	if(redraw)
		InvalidateCtrl();
}

void CProcessCtrl::GetRange(UINT& low, UINT& high)
{
	low		= m_lowLevel;
	high	= m_highLevel;
}

void CProcessCtrl::DrawGraph( UINT level )
{
	m_level	= (UINT)(level * 100.0 / m_highLevel);
	if(m_level > 100)
		m_level = 100;

	InvalidateCtrl();
}

void CProcessCtrl::InvalidateCtrl()
{
	CClientDC dc(this);  
	if (m_dcGrid.GetSafeHdc() == NULL)
	{
		m_dcGrid.CreateCompatibleDC(&dc);
		m_bitmapGrid.CreateCompatibleBitmap(&dc, m_clientWidth, m_clientHeight);
		m_pbitmapOldGrid = m_dcGrid.SelectObject(&m_bitmapGrid);
	}

	m_dcGrid.SetBkColor(m_crBackColor);
	m_dcGrid.FillRect(m_rectClient, &m_brushBack);

	m_plotHeight	= m_rectPlot.Height();
	m_plotWidth		= m_rectPlot.Width();

	// draw the plot rectangle
	CPen *oldPen = m_dcGrid.SelectObject (&m_penPlot); 

	// 테두리
	m_dcGrid.MoveTo (m_rectPlot.left, m_rectPlot.top);
	m_dcGrid.LineTo (m_rectPlot.right+1, m_rectPlot.top);
	m_dcGrid.LineTo (m_rectPlot.right+1, m_rectPlot.bottom+1);
	m_dcGrid.LineTo (m_rectPlot.left, m_rectPlot.bottom+1);
	m_dcGrid.LineTo (m_rectPlot.left, m_rectPlot.top);

	int middle, range;
	if(IsVertical())
	{
		middle = (m_rectPlot.right + m_rectPlot.left) / 2;
		range = (m_rectPlot.bottom - m_rectPlot.top - 1) * m_level / 100;
	}
	else
	{
		middle = (m_rectPlot.top + m_rectPlot.bottom) / 2 + 1;
		range = (m_rectPlot.right - m_rectPlot.left - 1) * m_level / 100;
	}

	m_dcGrid.SelectObject (oldPen); 
	
	// 그리드
	if( m_level >= 90)
	{
		oldPen = m_dcGrid.SelectObject (&m_penAlert); 
	}
	else
	{
		oldPen = m_dcGrid.SelectObject (&m_penGrid); 
	}

	for( int i = 0; i < range; i+=2 )
	{
		if(IsVertical())
		{
			int height = m_rectPlot.bottom - i - 1;

			m_dcGrid.MoveTo( m_rectPlot.left+2, height );
			m_dcGrid.LineTo( middle, height );

			m_dcGrid.MoveTo( middle+1, height );
			m_dcGrid.LineTo( m_rectPlot.right, height );
		}
		else
		{
			int width = m_rectPlot.left + i + 2;

			m_dcGrid.MoveTo( width, m_rectPlot.top +1 );
			m_dcGrid.LineTo( width, m_rectPlot.bottom +1 );
		}
	}

	m_dcGrid.SelectObject (oldPen); 
	//if (m_dcPlot.GetSafeHdc() == NULL)
	//{
	//	m_dcPlot.CreateCompatibleDC(&dc);
	//	m_bitmapPlot.CreateCompatibleBitmap(&dc, m_clientWidth, m_clientHeight);
	//	m_pbitmapOldPlot = m_dcPlot.SelectObject(&m_bitmapPlot);
	//}

	//m_dcPlot.SetBkColor (m_crBackColor);
	//m_dcPlot.FillRect(m_rectClient, &m_brushBack);

	InvalidateRect(m_rectClient);
}

void CProcessCtrl::OnPaint() 
{
	CPaintDC dc(this);
	CDC memDC;
	CBitmap memBitmap;
	CBitmap* oldBitmap;

	memDC.CreateCompatibleDC(&dc);
	memBitmap.CreateCompatibleBitmap(&dc, m_clientWidth, m_clientHeight);
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap);

	if (memDC.GetSafeHdc() != NULL)
	{
		memDC.BitBlt(0, 0, m_clientWidth, m_clientHeight, &m_dcGrid, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 0, m_clientWidth, m_clientHeight, &m_dcPlot, 0, 0, SRCPAINT);
		dc.BitBlt(0, 0, m_clientWidth, m_clientHeight, &memDC, 0, 0, SRCCOPY);
	}
	memDC.SelectObject(oldBitmap);
}

void CProcessCtrl::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
  
	GetClientRect(m_rectClient);

	m_clientHeight = m_rectClient.Height();
	m_clientWidth  = m_rectClient.Width();

	m_rectPlot.left   = 2;  
	m_rectPlot.top    = 2;
	m_rectPlot.right  = m_rectClient.right - 5;
	m_rectPlot.bottom = m_rectClient.bottom - 3;

	m_plotHeight = m_rectPlot.Height();
	m_plotWidth  = m_rectPlot.Width();
}

void CProcessCtrl::InitToolTip()
{
	if (m_toolTip.m_hWnd == NULL) 
	{ 
		m_toolTip.Create(this); 
		m_toolTip.Activate(FALSE); 

		m_toolTip.SetDelayTime(TTDT_AUTOPOP, 3000);
	} 
}

void CProcessCtrl::SetToolTip(CString text)
{
	m_toolTip.DelTool(this, 0);
	m_toolTip.AddTool(this, text, NULL, 0);
}


BOOL CProcessCtrl::PreTranslateMessage(MSG* pMsg)
{
	m_toolTip.RelayEvent(pMsg);
	return CWnd::PreTranslateMessage(pMsg); 
}

void CProcessCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_toolTip.Activate(TRUE); 

	CWnd::OnMouseMove(nFlags, point);
}
