// LightControl_ocxPropPage.cpp : CLightControl_ocxPropPage 속성 페이지 클래스의 구현입니다.

#include "stdafx.h"
#include "LightControl_ocx.h"
#include "LightControl_ocxPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CLightControl_ocxPropPage, COlePropertyPage)



// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CLightControl_ocxPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CLightControl_ocxPropPage, "LIGHTCONTROL_O.LightControl_oPropPage.1",
	0xa5fe37ce, 0x84c8, 0x459c, 0xb3, 0xde, 0x7c, 0x6a, 0x40, 0xa3, 0x9a, 0x34)



// CLightControl_ocxPropPage::CLightControl_ocxPropPageFactory::UpdateRegistry -
// CLightControl_ocxPropPage에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CLightControl_ocxPropPage::CLightControl_ocxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LIGHTCONTROL_OCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CLightControl_ocxPropPage::CLightControl_ocxPropPage - 생성자입니다.

CLightControl_ocxPropPage::CLightControl_ocxPropPage() :
	COlePropertyPage(IDD, IDS_LIGHTCONTROL_OCX_PPG_CAPTION)
{
}



// CLightControl_ocxPropPage::DoDataExchange - 페이지와 속성 사이에서 데이터를 이동시킵니다.

void CLightControl_ocxPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CLightControl_ocxPropPage 메시지 처리기입니다.
