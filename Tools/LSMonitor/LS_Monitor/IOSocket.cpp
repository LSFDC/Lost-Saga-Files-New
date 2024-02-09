#include "StdAfx.h"
#include "resource.h"
#include "ZoneDialog.h"
#include "WinMessage.h"
#include "IOSocket.h"


CIOSocket::CIOSocket(void) : m_connected(FALSE), m_dlg(NULL), m_bytesSent(0), m_bytesBufferSize(0), m_bytesReceived(0)
{
	Init();
}

CIOSocket::~CIOSocket(void)
{
	Destroy();
}

void CIOSocket::Init()
{
	ZeroMemory(m_sendBuffer, sizeof(m_sendBuffer));
	m_billingKeyIndex	= -1;
}

void CIOSocket::Destroy()
{
}

BOOL CIOSocket::Create()
{
	InitState();

	if(CAsyncSocket::Create())
	{
		BOOL flag = 1;
		SetSockOpt(TCP_NODELAY, &flag, sizeof(flag), IPPROTO_TCP);
		return TRUE;
	}
	return FALSE;
}

BOOL CIOSocket::Connect(const ServerTypes serverType, CZoneDialog* dlg, const char* IP, const int port)
{
	SetType(serverType);
	SetDlg(dlg);

	return CAsyncSocket::Connect(IP, port);
}

BOOL CIOSocket::BillingServerConnect(const ServerTypes serverType, CZoneDialog* dlg, const char* IP, const int port, const int billingkeyIndex)
{
	SetType(serverType);
	SetDlg(dlg);
	SetBillingIndex(billingkeyIndex);

	return CAsyncSocket::Connect(IP, port);
}

void CIOSocket::Disconnect()
{
	CAsyncSocket::Close();
}

void CIOSocket::SendPacket(CPacket &rkPacket)
{
	if(IsConnected())
	{
		PrepareMsg( rkPacket );

		m_bytesBufferSize = rkPacket.GetBufferSize();
		CopyMemory(m_sendBuffer, rkPacket.GetBuffer(), m_bytesBufferSize);

		int sentBytes = CAsyncSocket::Send(rkPacket.GetBuffer(), rkPacket.GetBufferSize());
		if(sentBytes > 0)
		{
			if(sentBytes != rkPacket.GetBufferSize())
			{
				TRACE(_T("Send loop : %d\r\n"), sentBytes);
			}
		}
		else
		{
			DWORD error = GetLastError();
			TRACE(_T("Send failed : %lu\r\n"), error);
		}
		CompletionMsg( rkPacket );
	}
}

void CIOSocket::OnConnect(int nErrorCode)		
{
	if(0 == nErrorCode)
	{
		SetConnected(TRUE);

		BOOL flag = 1;
		SetSockOpt(TCP_NODELAY, &flag, sizeof(flag), IPPROTO_TCP);
	}
	else
	{
		SetConnected(FALSE);
	}
	
	GetDlg()->OnConnect(GetType(), nErrorCode, GetBillingIndex());
}

void CIOSocket::OnClose(int nErrorCode)
{
	SetConnected(FALSE);
	
	GetDlg()->OnClose(GetType(), nErrorCode, GetBillingIndex());
}

void CIOSocket::OnReceive(int nErrorCode)
{
	TCHAR buffer[1024 * 16];
	int readBytes = Receive(buffer, _countof(buffer)); 

	switch (readBytes)
	{
	case 0:
		{
			Close();
		}
		break;

	case SOCKET_ERROR:
		{
			if (GetLastError() != WSAEWOULDBLOCK) 
			{
				Close();
			}
		}
		break;

	default:
		{
			// 저장된 버퍼에 복사
			CopyMemory(m_recvBuffer + m_bytesReceived, buffer, readBytes);
			m_bytesReceived += readBytes;

			while(m_bytesReceived > 0)
			{
				CPacket kPacket((char*)m_recvBuffer, m_bytesReceived);
				if( kPacket.IsValidPacket() && m_bytesReceived >= kPacket.GetBufferSize() )
				{
					if(CheckNS( kPacket))
					{
						GetDlg()->OnReceive(GetType(), (SP2Packet&)kPacket);		//타입이랑, 패킷을 PostMessage로 보내도록 수정해야함

						TRACE("right recv byte : %lu, packet size %lu\n", m_bytesReceived, kPacket.GetBufferSize());
						m_bytesReceived -= kPacket.GetBufferSize();
						CopyMemory(m_recvBuffer, m_recvBuffer+kPacket.GetBufferSize(), m_bytesReceived);
					}
					else
					{
						break;
					}
				}
				else
				{
					// 패킷이 적게 들어옴
					TRACE("less recv byte : %lu, packet size %lu\n", m_bytesReceived, kPacket.GetBufferSize());
					break;
				}
			}
		}
		break;
	}
}

void CIOSocket::OnSend(int nErrorCode)
{
	TRACE(_T("OnSend : %d\r\n"), nErrorCode);

	//while (m_bytesSent < m_bytesBufferSize)
	//{
	//	int sentBytes = Send(m_sendBuffer + m_bytesSent, m_bytesBufferSize - m_bytesSent);
 //		if(sentBytes == SOCKET_ERROR)
	//	{
	//		if (GetLastError() == WSAEWOULDBLOCK)
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			Close();
	//		}
	//	}
	//	else
	//	{
	//		m_bytesSent += sentBytes;
	//	}
	//}
 // 
	//if (m_bytesSent == m_bytesBufferSize)
	//{
	//	m_bytesSent = 0;
	//	m_bytesBufferSize = 0;
	//	ZeroMemory(m_sendBuffer, sizeof(m_sendBuffer));
	//}
}

