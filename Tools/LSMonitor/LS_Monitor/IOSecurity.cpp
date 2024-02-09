#include "StdAfx.h"
#include "Network/cryption.h"
#include "IOSecurity.h"


CIOSecurity::CIOSecurity(void)
{
	Init();
}

CIOSecurity::~CIOSecurity(void)
{
	Destroy();
}

void CIOSecurity::Init()
{
	InitState();
}

void CIOSecurity::Destroy()
{
}

void CIOSecurity::InitState()
{
	m_SndState.InitState();
	m_RcvState.InitState();
}

// Packet CheckSum
void CIOSecurity::EncryptMsg(CPacket &rkPacket)
{
	// Check Sum
	DWORD dwResult = MakeDigest((BYTE*)rkPacket.GetBuffer(), rkPacket.GetBufferSize());
	rkPacket.SetCheckSum( dwResult );
	
	// Encryption
	BYTE *pSrc;
	pSrc = (BYTE*)rkPacket.GetBuffer() + PK_CKSUM_ADDR;
	Encrypt( pSrc, rkPacket.GetBufferSize() - PK_CKSUM_ADDR );		
}

void CIOSecurity::DecryptMsg( CPacket &rkPacket )
{
	// Decryption
	BYTE *pSrc;
	pSrc = (BYTE*)rkPacket.GetBuffer() + PK_CKSUM_ADDR;
	Decrypt( pSrc, rkPacket.GetBufferSize() - PK_CKSUM_ADDR );
}

bool CIOSecurity::IsCheckSum( CPacket &rkPacket )
{
	DecryptMsg( rkPacket );

	DWORD dwTemp = rkPacket.GetCheckSum();   //임시 저장.
	rkPacket.SetCheckSum( 0 );
	
	DWORD dwResult = MakeDigest( (BYTE*)rkPacket.GetBuffer(), rkPacket.GetBufferSize() );

	rkPacket.SetCheckSum( dwTemp );
	return (dwResult == rkPacket.GetCheckSum());
}

// Packet Replay
int CIOSecurity::GetSndState()
{
	return m_SndState.GetState();
}

void CIOSecurity::UpdateSndState()
{
	m_SndState.UpdateState();
}

int CIOSecurity::GetRcvState()
{
	return m_RcvState.GetState();
}

void CIOSecurity::UpdateRcvState()
{
	m_RcvState.UpdateState();
}

bool CIOSecurity::CheckState( CPacket &rkPacket )
{
	if( GetRcvState() == MAGIC_TOKEN_FSM )
	{
		m_RcvState.SetState( rkPacket.GetState() );
		m_SndState.SetState( rkPacket.GetState() );		
		UpdateSndState();
	}
	else
	{
		if( GetRcvState() != rkPacket.GetState() )
			return false;
	}
	
	UpdateRcvState();	
	return true;
}

bool CIOSecurity::CheckNS( CPacket &rkPacket )
{
	if( !IsCheckSum( rkPacket ) )
	{
		return false;
	}

	if( !CheckState( rkPacket ) )
	{
		return false;
	}
	return true;
}

void CIOSecurity::PrepareMsg( CPacket &rkPacket )
{
	rkPacket.SetState( GetSndState() );

	EncryptMsg( rkPacket );

	UpdateSndState();
}

void CIOSecurity::CompletionMsg( CPacket &rkPacket )
{
	
}

