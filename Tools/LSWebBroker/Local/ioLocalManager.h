#ifndef __ioLocalManager_h__
#define __ioLocalManager_h__

#define MAX_PASSWORD 11

#include "../StringManager/ioSingleton.h"
#include <vector>

class ioLocalParent;

class ioLocalManager : public Singleton< ioLocalManager >
{
public:
	enum LocalType
	{
		LCT_KOREA		= 119483910,	// Ÿ�԰��� ������ ���ؼ� ���������� �������� �ʰ� �����ϰ� ����.
		LCT_US			= 365849202,
		LCT_CHINA		= 917382048,
		LCT_TAIWAN		= 521837584,
		LCT_JAPAN		= 213527182,
		LCT_INDONESIA	= 938400398,
		LCT_VIETNAM		= 783920174,
		LCT_THAILAND	= 800125411,
		LCT_BRAZIL		= 329859423,
		LCT_LATIN		= 458278951,

		LCT_SINGAPORE	= 331611151,		// �̰��� �����̽þ�.
		LCT_MALAYSIA	= 331611152,

		LCT_EU			= 647291028,	//Nexon EU
		LCT_GERMANY		= 647291029,	//Nexon EU
		LCT_FRANCE		= 647291030,	//Nexon EU
		LCT_ITALIA		= 647291031,	//Nexon EU
		LCT_POLAND		= 647291032,	//Nexon EU
		LCT_TURKEY		= 647291033,	//Nexon EU
	};

protected:
	static LocalType m_eLocalType;
	
public:
	static LocalType GetLocalType() { return m_eLocalType; }

protected:
	typedef std::vector< ioLocalParent* > vLocalVector;
	vLocalVector m_vLocalVector;

protected:
	ioLocalParent *CreateLocal( LocalType eLocalType );
	void AddLocal( ioLocalParent *pLocal );
	const char *GetLocalName( LocalType eLocalType );

public:
	void Init();
	ioLocalParent *GetLocal( LocalType eLocalType );
	bool ParseCmdForSetLocal( const char *szCmd );
	void SetLocalType( const char *szLocal );

public:
	static ioLocalManager &GetSingleton();


public:
	ioLocalManager(void);
	virtual ~ioLocalManager(void);
};


#define g_LocalMgr ioLocalManager::GetSingleton()

#endif // __ioLocalManager_h__