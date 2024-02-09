#pragma once

#include "IOSecurity.h"
#include "ServerTypes.h"
#include "Network/Packet.h"

enum SocketEvents
{
	SOCKEVENT_NONE = 0,
	SOCKEVENT_CONNECT,
	SOCKEVENT_RECEIVE,
	SOCKEVENT_SEND,
	SOCKEVENT_CLOSE,
	SOCKEVENT_END
};

class CZoneDialog;

class CIOSocket : public CAsyncSocket, public CIOSecurity
{
public:
	CIOSocket(void);
	~CIOSocket(void);

	void Init();
	void Destroy();

public:
	BOOL Create();
	BOOL Connect(const ServerTypes serverType, CZoneDialog* dlg, const char* IP, const int port);
	BOOL BillingServerConnect(const ServerTypes serverType, CZoneDialog* dlg, const char* IP, const int port, const int billingIndex);
	void Disconnect();

	void SendPacket(CPacket &rkPacket);

protected:
	void SetType(const ServerTypes type)				{ m_serverType = type; }
	void SetConnected(const BOOL b)						{ m_connected = b; }
	void SetDlg(CZoneDialog* dlg)						{ m_dlg = dlg; }
	void SetBillingIndex(const int billingkeyIndex)		{ m_billingKeyIndex = billingkeyIndex; }

	ServerTypes GetType()					{ return m_serverType; }
	BOOL IsConnected()						{ return m_connected; }
	CZoneDialog* GetDlg()					{ return m_dlg; }
	int GetBillingIndex()					{ return m_billingKeyIndex; }
	
public:
	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	
protected:
	ServerTypes m_serverType;
	CZoneDialog* m_dlg;
	int			m_billingKeyIndex;
	BOOL m_connected;

	BYTE m_sendBuffer[1024 * 16];
	BYTE m_recvBuffer[1024 * 16];
	int  m_bytesSent;
	int  m_bytesBufferSize;
	int  m_bytesReceived;

};

