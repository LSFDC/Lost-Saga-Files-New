// SecretShopDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "SecretShopDlg.h"
#include "ZoneDialog.h"
#include "afxdialogex.h"


// CSecretShopDlg ��ȭ �����Դϴ�.

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


// CSecretShopDlg �޽��� ó�����Դϴ�.


void CSecretShopDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CSecretShopDlg::OnBnClickedButtonInforeset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_itemList.DeleteAllItems();
	m_itemCount.DeleteAllItems();
}


void CSecretShopDlg::OnEnChangeEditItemcode()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSecretShopDlg::OnEnChangeEditItemcount()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSecretShopDlg::OnLvnItemchangedListItemcode(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CSecretShopDlg::OnLvnItemchangedListItemcount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


BOOL CSecretShopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_itemList.DeleteAllItems();
	m_itemList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_itemList.InsertColumn(0, _T("Code"), LVCFMT_LEFT, 120);

	m_itemCount.DeleteAllItems();
	m_itemCount.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_itemCount.InsertColumn(0, _T("ResetCount"), LVCFMT_LEFT, 180);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
				if(count > 0) //kyg ���⿡ ���� �߰� 
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
