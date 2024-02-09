// Packet.cpp: implementation of the CPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "../stdafx.h"
#include "Packet.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPacket::CPacket()
{
	Clear();
}

CPacket::CPacket(DWORD ID)
{
	Clear();
	*m_packet_header.m_ID = ID;
	m_currentPos = sizeof(PACKETHEADER);	
}

CPacket::CPacket(char *buffer,int size) 
{
	Clear();

	if( size >= sizeof(PACKETHEADER) )
	{
		memcpy( &m_pBuffer[0] , buffer, sizeof(PACKETHEADER) );
		m_currentPos = sizeof(PACKETHEADER);
	
		if( size >= GetBufferSize() )
			memcpy( &m_pBuffer[m_currentPos], &buffer[m_currentPos], GetBufferSize() - m_currentPos );			
	}
}

CPacket::~CPacket()
{

}

void CPacket::Clear()
{
	memset(m_pBuffer,0,MAX_PACKET_BUFFER);
	m_currentPos = 0;
	m_packet_header.m_ID		= (DWORD*)&m_pBuffer[PK_ID_ADDR];
	m_packet_header.m_Size		= (DWORD*)&m_pBuffer[PK_SIZE_ADDR];
	m_packet_header.m_CheckSum  = (DWORD*)&m_pBuffer[PK_CKSUM_ADDR];
	m_packet_header.m_iState    = (int*)&m_pBuffer[PK_FSM_ADDR];
	*m_packet_header.m_Size = sizeof(PACKETHEADER);
}

void CPacket::SetBufferCopy(char *pBuf,int size)
{
	Clear();

	memcpy( m_pBuffer, pBuf, size );
	m_currentPos = sizeof(PACKETHEADER);
}

void CPacket::SetDataAdd(char *pBuf,int size)
{
	memcpy( &m_pBuffer[m_currentPos], pBuf, size );
	m_currentPos += size;
	*m_packet_header.m_Size = m_currentPos;
}

void CPacket::SetCheckSum( DWORD dwSum )
{
	*m_packet_header.m_CheckSum = dwSum;
}

void CPacket::SetState( int iState )
{
	*m_packet_header.m_iState = iState;
}

const char* CPacket::GetBuffer() const
{
	return &m_pBuffer[0];
}

const char* CPacket::GetData() const
{
	return &m_pBuffer[0] + sizeof(PACKETHEADER);
}

int CPacket::GetBufferSize() const
{
	return *m_packet_header.m_Size;
}

int CPacket::GetDataSize() const
{
	return *m_packet_header.m_Size - sizeof(PACKETHEADER);
}

DWORD CPacket::GetPacketID() const
{
	return *m_packet_header.m_ID;
}

DWORD CPacket::GetCheckSum() const
{
	return *m_packet_header.m_CheckSum;
}

int CPacket::GetState() const
{
	return *m_packet_header.m_iState;
}

bool CPacket::IsValidHeader() const
{
	return (GetBufferSize() >= sizeof(PACKETHEADER) );
}

bool CPacket::IsValidPacket() const
{
	if(!IsValidHeader()) return false;

	return (GetBufferSize() >= m_currentPos);
}

bool CPacket::CheckLeftPacketSize( int iAddSize )
{	
	if( m_currentPos + iAddSize >= MAX_PACKET_BUFFER )
	{
		return false;
	}
	return true;
}

bool CPacket::CheckRightPacketSize( int iAddSize )
{	
	if( m_currentPos + iAddSize >= MAX_PACKET_BUFFER )
	{
		return false;
	}
	return true;
}

