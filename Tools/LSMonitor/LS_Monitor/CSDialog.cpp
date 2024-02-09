// CSDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "CSDialog.h"
#include "WinMessage.h"
#include "afxdialogex.h"


// CCSDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCSDialog, CDialogEx)

CCSDialog::CCSDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCSDialog::IDD, pParent), m_parent(NULL)
{

}

CCSDialog::~CCSDialog()
{
}

void CCSDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CSLOG, m_csLog);
	DDX_Control(pDX, IDC_EDIT_CHANGEVERSION, m_changeVersion);
	DDX_Control(pDX, IDC_EDIT_VERSION, m_version);
}


BEGIN_MESSAGE_MAP(CCSDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOADCS, &CCSDialog::OnBnClickedButtonLoadCS)
	ON_BN_CLICKED(IDC_BUTTON_SHOWCS, &CCSDialog::OnBnClickedButtonShowCS)
END_MESSAGE_MAP()


// CCSDialog �޽��� ó�����Դϴ�.
void CCSDialog::Startup(CZoneDialog* dlg)
{
	m_parent = dlg;
	ShowWindow(SW_HIDE);
}

void CCSDialog::OnBnClickedButtonLoadCS()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_LOADCS, NULL);
}

void CCSDialog::OnBnClickedButtonShowCS()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_parent->PostMessage(WM_COMMAND, IDC_SERVICE_SHOWCS, NULL);
}

BOOL CCSDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	m_csLog.ResetContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CCSDialog::Log(const char *format, ...)
{
	TCHAR buffer[2048]; 
	va_list marker; 

	va_start( marker, format ); 
	_vstprintf_s( buffer, _countof(buffer), format, marker ); 
	va_end( marker );

	if(m_csLog.GetCount() > 100)
	{
		m_csLog.DeleteString(0);
	}
	m_csLog.AddString( buffer );
	m_csLog.SetTopIndex( m_csLog.GetCount() - 1 );
}

void CCSDialog::GetVersion(CString& version, CString& change)
{
	m_version.GetWindowText(version);
	m_changeVersion.GetWindowText(change);
}

BOOL CCSDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}
