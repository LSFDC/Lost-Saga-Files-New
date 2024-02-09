/********************************************************************
	created:	2003/01/22
	created:	22:1:2003   10:40
	filename: 	e:\°· now\workingdll\iosocketdll\iosocket\iosocketdll.h
	file path:	e:\°· now\workingdll\iosocketdll\iosocket
	file base:	iosocketdll
	file ext:	h
	author:		±Ë¿Œ¡ﬂ
	
	purpose:	
	history:	
		2003/01/22	Edit IOSocketDLL after Generalizing LogDLL.
*********************************************************************/
#ifndef __IOSOCKETDLL_H__
#define __IOSOCKETDLL_H__

#ifndef __DLL_INFO__
#define __DLL_INFO__

#define WIN32_LEAN_AND_MEAN		

//#define __WORK__
//#define __MK_DLL__
#ifdef __WORK__
#define __EX
#else
#ifdef __MK_DLL__
#define __EX __declspec(dllexport)
#else
#define __EX __declspec(dllimport)
#endif
#endif
#endif

#include <stdio.h>
#include <windows.h>
#include "IncludeDLL/LogDLL.h"

#pragma comment(lib, "ws2_32.lib")

#ifdef _DEBUG
#pragma comment(lib, "IncludeDLL/LogDDLL.lib")
#else
#pragma comment(lib, "IncludeDLL/LogDLL.lib")
#endif

#pragma warning(disable:4251)

#include "Encrypt/FSM.h"

#include "IOSocket/cgenericsocket.h"
#include "IOSocket/cgenericmessage.h"
#include "IOSocket/RecvBuffer.h"
#include "IOSocket/SendBuffer.h"
#include "IOSocket/cclienttcpsocket.h"
#include "IOSocket/cservertcpsocket.h"
#include "IOSocket/cudpsocket.h"
#include "IOSocket/CClientObject.h"

#endif
