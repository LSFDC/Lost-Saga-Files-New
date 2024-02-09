
#include "../stdafx.h"

#include "FSM.h"
#include "Packet.h"
#include "NetworkSecurity.h"

NetworkSecurity::NetworkSecurity()
{
}

NetworkSecurity::~NetworkSecurity()
{
}

// DoS Attack
bool NetworkSecurity::UpdateReceiveCount()
{
	return true;
}
		
// Packet CheckSum
bool NetworkSecurity::IsCheckSum( CPacket &rkPacket )
{
	return true;
}
		
// Packet Replay
int NetworkSecurity::GetSndState()
{
	return MAGIC_TOKEN_FSM;
}

void NetworkSecurity::UpdateSndState()
{

}

int NetworkSecurity::GetRcvState()
{
	return MAGIC_TOKEN_FSM;
}

void NetworkSecurity::UpdateRcvState()
{

}

bool NetworkSecurity::CheckState( CPacket &rkPacket )
{
	return true;
}


void NetworkSecurity::PrepareMsg( CPacket &rkPacket )
{
	
}

void NetworkSecurity::CompletionMsg( CPacket &rkPacket )
{
	
}