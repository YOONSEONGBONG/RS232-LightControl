#pragma once

// LightControl_ocxPropPage.h : CLightControl_ocxPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.


// CLightControl_ocxPropPage : ������ ������ LightControl_ocxPropPage.cpp��(��) �����Ͻʽÿ�.

class CLightControl_ocxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLightControl_ocxPropPage)
	DECLARE_OLECREATE_EX(CLightControl_ocxPropPage)

// �������Դϴ�.
public:
	CLightControl_ocxPropPage();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPPAGE_LIGHTCONTROL_OCX };

// �����Դϴ�.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �޽��� ���Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

