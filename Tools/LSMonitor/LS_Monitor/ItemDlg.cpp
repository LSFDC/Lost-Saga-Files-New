// ItemDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "ItemDlg.h"
#include "afxdialogex.h"


// CItemDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CItemDlg, CDialogEx)

CItemDlg::CItemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CItemDlg::IDD, pParent), m_parent(NULL), m_namePropertyRadio(0)
{
	m_namePropertyRadio = MONITER_INSERT_ITEM_PUBLIC_ID;
}

CItemDlg::~CItemDlg()
{
}

void CItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OPITEM, m_itemList);
	DDX_Control(pDX, IDC_LIST_OPUSERID, m_userList);
	DDX_Control(pDX, IDC_EDIT_ITEMUSERID, m_editUserID);
	DDX_Control(pDX, IDC_EDIT_ITEMCODE, m_editItemCode);
	DDX_Control(pDX, IDC_CHECK_SEAL, m_seal);
	DDX_Radio(pDX, IDC_RADIO_NAME_PUBLIC, m_namePropertyRadio);
}


BEGIN_MESSAGE_MAP(CItemDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ITEMINSERT, &CItemDlg::OnBnClickedButtonItemInsert)
	ON_BN_CLICKED(IDC_BUTTON_ITEMRESET, &CItemDlg::OnBnClickedButtonItemReset)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_OPUSERID, &CItemDlg::OnLvnItemchangedListOpuserid)
	ON_BN_CLICKED(IDC_STATIC_ISPUBLIC, &CItemDlg::OnBnClickedStaticIspublic)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_NAME_PUBLIC, IDC_RADIO_NAME_PRIVATE, &CItemDlg::OnNamePropertyRadioCtrl)
	ON_BN_CLICKED(IDC_BUTTON_ITEMRESET2, &CItemDlg::OnBnClickedButtonItemreset2)
END_MESSAGE_MAP()


// CItemDlg 메시지 처리기입니다.


BOOL CItemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitList();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CItemDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CItemDlg::InitList()
{
	m_userList.DeleteAllItems();
	m_userList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_userList.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 120);

	m_itemList.DeleteAllItems();
	m_itemList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_itemList.InsertColumn(0, _T("PresentType"), LVCFMT_LEFT, 75);
	m_itemList.InsertColumn(1, _T("Value1"), LVCFMT_LEFT, 100);
	m_itemList.InsertColumn(2, _T("Value2"), LVCFMT_LEFT, 100);
}

void CItemDlg::OnBnClickedButtonItemInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int seal = m_seal.GetCheck();

	CString userId, presentType, value1, value2;
	for(int i = 0 ; i < m_userList.GetItemCount() ; i++)
	{
		userId = m_userList.GetItemText(i, 0);

		for(int j = 0 ; j < m_itemList.GetItemCount() ; j++)
		{
			presentType = m_itemList.GetItemText(j, 0);
			value1 = m_itemList.GetItemText(j, 1);
			value2 = m_itemList.GetItemText(j, 2);

			// 아이템 추가
			if(seal == 0)
			{
				ReqeustItemInsert(userId, atoi(presentType), atoi(value1), atoi(value2), 1, m_namePropertyRadio);
			}
			else
			{
				ReqeustItemInsert(userId, atoi(presentType), atoi(value1), atoi(value2), 40, m_namePropertyRadio);
			}
			Sleep(10);
		}
	}

	MessageBox(_T("Completed"), _T("ITEM"), MB_OK);
}

void CItemDlg::InsertUserID(CString userId)
{
	if(userId.GetLength() == 0) return;

	m_userList.InsertItem(m_userList.GetItemCount(), userId);
}

void CItemDlg::InsertItemCode(CString itemCode)
{
	if(itemCode.GetLength() == 0) return;

	int index = 0;
	CString presentType, value1, value2;
	presentType = itemCode.Tokenize(_T("."), index);
	if(presentType.IsEmpty()) return;

	value1 = itemCode.Tokenize(_T("."), index);
	if(value1.IsEmpty()) return;

	value2 = itemCode.Tokenize(_T("."), index);
	if(value2.IsEmpty()) return;

	int itemCount = m_itemList.GetItemCount();
	m_itemList.InsertItem(itemCount, presentType);
	m_itemList.SetItemText(itemCount, 1, value1);
	m_itemList.SetItemText(itemCount, 2, value2);
}

void CItemDlg::OnDropUserFiles(CString file)
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

void CItemDlg::OnDropItemFiles(CString file)
{
	m_itemList.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertItemCode(line);
			}
		}
	}
}

void CItemDlg::ReqeustItemInsert(CString userId, int presentType, int value1, int value2, int ment, int isPublicIDState)
{
	m_parent->RequestItemInsert(userId, presentType, value1, value2, ment, isPublicIDState);
}

BOOL CItemDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
		else if(m_itemList.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropItemFiles( file );
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
			else if(m_editItemCode.GetSafeHwnd() == pMsg->hwnd)
			{
				CString itemCode;
				m_editItemCode.GetWindowText(itemCode);
				m_editItemCode.SetWindowText(_T(""));

				InsertItemCode(itemCode);
			}
			return TRUE;
		}
		else if(VK_DELETE == pMsg->wParam)
		{
			if(m_userList.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_userList.GetSelectedCount();
				if(count > 0)
				{
					DeleteListItem(m_userList);
				}
			}
			else if(m_itemList.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_itemList.GetSelectedCount();
				if(count > 0)
				{
					DeleteListItem(m_userList);
				}
			}
			return TRUE;
		}
	}

	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CItemDlg::OnBnClickedButtonItemReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_userList.DeleteAllItems();
}


void CItemDlg::OnLvnItemchangedListOpuserid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CItemDlg::DeleteListItem(CListCtrl& m_List)
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

void CItemDlg::OnBnClickedStaticIspublic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CItemDlg::OnNamePropertyRadioCtrl( UINT uintID )
{
	(uintID == IDC_RADIO_NAME_PUBLIC) ? m_namePropertyRadio = 1 : m_namePropertyRadio = 2;
	m_namePropertyRadio;
	int a = 0;
}


void CItemDlg::OnBnClickedButtonItemreset2()
{
	// TODO: Add your control notification handler code here
	m_itemList.DeleteAllItems();

}
