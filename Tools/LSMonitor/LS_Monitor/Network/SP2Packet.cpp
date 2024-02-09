#include "../stdafx.h"
#include "SP2Packet.h"

SP2Packet::SP2Packet()
{
}

SP2Packet::SP2Packet(DWORD ID) : CPacket( ID )
{
}

SP2Packet::SP2Packet(char *buffer,int size) : CPacket( buffer, size )
{
}
SP2Packet::~SP2Packet()
{
}

const char* SP2Packet::GetData() const
{
	return &m_pBuffer[0] + sizeof(PACKETHEADER);
}

int SP2Packet::GetDataSize() const
{
	return *m_packet_header.m_Size - sizeof(PACKETHEADER);
}

void SP2Packet::SetDataAdd( char *buffer, int size )
{
	m_currentPos = sizeof(PACKETHEADER);
	memcpy( &m_pBuffer[m_currentPos], buffer, size );
	m_currentPos += size;
	*m_packet_header.m_Size = m_currentPos;
}

void SP2Packet::SetPosBegin()
{
	m_currentPos = sizeof(PACKETHEADER);
}

//operator
SP2Packet& SP2Packet::operator = (SP2Packet &packet)
{
	Clear();
	memcpy(&m_pBuffer[0],packet.GetBuffer(),packet.GetBufferSize());
	m_currentPos = sizeof(PACKETHEADER);

	return *this;
}

SP2Packet&  SP2Packet::operator << (BYTE arg)
{
	if( !CheckLeftPacketSize( sizeof(BYTE) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(BYTE));
	m_currentPos += sizeof(BYTE);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (bool arg)
{
	if( !CheckLeftPacketSize( sizeof(bool) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(bool));
	m_currentPos += sizeof(bool);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (int arg)
{
	if( !CheckLeftPacketSize( sizeof(int) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(int));
	m_currentPos += sizeof(int);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (LONG arg)
{
	if( !CheckLeftPacketSize( sizeof(LONG) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(LONG));
	m_currentPos += sizeof(LONG);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (WORD arg)
{
	if( !CheckLeftPacketSize( sizeof(WORD) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(WORD));
	m_currentPos += sizeof(WORD);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (DWORD arg)
{
	if( !CheckLeftPacketSize( sizeof(DWORD) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(DWORD));
	m_currentPos += sizeof(DWORD);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (__int64 arg)
{
	if( !CheckLeftPacketSize( sizeof(__int64) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(__int64));
	m_currentPos += sizeof(__int64);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (LPTSTR arg)
{
	int nlen = lstrlen(arg) * sizeof( TCHAR ) + sizeof( TCHAR );

	if( !CheckLeftPacketSize( nlen ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],arg,nlen);
	m_currentPos += nlen;
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (double arg)
{
	if( !CheckLeftPacketSize( sizeof(double) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(double));
	m_currentPos += sizeof(double);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}

SP2Packet&  SP2Packet::operator << (float arg)
{
	if( !CheckLeftPacketSize( sizeof(float) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(float));
	m_currentPos += sizeof(float);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}


SP2Packet& SP2Packet::operator << ( const ioHashString &arg )
{
	int nlen = lstrlen( arg.c_str() ) + 1;

	if( !CheckLeftPacketSize( nlen ) ) return *this;

	memcpy( &m_pBuffer[m_currentPos], arg.c_str(), nlen );
	m_currentPos += nlen;
	*m_packet_header.m_Size = m_currentPos;

	return *this;
}

SP2Packet& SP2Packet::operator << ( const GAMESERVERINFO& arg )
{
	if( ! CheckLeftPacketSize( sizeof( GAMESERVERINFO ) ) )
		return *this;

	memcpy( &m_pBuffer[ m_currentPos ], &arg, sizeof( GAMESERVERINFO ) );
	m_currentPos += sizeof( GAMESERVERINFO );
	*m_packet_header.m_Size	= m_currentPos;

	return *this;
}

SP2Packet& SP2Packet::operator << ( const MAINSERVERINFO& arg )
{
	if( ! CheckLeftPacketSize( sizeof( MAINSERVERINFO ) ) )
		return *this;

	memcpy( &m_pBuffer[ m_currentPos ], &arg, sizeof( MAINSERVERINFO ) );
	m_currentPos += sizeof( MAINSERVERINFO );
	*m_packet_header.m_Size	= m_currentPos;

	return *this;
}

SP2Packet&  SP2Packet::operator >> (BYTE &arg)
{
	if( !CheckRightPacketSize( sizeof(BYTE) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(BYTE));
	m_currentPos += sizeof(BYTE);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (bool &arg)
{
	if( !CheckRightPacketSize( sizeof(bool) ) )
	{
		arg = false;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(bool));
	m_currentPos += sizeof(bool);

	return *this;
}

SP2Packet&  SP2Packet::operator >> (int &arg)
{
	if( !CheckRightPacketSize( sizeof(int) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(int));
	m_currentPos += sizeof(int);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (LONG &arg)
{
	if( !CheckRightPacketSize( sizeof(LONG) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(LONG));
	m_currentPos += sizeof(LONG);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (WORD &arg)
{
	if( !CheckRightPacketSize( sizeof(WORD) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(WORD));
	m_currentPos += sizeof(WORD);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (DWORD &arg)
{
	if( !CheckRightPacketSize( sizeof(DWORD) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(DWORD));
	m_currentPos += sizeof(DWORD);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (__int64 &arg)
{	
	if( !CheckRightPacketSize( sizeof(__int64) ) )
	{
		arg = 0;
		return *this;
	}
	
	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(__int64));
	m_currentPos += sizeof(__int64);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (LPTSTR arg)
{
	int nlen = lstrlen((LPTSTR)&m_pBuffer[m_currentPos]) * sizeof( TCHAR ) + sizeof( TCHAR );

	if( !CheckRightPacketSize( nlen ) )
	{
		arg[0] = 0;
		return *this;
	}

	memcpy(arg,&m_pBuffer[m_currentPos],nlen);
	m_currentPos += nlen;
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (double &arg)
{
	if( !CheckRightPacketSize( sizeof(double) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(double));
	m_currentPos += sizeof(double);
	
	return *this;
}

SP2Packet&  SP2Packet::operator >> (float &arg)
{
	if( !CheckRightPacketSize( sizeof(float) ) )
	{
		arg = 0;
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(float));
	m_currentPos += sizeof(float);
	
	return *this;
}


SP2Packet& SP2Packet::operator >> ( ioHashString &arg )
{
	int nlen = lstrlen((LPTSTR)&m_pBuffer[m_currentPos]) * sizeof( TCHAR ) + sizeof( TCHAR );

	if( !CheckRightPacketSize( nlen ) )
	{
		arg.Clear();
		return *this;
	}

	arg = &m_pBuffer[m_currentPos];
	m_currentPos += nlen;
	
	return *this;
}

SP2Packet& SP2Packet::operator >> ( GAMESERVERINFO& arg )
{
	if( ! CheckRightPacketSize( sizeof( GAMESERVERINFO ) ) )
	{
		ZeroMemory(&arg, sizeof(arg));
		return *this;
	}

	memcpy( &arg, &m_pBuffer[ m_currentPos ], sizeof( GAMESERVERINFO ) );
	m_currentPos += sizeof( GAMESERVERINFO );

	return *this;
}

SP2Packet& SP2Packet::operator >> ( MAINSERVERINFO& arg )
{
	if( ! CheckRightPacketSize( sizeof( MAINSERVERINFO ) ) )
	{
		ZeroMemory(&arg, sizeof(arg));
		return *this;
	}

	memcpy( &arg, &m_pBuffer[ m_currentPos ], sizeof( MAINSERVERINFO ) );
	m_currentPos += sizeof( MAINSERVERINFO );
	return *this;

}
SP2Packet& SP2Packet::operator>>( SendRelayInfo_& arg )
{
	if( !CheckRightPacketSize( sizeof(SendRelayInfo_) ) )
	{
		ZeroMemory( &arg, sizeof( SendRelayInfo_ ) );
		return *this;
	}

	memcpy(&arg,&m_pBuffer[m_currentPos],sizeof(SendRelayInfo_));
	m_currentPos += sizeof(SendRelayInfo_);
	return *this;
}

SP2Packet& SP2Packet::operator<<( SendRelayInfo_& arg )
{
	if( !CheckLeftPacketSize( sizeof(SendRelayInfo_) ) ) return *this;

	memcpy(&m_pBuffer[m_currentPos],&arg,sizeof(SendRelayInfo_));
	m_currentPos += sizeof(SendRelayInfo_);
	*m_packet_header.m_Size = m_currentPos;
	return *this;
}
