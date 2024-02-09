// AnnounceDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "AnnounceDlg.h"
#include "afxdialogex.h"
#include "Network/Protocol.h"


// CAnnounceDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAnnounceDlg, CDialogEx)

CAnnounceDlg::CAnnounceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAnnounceDlg::IDD, pParent)
	, m_parent(NULL)
	, m_count(0)
{

}

CAnnounceDlg::~CAnnounceDlg()
{
}

void CAnnounceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ANNOUNCE, m_editAnnounce);
	DDX_Control(pDX, IDC_EDIT_USERID, m_editUserID);
	DDX_Control(pDX, IDC_EDIT_INTERVAL, m_interval);
	DDX_Control(pDX, IDC_LIST_KICKUSERID, m_userList);
	DDX_Control(pDX, IDC_LIST_ANNOUNCE, m_announceList);
}


BEGIN_MESSAGE_MAP(CAnnounceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ANNOUNCE, &CAnnounceDlg::OnBnClickedButtonAnnounce)
	ON_BN_CLICKED(IDC_BUTTON_KICK, &CAnnounceDlg::OnBnClickedButtonKickout)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_COMMONRESET, &CAnnounceDlg::OnBnClickedButtonReset)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_KICKUSERID, &CAnnounceDlg::OnLvnItemchangedListKickuserid)
END_MESSAGE_MAP()


// CAnnounceDlg �޽��� ó�����Դϴ�.

void CAnnounceDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CAnnounceDlg::OnBnClickedButtonAnnounce()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);

	CString count;
	m_interval.GetWindowText(count);
	m_count = atoi(count);
	if(m_count <= 0)
	{
		m_count = 1;
	}

	if(m_count > 1)
	{
		int delay = m_announceList.GetItemCount() * 20000;
		SetTimer(1, delay, NULL);
	}
	else
	{
		DoAnnounce();
	}

	MessageBox(_T("Completed"), _T("ANNOUNCE"), MB_OK);
}

void CAnnounceDlg::OnBnClickedButtonKickout()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString userId;

	int count = m_userList.GetItemCount();
	for(int i = 0 ; i < count ; i++)
	{
		userId = m_userList.GetItemText(i, 0);

		if(!userId.IsEmpty())
		{
			m_parent->RequestKickUser(userId);
		}
	}

	MessageBox(_T("Completed"), _T("KICK OUT"), MB_OK);
}

BOOL CAnnounceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitList();

	CWnd* pWnd = GetDesktopWindow();
	CenterWindow(pWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CAnnounceDlg::InitList()
{
	m_userList.DeleteAllItems();
	m_userList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_userList.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 120);

	m_announceList.DeleteAllItems();
	m_announceList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_announceList.InsertColumn(0, _T("Announcement"), LVCFMT_LEFT, 275);
}

void CAnnounceDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(1 == nIDEvent)
	{
		DoAnnounce();

		--m_count;
		if(m_count <= 0)
		{
			KillTimer(1);
			TRACE("Announce End\n");
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CAnnounceDlg::OnDropUserFiles(CString file)
{
	m_userList.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertUserID(line);
			}
		}
	}
}

void CAnnounceDlg::OnDropAnnounceFiles(CString file)
{
	m_announceList.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertAnnounce(line);
			}
		}
	}
}

void CAnnounceDlg::InsertUserID(CString userId)
{
	if(userId.GetLength() == 0) return;

	m_userList.InsertItem(m_userList.GetItemCount(), userId);
}

void CAnnounceDlg::InsertAnnounce(CString announce)
{
	if(announce.GetLength() == 0) return;

	m_announceList.InsertItem(m_announceList.GetItemCount(), announce);
}

void CAnnounceDlg::DoAnnounce()
{
	CString userId;
	CString announce;

	m_editUserID.GetWindowText(userId);

	int count = m_announceList.GetItemCount();
	for(int i = 0 ; i < count ; i++)
	{
		announce = m_announceList.GetItemText(i, 0);
		if(!announce.IsEmpty())
		{
			int msgType = userId.IsEmpty() ? ANNOUNCE_TYPE_ALL : ANNOUNCE_TYPE_ONE;
			m_parent->RequestAnnounce(msgType, userId, announce);

			TRACE("[%d]Announce : %s\n", m_count, announce);
		}
	}
}

BOOL CAnnounceDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(WM_DROPFILES == pMsg->message)
	{
		if(m_userList.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropUserFiles( file );
			}
		}
		else if(m_announceList.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropAnnounceFiles( file );
			}
		}
	}
	else if(WM_KEYDOWN == pMsg->message )
	{
		if(VK_RETURN == pMsg->wParam)
		{
			if(m_editUserID.GetSafeHwnd() == pMsg->hwnd)
			{
				CString userId;
				m_editUserID.GetWindowText(userId);
				m_editUserID.SetWindowText(_T(""));

				InsertUserID(userId);
			}
			else if(m_editAnnounce.GetSafeHwnd() == pMsg->hwnd)
			{
				CString itemCode;
				m_editAnnounce.GetWindowText(itemCode);
				m_editAnnounce.SetWindowText(_T(""));

				InsertAnnounce(itemCode);
			}
			return TRUE;
		}
		else if(VK_DELETE == pMsg->wParam)
		{
			if(m_userList.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_userList.GetSelectedCount();
				if(count > 0) //kyg ���⿡ ���� �߰� 
				{ 
					DeleteListItem(m_userList);

				}
			}
			else if(m_announceList.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_announceList.GetSelectedCount();
				if(count > 0)
				{

					DeleteListItem(m_announceList);
				}
			}
			return TRUE;
		}
	}

	if(RestrictMessage(pMsg))
		return FALSE;


	return CDialogEx::PreTranslateMessage(pMsg);
}

void CAnnounceDlg::OnBnClickedButtonReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);

	m_userList.DeleteAllItems();
	m_announceList.DeleteAllItems();
}


void CAnnounceDlg::OnLvnItemchangedListKickuserid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//m_userList.GetItemState()
	*pResult = 0;
}

void CAnnounceDlg::DeleteListItem(CListCtrl& m_List)
{
	int index = -1;
	POSITION pos = m_List.GetFirstSelectedItemPosition();
	while(pos)
	{
		int index = m_List.GetNextSelectedItem(pos);
		m_List.DeleteItem(index);
		pos = m_List.GetFirstSelectedItemPosition();
	}
	 
}
