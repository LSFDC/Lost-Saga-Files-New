// LSWebBroker.h : LSWebBroker ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ


// CLSWebBrokerApp:
// �� Ŭ������ ������ ���ؼ��� LSWebBroker.cpp�� �����Ͻʽÿ�.
//

class CLSWebBrokerApp : public CWinApp
{
public:
	CLSWebBrokerApp();


// ������
public:
	virtual BOOL InitInstance();

// ����

public:
	DECLARE_MESSAGE_MAP()
};

extern CLSWebBrokerApp theApp;
