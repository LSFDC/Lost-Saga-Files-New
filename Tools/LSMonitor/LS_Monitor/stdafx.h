
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


#include <afxdisp.h>        // MFC Automation classes



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars


#include <afxsock.h>            // MFC socket extensions

#include "../../../src/include/common.h"
#include "EasySize.h"

extern BOOL RestrictMessage(MSG* pMsg);

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

//CCU용 설정값 입니다.
enum COUNTRY_ID { CI_EG, CI_GE, CI_FR, CI_IT, CI_PL, CI_TR, CI_ETC, CI_MAX};
//국가별 이름입니다. 이름앞에 _로 item에서 값을 체크합니다.
#define CCU_ENG "_UnitedKingdom"
#define CCU_GER "_Germany"
#define CCU_FRA "_France"
#define CCU_ITA "_Italy"
#define CCU_POL "_Poland"
#define CCU_TUR "_Turkey"
#define CCU_ETC "_ETC"	

//국가별 색상설정 cf) http://ggamzang.tistory.com/102
#define CCU_RGB_ENG RGB(0,0,204)
#define CCU_RGB_GER RGB(102,51,0)
#define CCU_RGB_FRA RGB(255,0,255)
#define CCU_RGB_ITA RGB(0,102,0)
#define CCU_RGB_POL RGB(102,51,204)
#define CCU_RGB_TUR RGB(51,255,255)
#define CCU_RGB_ETC RGB(204,102,51)

enum MoniterInertItemTypes
{
	MONITER_INSERT_ITEM_PUBLIC_ID = 1,
	MONITER_INSERT_ITEM_PRIVATE_ID = 2,
};