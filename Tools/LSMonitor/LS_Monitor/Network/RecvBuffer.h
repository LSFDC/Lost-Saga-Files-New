

#ifndef _RecvBuffer_h_
#define _RecvBuffer_h_

#include "ioPortalHelp.h"

class RecvBuffer
{
private:
	char m_pBuf[MAX_BUFFER];
	int	 m_iCurRcvSize;

	char m_pRewindBuf[MAX_BUFFER];

public:
	void InitBuffer();
	void UpdateRecvSize( int iCurRcvSize );
	void RewindBuffer( int iRewindSize );

public:
	char* GetStartPtr();
	char* GetFreeSpacePtr();
	int GetCurRcvSize() const;
	int GetFreeSpaceSize() const;

public:
	RecvBuffer();
	~RecvBuffer();
};
#endif