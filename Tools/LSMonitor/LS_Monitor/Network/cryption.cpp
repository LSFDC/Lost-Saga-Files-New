#include "../stdafx.h"
#include "md5.h"
#include "cryption.h"

void Encrypt(BYTE *szSrc, int len)
{
	BYTE ch;
	BYTE temp;

	for( int i=0 ; i<len ; i++ )
	{
		ch = szSrc[i];
		ch ^= 0xff;
		temp = (ch & 0xe0) >> 5;
		ch <<= 3;
		ch |= temp;
		szSrc[i] = ch;
	}
}

void Decrypt(BYTE *szSrc, int len)
{
	BYTE ch;
	BYTE temp;

	for( int i=0 ; i<len ; i++ )
	{
		ch = szSrc[i];
		temp = (ch & 0x07) << 5;
		ch>>=3;
		ch |= temp;
		ch ^= 0xff;
		szSrc[i] = ch;
	}	
}

DWORD MakeDigest( BYTE *szSrc, int len )
{
	MD5Context md5_ctx;
	DWORD	dwDigest[4];
	
	MD5Init( &md5_ctx );
	MD5Update( &md5_ctx, (unsigned char const *)szSrc, len );
	MD5Final( (BYTE*)&dwDigest, &md5_ctx );
	
	DWORD dwResult;
	dwResult = dwDigest[0] ^ dwDigest[1] ^ dwDigest[2] ^ dwDigest[3];
	
	return dwResult;
}