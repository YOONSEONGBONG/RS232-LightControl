#pragma once

// LightControl_ocxCtrl.h : CLightControl_ocxCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.
#include "LightComm.h"

// CLightControl_ocxCtrl : ������ ������ LightControl_ocxCtrl.cpp��(��) �����Ͻʽÿ�.

class CLightControl_ocxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLightControl_ocxCtrl)

// �������Դϴ�.
public:
	CLightControl_ocxCtrl();

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// �����Դϴ�.
protected:
	~CLightControl_ocxCtrl();

	DECLARE_OLECREATE_EX(CLightControl_ocxCtrl)    // Ŭ���� ���͸��� GUID�Դϴ�.
	DECLARE_OLETYPELIB(CLightControl_ocxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLightControl_ocxCtrl)     // �Ӽ� ������ ID�Դϴ�.
	DECLARE_OLECTLTYPE(CLightControl_ocxCtrl)		// ���� �̸��� ��Ÿ �����Դϴ�.

// �޽��� ���Դϴ�.
	DECLARE_MESSAGE_MAP()

// ����ġ ���Դϴ�.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �̺�Ʈ ���Դϴ�.
	DECLARE_EVENT_MAP()

// ����ġ�� �̺�Ʈ ID�Դϴ�.
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
	

