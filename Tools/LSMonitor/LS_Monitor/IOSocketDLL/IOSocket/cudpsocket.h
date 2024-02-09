// CUDPSocket.h
//

#if !defined(CUDPSocket_h)
#define CUDPSocket_h

#define SEM_UDP_NOT_VALID_MSG		1001
#define SEM_UDP_STATE_SAME			1002

class __EX CUDPSocket : public CGenericSocket
{
public:
    bool InitUDP(HWND ishwnd, UINT imsg, int iport);
    void CloseUDP();
    bool SendLoop(char* ip, int port, char* snd, int snd_size);
    bool ReceiveLoop(SOCKET rsocket, CGenericRcvMsg & Generic);
    void GetRecentIPPort(char *ip, int & port);
	char* GetMyIP();

public:
	bool CheckValidMsg(CGenericRcvMsg *pGeneric);
	virtual void SocketErrorMsg(int iType);

protected:
	void InitState();
	bool SetSndStateIfFirst();
	void SetRcvState(int iState);
	int GetRcvState();
	int GetSndState();
	void UpdateSndState();

public:
    CUDPSocket();
    virtual ~CUDPSocket();

protected:
    char	m_recent_rcv_ip[16];
    int		m_recent_rcv_port;
    int		m_main_port;

	char	m_pre_recent_rcv_ip[16];
	int		m_pre_recent_rcv_port;
	FSM		m_rcvState;
	FSM		m_sndState;
};

#endif /* CUDPSocket_h */
