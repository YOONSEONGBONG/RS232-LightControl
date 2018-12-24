// LightControl.cpp : �ش� DLL�� �ʱ�ȭ ��ƾ�� �����մϴ�.
//

#include "stdafx.h"
#include "LightControl.h"
#include "LightComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//
//TODO: �� DLL�� MFC DLL�� ���� �������� ��ũ�Ǿ� �ִ� ���
//		MFC�� ȣ��Ǵ� �� DLL���� ���������� ��� �Լ���
//		���� �κп� AFX_MANAGE_STATE ��ũ�ΰ�
//		��� �־�� �մϴ�.
//
//		��:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �Ϲ����� �Լ� ������ ���⿡ �ɴϴ�.
//		}
//
//		�� ��ũ�δ� MFC�� ȣ���ϱ� ����
//		�� �Լ��� �ݵ�� ��� �־�� �մϴ�.
//		��, ��ũ�δ� �Լ��� ù ��° ���̾�� �ϸ� 
//		��ü ������ �����ڰ� MFC DLL��
//		ȣ���� �� �����Ƿ� ��ü ������ ����Ǳ� ����
//		���;� �մϴ�.
//
//		�ڼ��� ������
//		MFC Technical Note 33 �� 58�� �����Ͻʽÿ�.
//

// CLightControlApp

BEGIN_MESSAGE_MAP(CLightControlApp, CWinApp)
END_MESSAGE_MAP()


// CLightControlApp ����

CLightControlApp::CLightControlApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CLightControlApp ��ü�Դϴ�.

CLightControlApp theApp;


// CLightControlApp �ʱ�ȭ

BOOL CLightControlApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


extern "C" __declspec() void SendLightMessage(CLightCtrlComm& m_LightCtrl,int nLightChannel,int LightEventFlag ,int nLightOnOff, int nLightLevel)
{	
	CString strCmd(_T(""));
	switch(LightEventFlag)
	{
			
		case 0:
			// PC -> CONTROLLER : [STX] [ä�� %02d] [WR] [���� %03d] [ETX]
			strCmd.Format(_T("%c%02dWR%03d%c"), 0x02, nLightChannel, nLightLevel, 0x03); 
			m_LightCtrl.WriteString(strCmd);
			break;

		case 1:
			// PC -> CONTROLLER : [STX] [ä�� %02d] [SV] [ETX]
			strCmd.Format(_T("%c%02dSV%c"), 0x02, nLightChannel, 0x03); 
			m_LightCtrl.WriteString(strCmd); 
			break;

		case 2:
			// PC -> CONTROLLER : [STX] [ä�� %02d] [ON] [��/���� %01d] [ETX]
			strCmd.Format(_T("%c%02dON%d%c"), 0x02, nLightChannel, nLightOnOff, 0x03); 
			m_LightCtrl.WriteString(strCmd); 
			break;
			
		case 3:
			// PC -> CONTROLLER : [STX] [ä�� %02d] [RD] [ETX]
			// CONTROLLER -> PC : [STX] [ä�� %02d] [WR] [��/���� %01d] [���� %02d] [ETX]
			strCmd.Format(_T("%c%02dRD%c"), 0x02, nLightChannel, 0x03); 
			m_LightCtrl.WriteString(strCmd);
			break;
	}
}
extern "C" __declspec() void LightAutoTest(int nLightAutoTestChannel, int nLightAutoTestSpeed,int nLightAuoTestCount,CLightCtrlComm& m_LightCtrl)
{	
	int LightEventFlag = 0;
	while (nLightAuoTestCount>0)
	{	
		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,0);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,50);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,100);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,255);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,100);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,50);
		Sleep(nLightAutoTestSpeed);	

		SendLightMessage(m_LightCtrl,nLightAutoTestChannel,LightEventFlag,1,0);
		Sleep(nLightAutoTestSpeed);
		nLightAuoTestCount--;
	}
	AfxMessageBox(_T("Test �Ϸ�!"));
}




