// CGenericMessage.h
//

#if !defined(CGenericMessage_h)
#define CGenericMessage_h

#define ERROR_CHECK_CODE	0x2B1C
#define MAX_SOCKET_BUFFER	16384

class __EX CGenericMessage
{
protected:
    int		m_message_size;
    DWORD	m_dwType;
    DWORD	m_error_check;
	DWORD	m_check_sum;
	int		m_iState;

public:
	void EncryptMsg();
	bool CheckError();
	bool CheckCheckSum();

protected:
	DWORD MakeDigest();

public:
	void SetState(int iState);
	void SetBasicHeader(int isize, DWORD itype);

public:
    DWORD GetType();
	DWORD GetSize();
	int	  GetState();

public:
	CGenericMessage();
};


class __EX CGenericRcvMsg : public CGenericMessage
{
public:
    char	m_message[MAX_SOCKET_BUFFER];

};

#endif /* CGenericMessage_h */
