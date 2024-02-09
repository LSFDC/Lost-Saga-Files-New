#pragma once



// cFile
class cFile  
{
public:
	cFile();
	cFile(LPCTSTR fileName, DWORD dwMode, DWORD dwShareMode, DWORD dwCreationDisposition);
	virtual ~cFile();

public:
	BOOL Open(const TCHAR* fileName, DWORD dwMode, DWORD dwShareMode, DWORD dwCreationDisposition);
	void Close();

	BOOL Move(DWORD dwOrigin, LONG lOffset);
	virtual DWORD GetFileSize();

	enum SaveFileFormat
	{
		FILEFORMAT_ANSI = 1,
		FILEFORMAT_UNICODE_UTF8,
		FILEFORMAT_UNICODE_LE,
		FILEFORMAT_UNICODE_BE,
	};

protected:
	HANDLE	m_hFile;
	DWORD	m_dwSizeLow, m_dwSizeHigh;
};

// cFileReader
class cFileReader : public cFile
{
public:
	cFileReader(const TCHAR* fileName=NULL);

public:
	BOOL Open(const TCHAR* fileName);

	BOOL Read(BYTE* buffer, const DWORD dwLength);
	BOOL Convert(const BYTE* bufferA, const int lengthA, BYTE* bufferB, const int lengthB);

	int GetBOM();

	virtual DWORD GetFileSize();

private:
	int m_nReadType;
};

// cFileWriter
class cFileWriter : public cFile
{
public:
	cFileWriter(const TCHAR* fileName=NULL);

public:
	BOOL Open(const TCHAR* fileName);

	BOOL Write(const BYTE* buffer, const DWORD dwLength);
	BOOL WriteFormat(const TCHAR* format, ...);

	void WriteHeader();
};


