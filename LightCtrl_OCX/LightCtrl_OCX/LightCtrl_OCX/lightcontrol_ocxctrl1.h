#pragma once

// ��ǻ�Ϳ��� Microsoft Visual C++�� ����Ͽ� ������ IDispatch ���� Ŭ�����Դϴ�.

// ����: �� ������ ������ �������� ���ʽÿ�. Microsoft Visual C++����
//  �� Ŭ������ �ٽ� ������ �� ������ ������ ����ϴ�.

/////////////////////////////////////////////////////////////////////////////
// CLightcontrol_ocxctrl1 ���� Ŭ�����Դϴ�.

class CLightcontrol_ocxctrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CLightcontrol_ocxctrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xD3DA0BCF, 0x2F14, 0x4D39, { 0x97, 0x34, 0xAB, 0x1, 0x51, 0xF9, 0x35, 0x8A } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Ư���Դϴ�.
public:


// �۾��Դϴ�.
public:

// _DLightControl_ocx

// Functions
//

	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long PortOpen(int portNum)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, portNum);
		return result;
	}
	void PortClose()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long GetConnected()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void SendLightMessage(long nLightChannel, long LightEventFlag, long nLightOnOff, long nLightLevel)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nLightChannel, LightEventFlag, nLightOnOff, nLightLevel);
	}
	void LightAutoTest(long nLightAutoTestChannel, long nLightAutoTestSpeed, long nLightAuoTestCount)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nLightAutoTestChannel, nLightAutoTestSpeed, nLightAuoTestCount);
	}

// Properties
//



};
