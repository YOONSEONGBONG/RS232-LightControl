
// LightCtrl_OCXDlg.h : 헤더 파일
//
#include "afxwin.h"
#include "afxcmn.h"

#pragma once
#include "lightcontrol_ocxctrl1.h"

#define  MAX_CHANNEL 6
#define  TRUE  1
#define  FALSE 0


// CLightCtrl_OCXDlg 대화 상자
class CLightCtrl_OCXDlg : public CDialog
{
// 생성입니다.
public:
	CLightCtrl_OCXDlg(CWnd* pParent = NULL);	// 표준 생성자입니다. 
// 대화 상자 데이터입니다.
	enum { IDD = IDD_LIGHTCTRL_OCX_DIALOG };
	
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedAutotest();
	afx_msg void OnBtnSave();
	afx_msg void OnBtnOnoff();
	afx_msg void OnChkConnect();
	afx_msg void OnChkDisconnect();
	afx_msg void OnChkOnoff();
	afx_msg void OnBtnAuto();
	afx_msg void OnWriteInit();
	afx_msg void CheckLightConnected();
	//afx_msg LRESULT OnReceiveData( WPARAM wParam, LPARAM lParam );

	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit1();	
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void saveFile();
	afx_msg	void loadFile();
	DECLARE_MESSAGE_MAP()

public:
	CComboBox m_ctrlAutoTestChannel;
	CComboBox m_ctrlAutoTestSpeed;
	CComboBox m_ctrlAutoTestCount;

	CButton m_ctrlAutoTest;
	CButton m_ctrlSave;
	CButton m_ctrlOnOff;
	CButton m_ctrlWriteInit;
	CButton m_ctrlConnect;
	CButton m_ctrlDisconnect;

	CSliderCtrl m_ctrlSliderCh1;
	CSliderCtrl m_ctrlSliderCh2;
	CSliderCtrl m_ctrlSliderCh3;
	CSliderCtrl m_ctrlSliderCh4;
	CSliderCtrl m_ctrlSliderCh5;
	CSliderCtrl m_ctrlSliderCh6;

	CEdit m_Ch1_Level;
	CEdit m_Ch2_Level;
	CEdit m_Ch3_Level;
	CEdit m_Ch4_Level;
	CEdit m_Ch5_Level;
	CEdit m_Ch6_Level;
public:
	int nConnect_Flag;			 // 연결 해제 확인
	int	nLightEventFlag;    //0:WR(WRITE), 1:SV(SAVE), 2:ON(ONOFF)
	int nOnOff;            //0:OFF,1:ON
	int nLevel[6];        //조명 channel당 Level값;
	int nChannel;	     // 조명 채널
	
	
	
	CLightcontrol_ocxctrl1 m_LightCtrlOCX;
};
