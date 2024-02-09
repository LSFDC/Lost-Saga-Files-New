/********************************************************************
	created:	2003/01/22
	created:	22:1:2003   10:12
	filename: 	e:\■ now\workingdll\logdll\logdll.h
	file path:	e:\■ now\workingdll\logdll
	file base:	logdll
	file ext:	h
	author:		김인중
	
	purpose:	
	history:	
		2003.1.23	replace wsprintf by sprintf.
		2003.1.22	add ASSERT processing
		2003.1.22	add log function, CLog:DebugLOG, DebugMBox
					for debug infomation (__FILE__, __LINE__)
		2003.1.22	edit DEBUGLOG, DEBUGBOX definition for using this function	
		2003.2.27   add debug level
*********************************************************************/

#ifndef ___LOG_H__
#define ___LOG_H__

#define WIN32_LEAN_AND_MEAN
//#define __EX __declspec(dllexport)
//#define __EX __declspec(dllimport)
#define __IM __declspec(dllimport)

#include <stdio.h>	
#include <windows.h>
#include <direct.h>
#include <assert.h>
#include <conio.h>

/**************** Debuging시 사용 ******************
	LOG.DebugLog(__FILE__,__LINE__,
	DebugMBox(__FILE__,__LINE__,NULL,
****************************************************/
// assert는 Resize class 적용하면서 충돌이 발생하여 주석 처리함.
//#ifdef ASSERT
//#undef ASSERT
//#endif

//#define ASSERT(f)			{if(!(f)) {LOG.DebugLog(0, __FILE__,__LINE__,"ASSERT Fail,return");		    assert(f);return;}}
//#define ASSERT_minusone(f)	{if(!(f)) {LOG.DebugLog(0, __FILE__,__LINE__,"ASSERT Fail,return -1");		assert(f);return -1;}}
//#define ASSERT_false(f)		{if(!(f)) {LOG.DebugLog(0, __FILE__,__LINE__,"ASSERT Fail,return false");	assert(f);return false;}}

class __IM CLog
{
public:
	char				m_file_name[255];
	int				    m_debug_level;
	CRITICAL_SECTION	m_critical_section;
	
	void OpenLog(int debuglv, char* fName, bool is_append = false);	// debug lv : 0 Release version, 0302(3월2일) private debug version 
	void CloseLog();
	void PrintNoEnterLog(int debuglv, LPSTR fmt,...); 
	void PrintLog(int debuglv, LPSTR fmt,...);
	void PrintTimeAndLog(int debuglv, LPSTR fmt,...);
	void DebugLog(int debuglv, LPSTR filename, int linenum, LPSTR fmt,...);
	void WriteReadyFolderAndFiles(char *fName);
	void PrintConsoleLog(int debuglv,LPSTR fmt,...);
	void CloseAndRelease();
	
	CLog();
	virtual ~CLog();

protected:
	FILE* m_pFile;
};

extern __IM CLog LOG;
__IM void MBox(HWND thwnd, LPSTR title, LPSTR szStr,...);
__IM void DebugMBox(LPSTR filename, int linenum, HWND thwnd, LPSTR szStr,...);

#endif 
