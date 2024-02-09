

#ifndef _CCLINETOBJECT_H_
#define _CCLINETOBJECT_H_

// �������� Ŭ���̾�Ʈ�� �����Ҷ� ����ϴ� Ŭ�������� ����ؾ��ϴ� Ŭ����
// GameServer�� UserNode, �α��μ����� UserObject, GameServerObject���� �̹��ֿ� ���Ѵ�.

#define MAX_MSG_COUNT_ONE_SEC	15

class __EX CClientObject
{
public:	
	void New(SOCKET csocket,DWORD msg_one_sec_count = MAX_MSG_COUNT_ONE_SEC);
	void Delete();

protected:
	bool		m_bExist;
	SOCKET		m_socket;
	SendBuffer	m_SendBuffer;
	RecvBuffer	m_RecvBuffer;
	FSM			m_sndState;
	FSM			m_rcvState;
	DWORD		m_dwTimeCountZero;
	DWORD		m_dwRcvMsgCount;
	DWORD       m_max_one_sec_msg_count;
	int			m_iCurMagicNum;

public:
	bool IsExist(){ return m_bExist; }
	bool IsValid();
	SOCKET	GetSocket() const { return m_socket; }
	SendBuffer* GetSendBuffer() { return &m_SendBuffer; }
	RecvBuffer* GetRecvBuffer() { return &m_RecvBuffer; }

public:
	void InitState();
	int GetSndServerState();
	int GetRcvServerState();
	void SetSndServerState(int iState);
	void SetRcvServerState(int iState);
	void UpdateSndServerState();
	void UpdateRcvServerState();

public:
	DWORD GetRcvMsgCount();
	bool UpdateMsgCount();

public:
	inline void AddMagicNum() { m_iCurMagicNum++; }
	inline int GetMagicNum() const { return m_iCurMagicNum; }
	inline void ClearMagicNum() { m_iCurMagicNum = 0; }

public:
	CClientObject();
	CClientObject(SOCKET csocket);
	virtual ~CClientObject();
};

#endif

