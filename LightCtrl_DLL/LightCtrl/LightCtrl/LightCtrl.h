
// LightCtrl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLightCtrlApp:
// �� Ŭ������ ������ ���ؼ��� LightCtrl.cpp�� �����Ͻʽÿ�.
//

class CLightCtrlApp : public CWinAppEx
{
public:
	CLightCtrlApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLightCtrlApp theApp;