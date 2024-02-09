// SecretShopDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "SecretShopDlg.h"
#include "ZoneDialog.h"
#include "afxdialogex.h"


// CSecretShopDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSecretShopDlg, CDialogEx)

CSecretShopDlg::CSecretShopDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSecretShopDlg::IDD, pParent)
{

}

CSecretShopDlg::~CSecretShopDlg()
{
}

void CSecretShopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ITEMCODE, m_itemList);
	DDX_Control(pDX, IDC_LIST_ITEMCOUNT, m_itemCount);
	DDX_Control(pDX, IDC_EDIT_ITEMCODE, m_editItemCode);
	DDX_Control(pDX, IDC_EDIT_ITEMCOUNT, m_editItemCount);
}


BEGIN_MESSAGE_MAP(CSecretShopDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INFORESET, &CSecretShopDlg::OnBnClickedButtonInforeset)
	ON_EN_CHANGE(IDC_EDIT_ITEMCODE, &CSecretShopDlg::OnEnChangeEditItemcode)
	ON_EN_CHANGE(IDC_EDIT_ITEMCOUNT, &CSecretShopDlg::OnEnChangeEditItemcount)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ITEMCODE, &CSecretShopDlg::OnLvnItemchangedListItemcode)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ITEMCOUNT, &CSecretShopDlg::OnLvnItemchangedListItemcount)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CSecretShopDlg::OnBnClickedButtonInsert)
END_MESSAGE_MAP()


// CSecretShopDlg 메시지 처리기입니다.


void CSecretShopDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CSecretShopDlg::OnBnClickedButtonInforeset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_itemList.DeleteAllItems();
	m_itemCount.DeleteAllItems();
}


void CSecretShopDlg::OnEnChangeEditItemcode()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSecretShopDlg::OnEnChangeEditItemcount()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSecretShopDlg::OnLvnItemchangedListItemcode(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CSecretShopDlg::OnLvnItemchangedListItemcount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


BOOL CSecretShopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_itemList.DeleteAllItems();
	m_itemList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_itemList.InsertColumn(0, _T("Code"), LVCFMT_LEFT, 120);

	m_itemCount.DeleteAllItems();
	m_itemCount.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_itemCount.InsertColumn(0, _T("ResetCount"), LVCFMT_LEFT, 180);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CSecretShopDlg::InsertItemCode(CString itemCode)
{
	if( itemCode.GetLength() == 0 )
		return;

	m_itemList.InsertItem(m_itemList.GetItemCount(), itemCode);
}

void CSecretShopDlg::InsertItemCount(CString itemCount)
{
	if( itemCount.GetLength() == 0 )
		return;

	m_itemCount.InsertItem(m_itemCount.GetItemCount(), itemCount);
}

void CSecretShopDlg::OnDropItemFiles(CString file)
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

void CSecretShopDlg::OnDropItemCountFiles(CString file)
{
	m_itemCount.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertItemCount(line);
			}
		}
	}
}

void CSecretShopDlg::DeleteListItem(CListCtrl& m_List)
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

BOOL CSecretShopDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(WM_DROPFILES == pMsg->message)
	{
		if(m_itemList.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropItemFiles( file );
			}
		}
		else if(m_itemCount.GetSafeHwnd() == pMsg->hwnd)
		{
			UINT dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
			char file[MAX_PATH];
 
			if( dragCount > 0 )
			{
				DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
				OnDropItemCountFiles( file );
			}
		}
	}
	else if(WM_KEYDOWN == pMsg->message )
	{
		if(VK_RETURN == pMsg->wParam)
		{
			if(m_editItemCode.GetSafeHwnd() == pMsg->hwnd)
			{
				CString itemCode;
				m_editItemCode.GetWindowText(itemCode);
				m_editItemCode.SetWindowText(_T(""));

				InsertItemCode(itemCode);
			}
			else if(m_editItemCount.GetSafeHwnd() == pMsg->hwnd)
			{
				CString itemCount;
				m_editItemCount.GetWindowText(itemCount);
				m_editItemCount.SetWindowText(_T(""));

				InsertItemCount(itemCount);
			}
			return TRUE;
		}
		else if(VK_DELETE == pMsg->wParam)
		{
			if(m_itemList.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_itemList.GetSelectedCount();
				if(count > 0) //kyg 여기에 루프 추가 
				{ 
					DeleteListItem(m_itemList);

				}
			}
			else if(m_itemCount.GetSafeHwnd() == pMsg->hwnd)
			{
				UINT count = m_itemCount.GetSelectedCount();
				if(count > 0)
				{

					DeleteListItem(m_itemCount);
				}
			}
			return TRUE;
		}
	}

	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSecretShopDlg::ReqeustCountChange(int itemCode, int itemCount)
{
	m_parent->RequestSecretShopCountChange(itemCode, itemCount);
}

void CSecretShopDlg::OnBnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString itemCode, itemCount;
	for(int i = 0 ; i < m_itemList.GetItemCount() ; i++)
	{
		itemCode = m_itemList.GetItemText(i, 0);

		if( m_itemCount.GetItemCount() <= i )
			break;

		itemCount = m_itemCount.GetItemText(i, 0);

		ReqeustCountChange(atoi(itemCode), atoi(itemCount));
	}
}
