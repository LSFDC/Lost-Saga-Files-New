// GraphDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "GraphDlg.h"
#include "afxdialogex.h"
#include "WinMessage.h"


// CGraphDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CGraphDlg, CDialogEx)

CGraphDlg::CGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraphDlg::IDD, pParent), m_PCCU(0), m_terms(GRAPH_TERM_3SEC), m_bCountryCode(false)
{

}

CGraphDlg::~CGraphDlg()
{
}

void CGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGraphDlg, CDialogEx)
END_MESSAGE_MAP()


// CGraphDlg 메시지 처리기입니다.
void CGraphDlg::CreateGraph()
{
	CRect rc;
	GetDlgItem(IDC_OSC_CCU)->GetWindowRect(rc) ;
	ScreenToClient(rc) ;
	m_graphCCU.DestroyWindow();
	m_graphCCU.Create(WS_VISIBLE | WS_CHILD, rc, this) ; 
	m_graphCCU.SetRange( true, 0, 100, 1) ;
	m_graphCCU.SetYUnits(_T("")) ;
	GetDlgItem(IDC_OSC_CCU)->ShowWindow(SW_HIDE);
}

BOOL CGraphDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	CreateGraph();
	CreateMenu();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CGraphDlg::Startup(CString title)
{
	m_title = title;
	
	RefreshTitle();
	ShowWindow(SW_HIDE);
}

void CGraphDlg::CreateMenu()
{
	m_menu.DestroyMenu();
	m_menu.CreatePopupMenu();

	CString menu = _T("3 sec");
	m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GRAPH3SEC, (LPCTSTR)menu);
	menu = _T("1 min");
	m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GRAPH1MIN, (LPCTSTR)menu);
	menu = _T("10 min");
	m_menu.AppendMenu(MF_STRING, IDC_SERVICE_GRAPH10MIN, (LPCTSTR)menu);
}

void CGraphDlg::RefreshTitle()
{
	CString temp;
	temp.Format(_T("%s - CCU Graph(PCCU : %d)"), GetTitle(), (int)GetPCCU());
	SetWindowText(temp);
}

void CGraphDlg::SetRange(bool b, double dLower, double dUpper, int nDecimalPlaces)
{
	m_graphCCU.SetRange(b, dLower, dUpper, nDecimalPlaces);
}

void CGraphDlg::AppendPoint(bool bCCU, int nPoint)
{
	m_bCountryCode = bCCU;
	m_points.push_back(nPoint); // 11860(200 * 593) max

	if(nPoint > m_PCCU)
	{
		m_PCCU = nPoint;
		RefreshTitle();
	}

	int term = GetTerm(m_terms);
	int divide =  m_points.size() % term;

	if(divide == 0)
	{
		m_graphCCU.AppendPoint(m_bCountryCode, nPoint);
	}
}

void CGraphDlg::SetXUnits(CString string)
{
	m_graphCCU.SetXUnits(string);
}

void CGraphDlg::ShowGraph(MSG* pMsg)
{
	if(m_graphCCU.GetSafeHwnd() == pMsg->hwnd)
	{
		//TRACE("Message : %08x\n", pMsg->message);
		 if(pMsg->message == WM_RBUTTONUP)
		{
			CPoint pos;
			GetCursorPos(&pos);

			int term = GetTerm();
			for(int i = 1 ; i <= 3 ; i++)
			{
				if(i == term)
				{
					m_menu.CheckMenuItem(IDC_SERVICE_GRAPH3SEC+i-1, MF_CHECKED);
				}
				else
				{
					m_menu.CheckMenuItem(IDC_SERVICE_GRAPH3SEC+i-1, MF_UNCHECKED);
				}
			}
			m_menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pos.x, pos.y, this);
			
		}
	}
}

void CGraphDlg::HideGraph(MSG* pMsg)
{
	if(m_graphCCU.GetSafeHwnd() == pMsg->hwnd)
	{
		//TRACE("Message : %08x\n", pMsg->message);
		if(pMsg->message == WM_LBUTTONUP)
		{
			ShowWindow(SW_HIDE);
		}
	}
}

void CGraphDlg::ProgressTime(MSG* pMsg)
{
	if(m_graphCCU.GetSafeHwnd() == pMsg->hwnd)
	{
		CString szTime;
		int x = GET_X_LPARAM(pMsg->lParam);
		int y = GET_Y_LPARAM(pMsg->lParam);
		int rightPixel = m_graphCCU.GetRightPixel();
		int leftPixel = m_graphCCU.GetLeftPixel();

		if( (x < leftPixel) || (x > rightPixel) )
			return;

		int elapseTime = (rightPixel - x) / 4;
		int term = GetTerm(m_terms) * 3;
		elapseTime *= term;

		CTime nowTime = CTime::GetCurrentTime();
		CTime pastTime = nowTime;
		pastTime -= elapseTime;

		if( nowTime.GetDay() == pastTime.GetDay() )
		{
			szTime.Format("%02d:%02d:%02d", pastTime.GetHour(), pastTime.GetMinute(), pastTime.GetSecond());
		}
		else
		{
			szTime.Format("%04d-%02d-%02d %02d:%02d:%02d", pastTime.GetYear(), pastTime.GetMonth(), pastTime.GetDay(), pastTime.GetHour(), pastTime.GetMinute(), pastTime.GetSecond());
		}
		m_graphCCU.SetToolTip( szTime );
	}
}


int CGraphDlg::GetTerm(const GraphTerms terms)
{
	int term = 1;
	switch(terms)
	{
	case GRAPH_TERM_3SEC :
		term = 1;
		break;
	case GRAPH_TERM_1MIN :
		//term = 5;
		term = 20;
		break;
	case GRAPH_TERM_10MIN :
		//term = 10;
		term = 200;
		break;
	}
	return term;
}

BOOL CGraphDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ProgressTime(pMsg);
	HideGraph(pMsg);
	ShowGraph(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CGraphDlg::Rearrange(const GraphTerms terms)
{
	ShowWindow(SW_HIDE);

	m_graphCCU.Reset();

	m_terms = terms;
	int term = GetTerm(terms);
	int width = m_graphCCU.GetWidth();
	int offset = (width+1) * term;

	int start = 0;
	if((int)m_points.size() > offset)
	{
		start = m_points.size() - offset;
	}
	
	TRACE("[Rearrange - %d]\n", term);
	for(int i = start ; i < (int)m_points.size() ; i += term)
	{
		m_graphCCU.AppendPoint(m_bCountryCode, m_points[i]);
		TRACE("graph : %d\n", m_points[i]);
	}

	ShowWindow(SW_SHOW);
}

BOOL CGraphDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	int itemIndex = lParam;
	switch(wParam)
	{
	case IDC_SERVICE_GRAPH3SEC :
		{
			m_terms = GRAPH_TERM_3SEC;
			Rearrange(GRAPH_TERM_3SEC);
		}
		return TRUE;

	case IDC_SERVICE_GRAPH1MIN :
		{
			m_terms = GRAPH_TERM_1MIN;
			Rearrange(GRAPH_TERM_1MIN);
		}
		return TRUE;

	case IDC_SERVICE_GRAPH10MIN :
		{
			m_terms = GRAPH_TERM_10MIN;
			Rearrange(GRAPH_TERM_10MIN);
		}
		return TRUE;
	}

	return CDialog::OnCommand(wParam, lParam);
}

void CGraphDlg::AppendCCUPoint( double dNewGB,double dNewDE,double dNewFR,double dNewIT,double dNewPL,double dNewTR, double dNewETC )
{
	m_graphCCU.AppendCCUPoint(dNewGB, dNewDE, dNewFR, dNewIT, dNewPL, dNewTR, dNewETC);
}
