
// LightCtrl_OCX.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLightCtrl_OCXApp:
// �� Ŭ������ ������ ���ؼ��� LightCtrl_OCX.cpp�� �����Ͻʽÿ�.
//

class CLightCtrl_OCXApp : public CWinAppEx
{
public:
	CLightCtrl_OCXApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLightCtrl_OCXApp theApp;