
#ifndef _CSERVERTCPSOCKET_H_
#define _CSERVERTCPSOCKET_H_

#include "CGenericSocket.h"

class RecvBuffer;
class CClientObject;
class CGenericRcvMsg;

#define SEM_NOT_VALID_MSG			1001
#define SEM_TOO_MANY_MSG_ONE_SEC	1002
#define MAX_BYPASS_MAGIC_TOKEN      5  

class __EX CServerTCPSocket : public CGenericSocket
{
protected:
	bool	m_bServerClientSocket;

public:
	inline void SetServerClientSocket( bool bClient ) { m_bServerClientSocket = bClient; }
	inline bool IsServerClientSocket() const { return m_bServerClientSocket; }

public:    
    bool InitServerTCP (HWND ishwnd, UINT imsg, int iport);
    void CloseServerTCP();

public:
	bool EvaluateSocket(WPARAM wParam, LPARAM lParam);	
    bool SendLoop(CClientObject &client_object, char* snd, int snd_size);
	bool BufferSendLoop(CClientObject &client_object);
	bool ReceiveProcess(SOCKET csocket);	
	int ReceiveLoop(SOCKET rsocket, RecvBuffer *pBuffer);	// return value > 0 : 메시지 사이즈 '=0' grace close, '-1'에러, '-2'블럭
	bool CheckValidMsg( CClientObject *pObject, CGenericRcvMsg *pGeneric );
	
public:
	virtual CClientObject* FindClientObject(SOCKET csocket) = 0;
	virtual void ClientAcceptProcess(SOCKET csocket, LPCTSTR cip) = 0;
	virtual void ClientDisconnectProcess(SOCKET csocket) = 0;
	virtual void ProcessRcvMsg(SOCKET csocket, CGenericRcvMsg *pGeneric) = 0;
	virtual void SocketErrorMsg( SOCKET csocket, int iErrorType ) = 0;

public:
	CServerTCPSocket();
    virtual ~CServerTCPSocket();
};

#endif /* CServerTCPSocket_h */
