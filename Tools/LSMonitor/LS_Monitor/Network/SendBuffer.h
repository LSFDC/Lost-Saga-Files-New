

#ifndef _SendBuffer_h_
#define _SendBuffer_h_


class SendBuffer
{
private:
	char m_pBuffer[MAX_BUFFER + MAX_TEMP_BUFF];
	char *m_pStart;
	char *m_pEnd;

	int	 m_iRestCnt;	
	bool m_bBlock;

public:
	void InitBuffer();
	void ClearBuffer();

public:
	bool EnqueueData( const char *pData, int iPacketSize );		// return : Can Now Send ?	
	int  DequeueData( int iTransfered );

public:
	int GetRestCnt();
	char* GetQueuePtr() const;

public:
	void SetBlock( bool bBlock );
	bool IsBlocked() const;

public:
	SendBuffer();
	~SendBuffer();
};

#endif