// stdafx.h : �� ������� �ʰ� ���� ����ϴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Windows ������� ���� ������ �ʴ� ������ ���ܽ�ŵ�ϴ�.
#endif

// �Ʒ� ������ �÷������� �켱�ϴ� �÷����� ������� �ϴ� ��� ���� ���Ǹ� �����Ͻʽÿ�.
// �ٸ� �÷����� ���Ǵ� �ش� ���� �ֽ� ������ MSDN�� �����Ͻʽÿ�.
#ifndef WINVER				// Windows 95 �� Windows NT 4 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define WINVER 0x0500		// Windows 98�� Windows 2000 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_WINNT		// Windows NT 4 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINNT 0x0500		// Windows 98�� Windows 2000 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif						

#ifndef _WIN32_WINDOWS		// Windows 98 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINDOWS 0x0410 // Windows Me ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_IE			// IE 4.0 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_IE 0x0400	// IE 5.0 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#define __EX
#define SAFEDELETE(x) if(x != NULL) { delete x; x = NULL; }
#define SAFEDELETEARRAY(x) if(x != NULL) { delete [] x; x = NULL; }
#define COMPARE(x,min,max) (((x)>=(min))&&((x)<(max)))

// disable : 'xxxx': �̸��� #pragma deprecated�� ǥ�õǾ����ϴ�.
#	pragma warning(disable:4995)
#	pragma warning(disable:4267)


#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ���
#include <afxext.h>         // MFC �ͽ��ټ�

#include <afxdtctl.h>		// Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC ����
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Windows ���� ��Ʈ�ѿ� ���� MFC ����
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"

// ���� �ڵ� ������. �⺻�� Korean 949
#if defined( SRC_ID )
	#define COUNTRY_CODE_PAGE	1252
	#define IDR_ERROR IDR_TXT_ERROR_ID
#elif defined( SRC_SEA )
	#define COUNTRY_CODE_PAGE	1252
	#define IDR_ERROR IDR_TXT_ERROR_NA
#elif defined( SRC_NA )
	#define COUNTRY_CODE_PAGE	1252
	#define IDR_ERROR IDR_TXT_ERROR_NA
#elif defined( SRC_TW )
	#define COUNTRY_CODE_PAGE	950
	#define MULTI_BYTE_CHECK
#define IDR_ERROR IDR_TXT_ERROR_TW
#elif defined( SRC_TH )
	#define COUNTRY_CODE_PAGE	874
	#define MULTI_BYTE_CHECK
	#define IDR_ERROR IDR_TXT_ERROR_TH
#elif defined( SRC_EU )
	#define COUNTRY_CODE_PAGE	1252
	#define IDR_ERROR IDR_TXT_ERROR_EU
#elif defined( SRC_SA )
	#define COUNTRY_CODE_PAGE	1250
	#define IDR_ERROR IDR_TXT_ERROR_SA
#elif defined( SRC_SEA )
	#define COUNTRY_CODE_PAGE	1252
	#define IDR_ERROR IDR_TXT_ERROR_ID
#else
	#define COUNTRY_CODE_PAGE	949
	#define IDR_ERROR IDR_TXT_ERROR
#endif

#define TEXT_RESOURCE "txt"
