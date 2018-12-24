
// LightCtrl_OCXDlg.cpp : 구현 파일
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
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CLightCtrl_OCXDlg 대화 상자




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


// CLightCtrl_OCXDlg 메시지 처리기

BOOL CLightCtrl_OCXDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	OnChkConnect();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CLightCtrl_OCXDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
		AfxMessageBox(_T("[ERROR]:조명 OFF입니다!"));
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
	// PC -> CONTROLLER : [STX] [채널 %02d] [ON] [온/오프 %01d] [ETX]
	 
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
	DWORD dwPID = GetCurrentProcessId();    // 현재 자신의 프로세스 ID 가져오기.

	HANDLE hProcess = OpenProcess( PROCESS_ALL_ACCESS, 0, dwPID );    // 프로세스 핸들 가져오기

	if( NULL != hProcess )
	{
		GetExitCodeProcess( hProcess, &dwExitCode );   // 프로세스 나가기 코드 얻어오기
		TerminateProcess( hProcess, dwExitCode );    // 프로세스 연결 끊기
		WaitForSingleObject( hProcess, INFINITE ); // 종료 될때까지 대기
		CloseHandle( hProcess );                                 // 프로세스 핸들 닫기
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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