// CClientTCPSocket.h
//

#if !defined(CClientTCPSocket_h)
#define CClientTCPSocket_h

#include "RecvBuffer.h"
#include "SendBuffer.h"

class __EX CClientTCPSocket : public CGenericSocket
{
public:
    bool InitClientTCP(HWND ishwnd, UINT imsg, char *iip, int iport);
    void CloseClientTCP();

public:
	bool EvaluateSocket(WPARAM wParam, LPARAM lParam);

    virtual bool SendLoop(char* snd, int snd_size);
	int  BufferSendLoop();

    virtual bool ReceiveLoop(SOCKET rsocket);	
	virtual bool ReceiveProcess(SOCKET csocket);

	bool CheckValidMsg( CGenericRcvMsg *pGeneric );

public:
	virtual void ConnectProcess() = 0;
	virtual void DisconnectProcess() = 0;
	virtual void ProcessRcvMsg(CGenericRcvMsg *pGeneric) = 0;
	
public:
	bool IsConnect(){return m_is_connect;};
	SOCKET GetSocket(){return m_socket_object;	};

public:
	void InitClientState();
	void SetSndClientState(int iState);
	void SetRcvClientState(int iState);
	int GetSndClientState();
	int GetRcvClientState();
	void UpdateSndClientState();
	void UpdateRcvClientState();
	
public:	
	CClientTCPSocket();
    virtual ~CClientTCPSocket();
	
protected:
    bool		m_is_connect;
	RecvBuffer	m_RecvBuffer;
	SendBuffer	m_SendBuffer;
	FSM			m_sndState;
	FSM			m_rcvState;
};

#endif /* CClientTCPSocket_h */
