
#ifndef _MD5_H
#define _MD5_H

typedef struct tagMD5Context
{
   DWORD buf[4];
   DWORD bits[2];
   unsigned char in[64];
}MD5Context;

void MD5Init( MD5Context *context );
void MD5Update( MD5Context *context, unsigned char const *buf,
			    unsigned len );
void MD5Final( unsigned char digest[16], MD5Context *context );
void MD5Transform( DWORD buf[4], DWORD const in[16] );

/*
 * This is needed to make RSAREF happy on some MS-DOS compilers.
 */

#endif /* !MD5_H */
