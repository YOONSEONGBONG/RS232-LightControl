// LightControl_ocxCtrl.cpp : CLightControl_ocxCtrl ActiveX 컨트롤 클래스의 구현입니다.

#include "stdafx.h"
#include "LightControl_ocx.h"
#include "LightControl_ocxCtrl.h"
#include "LightControl_ocxPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CLightControl_ocxCtrl, COleControl)



// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CLightControl_ocxCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// 디스패치 맵입니다.

BEGIN_DISPATCH_MAP(CLightControl_ocxCtrl, COleControl)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "PortOpen", dispidOpen, PortOpen, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "PortClose", dispidClose, PortClose, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "GetConnected", dispidGetConnected, GetConnected, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "SendLightMessage", dispidSendLightMessage, SendLightMessage, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "LightAutoTest", dispidLightAutoTest, LightAutoTest, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4)	
END_DISPATCH_MAP()



// 이벤트 맵입니다.

BEGIN_EVENT_MAP(CLightControl_ocxCtrl, COleControl)
END_EVENT_MAP()



// 속성 페이지입니다.

// TODO: 필요에 따라 속성 페이지를 추가합니다. 카운트도 이에 따라 증가해야 합니다.
BEGIN_PROPPAGEIDS(CLightControl_ocxCtrl, 1)
	PROPPAGEID(CLightControl_ocxPropPage::guid)
END_PROPPAGEIDS(CLightControl_ocxCtrl)



// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CLightControl_ocxCtrl, "LIGHTCONTROL_OCX.LightControl_ocxCtrl.1",
	0xd3da0bcf, 0x2f14, 0x4d39, 0x97, 0x34, 0xab, 0x1, 0x51, 0xf9, 0x35, 0x8a)



// 형식 라이브러리 ID와 버전입니다.

IMPLEMENT_OLETYPELIB(CLightControl_ocxCtrl, _tlid, _wVerMajor, _wVerMinor)



// 인터페이스 ID입니다.

const IID BASED_CODE IID_DLightControl_ocx =
		{ 0x9566B873, 0xB2F4, 0x4E89, { 0xAC, 0x4E, 0xC5, 0x19, 0xD2, 0x37, 0x56, 0xB } };
const IID BASED_CODE IID_DLightControl_ocxEvents =
		{ 0xE5F440A7, 0x5DB, 0x4AF2, { 0xAE, 0x96, 0x86, 0x7, 0x5, 0x5A, 0x34, 0x68 } };



// 컨트롤 형식 정보입니다.

static const DWORD BASED_CODE _dwLightControl_ocxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLightControl_ocxCtrl, IDS_LIGHTCONTROL_OCX, _dwLightControl_ocxOleMisc)



// CLightControl_ocxCtrl::CLightControl_ocxCtrlFactory::UpdateRegistry -
// CLightControl_ocxCtrl에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CLightControl_ocxCtrl::CLightControl_ocxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 컨트롤이 아파트 모델 스레딩 규칙을 준수하는지
	// 확인합니다. 자세한 내용은 MFC Technical Note 64를
	// 참조하십시오. 컨트롤이 아파트 모델 규칙에
	// 맞지 않는 경우 다음에서 여섯 번째 매개 변수를 변경합니다.
	// afxRegApartmentThreading을 0으로 설정합니다.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LIGHTCONTROL_OCX,
			IDB_LIGHTCONTROL_OCX,
			afxRegApartmentThreading,
			_dwLightControl_ocxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CLightControl_ocxCtrl::CLightControl_ocxCtrl - 생성자입니다.

CLightControl_ocxCtrl::CLightControl_ocxCtrl()
{
	InitializeIIDs(&IID_DLightControl_ocx, &IID_DLightControl_ocxEvents);
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 초기화합니다.
}



// CLightControl_ocxCtrl::~CLightControl_ocxCtrl - 소멸자입니다.

CLightControl_ocxCtrl::~CLightControl_ocxCtrl()
{
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 정리합니다.
}



// CLightControl_ocxCtrl::OnDraw - 그리기 함수입니다.

void CLightControl_ocxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 다음 코드를 사용자가 직접 작성한 그리기 코드로 바꾸십시오.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CLightControl_ocxCtrl::DoPropExchange - 지속성 지원입니다.

void CLightControl_ocxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 지속적인 사용자 지정 속성 모두에 대해 PX_ functions를 호출합니다.
}



// CLightControl_ocxCtrl::OnResetState - 컨트롤을 기본 상태로 다시 설정합니다.

void CLightControl_ocxCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange에 들어 있는 기본값을 다시 설정합니다.

	// TODO: 여기에서 다른 모든 컨트롤의 상태를 다시 설정합니다.
}



// CLightControl_ocxCtrl::AboutBox - "정보" 대화 상자를 사용자에게 보여 줍니다.

void CLightControl_ocxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_LIGHTCONTROL_OCX);
	dlgAbout.DoModal();
}
// CLightControl_ocxCtrl 메시지 처리기입니다.

LONG CLightControl_ocxCtrl::PortOpen(LONG portNum)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 여기에 디스패치 처리기를 추가합니다.
		LONG nConnected_Flag;	
		CString strLog; 	
		strPort.Format(_T("COM%d"),portNum);
		
		if(m_LightCtrl.Open(strPort))
		{
			m_LightCtrl.m_hwnd = this->m_hWnd;
			LONG nChannel = 1;
			LONG nLightEventFlag = 3;
			LONG nOnOff = 1;
			LONG nLevel = 0;
			SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel);
			Sleep(100);

			if (m_LightCtrl.strReceiveData.Left(1)==_T("")) 
			{
				nConnected_Flag = 1;
				strLog.Format(_T("[SYSTEM] %s 포트 접속 성공!"), strPort);
				
			}
			else
			{
				nConnected_Flag = 0;
				strLog.Format(_T("[ERROR] %s 포트 접속 실패!"), strPort);
				
			}
		}
		else
		{
			nConnected_Flag = 0;
			strLog.Format(_T("[ERROR] %s 포트 접속 실패!"), strPort);
			
		}
		char* title = "LightCtrlOCX";	// 새로운 타이틀 설정 
		AfxGetApp()->m_pszAppName = title;	// 새로운 타이틀 적용 
		AfxMessageBox(strLog);
	return nConnected_Flag;
}


void CLightControl_ocxCtrl::PortClose(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_LightCtrl.Close();
}

LONG CLightControl_ocxCtrl::GetConnected(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONG result;
	// TODO: 여기에 디스패치 처리기를 추가합니다.
	if(m_LightCtrl.GetConnected()==true)
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return result;
}



void CLightControl_ocxCtrl::SendLightMessage(LONG nLightChannel, LONG LightEventFlag, LONG nLightOnOff, LONG nLightLevel)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 여기에 디스패치 처리기를 추가합니다.
	CString strCmd;
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

void CLightControl_ocxCtrl::LightAutoTest(LONG nLightAutoTestChannel, LONG nLightAutoTestSpeed, LONG nLightAuoTestCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 여기에 디스패치 처리기를 추가합니다.
	int nLightEventFlag = 0;
	/*while (nLightAuoTestCount>0)
	{	
		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,0);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,50);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,100);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,255);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,100);
		Sleep(nLightAutoTestSpeed);

		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,50);
		Sleep(nLightAutoTestSpeed);	

		SendLightMessage(nLightAutoTestChannel,nLightEventFlag,1,0);
		Sleep(nLightAutoTestSpeed);
		nLightAuoTestCount--;
	}*/
	AfxMessageBox(_T("Test 완료!"));
}


