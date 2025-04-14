// UILogIn.h: interface for the CUILogIn class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include "N3Base/N3UIBase.h"

struct __GameServerInfo {
    std::string szName;
    std::string szIP;
    int         iConcurrentUserCount;

    void Init() {
        szName = "";
        szIP = "";
        iConcurrentUserCount = 0;
    }

    __GameServerInfo() { this->Init(); };
    __GameServerInfo(const std::string & szName2, const std::string & szIP2, int iConcurrentUserCount2) {
        szName = szName2;
        szIP = szIP2;
        iConcurrentUserCount = iConcurrentUserCount2;
    }
};

class CUILogIn : public CN3UIBase {
  protected:
    CN3UIEdit * m_pEdit_id;
    CN3UIEdit * m_pEdit_pw;

    CN3UIButton * m_pBtn_LogIn;
    CN3UIButton * m_pBtn_Connect;
    CN3UIButton * m_pBtn_Cancel;
    CN3UIButton * m_pBtn_Option;
    CN3UIButton * m_pBtn_Join;

    CN3UIBase * m_pGroup_ServerList;
    CN3UIBase * m_pGroup_LogIn;

    CN3UIBase * m_pText_Rights;
    CN3UIBase * m_pImg_MGameLogo;
    CN3UIBase * m_pImg_DaumLogo;

    CN3UIBase *   m_pGroup_Notice[3];
    CN3UIString * m_pNotice_Title[3];
    CN3UIString * m_pNotice_Text[3];

    CN3UIList * m_pList_Server;

    std::vector<__GameServerInfo> m_ListServerInfos;

    bool  m_bOpenningNow; // 위에서 아래로 스르륵...열려야 한다면..
    float m_fMoveDelta;
    bool  m_bLogIn; // 로그인 중복 방지..

  public:
    std::string m_loginNewsTitle[3]; 
    std::string m_loginNewsText[3];  
    int  m_loginNewsCount = 0;


    void SetRequestedLogIn(bool bLogIn) { m_bLogIn = bLogIn; }
    bool OnKeyPress(int iKey);
    void SetVisibleLogInUIs(bool bEnable); // 계정 LogIn 에 필요한 UI 들을 숨긴다..
    void OpenServerList();
    void Tick();

    void InitEditControls();
    void FocusCircular();
    void FocusToID();
    bool Load(HANDLE hFile);
    bool ReceiveMessage(CN3UIBase * pSender, DWORD dwMsg); // 메시지를 받는다.. 보낸놈, msg

    int  ServerInfoCount() { return m_ListServerInfos.size(); }
    bool ServerInfoAdd(const __GameServerInfo & GSI);
    bool ServerInfoGet(int iIndex, __GameServerInfo & GSI);
    bool ServerInfoGetCur(__GameServerInfo & GSI);
    void ServerInfoUpdate();
    void LoadNewsData();

    void AccountIDGet(std::string & szID);
    void AccountPWGet(std::string & szPW);

    void ConnectButtonSetEnable(bool bEnable);

    CUILogIn();
    virtual ~CUILogIn();
};
