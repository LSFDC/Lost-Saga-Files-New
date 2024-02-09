// EventDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "EventDlg.h"
#include "afxdialogex.h"


// CEventDlg ��ȭ �����Դϴ�.

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


// CEventDlg �޽��� ó�����Դϴ�.
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
	
	// �ؽ�Ʈ �Ľ�
	Parse(text);

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_parent->RequestEventInsert(m_values, m_valueCount);

	MessageBox(_T("Completed"), _T("EVENT"), MB_OK);
}

BOOL CEventDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
