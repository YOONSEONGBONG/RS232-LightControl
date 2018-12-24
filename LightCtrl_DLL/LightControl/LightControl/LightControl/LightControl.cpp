// LightControl.cpp : 해당 DLL의 초기화 루틴을 정의합니다.
//

#include "stdafx.h"
#include "LightControl.h"
#include "LightComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//
//TODO: 이 DLL이 MFC DLL에 대해 동적으로 링크되어 있는 경우
//		MFC로 호출되는 이 DLL에서 내보내지는 모든 함수의
//		시작 부분에 AFX_MANAGE_STATE 매크로가
//		들어 있어야 합니다.
//
//		예:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 일반적인 함수 본문은 여기에 옵니다.
//		}
//
//		이 매크로는 MFC로 호출하기 전에
//		각 함수에 반드시 들어 있어야 합니다.
//		즉, 매크로는 함수의 첫 번째 문이어야 하며 
//		개체 변수의 생성자가 MFC DLL로
//		호출할 수 있으므로 개체 변수가 선언되기 전에
//		나와야 합니다.
//
//		자세한 내용은
//		MFC Technical Note 33 및 58을 참조하십시오.
//

// CLightControlApp

BEGIN_MESSAGE_MAP(CLightControlApp, CWinApp)
END_MESSAGE_MAP()


// CLightControlApp 생성

CLightControlApp::CLightControlApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CLightControlApp 개체입니다.

CLightControlApp theApp;


// CLightControlApp 초기화

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
			// PC -> CONTROLLER : [STX] [채널 %02d] [WR] [레벨 %03d] [ETX]
			strCmd.Format(_T("%c%02dWR%03d%c"), 0x02, nLightChannel, nLightLevel, 0x03); 
			m_LightCtrl.WriteString(strCmd);
			break;

		case 1:
			// PC -> CONTROLLER : [STX] [채널 %02d] [SV] [ETX]
			strCmd.Format(_T("%c%02dSV%c"), 0x02, nLightChannel, 0x03); 
			m_LightCtrl.WriteString(strCmd); 
			break;

		case 2:
			// PC -> CONTROLLER : [STX] [채널 %02d] [ON] [온/오프 %01d] [ETX]
			strCmd.Format(_T("%c%02dON%d%c"), 0x02, nLightChannel, nLightOnOff, 0x03); 
			m_LightCtrl.WriteString(strCmd); 
			break;
			
		case 3:
			// PC -> CONTROLLER : [STX] [채널 %02d] [RD] [ETX]
			// CONTROLLER -> PC : [STX] [채널 %02d] [WR] [온/오프 %01d] [레벨 %02d] [ETX]
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
	AfxMessageBox(_T("Test 완료!"));
}




