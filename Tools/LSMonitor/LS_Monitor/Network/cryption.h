#pragma once

void Encrypt(BYTE *szSrc, int len);
void Decrypt(BYTE *szSrc, int len);
DWORD MakeDigest( BYTE *szSrc, int len );
