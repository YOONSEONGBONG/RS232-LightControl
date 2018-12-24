#pragma once

// LightControl_ocxPropPage.h : CLightControl_ocxPropPage 속성 페이지 클래스의 선언입니다.


// CLightControl_ocxPropPage : 구현을 보려면 LightControl_ocxPropPage.cpp을(를) 참조하십시오.

class CLightControl_ocxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLightControl_ocxPropPage)
	DECLARE_OLECREATE_EX(CLightControl_ocxPropPage)

// 생성자입니다.
public:
	CLightControl_ocxPropPage();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROPPAGE_LIGHTCONTROL_OCX };

// 구현입니다.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 메시지 맵입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

