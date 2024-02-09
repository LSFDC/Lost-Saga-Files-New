#ifndef _SENDBUFFER_H_
#define _SENDBUFFER_H_

#define MAX_BUFF_SIZE		16384
#define MAX_TEMP_BUFF		16384

//HARDCODE : MAX_TEMP_BUFF �� Recv�� ����� �������� �ʿ���
//			WSASend�ÿ� m_pStart���� ������ �Ǵµ� m_pStart�� �������ʿ� �ִ°�� 
//			���ʵ����͸� �������� ����ͼ� ���������� ���۷� ������־�� �ϱ⶧����

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