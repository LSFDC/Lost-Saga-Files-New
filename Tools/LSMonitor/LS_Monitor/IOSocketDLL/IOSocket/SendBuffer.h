#ifndef _SENDBUFFER_H_
#define _SENDBUFFER_H_

#define MAX_BUFF_SIZE		16384
#define MAX_TEMP_BUFF		16384

//HARDCODE : MAX_TEMP_BUFF 는 Recv와 비슷한 이유에서 필요함
//			WSASend시에 m_pStart부터 보내게 되는데 m_pStart가 마지막쪽에 있는경우 
//			앞쪽데이터를 이쪽으로 끌고와서 직선형태의 버퍼로 만들어주어야 하기때문임

class __EX SendBuffer
{
	private:
	char	m_pBuffer[MAX_BUFF_SIZE + MAX_TEMP_BUFF];
	char	*m_pStart;
	char	*m_pEnd;

	int		m_iRestCnt;	
	bool	m_bBlock;

	public:
	void InitBuffer();
	void ClearBuffer();

	public:
	bool EnqueueData(char *pData, int iPacketSize);		// return : Can Now Send ?	
	int  DequeueData(int iTransfered);

	public:
	int GetRestCnt();
	char* GetQueuePtr() { return m_pStart; }

	public:
	void SetBlock(bool bBlock){ m_bBlock = bBlock; }
	bool IsBlocked(){ return m_bBlock; }

	public:
	SendBuffer();
	virtual ~SendBuffer();
};

#endif