
// User.h : User 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
#define WM_SERVERDRUGREAD WM_USER+100
#define WM_SUDRUGUPDATE WM_USER+101
#define WM_SUBASEINFOREAD WM_USER+102
#define WM_SUBASEINFOINPUT WM_USER+103
#define WM_DOCTORINFOLIST WM_USER+104
#define WM_SUDOCTORCHOOSE WM_USER+105
#define WM_SUDOCINFO WM_USER+106
#define WM_HEALINFOINPUT WM_USER+107
#define WM_SERVERLOGON WM_USER+108
#define WM_SUPLATINFOREAD WM_USER+109
#define WM_SUREGVERY WM_USER+110
#define WM_SUREGVERY1 WM_USER+111
#define WM_SUREG WM_USER+112
#define WM_SUREG1 WM_USER+113
#define WM_SUSUBCODE WM_USER+113

#define WM_SUWEL WM_USER+117
#define WM_SULATESTHEALREAD WM_USER+118
#define WM_SUHISHEALREAD WM_USER+119
#define WM_SUREPREAD WM_USER+120
#define WM_SUEXCEPREAD WM_USER+121

#define WM_SUMESSREAD WM_USER+125
#define WM_SUMESSSEND WM_USER+126

#define WM_SUHRTREP   WM_USER+127

#define WM_MESSREADORNO  WM_USER+128
#define WM_REPREADORNO   WM_USER+129

#define WM_PWRESET       WM_USER+130

#include "resource.h"       // 主符号
#include "LeftPaneView.h"
#include "RightPaneView.h"
#include "SocketClientCtrl.h"


// CUserApp:
// 有关此类的实现，请参阅 User.cpp
//
DWORD WINAPI RecvProc();
class CUserApp : public CWinApp
{
public:
	CUserApp();

public:
	CLeftPaneView* m_pleftpane;
	CLeftHealplatView* m_plefthealplatview;
	CDialog* m_prightpreview;
	CRightChangeinfoView* m_prightchangeinfoview;
	CRightChgperinfoView* m_prightchgperinfoview;
	CRightContactView* m_prightcontactview;
	CRightDoclistView* m_prightdoclistview;
	CRightExcepinfoView* m_prightexcepinfoview;
	CRightHealrepView* m_prighthealrepview;
/*	CRightHealtoolView* m_prighthealtoolview;*/
	CCalorieToolView* m_pCalorieToolView;
	CRightHisqueView* m_prighthisqueview;
	CRightInputView* m_prightinputview;
	CRightLatestinfoView* m_prightlatestinfoview;
	CRightLoginView* m_prightloginview;
	CRightMessagereadView* m_prightmessagereadview;
	CRightMydocView* m_prightmydocview;
	CRightPaneView* m_prightpane;
	CRightPlatuseView* m_prightplatuseview;
	CRightRegView* m_prightregview;
	CRightReg2View* m_prightreg2view;
	CRightResetpassView* m_prightresetpassview;
	CRightWelcomeView* m_rightwelcomeview;

	CSocketClientCtrl socketclient;
	SOCKET m_sockClient;
	SOCKADDR_IN m_addrSrv;
	CString *vecstr;
	CString strRecv;

	//********************静态字体************************
	CFont m_TextFont;
// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	int  SplitString(CString str_in, CString chSplit_in,
		BOOL bAllowNullString,vector<CString>& data); 
	void ReOrder(vector<CString> vec,int Index,vector<vector<CString>> &MutiVec1);
// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	
	

};

extern CUserApp theApp;








//struct RECVPARAM
//{
//	SOCKET sock;
//	HINSTANCE hinstance;
//};