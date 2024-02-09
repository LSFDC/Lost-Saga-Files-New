

#ifndef _RECVBUFFER_H_
#define _RECVBUFFER_H_

#include "CGenericMessage.h"

class __EX RecvBuffer
{
	private:
	CGenericRcvMsg	m_RcvMsg;
	int		m_curRcvSize;
	int		m_curTotalSize;

	public:
	void InitBuffer();
	bool IsAllRecvMsg();
	void UpdateRecvData(int curRcvSize);

	public:
	LPSTR GetBufferPtr(){ return (LPSTR)((char*)&m_RcvMsg + m_curRcvSize); }
	int GetCurBufferSize();
	int GetCurTotalSize(){ return m_curTotalSize; }

	public:
	CGenericRcvMsg* GetRcvMsgPtr(){ return &m_RcvMsg; }
};
#endif