
#ifndef _NetworkSecurity_h_
#define _NetworkSecurity_h_

class TOWN_PORTAL_API NetworkSecurity
{
	// DoS Attack
	public:
	virtual bool UpdateReceiveCount();
	
	// Packet CheckSum
	public:
	virtual bool IsCheckSum( CPacket &rkPacket );

	// Packet Replay
	public:
	virtual int	 GetSndState();
	virtual void UpdateSndState();
	virtual int  GetRcvState();
	virtual void UpdateRcvState();
	virtual bool CheckState( CPacket &rkPacket );

	// Send 
	public:
	virtual void PrepareMsg( CPacket &rkPacket );
	virtual void CompletionMsg( CPacket &rkPacket );

	public:
	NetworkSecurity();
	virtual ~NetworkSecurity();
};

#endif