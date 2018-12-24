// LightControl_ocx.cpp : CLightControl_ocxApp 및 DLL 등록의 구현입니다.

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



// CLightControl_ocxApp::InitInstance - DLL 초기화입니다.

BOOL CLightControl_ocxApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 여기에 직접 작성한 모듈 초기화 코드를 추가합니다.
	}

	return bInit;
}



// CLightControl_ocxApp::ExitInstance - DLL 종료입니다.

int CLightControl_ocxApp::ExitInstance()
{
	// TODO: 여기에 직접 작성한 모듈 종료 코드를 추가합니다.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 시스템 레지스트리에 항목을 추가합니다.

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 시스템 레지스트리에서 항목을 제거합니다.

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
