#pragma once

#include <Mmsystem.h>
#include <vector>
#include <map>
#include "IOSocket.h"

// define
#define COMPARE(x,min,max) (((x)>=(min))&&((x)<(max)))
#define SAFEDELETE(x)		if(x != NULL) { delete x; x = NULL; }
#define SAFEDELETEARRAY(x)	if(x != NULL) { delete [] x; x = NULL; }

enum ServerStates
{
	SERVERSTATE_OFF=0,
	SERVERSTATE_ON,
	SERVERSTATE_BUSY,
	SERVERSTATE_END,
	SERVERSTATE_EMPTY
};

struct BILLINGSERVERINFO
{
	BILLINGSERVERINFO()
	{
		serviceName			= "";
		serviceIP			= "";
		servicePort			= 0;
		billingServerState	= 0;
		serverType			= 0;
		serverListIndex		= -1;
		serverKeyIndex		= -1;
		connect				= 0;
		userInfoCount		= 0;
		reloadStatus		= "";
	}

	CString		serviceName;
	CString		serviceIP;
	int			servicePort;
	int			billingServerState;
	int			serverType;
	int			serverListIndex;
	int			serverKeyIndex;
	int			connect;
	WORD		userInfoCount;
	CIOSocket   billingSocket;
	CString		reloadStatus;
};

typedef std::map<int, BILLINGSERVERINFO*> BILLINGSERVERTABLE;



struct SERVERINFO
{
	SERVERINFO()
	{
		serverIndex		= 0;
		serverType		= 0;
		serverState		= 0;
		serviceName		= "";
		serviceIP		= "";
		servicePort		= 0;
		connect			= 0;
// 		GB_Connect		= 0;
// 		DE_Connect		= 0;
// 		FR_Connect		= 0;
// 		IT_Connect		= 0;
// 		PL_Connect		= 0;
// 		TR_Connect		= 0;
// 		ETC_Connect		= 0;
		roomCount		= 0;
		plazaCount		= 0;
		battleRoomCount = 0;
		pingMS			= 0;
		DBMS			= 0;
		delay			= 0;
		relayFlag		= 0;
	}
	int		serverIndex;
	int		serverType;
	int		serverState;
	CString serviceName;
	CString serviceIP;
	int		servicePort;
	WORD	connect;
// 	WORD	GB_Connect; //영국
// 	WORD	DE_Connect; //독일
// 	WORD	FR_Connect; //프랑스
// 	WORD	IT_Connect; //이탈리아
// 	WORD	PL_Connect; //폴란드
// 	WORD	TR_Connect; //터키
// 	WORD	ETC_Connect; //터키
	WORD	roomCount;
	WORD    plazaCount;
	WORD	battleRoomCount;
	WORD 	pingMS;
	WORD    DBMS;
	WORD	delay;
	BOOL	relayFlag;
};

struct MAINSERVERINFO
{
	DWORD	dwGlobalTime;			//GLOBAL TIME
	char	szPublicIP[ 32 ];		//Network Info
	char	szPrivateIP[ 32 ];
	int		iPort;
	int		ThreadCount;			//Thread Info
	int		JoinServerCount;		//Connect Client Info
	int		RemainderMemPoolCount;	//Remainder MemPool Info
	int		RecvQueuePacketCount[4];//RECV QUEUE
	int		RecvQueueRemainderCount[4];//Remainder MemPool Info
	char	szDBAgentIP[ 32 ];		//DB AGENT SERVER INFO
	char	szLogDBAgentIP[ 32 ];		//DB AGENT SERVER INFO
	int		DBAgentPort;
	bool	bDBAConnected;
	int		LogDBAgentPort;
	bool	bLogDBAConnected;
	int		MaxGuildCount;			//GUILD INFO
	int		MaxUpdateGuild;
	char	szCampStringHelp[ 128 ];//CAMP INFO
	int		MaxTradeItemCount;		//Trade Info
	char	szEventShopState[ 32 ];	//Event Shop Info
	int		EventGoodsSaveDataCount;
	int		MaxToolConnectCount;	//MANAGER TOOL
	bool	bUseClientVersion;		// Client Version
	int		iClientVersion;
	char	szMainServerVersion[ 8 ];// Main Server Version
	char	szMainServerName[ 32 ];

	// Log
	int		usingLogCount;					// 현재
	int		maxUsingLogCount;				// 가장 많이 쓸때
	int		remainLogCount;					// remain
	int		dropLogCount;					// 드랍된 갯수.

	MAINSERVERINFO() : dwGlobalTime(0), iPort(0), ThreadCount(0), JoinServerCount(0), RemainderMemPoolCount(0)
		, DBAgentPort(0), bDBAConnected(false), LogDBAgentPort(0), bLogDBAConnected(false), MaxGuildCount(0)
		, MaxUpdateGuild(0), MaxTradeItemCount(0), EventGoodsSaveDataCount(0), MaxToolConnectCount(0)
		, bUseClientVersion(false), iClientVersion(0), usingLogCount(0), maxUsingLogCount(0), remainLogCount(0), dropLogCount(0)
	{
		   ZeroMemory( szPublicIP, sizeof( szPublicIP ) );
		   ZeroMemory( szPrivateIP, sizeof( szPrivateIP ) );
		   ZeroMemory( RecvQueuePacketCount, sizeof( RecvQueuePacketCount ) );
		   ZeroMemory( RecvQueueRemainderCount, sizeof( RecvQueueRemainderCount ) );
		   ZeroMemory( szDBAgentIP, sizeof( szDBAgentIP ) );
		   ZeroMemory( szLogDBAgentIP, sizeof( szLogDBAgentIP ) );
		   ZeroMemory( szCampStringHelp, sizeof( szCampStringHelp ) );
		   ZeroMemory( szEventShopState, sizeof( szEventShopState ) );
		   ZeroMemory( szMainServerVersion, sizeof( szMainServerVersion ) );
		   ZeroMemory( szMainServerName, sizeof( szMainServerName ) );
	}
};

struct GAMESERVERINFO
{
	DWORD	dwGlobalTime;			//GLOBAL TIME
	char szPublicIP[ 32 ];		//Network Info
	int	csPort;
	int SSPort;
	int MSPort;
	int ThreadCount;				//Thread Info
	int NodeSize;					//Connect Client Info
	int CopyNodeSize;
	int RemainderNode;				//Remainder MemPool Info
	int RoomNodeSize;				//CREATE ROOM 
	int PlazaNodeSize;
	int HeapQuartersNodeSize;
	int CopyRoomNodeSize;
	int CopyPlazaNodeSize;
	int CopyHeapQuartersNodeSize;
	int RommRemainderNode;			//Remainder MemPool Info
	int BattleRoomNodeSize;			//CREATE BATTLEROOM
	int BattleRoomCopyNodeSize;
	int PartyLevelCheckMinRoom;
	int BattleRoomRemainderNode;	//Remainder MemPool Info
	int LadderTeamNodeSize;			//CREATE LADDERTEAM
	int LadderTeamCopyNodeSize;
	int LadderTeamCampBattlePlay;
	int LadderTeamRemainderNode;	//Remainder MemPool Info
	int RecvQueueNodeSize[ 4 ];			//RECV QUEUE
	int BroadCastUDPnRelayNodeSize;
	int RecvQueueRemainderNodeSize[4];	//Remainder MemPool Info
	int BroadCastUDPnRelayRemainderNodeSize;
	int DBClientNodeSize;				//DB AGENT SERVER INFO
	int DBClientTotalNodeSize;				//DB AGENT SERVER INFO
	char szSTRFILEVER[ 8 ];				// Game Server Version
	char szSTRINTERNALNAME[ 32 ];
	char szGameServerID[ 32 ];			// Game Server ID
	char szGameServerName[ 32 ];		// Game Server Name
	char szLogDBIP[ 32 ];				// LogDB Agent IP / port
	int LogDBPort;
	bool IsLogDBAActive;
	DWORD HackCheckMin;					// HackCheck
	DWORD HackCheckMax;
	int HackCheckLess;
	int HackCheckOver;
	int HackCheckLessOver;
	int HackCheckTotal;
	int IsClientVersion;				// Client Version
	int GetClientVersion;
	int ChannelNodeSize;				//CREATE Channel
	int ChannelRemainderSize;
	int ChannelCopyNodeSize;
	int MemoNodeSize;					//MEMO
	DWORD GetServerIndex;				//GAME SERVER INFO
	int ServerNodeSize;
	int ServerRemainderNodeSize;
	bool IsMainServerActive;			// Main Server Info
	char MainServerIP[ 32 ];
	int MainServerPort;
	__int64 UDPTransferCount;			//UDP Transfer Count
	__int64 UDPTransferTCPCount;
	__int64 UDPTransferTCPSendCount;
	bool IsBillingRelayServerActive;	//BILLING RELAY SERVER INFO
	char BillingIP[ 32 ];
	int BillingPort;
	char XtrapVersion[ 32 ];
	int LicenseDate;					// Expiration dates
	bool m_bReserveLogout;				// Exit
	int remainSecond;
	int sendBufferUsingCnt;				// SendBuffer
	int sendBufferRemainCnt;
	int sendBufferMaxCnt;

	// Log
	int usingLogCount;					// 현재
	int maxUsingLogCount;				// 가장 많이 쓸때
	int remainLogCount;					// remain
	int dropLogCount;					// 드랍된 갯수.

	GAMESERVERINFO() : dwGlobalTime(0), csPort(0), SSPort(0), MSPort(0), ThreadCount(0), NodeSize(0), CopyNodeSize(0)
		, RemainderNode(0),	RoomNodeSize(0), PlazaNodeSize(0), HeapQuartersNodeSize(0),	CopyRoomNodeSize(0), CopyPlazaNodeSize(0)
		, CopyHeapQuartersNodeSize(0), RommRemainderNode(0), BattleRoomNodeSize(0),	BattleRoomCopyNodeSize(0), PartyLevelCheckMinRoom(0)
		, BattleRoomRemainderNode(0), LadderTeamNodeSize(0), LadderTeamCopyNodeSize(0),	LadderTeamCampBattlePlay(0), LadderTeamRemainderNode(0)
		, BroadCastUDPnRelayNodeSize(0), BroadCastUDPnRelayRemainderNodeSize(0), DBClientNodeSize(0), DBClientTotalNodeSize(0)
		, LogDBPort(0), IsLogDBAActive(false), HackCheckMin(0), HackCheckMax(0), HackCheckLess(0), HackCheckOver(0), HackCheckLessOver(0), HackCheckTotal(0), IsClientVersion(0)
		, GetClientVersion(0), ChannelNodeSize(0), ChannelRemainderSize(0), ChannelCopyNodeSize(0), MemoNodeSize(0)
		, GetServerIndex(0), ServerNodeSize(0), ServerRemainderNodeSize(0), IsMainServerActive(false), MainServerPort(0)
		, UDPTransferCount(0), UDPTransferTCPCount(0), UDPTransferTCPSendCount(0), IsBillingRelayServerActive(false), BillingPort(0)
		, LicenseDate(0), m_bReserveLogout(false), remainSecond(0), sendBufferUsingCnt(0), sendBufferRemainCnt(0), sendBufferMaxCnt(0)
		, usingLogCount(0), maxUsingLogCount(0), remainLogCount(0), dropLogCount(0)
	{
		ZeroMemory( szPublicIP, sizeof( szPublicIP ) );
		ZeroMemory( RecvQueueNodeSize, sizeof( RecvQueueNodeSize ) );
		ZeroMemory( RecvQueueRemainderNodeSize, sizeof( RecvQueueRemainderNodeSize ) );
		ZeroMemory( szSTRFILEVER, sizeof( szSTRFILEVER ) );
		ZeroMemory( szSTRINTERNALNAME, sizeof( szSTRINTERNALNAME ) );
		ZeroMemory( szGameServerID, sizeof( szGameServerID ) );
		ZeroMemory( szGameServerName, sizeof( szGameServerName ) );
		ZeroMemory( szLogDBIP, sizeof( szLogDBIP ) );
		ZeroMemory( MainServerIP, sizeof( MainServerIP ) );
		ZeroMemory( BillingIP, sizeof( BillingIP ) );
		ZeroMemory( XtrapVersion, sizeof( XtrapVersion ) );
	}
};

struct LoginServerInfo
{
	TCHAR serverIP[64];
	int serverPort;
	int acceptCountPerSec;
	int acceptCount;
	int closeCount;
	int opPoolCount;
	int clientPoolCount;
	int userInfoCount;
	int serverConnectorPoolCount;
	int packetQueueCount;
	int serverConnectCount;
};

struct ServerInfo
{
	TCHAR serverIP[64];
	TCHAR serverName[64];
	int serverPort;
	int userCount;
	int sendCount;
	int fullCount;
	int blockState;
	int serverId;
	int serverState;
};
#pragma pack(push,1)
struct SendRelayInfo_
{
	TCHAR m_ipAddr[64];
	int m_port;
	int  m_userCount;
	int  m_roomCount;
	int  m_serverCount;
	int m_64DropCount;
	int m_256DropCount;
	int m_1024DropCount;
	int m_64UsingCount;
	int m_256UsingCount;
	int m_1024UsingCount;
	SendRelayInfo_()
	{
		ZeroMemory(m_ipAddr,64);
		m_port = 0; 
		m_userCount = 0;
		m_roomCount= 0;
		m_64DropCount= 0;
		m_256DropCount= 0;
		m_1024DropCount= 0;
		m_64UsingCount= 0;
		m_256UsingCount= 0;
		m_1024UsingCount= 0;
	}
};
#pragma pack(pop)
namespace ESOCKET
{
	enum Socket
	{
		LS_CONNECTED = 0,
		LS_DISCONNECTED,
		LS_REQSERVERSTATE,
		LS_RESPSERVERSTATE,
		LS_ZOMBIESERVERSTATE,
		LS_BLOCKED,
	};
}

namespace EMCONTROLTYPE
{
	enum ECONTYPE
	{
		LS_GETSERVERINFO,
		LS_SETALLSERVERBLOCK,
		LS_SETSERVERBLOCK,
		LS_FILLSERVERINFO,
		LS_SETMAXUSER,
		LS_FILLINFODRAW,
		LS_QUICKEXIT,

	};
}


