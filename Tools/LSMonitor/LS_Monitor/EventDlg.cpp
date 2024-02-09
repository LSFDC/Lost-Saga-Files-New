// EventDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "EventDlg.h"
#include "afxdialogex.h"


// CEventDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEventDlg, CDialogEx)

CEventDlg::CEventDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEventDlg::IDD, pParent), m_parent(NULL)
{

}

CEventDlg::~CEventDlg()
{
}

void CEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_EVENT, m_eventEdit);
}


BEGIN_MESSAGE_MAP(CEventDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EVENTINSERT, &CEventDlg::OnBnClickedButtonEventApply)
END_MESSAGE_MAP()


// CEventDlg 메시지 처리기입니다.
void CEventDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CEventDlg::OnDropEventFiles(CString file)
{
	m_eventEdit.SetWindowText(_T(""));

	CStdioFile ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line, output = "";
		while(ff.ReadString(line))
		{
			output += line;
			output += _T("\r\n");
		}
		ff.Close();

		m_eventEdit.SetWindowText(output);
	}
}

void CEventDlg::Parse(CString text)
{
	ZeroMemory(m_values, sizeof(m_values));
	m_valueCount = 0;

	int curPos = 0;
	CString token= text.Tokenize(_T("\r\n"),curPos);
	while (token != _T(""))
	{
		token.MakeLower();

		if(!token.IsEmpty() && 
			(token.Find(_T(";"), 0) == -1) && 
			(token.Find(_T("["), 0) == -1) &&
			(token.Find(_T(";"), 0) == -1) )
		{
			int index = 0;
			CString key = token.Tokenize(_T("="), index);
			CString value = token.Tokenize(_T("="), index);
			m_values[m_valueCount++] = atoi(value);
		}
		token = text.Tokenize(_T("\r\n"), curPos);
	};
}

void CEventDlg::OnBnClickedButtonEventApply()
{
	CString text;
	m_eventEdit.GetWindowText(text);
	
	// 텍스트 파싱
	Parse(text);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_parent->RequestEventInsert(m_values, m_valueCount);

	MessageBox(_T("Completed"), _T("EVENT"), MB_OK);
}

BOOL CEventDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(WM_DROPFILES == pMsg->message)
	{
		if(m_eventEdit.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropEventFiles( file );
			}
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
