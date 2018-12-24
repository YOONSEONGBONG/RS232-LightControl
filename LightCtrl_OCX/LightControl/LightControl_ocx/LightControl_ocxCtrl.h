#pragma once

// LightControl_ocxCtrl.h : CLightControl_ocxCtrl ActiveX 컨트롤 클래스의 선언입니다.
#include "LightComm.h"

// CLightControl_ocxCtrl : 구현을 보려면 LightControl_ocxCtrl.cpp을(를) 참조하십시오.

class CLightControl_ocxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLightControl_ocxCtrl)

// 생성자입니다.
public:
	CLightControl_ocxCtrl();

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 구현입니다.
protected:
	~CLightControl_ocxCtrl();

	DECLARE_OLECREATE_EX(CLightControl_ocxCtrl)    // 클래스 팩터리와 GUID입니다.
	DECLARE_OLETYPELIB(CLightControl_ocxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLightControl_ocxCtrl)     // 속성 페이지 ID입니다.
	DECLARE_OLECTLTYPE(CLightControl_ocxCtrl)		// 형식 이름과 기타 상태입니다.

// 메시지 맵입니다.
	DECLARE_MESSAGE_MAP()

// 디스패치 맵입니다.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 이벤트 맵입니다.
	DECLARE_EVENT_MAP()

// 디스패치와 이벤트 ID입니다.
public:
	enum {	
		dispidLightAutoTest = 5L,
		dispidSendLightMessage = 4L,
		dispidGetConnected = 3L,
		dispidClose = 2L,
		dispidOpen = 1L,
		
	};

	CLightCtrlComm m_LightCtrl;
	CString strPort;
public:
	LONG PortOpen(LONG portNum);
	void PortClose(void);
	LONG GetConnected(void);
	void SendLightMessage(LONG nLightChannel, LONG LightEventFlag, LONG nLightOnOff, LONG nLightLevel);
	void LightAutoTest(LONG nLightAutoTestChannel, LONG nLightAutoTestSpeed, LONG nLightAuoTestCount);

};
	

