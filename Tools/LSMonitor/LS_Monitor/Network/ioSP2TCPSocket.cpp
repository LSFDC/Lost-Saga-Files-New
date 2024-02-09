

#include "../stdafx.h"
#include "ioSP2TCPSocket.h"
#include "SP2Packet.h"
#include "Protocol.h"
#include "../LS_MonitorDlg.h"


ioSP2TCPSocket::ioSP2TCPSocket()
{
	SetNS( new ioTCPClientSecurity );
}

ioSP2TCPSocket::~ioSP2TCPSocket()
{
	SAFEDELETE( m_pNS );
}

void ioSP2TCPSocket::InitState()
{
	if( m_pNS )
	{
		ioTCPClientSecurity *pCS = static_cast<ioTCPClientSecurity *>(m_pNS);
		pCS->InitState();
	}
}


void ioSP2TCPSocket::ConnectProcess()
{
	LOG.PrintTimeAndLog( 0, "Server Connect" );

	SP2Packet kPacket(CTPKM_REQUEST_NUM_CONNECT);
	SendLoop( kPacket );


	if( !AfxGetMainWnd() )
	{
		LOG.PrintTimeAndLog(0, "ioSP2TCPSocket::ConnectProcess - AfxGetMainWnd == NULL ");
		return;
	}

	CLSMonitorDlg *pDlg = static_cast< CLSMonitorDlg* > ( AfxGetMainWnd() );
	if( !pDlg )
	{
		LOG.PrintTimeAndLog(0, "ioSP2TCPSocket::ConnectProcess - pDlg == NULL ");
		return;
	}

	ioHashString szIP;
	pDlg->GetMyIP( szIP );
	if( szIP.IsEmpty() )
	{
		LOG.PrintTimeAndLog(0, "ioSP2TCPSocket::ConnectProcess - IP is Empty. ");
		return;
	}
	SP2Packet kIPPacket( CTPKM_MONITOR_IP );
	kIPPacket << szIP;
	SendLoop( kIPPacket );
	pDlg->OnConnect(m_WndMsg);
}

void ioSP2TCPSocket::DisconnectProcess()
{
	LOG.PrintTimeAndLog( 0, "ioSP2TCPSocket::DisconnectProcess - Disconnected Server" );		

	if(AfxGetApp())
	{
		CLSMonitorDlg *pWnd = (CLSMonitorDlg*)AfxGetApp()->GetMainWnd();
		if(pWnd)
			pWnd->Disconnect( m_WndMsg );
	}
}

bool ioSP2TCPSocket::CheckNS( CPacket &rkPacket )
{
	if( m_pNS == NULL )
	{
		LOG.PrintTimeAndLog( 0, "ioSP2TCPSocket::CheckNS ( m_pNS == NULL )" );
		return true;
	}

	ioTCPClientSecurity *pCS = (ioTCPClientSecurity*)m_pNS;

	if( !pCS->IsCheckSum( rkPacket ) )
	{
		LOG.PrintTimeAndLog( 0, "ioSP2TCPSocket::CheckNS Check Sum Fail!! [%d : %d]", rkPacket.GetPacketID(), rkPacket.GetCheckSum() );
		return false;
	}

	if( !pCS->CheckState( rkPacket ) )
	{
		LOG.PrintTimeAndLog( 0, "ioSP2TCPSocket::CheckNSType:%d State Not Same Client:%d, Server:%d", 
			rkPacket.GetPacketID(), rkPacket.GetState(), pCS->GetRcvState() );
		return false;
	}

	return true;
}

void ioSP2TCPSocket::ProcessPacket( CPacket &rkPacket )
{
 	if(AfxGetApp())
 	{
 		CLSMonitorDlg *pWnd = (CLSMonitorDlg*)AfxGetApp()->GetMainWnd();
 		if(pWnd)
 			pWnd->ProcessPacket( m_WndMsg, (SP2Packet&)rkPacket );
 	}
}
//////////////////////////////////////////////////////////////////////////
ioTCPClientSecurity::ioTCPClientSecurity()
{
	InitState();
}

ioTCPClientSecurity::~ioTCPClientSecurity()
{

}

void ioTCPClientSecurity::InitState()
{
	m_SndState.InitState();
	m_RcvState.InitState();
}

// Packet CheckSum
void ioTCPClientSecurity::EncryptMsg( CPacket &rkPacket )
{
	// Check Sum
	DWORD dwResult = MakeDigest(  (BYTE*)rkPacket.GetBuffer(), rkPacket.GetBufferSize()  );
	rkPacket.SetCheckSum( dwResult );
	
	// Encryption
	BYTE *pSrc;
	pSrc = (BYTE*)rkPacket.GetBuffer() + PK_CKSUM_ADDR;
	Encrypt( pSrc, rkPacket.GetBufferSize() - PK_CKSUM_ADDR );		
}

void ioTCPClientSecurity::DecryptMsg( CPacket &rkPacket )
{
	// Decryption
	BYTE *pSrc;
	pSrc = (BYTE*)rkPacket.GetBuffer() + PK_CKSUM_ADDR;
	Decrypt( pSrc, rkPacket.GetBufferSize() - PK_CKSUM_ADDR );
}

bool ioTCPClientSecurity::IsCheckSum( CPacket &rkPacket )
{
	//Decrypt
	DecryptMsg( rkPacket );

	DWORD	dwTemp = rkPacket.GetCheckSum();   //임시 저장.
	rkPacket.SetCheckSum( 0 );
	
	DWORD dwResult = MakeDigest( (BYTE*)rkPacket.GetBuffer(), rkPacket.GetBufferSize() );

	rkPacket.SetCheckSum( dwTemp );

	// Check Sum
	return ( dwResult == rkPacket.GetCheckSum() );
}

// Packet Replay
int ioTCPClientSecurity::GetSndState()
{
	return m_SndState.GetState();
}

void ioTCPClientSecurity::UpdateSndState()
{
	m_SndState.UpdateState();
}

int ioTCPClientSecurity::GetRcvState()
{
	return m_RcvState.GetState();
}

void ioTCPClientSecurity::UpdateRcvState()
{
	m_RcvState.UpdateState();
}

bool ioTCPClientSecurity::CheckState( CPacket &rkPacket )
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

void ioTCPClientSecurity::PrepareMsg( CPacket &rkPacket )
{
	rkPacket.SetState( GetSndState() );

	EncryptMsg( rkPacket );

	UpdateSndState();
}

void ioTCPClientSecurity::CompletionMsg( CPacket &rkPacket )
{
	
}

