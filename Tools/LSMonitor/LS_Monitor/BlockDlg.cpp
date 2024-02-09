// BlockDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LS_Monitor.h"
#include "ZoneDialog.h"
#include "BlockDlg.h"
#include "afxdialogex.h"


// CBlockDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBlockDlg, CDialogEx)

CBlockDlg::CBlockDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlockDlg::IDD, pParent)
{
}

CBlockDlg::~CBlockDlg()
{
}

void CBlockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control( pDX, IDC_LIST_BLOCK_PUBLICID, m_userList );
	DDX_Control( pDX, IDC_LIST_BLOCK_NOTE, m_noteList );
	DDX_Control( pDX, IDC_EDIT_BLOCK_PUBLICID, m_editPublicID );
	DDX_Control( pDX, IDC_EDIT_BLOCK_NOTE, m_editBlockNote );
	DDX_Control( pDX, IDC_COMBO_LIMITTIME, m_timeCombo );
	DDX_Control( pDX, IDC_COMBO_LEVEL, m_levelCombo );
}


BEGIN_MESSAGE_MAP(CBlockDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BLOCK_RESET, &CBlockDlg::OnBnClickedButtonBlockReset)
	ON_BN_CLICKED(IDC_BUTTON_BLOCK_BLOCK, &CBlockDlg::OnBnClickedButtonBlockBlock)
	ON_BN_CLICKED(IDC_BUTTON_BLOCK_UNBLOCK, &CBlockDlg::OnBnClickedButtonBlockUnblock)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_BLOCK_NOTE, &CBlockDlg::OnLvnItemchangedListBlockNote)
	ON_CBN_SELCHANGE(IDC_COMBO_LIMITTIME, &CBlockDlg::OnCbnSelchangeComboTime)
	ON_CBN_SELCHANGE(IDC_COMBO_LEVEL, &CBlockDlg::OnCbnSelchangeComboLevel)
END_MESSAGE_MAP()


// CBlockDlg 메시지 처리기입니다.

BOOL CBlockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitList();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CBlockDlg::Startup(CZoneDialog* parent)
{
	m_parent = parent;
	ShowWindow(SW_HIDE);
}

void CBlockDlg::InitList()
{
	m_userList.DeleteAllItems();
	m_userList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_userList.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 104);

	m_noteList.DeleteAllItems();
	m_noteList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_LABELTIP | LVS_EX_FULLROWSELECT);
	m_noteList.InsertColumn(0, _T("Note"), LVCFMT_LEFT, 194);

	// 내용
	OnDropNoteFiles(_T("./blockNote.txt"));

	// 기간
	InsertBlockTime(_T("-- Time --"));
	InsertBlockTime(_T("1 Day"));
	InsertBlockTime(_T("3 Days"));
	InsertBlockTime(_T("5 Days"));
	InsertBlockTime(_T("10 Days"));
	InsertBlockTime(_T("30 Days"));
	InsertBlockTime(_T("90 Days"));
	InsertBlockTime(_T("Infinite"));
	ResetTimeComboBox();

	// 등급
	InsertBlockLevel(_T("-- Level --"));
	InsertBlockLevel(_T("Caution"));
	InsertBlockLevel(_T("Limitation"));
	InsertBlockLevel(_T("Block"));
	InsertBlockLevel(_T("Unblock"));
	ResetLevelComboBox();
}

void CBlockDlg::InsertPublicID(CString PublicID)
{
	if( PublicID.GetLength() == 0 ) return ;

	m_userList.InsertItem( m_userList.GetItemCount(), PublicID );
}

void CBlockDlg::InsertBlockNote(CString note)
{
	if( note.GetLength() == 0 ) return ;

	m_noteList.InsertItem( m_noteList.GetItemCount(), note );
}

void CBlockDlg::InsertBlockTime(CString limitTime)
{
	if( limitTime.GetLength() == 0 ) return ;

	m_timeCombo.InsertString( m_timeCombo.GetCount(), limitTime );
}

void CBlockDlg::InsertBlockLevel(CString level)
{
	if( level.GetLength() == 0 ) return ;
	
	m_levelCombo.InsertString( m_levelCombo.GetCount(), level );
}

void CBlockDlg::OnDropUserFiles(CString file)
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
				InsertPublicID(line);
			}
		}
	}
}

void CBlockDlg::OnDropNoteFiles(CString file)
{
	m_noteList.DeleteAllItems();

	CStdioFile  ff;
	if(ff.Open(file, CFile::modeRead))
	{
		CString line;
		while(ff.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				InsertBlockNote(line);
			}
		}
	}
}

BlockInfo* CBlockDlg::GetSelectUserInfo(uint index)
{
	// 사용 안함
	//if( m_userList.GetSelectedCount() <= 0 )
	//	return NULL;

	//POSITION pos	= m_userList.GetFirstSelectedItemPosition();
	//while( (pos) && (index > 0) )
	//{
	//	m_userList.GetNextSelectedItem( pos );
	//	index--;
	//}

	//if( pos )
	//{
	//	int userListindex = m_userList.GetNextSelectedItem(pos);
	//	if( userListindex != -1 )
	//	{
	//		CString userId = m_userList.GetItemText( userListindex, 0 );
	//		POSITION find = m_blockUserInfo.Find( BlockInfo(userId) );
	//		
	//		if( !find )
	//			return NULL;
	//		return &m_blockUserInfo.GetAt(find);
	//	}		
	//}
	return NULL;
}

void CBlockDlg::SelectListItem(CListCtrl& list, CString item)
{
	// 사용안함
	//LVFINDINFOA	find;
	//find.flags	= LVFI_STRING;
	//find.psz	= item;

	//int index	= list.FindItem( &find );

	//if( index != -1 )
	//{
	//	list.SetItemState(	index, 
	//						LVIS_SELECTED,
	//						LVIS_SELECTED);
	//}
	//else
	//{
	//	for(int i = 0 ; i < list.GetItemCount() ; i++)
	//	{
	//		list.SetItemState( i, 0, LVIS_SELECTED );
	//	}
	//}

	//list.Invalidate(true);
}

void CBlockDlg::SetUserInfoNote(CString note)
{
	if( note.GetLength() == 0 ) return ;

	m_blockUserInfo.blockNote = note;
}

void CBlockDlg::SetUserInfoTime(CString limitTime)
{
	m_blockUserInfo.limitTime = limitTime;
}

void CBlockDlg::SetUserInfoLevel(int level)
{
	m_blockUserInfo.level = level;
}

void CBlockDlg::ResetUserInfoNote(CString note)
{
	m_blockUserInfo.blockNote == note;
	m_blockUserInfo.blockNote.Empty();
}

void CBlockDlg::ResetNoteListCtrl()
{
	for( int i = 0 ; i < m_noteList.GetItemCount() ; i++ )
	{
		if( m_noteList.GetItemState( i, LVIS_SELECTED ) == LVIS_SELECTED )
		{
			m_noteList.SetItemState( i, 0, LVIS_SELECTED );
			m_noteList.SetItemState( i, 0, LVIS_FOCUSED );
			break;
		}
	}
}

BOOL CBlockDlg::PreTranslateMessage(MSG* pMsg)
{
	switch( pMsg->message )
	{
	case WM_DROPFILES:
		{
			if( m_userList.GetSafeHwnd() == pMsg->hwnd )
			{
				uint dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
				char file[MAX_PATH];

				if( dragCount > 0 )
				{
					DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
					OnDropUserFiles( file );
				}
			}
			else if( m_noteList.GetSafeHwnd() == pMsg->hwnd )
			{
				uint dragCount = DragQueryFile((HDROP)pMsg->wParam, 0xFFFFFFFF, NULL, 0);
				char file[MAX_PATH];

				if( dragCount > 0 )
				{
					DragQueryFile( (HDROP)pMsg->wParam, 0, file, MAX_PATH );
					OnDropNoteFiles( file );
				}
			}
		}
		break;
	case WM_KEYDOWN:
		{
			if( VK_RETURN == pMsg->wParam )
			{
				if( m_editPublicID.GetSafeHwnd() == pMsg->hwnd )
				{
					CString publicID;
					m_editPublicID.GetWindowText( publicID );
					m_editPublicID.SetWindowText( _T("") );

					InsertPublicID(publicID);
					m_userList.EnsureVisible( m_userList.GetItemCount()-1, FALSE );
				}
				else if( m_editBlockNote.GetSafeHwnd() == pMsg->hwnd )
				{
					CString blockNote;
					m_editBlockNote.GetWindowText( blockNote );
					m_editBlockNote.SetWindowText( _T("") );

					InsertBlockNote( blockNote );
					m_noteList.EnsureVisible( m_noteList.GetItemCount()-1, FALSE );
				}
				return TRUE;
			}
			else if (VK_DELETE == pMsg->wParam )
			{
				if( m_userList.GetSafeHwnd() == pMsg->hwnd )
				{
					int index = -1;
					POSITION pos = m_userList.GetFirstSelectedItemPosition();
					while(pos)
					{
						index = m_userList.GetNextSelectedItem( pos );
						m_userList.DeleteItem( index );
						pos = m_userList.GetFirstSelectedItemPosition();
					}

					m_timeCombo.SelectString( 0, m_blockUserInfo.limitTime );
					m_levelCombo.SetCurSel( m_blockUserInfo.level );
				}
				else if( m_noteList.GetSafeHwnd() == pMsg->hwnd )
				{
					int index = -1;
					POSITION pos = m_noteList.GetFirstSelectedItemPosition();
					while(pos)
					{
						index = m_noteList.GetNextSelectedItem( pos );
						CString delstr = m_noteList.GetItemText(index, 0);

						ResetUserInfoNote(delstr);

						m_noteList.DeleteItem( index );
						pos = m_noteList.GetFirstSelectedItemPosition();
					}
				}
				return TRUE;
			}
		}
		break;
	}
	
	if(RestrictMessage(pMsg))
		return FALSE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CBlockDlg::OnBnClickedButtonBlockReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_userList.DeleteAllItems();
	SelectListItem( m_noteList, _T("") );

	m_blockUserInfo.Clear();
	
	ResetNoteListCtrl();
	ResetTimeComboBox();
	ResetLevelComboBox();
}

void CBlockDlg::OnBnClickedButtonBlockBlock()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if( !m_parent ) return;

	if( m_userList.GetItemCount() == 0 )
	{
		MessageBox(_T("UserList is Empty!!"), _T("BLOCK"), MB_OK);
		return ;
	}

	if( m_blockUserInfo.level == BLOCKTYPE_UNBLOCK )
		return OnBnClickedButtonBlockUnblock();

	if( !CheckBlockUserInfoList() )
		return ;
	
	CString publicID;
	int64 limitTime = GetTime( m_blockUserInfo.limitTime ) * 3600;

	for(int i = 0 ; i < m_userList.GetItemCount() ; i++)
	{
		publicID = m_userList.GetItemText( i, 0 );

		m_parent->RequestUserBlock( publicID,
									m_blockUserInfo.blockNote,
									limitTime,
									m_blockUserInfo.level );
	}
	
	m_parent->WriteLogDlg( _T("[Block] Request UserBlock") );
	MessageBox(_T("Completed"), _T("BLOCK"), MB_OK);
}

void CBlockDlg::OnBnClickedButtonBlockUnblock()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if( !m_parent ) return ;

	if( m_userList.GetItemCount() == 0 )
	{
		MessageBox(_T("UserList is Empty!!"), _T("BLOCK"), MB_OK);
		return ;
	}

	CString publicID;
	for(int i = 0 ; i < m_userList.GetItemCount() ; i++)
	{
		publicID = m_userList.GetItemText( i, 0 );

		m_parent->RequestUserUnblock( publicID );
	}
	
	m_parent->WriteLogDlg( _T("[Block] Request UserUnblock") );
	MessageBox(_T("Completed"), _T("UNBLOCK"), MB_OK);
}

void CBlockDlg::OnLvnItemchangedListBlockNote(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	if( !( ( pNMLV->uChanged == LVIF_STATE ) && ( pNMLV->uNewState == (LVIS_SELECTED | LVIS_FOCUSED) ) ) )
		return ;

	CString note = m_noteList.GetItemText( pNMLV->iItem, 0 );
	SetUserInfoNote( note );
}

BOOL CBlockDlg::CheckBlockUserInfoList()
{
	if( m_blockUserInfo.blockNote.IsEmpty() )
	{
		MessageBox(_T("Note is Unselected!!"), _T("BLOCK"), MB_OK);
		return FALSE;
	}

	if( m_blockUserInfo.limitTime.IsEmpty() ||
		m_blockUserInfo.limitTime == _T("-- Time --"))
	{
		MessageBox(_T("Time is Unselected!!"), _T("BLOCK"), MB_OK);
		return FALSE;
	}

	if( m_blockUserInfo.level <= 0 )
	{
		MessageBox(_T("Level is Unselected!!"), _T("BLOCK"), MB_OK);
		return FALSE;
	}
	
	return TRUE;
}

int CBlockDlg::GetTime(CString limitTime)
{
	CString timeToken;
	
	int findIndex = 0, tokenIndex = 0;

	findIndex = limitTime.Find( _T("Hour") );
	if( findIndex != -1 )
	{
		timeToken = limitTime.Tokenize(_T("Hour"), tokenIndex);
		return _ttoi(timeToken.GetBuffer( timeToken.GetLength() ));
	}

	findIndex = 0, tokenIndex = 0;
	findIndex = limitTime.Find( _T("Day") );
	if( findIndex != -1 )
	{
		timeToken = limitTime.Tokenize(_T("Day"), tokenIndex);
		return _ttoi(timeToken.GetBuffer( timeToken.GetLength() )) * 24;
	}

	findIndex = 0, tokenIndex = 0;
	findIndex = limitTime.Find( _T("Week") );
	if( findIndex != -1 )
	{
		timeToken = limitTime.Tokenize(_T("Week"), tokenIndex);
		return _ttoi(timeToken.GetBuffer( timeToken.GetLength() )) * 24 * 7;
	}

	findIndex = 0, tokenIndex = 0;
	findIndex = limitTime.Find( _T("Month") );
	if( findIndex != -1 )
	{
		timeToken = limitTime.Tokenize(_T("Month"), tokenIndex);
		return _ttoi(timeToken.GetBuffer( timeToken.GetLength() )) * 24 * 30;
	}

	findIndex = 0, tokenIndex = 0;
	findIndex = limitTime.Find( _T("Year") );
	if( findIndex != -1 )
	{
		timeToken = limitTime.Tokenize(_T("Year"), tokenIndex);
		return _ttoi(timeToken.GetBuffer( timeToken.GetLength() )) * 24 * 365;
	}

	return 50 * 24 * 365;
}

void CBlockDlg::OnCbnSelchangeComboTime()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int select = m_timeCombo.GetCurSel();
	CString limitTime;
	m_timeCombo.GetLBText(select, limitTime);

	SetUserInfoTime( limitTime );
}


void CBlockDlg::OnCbnSelchangeComboLevel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int select = m_levelCombo.GetCurSel();
	SetUserInfoLevel( select );
}
