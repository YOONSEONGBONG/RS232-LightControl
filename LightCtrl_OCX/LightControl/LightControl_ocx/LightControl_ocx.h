#pragma once

// LightControl_ocx.h : LightControl_ocx.DLL�� �⺻ ��� �����Դϴ�.

#if !defined( __AFXCTL_H__ )
#error "�� ������ �����ϱ� ���� 'afxctl.h'�� �����Ͻʽÿ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLightControl_ocxApp : ������ ������ LightControl_ocx.cpp�� �����Ͻʽÿ�.

class CLightControl_ocxApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

