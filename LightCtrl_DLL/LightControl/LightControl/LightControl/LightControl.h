// LightControl.h : LightControl DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"// �� ��ȣ�Դϴ�.
#include "LightComm.h"

// CLightControlApp
// �� Ŭ������ ������ ������ LightControl.cpp�� �����Ͻʽÿ�.
//
extern "C" __declspec() void SendLightMessage(CLightCtrlComm& m_LightCtrl,int nLightChannel,int LightEventFlag ,int nLightOnOff, int nLightLevel);
extern "C" __declspec() void LightAutoTest(int nLightAutoTestChannel, int nLightAutoTestSpeed,int nLightAuoTestCount,CLightCtrlComm& m_LightCtrl);

class CLightControlApp : public CWinApp
{
public:
	CLightControlApp();
	

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
	
};
