// LightControl_ocxPropPage.cpp : CLightControl_ocxPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "LightControl_ocx.h"
#include "LightControl_ocxPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CLightControl_ocxPropPage, COlePropertyPage)



// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CLightControl_ocxPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CLightControl_ocxPropPage, "LIGHTCONTROL_O.LightControl_oPropPage.1",
	0xa5fe37ce, 0x84c8, 0x459c, 0xb3, 0xde, 0x7c, 0x6a, 0x40, 0xa3, 0x9a, 0x34)



// CLightControl_ocxPropPage::CLightControl_ocxPropPageFactory::UpdateRegistry -
// CLightControl_ocxPropPage���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CLightControl_ocxPropPage::CLightControl_ocxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LIGHTCONTROL_OCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CLightControl_ocxPropPage::CLightControl_ocxPropPage - �������Դϴ�.

CLightControl_ocxPropPage::CLightControl_ocxPropPage() :
	COlePropertyPage(IDD, IDS_LIGHTCONTROL_OCX_PPG_CAPTION)
{
}



// CLightControl_ocxPropPage::DoDataExchange - �������� �Ӽ� ���̿��� �����͸� �̵���ŵ�ϴ�.

void CLightControl_ocxPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CLightControl_ocxPropPage �޽��� ó�����Դϴ�.
