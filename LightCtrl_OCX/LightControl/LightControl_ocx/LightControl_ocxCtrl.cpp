// LightControl_ocxCtrl.cpp : CLightControl_ocxCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "LightControl_ocx.h"
#include "LightControl_ocxCtrl.h"
#include "LightControl_ocxPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CLightControl_ocxCtrl, COleControl)



// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CLightControl_ocxCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// ����ġ ���Դϴ�.

BEGIN_DISPATCH_MAP(CLightControl_ocxCtrl, COleControl)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "PortOpen", dispidOpen, PortOpen, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "PortClose", dispidClose, PortClose, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "GetConnected", dispidGetConnected, GetConnected, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "SendLightMessage", dispidSendLightMessage, SendLightMessage, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CLightControl_ocxCtrl, "LightAutoTest", dispidLightAutoTest, LightAutoTest, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4)	
END_DISPATCH_MAP()



// �̺�Ʈ ���Դϴ�.

BEGIN_EVENT_MAP(CLightControl_ocxCtrl, COleControl)
END_EVENT_MAP()



// �Ӽ� �������Դϴ�.

// TODO: �ʿ信 ���� �Ӽ� �������� �߰��մϴ�. ī��Ʈ�� �̿� ���� �����ؾ� �մϴ�.
BEGIN_PROPPAGEIDS(CLightControl_ocxCtrl, 1)
	PROPPAGEID(CLightControl_ocxPropPage::guid)
END_PROPPAGEIDS(CLightControl_ocxCtrl)



// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CLightControl_ocxCtrl, "LIGHTCONTROL_OCX.LightControl_ocxCtrl.1",
	0xd3da0bcf, 0x2f14, 0x4d39, 0x97, 0x34, 0xab, 0x1, 0x51, 0xf9, 0x35, 0x8a)



// ���� ���̺귯�� ID�� �����Դϴ�.

IMPLEMENT_OLETYPELIB(CLightControl_ocxCtrl, _tlid, _wVerMajor, _wVerMinor)



// �������̽� ID�Դϴ�.

const IID BASED_CODE IID_DLightControl_ocx =
		{ 0x9566B873, 0xB2F4, 0x4E89, { 0xAC, 0x4E, 0xC5, 0x19, 0xD2, 0x37, 0x56, 0xB } };
const IID BASED_CODE IID_DLightControl_ocxEvents =
		{ 0xE5F440A7, 0x5DB, 0x4AF2, { 0xAE, 0x96, 0x86, 0x7, 0x5, 0x5A, 0x34, 0x68 } };



// ��Ʈ�� ���� �����Դϴ�.

static const DWORD BASED_CODE _dwLightControl_ocxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLightControl_ocxCtrl, IDS_LIGHTCONTROL_OCX, _dwLightControl_ocxOleMisc)



// CLightControl_ocxCtrl::CLightControl_ocxCtrlFactory::UpdateRegistry -
// CLightControl_ocxCtrl���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CLightControl_ocxCtrl::CLightControl_ocxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��Ʈ���� ����Ʈ �� ������ ��Ģ�� �ؼ��ϴ���
	// Ȯ���մϴ�. �ڼ��� ������ MFC Technical Note 64��
	// �����Ͻʽÿ�. ��Ʈ���� ����Ʈ �� ��Ģ��
	// ���� �ʴ� ��� �������� ���� ��° �Ű� ������ �����մϴ�.
	// afxRegApartmentThreading�� 0���� �����մϴ�.

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



// CLightControl_ocxCtrl::CLightControl_ocxCtrl - �������Դϴ�.

CLightControl_ocxCtrl::CLightControl_ocxCtrl()
{
	InitializeIIDs(&IID_DLightControl_ocx, &IID_DLightControl_ocxEvents);
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �ʱ�ȭ�մϴ�.
}



// CLightControl_ocxCtrl::~CLightControl_ocxCtrl - �Ҹ����Դϴ�.

CLightControl_ocxCtrl::~CLightControl_ocxCtrl()
{
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �����մϴ�.
}



// CLightControl_ocxCtrl::OnDraw - �׸��� �Լ��Դϴ�.

void CLightControl_ocxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: ���� �ڵ带 ����ڰ� ���� �ۼ��� �׸��� �ڵ�� �ٲٽʽÿ�.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CLightControl_ocxCtrl::DoPropExchange - ���Ӽ� �����Դϴ�.

void CLightControl_ocxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: �������� ����� ���� �Ӽ� ��ο� ���� PX_ functions�� ȣ���մϴ�.
}



// CLightControl_ocxCtrl::OnResetState - ��Ʈ���� �⺻ ���·� �ٽ� �����մϴ�.

void CLightControl_ocxCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange�� ��� �ִ� �⺻���� �ٽ� �����մϴ�.

	// TODO: ���⿡�� �ٸ� ��� ��Ʈ���� ���¸� �ٽ� �����մϴ�.
}



// CLightControl_ocxCtrl::AboutBox - "����" ��ȭ ���ڸ� ����ڿ��� ���� �ݴϴ�.

void CLightControl_ocxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_LIGHTCONTROL_OCX);
	dlgAbout.DoModal();
}
// CLightControl_ocxCtrl �޽��� ó�����Դϴ�.

LONG CLightControl_ocxCtrl::PortOpen(LONG portNum)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: ���⿡ ����ġ ó���⸦ �߰��մϴ�.
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
				strLog.Format(_T("[SYSTEM] %s ��Ʈ ���� ����!"), strPort);
				
			}
			else
			{
				nConnected_Flag = 0;
				strLog.Format(_T("[ERROR] %s ��Ʈ ���� ����!"), strPort);
				
			}
		}
		else
		{
			nConnected_Flag = 0;
			strLog.Format(_T("[ERROR] %s ��Ʈ ���� ����!"), strPort);
			
		}
		char* title = "LightCtrlOCX";	// ���ο� Ÿ��Ʋ ���� 
		AfxGetApp()->m_pszAppName = title;	// ���ο� Ÿ��Ʋ ���� 
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
	// TODO: ���⿡ ����ġ ó���⸦ �߰��մϴ�.
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

	// TODO: ���⿡ ����ġ ó���⸦ �߰��մϴ�.
	CString strCmd;
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

void CLightControl_ocxCtrl::LightAutoTest(LONG nLightAutoTestChannel, LONG nLightAutoTestSpeed, LONG nLightAuoTestCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: ���⿡ ����ġ ó���⸦ �߰��մϴ�.
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
	AfxMessageBox(_T("Test �Ϸ�!"));
}


