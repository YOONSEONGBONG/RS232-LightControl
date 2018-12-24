
// LightCtrl_OCXDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "LightCtrl_OCX.h"
#include "LightCtrl_OCXDlg.h"
#include <fstream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLightCtrl_OCXDlg ��ȭ ����




CLightCtrl_OCXDlg::CLightCtrl_OCXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLightCtrl_OCXDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLightCtrl_OCXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSliderCh1);
	DDX_Control(pDX, IDC_SLIDER2, m_ctrlSliderCh2);
	DDX_Control(pDX, IDC_SLIDER3, m_ctrlSliderCh3);
	DDX_Control(pDX, IDC_SLIDER4, m_ctrlSliderCh4);
	DDX_Control(pDX, IDC_SLIDER5, m_ctrlSliderCh5);
	DDX_Control(pDX, IDC_SLIDER6, m_ctrlSliderCh6);
	DDX_Control(pDX, IDC_ONOFF, m_ctrlOnOff);
	DDX_Control(pDX, IDC_CONNECT, m_ctrlConnect);
	DDX_Control(pDX, IDC_DISCONNECT, m_ctrlDisconnect);
	DDX_Control(pDX, IDC_EDIT_LEVEl_CH1, m_Ch1_Level);
	DDX_Control(pDX, IDC_EDIT_LEVEl_CH2, m_Ch2_Level);
	DDX_Control(pDX, IDC_EDIT_LEVEl_CH3, m_Ch3_Level);
	DDX_Control(pDX, IDC_EDIT_LEVEl_CH4, m_Ch4_Level);
	DDX_Control(pDX, IDC_EDIT_LEVEl_CH5, m_Ch5_Level);
	DDX_Control(pDX, IDC_EDIT_LEVEl_CH6, m_Ch6_Level);
	DDX_Control(pDX, IDC_AUTOTEST_CHANNEL, m_ctrlAutoTestChannel);
	DDX_Control(pDX, IDC_AUTOTEST_SPEED, m_ctrlAutoTestSpeed);
	DDX_Control(pDX, IDC_AUTOTEST_Count, m_ctrlAutoTestCount);
	DDX_Control(pDX, IDC_AUTOTEST, m_ctrlAutoTest);
	DDX_Control(pDX, IDC_SAVE, m_ctrlSave);
	DDX_Control(pDX, IDC_WRITE_INIT, m_ctrlWriteInit);

	DDX_Control(pDX, IDC_LIGHTCONTROL_OCXCTRL1, m_LightCtrlOCX);
}

BEGIN_MESSAGE_MAP(CLightCtrl_OCXDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AUTOTEST, &CLightCtrl_OCXDlg::OnBnClickedAutotest)
	ON_BN_CLICKED(IDC_SAVE, OnBtnSave)
	ON_BN_CLICKED(IDC_CONNECT, OnChkConnect)	
	ON_BN_CLICKED(IDC_DISCONNECT, OnChkDisconnect)
	ON_BN_CLICKED(IDC_ONOFF, OnChkOnoff)
	ON_BN_CLICKED(IDC_WRITE_INIT, OnWriteInit)
//	ON_MESSAGE(WM_RECEIVEDATA, OnReceiveData)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CLightCtrl_OCXDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CLightCtrl_OCXDlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CLightCtrl_OCXDlg::OnNMCustomdrawSlider3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &CLightCtrl_OCXDlg::OnNMCustomdrawSlider4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER5, &CLightCtrl_OCXDlg::OnNMCustomdrawSlider5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER6, &CLightCtrl_OCXDlg::OnNMCustomdrawSlider6)
	ON_EN_CHANGE(IDC_EDIT_LEVEl_CH1, &CLightCtrl_OCXDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT_LEVEl_CH2, &CLightCtrl_OCXDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT_LEVEl_CH3, &CLightCtrl_OCXDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT_LEVEl_CH4, &CLightCtrl_OCXDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT_LEVEl_CH5, &CLightCtrl_OCXDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT_LEVEl_CH6, &CLightCtrl_OCXDlg::OnEnChangeEdit6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CLightCtrl_OCXDlg �޽��� ó����

BOOL CLightCtrl_OCXDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	OnChkConnect();
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CLightCtrl_OCXDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CLightCtrl_OCXDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CLightCtrl_OCXDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLightCtrl_OCXDlg::CheckLightConnected()
{
	if(nConnect_Flag ==TRUE)
	{
		m_ctrlConnect.SetCheck(TRUE); 
		m_ctrlConnect.EnableWindow(FALSE); 
		m_ctrlDisconnect.SetCheck(FALSE); 
		m_ctrlDisconnect.EnableWindow(TRUE);

		m_ctrlAutoTestChannel.EnableWindow(TRUE);
		m_ctrlAutoTestSpeed.EnableWindow(TRUE);
		m_ctrlAutoTestCount.EnableWindow(TRUE);
		m_ctrlAutoTest.EnableWindow(TRUE);
		m_ctrlSave.EnableWindow(TRUE);
		m_ctrlOnOff.EnableWindow(TRUE);
		m_ctrlSliderCh1.EnableWindow(TRUE);
		m_ctrlSliderCh2.EnableWindow(TRUE);
		m_ctrlSliderCh3.EnableWindow(TRUE);
		m_ctrlSliderCh4.EnableWindow(TRUE);
		m_ctrlSliderCh5.EnableWindow(TRUE);
		m_ctrlSliderCh6.EnableWindow(TRUE);
		m_Ch1_Level.EnableWindow(TRUE);
		m_Ch2_Level.EnableWindow(TRUE);
		m_Ch3_Level.EnableWindow(TRUE);
		m_Ch4_Level.EnableWindow(TRUE);
		m_Ch5_Level.EnableWindow(TRUE);
		m_Ch6_Level.EnableWindow(TRUE);
		m_ctrlWriteInit.EnableWindow(TRUE);

		m_ctrlOnOff.SetCheck(1);
		m_ctrlAutoTestChannel.SetCurSel(0);
		m_ctrlAutoTestCount.SetCurSel(0);
		m_ctrlAutoTestSpeed.SetCurSel(0);

		m_ctrlSliderCh1.SetRange(0,255);
		m_ctrlSliderCh1.SetTicFreq(10);
		m_ctrlSliderCh2.SetRange(0,255);
		m_ctrlSliderCh2.SetTicFreq(10);
		m_ctrlSliderCh3.SetRange(0,255);
		m_ctrlSliderCh3.SetTicFreq(10);
		m_ctrlSliderCh4.SetRange(0,255);
		m_ctrlSliderCh4.SetTicFreq(10);
		m_ctrlSliderCh5.SetRange(0,255);
		m_ctrlSliderCh5.SetTicFreq(10);
		m_ctrlSliderCh6.SetRange(0,255);
		m_ctrlSliderCh6.SetTicFreq(10);

		OnChkOnoff();		
		loadFile();

		SetDlgItemInt(IDC_EDIT_LEVEl_CH1, nLevel[0]);
		SetDlgItemInt(IDC_EDIT_LEVEl_CH2, nLevel[1]);
		SetDlgItemInt(IDC_EDIT_LEVEl_CH3, nLevel[2]);
		SetDlgItemInt(IDC_EDIT_LEVEl_CH4, nLevel[3]);
		SetDlgItemInt(IDC_EDIT_LEVEl_CH5, nLevel[4]);
		SetDlgItemInt(IDC_EDIT_LEVEl_CH6, nLevel[5]);


		m_ctrlSliderCh1.SetPos(nLevel[0]);	
		m_ctrlSliderCh2.SetPos(nLevel[1]);
		m_ctrlSliderCh3.SetPos(nLevel[2]);
		m_ctrlSliderCh4.SetPos(nLevel[3]);
		m_ctrlSliderCh5.SetPos(nLevel[4]);	
		m_ctrlSliderCh6.SetPos(nLevel[5]);

	}
	else
	{
		m_ctrlDisconnect.SetCheck(TRUE); 
		m_ctrlDisconnect.EnableWindow(FALSE); 
		m_ctrlConnect.SetCheck(FALSE); 
		m_ctrlConnect.EnableWindow(TRUE);

		m_ctrlAutoTestChannel.EnableWindow(FALSE);
		m_ctrlAutoTestSpeed.EnableWindow(FALSE);
		m_ctrlAutoTestCount.EnableWindow(FALSE);
		m_ctrlAutoTest.EnableWindow(FALSE);
		m_ctrlSave.EnableWindow(FALSE);
		m_ctrlOnOff.EnableWindow(FALSE);
		m_ctrlSliderCh1.EnableWindow(FALSE);
		m_ctrlSliderCh2.EnableWindow(FALSE);
		m_ctrlSliderCh3.EnableWindow(FALSE);
		m_ctrlSliderCh4.EnableWindow(FALSE);
		m_ctrlSliderCh5.EnableWindow(FALSE);
		m_ctrlSliderCh6.EnableWindow(FALSE);
		m_Ch1_Level.EnableWindow(FALSE);
		m_Ch2_Level.EnableWindow(FALSE);
		m_Ch3_Level.EnableWindow(FALSE);
		m_Ch4_Level.EnableWindow(FALSE);
		m_Ch5_Level.EnableWindow(FALSE);
		m_Ch6_Level.EnableWindow(FALSE);
		m_ctrlWriteInit.EnableWindow(FALSE);	
	}
}
void CLightCtrl_OCXDlg::OnBnClickedAutotest()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSleepTime;
	int nCount = m_ctrlAutoTestCount.GetCurSel()+1;
	int testChannel = m_ctrlAutoTestChannel.GetCurSel()+1;
	
	switch(m_ctrlAutoTestSpeed.GetCurSel())
	{
		case 0:
			nSleepTime=300;
			break;
		case 1:
			nSleepTime=200;
			break;
		case 2:
			nSleepTime=150;
			break;
		case 3:
			nSleepTime=100;
			break;
		case 4:
			nSleepTime=50;
			break;
		case 5:
			nSleepTime=10;
			break;

	}
	if(nOnOff==TRUE)
	{	
		nLightEventFlag = 0;
		nOnOff = 1;
		m_LightCtrlOCX.LightAutoTest(testChannel,nSleepTime,nCount);
		m_LightCtrlOCX.SendLightMessage(testChannel,nLightEventFlag,nOnOff,nLevel[testChannel -1]);
	}
	else
	{
		AfxMessageBox(_T("[ERROR]:���� OFF�Դϴ�!"));
	}
	
}




void CLightCtrl_OCXDlg::OnBtnSave() 
{
	// TODO: Add your control notification handler code here	
	nLightEventFlag = 1;
	nOnOff = m_ctrlOnOff.GetCheck();
	for(int nCnt= 0;nCnt<MAX_CHANNEL;nCnt++)
	{
		nChannel = nCnt+1;
		nLevel[nCnt] =GetDlgItemInt(IDC_EDIT_LEVEl_CH1+nCnt);
		m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[nCnt]);
		
	}
	
	saveFile();
}

void CLightCtrl_OCXDlg::OnChkOnoff() 
{
	// TODO: Add your control notification handler code here
	// PC -> CONTROLLER : [STX] [ä�� %02d] [ON] [��/���� %01d] [ETX]
	 
	nLightEventFlag = 2;
	nOnOff = m_ctrlOnOff.GetCheck();
	for(int nCnt= 0;nCnt<MAX_CHANNEL;nCnt++)
	{
		nChannel = nCnt+1; 
		nLevel[nCnt] = GetDlgItemInt(IDC_EDIT_LEVEl_CH1+nCnt);  
		m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[nCnt]);
	}
	
}
//
//LRESULT CLightCtrl_OCXDlg:: OnReceiveData( WPARAM wParam, LPARAM lParam )
//{	
//	bIsStart = true;
//	
//	return TRUE; 
//}

void CLightCtrl_OCXDlg::OnChkConnect() 
{
	// TODO: Add your control notification handler code here
	 int portNum= 1;
	nConnect_Flag = m_LightCtrlOCX.PortOpen(portNum);
	CheckLightConnected();					
}

void CLightCtrl_OCXDlg::OnChkDisconnect() 
{
	// TODO: Add your control notification handler code here
	
	
	if(nConnect_Flag==TRUE)
	{		
		
		nOnOff = 0;
		for(int nCnt =0; nCnt<MAX_CHANNEL; nCnt++)
		{	
			nLightEventFlag = 0;
			nChannel = nCnt + 1;
			nLevel[nCnt]= 0;
			m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[nCnt]);

			nLightEventFlag = 2;
			m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[nCnt]);

		}
	
			m_LightCtrlOCX.PortClose();
			nConnect_Flag = FALSE;
	}
	CheckLightConnected();	
		 
}

BOOL CLightCtrl_OCXDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	OnChkDisconnect();
	DWORD dwExitCode;
	DWORD dwPID = GetCurrentProcessId();    // ���� �ڽ��� ���μ��� ID ��������.

	HANDLE hProcess = OpenProcess( PROCESS_ALL_ACCESS, 0, dwPID );    // ���μ��� �ڵ� ��������

	if( NULL != hProcess )
	{
		GetExitCodeProcess( hProcess, &dwExitCode );   // ���μ��� ������ �ڵ� ������
		TerminateProcess( hProcess, dwExitCode );    // ���μ��� ���� ����
		WaitForSingleObject( hProcess, INFINITE ); // ���� �ɶ����� ���
		CloseHandle( hProcess );                                 // ���μ��� �ڵ� �ݱ�
	}
	return CDialog::DestroyWindow();
}


void CLightCtrl_OCXDlg::OnWriteInit() 
{
	// TODO: Add your control notification handler code here 
	m_ctrlSliderCh1.SetPos(0);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH1,nLevel[0]);
	m_ctrlSliderCh2.SetPos(0);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH2,nLevel[1]);
	m_ctrlSliderCh3.SetPos(0);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH3,nLevel[2]);
	m_ctrlSliderCh4.SetPos(0);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH4,nLevel[3]);
	m_ctrlSliderCh5.SetPos(0);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH5,nLevel[4]);
	m_ctrlSliderCh6.SetPos(0);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH6,nLevel[5]);
	
	m_ctrlAutoTestChannel.SetCurSel(0);
	m_ctrlAutoTestCount.SetCurSel(0);
	m_ctrlAutoTestSpeed.SetCurSel(0); 

	nLightEventFlag = 0;
	nOnOff = 1;
	for(int nCnt = 0; nCnt < MAX_CHANNEL; nCnt++)
	{
		nChannel = nCnt + 1;
		nLevel[nCnt]= 0;
		m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[nCnt]);
		
	}
	/*m_ctrlOnOff.SetCheck(0);
	OnChkOnoff();*/
	saveFile();
}

void CLightCtrl_OCXDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[0] = m_ctrlSliderCh1.GetPos();
	nLightEventFlag =0;
	nOnOff = 1;
	nChannel =1;
	
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[0]);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH1,nLevel[0]);
	*pResult = 0;
}

void CLightCtrl_OCXDlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[1] = m_ctrlSliderCh2.GetPos();
	nLightEventFlag =0;
	nChannel =2;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[1]);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH2,nLevel[1]);
	*pResult = 0;
}

void CLightCtrl_OCXDlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[2] =m_ctrlSliderCh3.GetPos();
	nLightEventFlag =0;
	nChannel =3;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[2]);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH3,nLevel[2]);
	*pResult = 0;
}

void CLightCtrl_OCXDlg::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[3] =m_ctrlSliderCh4.GetPos();
	nLightEventFlag =0;
	nChannel =4;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[3]);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH4,nLevel[3]);
	*pResult = 0;
}

void CLightCtrl_OCXDlg::OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[4] =m_ctrlSliderCh5.GetPos();
	nLightEventFlag =0;
	nChannel =5;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[4]);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH5,nLevel[4]);
	*pResult = 0;
}

void CLightCtrl_OCXDlg::OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[5] =m_ctrlSliderCh6.GetPos();
	nLightEventFlag =0;
	nChannel =6;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[5]);
	SetDlgItemInt(IDC_EDIT_LEVEl_CH6,nLevel[5]);
	*pResult = 0;
}

void CLightCtrl_OCXDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[0]=GetDlgItemInt(IDC_EDIT_LEVEl_CH1);
	nLightEventFlag =0;
	nChannel =1;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[0]);
	m_ctrlSliderCh1.SetPos(nLevel[0]);
	m_Ch1_Level.SetSel(m_Ch1_Level.GetLineCount()+1,-1);
	
	
}

void CLightCtrl_OCXDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[1]=GetDlgItemInt(IDC_EDIT_LEVEl_CH2);
	nLightEventFlag =0;
	nChannel =2;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[1]);
	m_ctrlSliderCh2.SetPos(nLevel[1]);
	m_Ch2_Level.SetSel(m_Ch2_Level.GetLineCount()+1,-1);
}

void CLightCtrl_OCXDlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[2]=GetDlgItemInt(IDC_EDIT_LEVEl_CH3);
	nLightEventFlag =0;
	nChannel =3;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[2]);
	m_ctrlSliderCh3.SetPos(nLevel[2]);
	m_Ch3_Level.SetSel(m_Ch3_Level.GetLineCount()+1,-1);
}

void CLightCtrl_OCXDlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[3]=GetDlgItemInt(IDC_EDIT_LEVEl_CH4);
	nLightEventFlag =0;
	nChannel =4;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[3]);
	m_ctrlSliderCh4.SetPos(nLevel[3]);
	m_Ch4_Level.SetSel(m_Ch4_Level.GetLineCount()+1,-1);
}

void CLightCtrl_OCXDlg::OnEnChangeEdit5()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[4]=GetDlgItemInt(IDC_EDIT_LEVEl_CH5);
	nLightEventFlag =0;
	nChannel =5;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[4]);
	m_ctrlSliderCh5.SetPos(nLevel[4]);
	m_Ch5_Level.SetSel(m_Ch5_Level.GetLineCount()+1,-1);
}

void CLightCtrl_OCXDlg::OnEnChangeEdit6()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nLevel[5]=GetDlgItemInt(IDC_EDIT_LEVEl_CH6);
	nLightEventFlag =0;
	nChannel =6;
	nOnOff = 1;
	m_LightCtrlOCX.SendLightMessage(nChannel,nLightEventFlag,nOnOff,nLevel[5]);
	m_ctrlSliderCh6.SetPos(nLevel[5]);
	m_Ch6_Level.SetSel(m_Ch6_Level.GetLineCount()+1,-1);
}

void CLightCtrl_OCXDlg::saveFile()
{
	ofstream file("LightSave.dat");
	file<<"ch1:"<<nLevel[0]<<endl;
	file<<"ch2:"<<nLevel[1]<<endl;
	file<<"ch3:"<<nLevel[2]<<endl;
	file<<"ch4:"<<nLevel[3]<<endl;
	file<<"ch5:"<<nLevel[4]<<endl;
	file<<"ch6:"<<nLevel[5]<<endl;

	file.close();
}

void CLightCtrl_OCXDlg::loadFile()
{	
	ifstream file("LightSave.dat");
	if(file!=0)
	{
		string str;
		int nCnt=0;
		while(!file.eof())
		{

			getline(file,str);
			int nStart=str.find(":");
			nLevel[nCnt] = atoi(str.substr(nStart+1).c_str());		
			nCnt++;
			if(nCnt==6)
			{
				break;
			}

		}	
		file.close();

	}
	else
	{
		*nLevel = NULL;
	}

}