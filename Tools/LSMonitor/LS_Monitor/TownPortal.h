

#ifndef _TownPortal_h_
#define _TownPortal_h_


#ifdef STATIC_TOWN_PORTAL_API
	#define TOWN_PORTAL_API
#else
	#ifdef EXPORT_TOWN_PORTAL
		#define TOWN_PORTAL_API __declspec(dllexport)
	#else
		#define TOWN_PORTAL_API __declspec(dllimport)
	#endif
#endif

#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#include "ioPortalHelp.h"
#include "Packet.h"
#include "ioClientTCPSocket.h"
#include "ioUDPSocket.h"
#include "NetworkSecurity.h"
#include "FSM.h"
#include "cryption.h"
#endif