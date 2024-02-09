// CGenericSocket.h
//

#if !defined(CGenericSocket_h)
#define CGenericSocket_h

#define MAX_SOCKET_DELAY_COUNT	10

#include <winsock.h>

class __EX CGenericSocket
{
public:
    bool InitSocket();
    void CloseSocket();
    int CheckSocketError(LPSTR filename, int linenum);

protected:
    SOCKET	m_socket_object;
    HWND	m_socket_hwnd;
    UINT	m_wnd_message;
};

#endif /* CGenericSocket_h */
