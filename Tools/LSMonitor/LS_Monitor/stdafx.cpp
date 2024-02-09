
// stdafx.cpp : source file that includes just the standard includes
// LS_Monitor.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"


BOOL RestrictMessage(MSG* pMsg)
{
	switch(pMsg->message)
	{
	case WM_KEYDOWN :
		{
			switch(pMsg->wParam)
			{
			case VK_F1 :
			case VK_RETURN :
			case VK_ESCAPE :
				return TRUE;
			}
		}
		break;
	case WM_SYSKEYDOWN:
		{
		}
		break;
	}
	return FALSE;
}