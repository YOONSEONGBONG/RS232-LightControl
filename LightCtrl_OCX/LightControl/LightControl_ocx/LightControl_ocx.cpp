// LightControl_ocx.cpp : CLightControl_ocxApp �� DLL ����� �����Դϴ�.

#include "stdafx.h"
#include "LightControl_ocx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CLightControl_ocxApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x76B98E19, 0xF820, 0x4C65, { 0x93, 0xA2, 0x14, 0x7E, 0x6E, 0x31, 0xC6, 0x6D } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CLightControl_ocxApp::InitInstance - DLL �ʱ�ȭ�Դϴ�.

BOOL CLightControl_ocxApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: ���⿡ ���� �ۼ��� ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	}

	return bInit;
}



// CLightControl_ocxApp::ExitInstance - DLL �����Դϴ�.

int CLightControl_ocxApp::ExitInstance()
{
	// TODO: ���⿡ ���� �ۼ��� ��� ���� �ڵ带 �߰��մϴ�.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - �ý��� ������Ʈ���� �׸��� �߰��մϴ�.

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �ý��� ������Ʈ������ �׸��� �����մϴ�.

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
