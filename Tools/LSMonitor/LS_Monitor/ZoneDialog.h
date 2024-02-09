#pragma once

#include "afxcmn.h"
#include "IOSocket.h"
#include "OScopeCtrl.h"
#include "ServerTypes.h"
#include "MonitorListCtrl.h"
#include "Network/Protocol.h"
#include "Network/SP2Packet.h"
#include <map>

const int CCU_PORT = 9999;

// 변수명에 userId로 쓰인것은
// publicId와 privateId중 어느 것인지 헤깔리는 부분이 있어
// 추후에 변경해야함

class CDisplayDlg;
class CCSDialog;
class CLoginDialog;
class COperatorDlg;
class CGraphDlg;
class cFileWriter;

typedef std::map<int,SERVERINFO*> SERVERTABLE;

#define BILLING_ANSWER 3

//
// CZoneDialog 대화 상자입니다.

class CZoneDialog : public CDialogEx
{
	DECLARE_EASYSIZE
	DECLARE_DYNAMIC(CZoneDialog)

public:
	CZoneDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CZoneDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ZONEINFO_DIALOG };

public:
	void Show();
	void Hide();
	void CreateMonitor(CString& title, CString& main, CString& login);
	void CreateBillingMonitor(CString& title, BOOL billingFlag, BILLINGSERVERTABLE& tempBilling);

	void SetBillingFlag(bool bBillingFlag)					{ m_billingFlag = bBillingFlag; }
	void SetBillingTable(BILLINGSERVERTABLE& tempBilling)	{ m_billingServerTable = tempBilling; }
	void SetBillingViewList();
	

	void SetBillingConnTimerFlag(bool bTimer)				{ m_billingConnTimerFlag = bTimer; }
	BOOL GetBillingConnTimerFlag()							{ return m_billingConnTimerFlag; }
	void SetBillingTimerFlag(bool bTimer)					{ m_billingTimerFlag = bTimer; }
	BOOL GetBilingTimerFlag()								{ return m_billingTimerFlag; }

	void AddBillingConnectCount()							{ ++m_billingConnCount; }
	void MinusBillingConnectCount()							{ --m_billingConnCount; }
	int  GetBillingConnectCount()							{ return m_billingConnCount; }
	

	void OnConnect(const ServerTypes serverType, const int errCode, const int billingIndex);
	void OnClose(const ServerTypes serverType, const int errCode, const int billingKeyIndex);
	void OnReceive(const ServerTypes serverType, SP2Packet& rkPacket);

	void ReceiveInfo( SP2Packet& rkPacket );
	void RequestInfo(int serverType, int index);
	void GetAddress(const ServerTypes serverType, const int item, CString& name, CString& IP, int& port);
	void GetBillingAddress(const int serverType, const int item, CString& name, CString& IP, int& port);
	
	BOOL GetRelayFlag(int index);

	BOOL IsShow()			{ return m_show; }
	BOOL IsAdministrator()	{ return (ADMIN_LEVEL_ADMINISTRATOR == m_level) ? TRUE : FALSE; }
	BOOL IsOperator()		{ return (ADMIN_LEVEL_OPERATOR == m_level) ? TRUE : FALSE; }

protected:
	void CreateSocket();
	void CreateGraph();
	void CreateList();
	void CreateChild();
	void CreateLog();
	void CreateTimer();
	void DestroyTimer();
	void CreatePanel();
	void CreatePopup();

	void InsertServer(SERVERINFO* serverInfo, const ServerStates state);
	void UpdateServer(SERVERINFO* serverInfo, const ServerStates state);
	void UpdateGameInfo(const int item, SERVERINFO& serverInfo);
	void UpdateBillingReloadStatus(const int item, BOOL status);
	void UpdateBillingUserCountInfo(const int item, BILLINGSERVERINFO& serverInfo, int billingKeyIndex);
	void UpdateGraph(const int userCount);
	void SortBillingList();

	void InsertBillingServer(BILLINGSERVERINFO* serverInfo, const ServerStates state, int billingKeyIndex);
	void UpdateBillingServer(BILLINGSERVERINFO* serverInfo, const ServerStates state, int billingKeyIndex);
	void UpdateBillingGraph();
	

	void SetTitle(CString& title)	{ m_title = title; }
	CString GetTitle()				{ return m_title; }

protected:
	int GetGameServerCount()	{ return m_gameServerTable.size(); }
	
	SERVERINFO*			GetGameServerInfo(const int index);
	SERVERINFO*			GetGameServerInfo(ioHashString& serverName);
	SERVERINFO*			GetGameServerInfo(ioHashString& serverIP, int serverPort);
	SERVERINFO*			GetOtherServerInfo(const int index);
	SERVERINFO*			GetOtherServerInfo(const ServerTypes serverType);
	
public :
	BILLINGSERVERINFO*  GetBillingServerInfo(const int index);
	BILLINGSERVERINFO*  GetBillingServerListInfo(const int index);

protected :
	void AddGameServerInfo(SERVERINFO* serverInfo);
	void AddOtherServerInfo(SERVERINFO* serverInfo);
	void RequestBillingUserInfoCount();	//접속되어 있는 빌링서버에 유저 카운트 요청함
	
	void ShowInfo(int serverType, int index, CString& title, CString& text);
	void ShowGraph(MSG* pMsg);

	void WriteLog(int currentUser);

public:
	void RequestKickUser(CString publicID);
	void RequestAnnounce(int msgType, CString publicID, CString announce);
	void RequestItemInsert(CString publicID, int presentType, int value1, int value2, int ment, int isPublicID);
	void RequestEventInsert(int values[], int valueCount);
	void RequestUserBlock(CString publicID, CString note, int64 limitTime, int level);
	void RequestUserUnblock(CString publicID);
	void RequestBillingServerLOG(int index);
	void RequestWhiteList(BOOL bWhiteList, ServerTypes eServerType);
	void RequestSecretShopCountChange(int iCode, int iCount);
	void RequestCompensation(int iType, int iCode, int iValue, __int64 iEndDate);

	void WriteLogDlg( const TCHAR* format, ...);
	void WriteLogDlg( CString text );
protected:
	BOOL GetIP(CString& localIP);

	void UpdateBegin();
	void UpdateEnd();

	void RequestMonitorIP();
	void RequestMainInfo();
	void RequestLoginConnect();
	void RequestLoginInfo();
	void RequestLoginPanel();
	void RequestLoginBlock(int serverIndex, int blockState);
	void RequestLoginQuickExit();
	void RequestGameServerInfo(int index);
	void RequestMainClose();
	
	void RequestGameSafeyClose(int index);
	void RequestGameQuicklyClose(int index);
	void RequestGameSafeyCloseAll();
	void RequestGameQuicklyCloseAll();
	void RequestShowCSFile();
	void RequestLoadCSFile();
	void RequestUpdateRivision(int version);
	void RequestReloadGSINI();
	void RequestReloadOption();
	void RequestReloadCloseINI();
	void RequestBillingReloadINI( int billingKeyIndex );
	
	//void RequestBillingReloadINI_ALL();
	//void RequestBillingNexonPCRoomLogout( int billingKeyIndex );
	
	void ResetEventShopCount();
	void ResetCloverShopCount();
	void ResetMilegeShopCount();
	void ReserPurchaseLog();
	void ReserOldMissionData();
	void RequestAuth(CString ID, CString PWD);
	void RequestChangeRelayServerState(int index);
	void RequestExportReports();

	void OnAnswerNumConnect(SP2Packet &rkPacket);
	void OnAnswerBillingConnect(SP2Packet &rkPacket);
	void OnBillingUserInfo(SP2Packet &rkPacket);
	void OnServerDisconnect(SP2Packet &rkPacket);
	void OnAllServerInfo(SP2Packet &rkPacket);
	void OnLoadCS3File(SP2Packet &rkPacket);
	void OnCS3FileVersion(SP2Packet &rkPacket);
	void OnServerInfoAck(SP2Packet &rkPacket);
	void OnAdminResponse(SP2Packet &rkPacket);
	void OnLoginInfoAck(SP2Packet &rkPacket);
	void OnLoginServerInfo(SP2Packet& rkPacket);
	void OnLoginServerRefresh(SP2Packet& rkPacket);
	void OnLoginServerBlock(SP2Packet& rkPacket);
	void OnLSResponse(SP2Packet &rkPacket);
	void OnAnswerBillingRequest(SP2Packet &rkPacket);
	void OnBillingReloadINIStatus(SP2Packet &rkPacket);
	
	void OnReceiveEUCCU(SP2Packet &rkPacket);
	void OnReceiveLicenseCheck(SP2Packet &rkPacket);


protected:
	
	BOOL		m_show;
	CImageList	m_imageList;
	COScopeCtrl m_countGraph;

	CString		m_title;
	CString		m_mainIP, m_loginIP;
	
	int			m_mainPort, m_loginPort;
	
	CIOSocket	m_sockMain;
	CIOSocket	m_sockLogin;

	SERVERTABLE			m_gameServerTable;
	SERVERTABLE			m_otherServerTable;

	BILLINGSERVERTABLE				m_billingServerTable;	//INI에서 읽어온 빌링서버 정보
	std::vector<BILLINGSERVERINFO*> m_billingServerList;	//리스트 출력 순대로 저장됨 -> index 를 통해 클릭된 빌링서버 정보 구할 수 있음
	
	int m_maxBillingUser, m_CurrentBillingUser;
	int m_lastBillingMax;
	int m_billingLOGReceiveCount, m_billingConnCount;

	int m_level;
	int	m_maxUser, m_currentUser;
	int	m_lastMax;
	int m_selectedItem;
	CDisplayDlg* m_displayDlg;
	CLoginDialog* m_loginDlg;
	COperatorDlg* m_operatorDlg;
	CGraphDlg* m_graphDlg;
	cFileWriter* m_file;

	CMenu m_menu;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	
public:
	CMonitorListCtrl m_services[2];
	BOOL m_billingFlag;
	BOOL m_billingTimerFlag;
	BOOL m_billingConnTimerFlag;
	BOOL m_bCountryCode;

	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam); 
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLvnItemchangedListGamedemons(NMHDR *pNMHDR, LRESULT *pResult);
private:
	//EU국가별 접속자수 카운팅 함수 및 변수입니다.
	void	SetUserEachOfCountry(int iSvrType, int iNum, char* cName, SERVERINFO* svrInfo, const ServerStates iSvrState);
	//EU국가별 접속자수 데이터 설정 함수
	void SetEachOfCountryData(int iNum, char* cName, DWORD wdConnect);
	//문자열 붙이는 함수입니다.
	void	CStringAddINT(int iData, CString* TStr);
	void	SetCloseCCU(CString* Tstr);
	void	MoveToItemData(int iSvrNum, int iSour, int iDest);

	SERVERINFO OtherSvrInfo[CI_MAX]; //국가별 카운트용
	DWORD	m_wdENG, m_wdGER, m_wdFRA, m_wdITA, m_wdPOL, m_wdTUR, m_wdETC;
public:
//	afx_msg void OnNMClickListGamedemons(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnKeydownListGamedemons(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkListGamedemons(NMHDR *pNMHDR, LRESULT *pResult);
	void GetCCUINFO(const int item, CString& strName, CString& IP, int& port, int& ENGcnt, int& GERcnt, int& FRAcnt, int& ITAcnt, int& POLcnt, int& TURcnt, int& ETCcnt);
};
