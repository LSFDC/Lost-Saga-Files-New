#pragma once

#include "Network/Packet.h"
#include "Network/FSM.h"

class CIOSecurity
{
public:
	CIOSecurity(void);
	~CIOSecurity(void);

	void Init();
	void Destroy();

public:
	void InitState();

protected:	
	void EncryptMsg( CPacket &rkPacket );
	void DecryptMsg( CPacket &rkPacket );

public:
	virtual bool IsCheckSum( CPacket &rkPacket );

public:
	virtual int	GetSndState();
	virtual void UpdateSndState();
	virtual int	GetRcvState();
	virtual void UpdateRcvState();
	virtual bool CheckState( CPacket &rkPacket );
	virtual bool CheckNS( CPacket &rkPacket );

public:
	virtual void PrepareMsg( CPacket &rkPacket );
	virtual void CompletionMsg( CPacket &rkPacket );

protected:
	FSM m_SndState;
	FSM m_RcvState;
};

