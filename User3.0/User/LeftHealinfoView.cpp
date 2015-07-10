// LeftHealinfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "LeftHealinfoView.h"
#include "afxdialogex.h"


// CLeftHealinfoView 对话框

IMPLEMENT_DYNAMIC(CLeftHealinfoView, CDialog)

CLeftHealinfoView::CLeftHealinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftHealinfoView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
}

CLeftHealinfoView::~CLeftHealinfoView()
{
}

void CLeftHealinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftHealinfoView, CDialog)
	ON_BN_CLICKED(IDC_BTN_ACCMAN, &CLeftHealinfoView::OnBnClickedBtnAccman)
	ON_BN_CLICKED(IDC_BTN_HEALEXPERT, &CLeftHealinfoView::OnBnClickedBtnHealexpert)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftHealinfoView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftHealinfoView::OnBnClickedBtnHealplat)
	ON_BN_CLICKED(IDC_BTN_INPUT, &CLeftHealinfoView::OnBnClickedBtnInput)
	ON_BN_CLICKED(IDC_BTN_LATEST, &CLeftHealinfoView::OnBnClickedBtnLatest)
	ON_BN_CLICKED(IDC_BTN_HISQUE, &CLeftHealinfoView::OnBnClickedBtnHisque)
	ON_BN_CLICKED(IDC_BTN_HEALREP, &CLeftHealinfoView::OnBnClickedBtnHealrep)
//	ON_BN_CLICKED(IDC_BTN_HEALREP2, &CLeftHealinfoView::OnBnClickedBtnHealrep2)
ON_BN_CLICKED(IDC_BTN_EXCEPINFO, &CLeftHealinfoView::OnBnClickedBtnExcepinfo)
ON_BN_CLICKED(IDC_BTN_HEALTOOL, &CLeftHealinfoView::OnBnClickedBtnHealtool)
ON_WM_CTLCOLOR()
ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftHealinfoView 消息处理程序


void CLeftHealinfoView::OnBnClickedBtnAccman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftaccmanview);
}


void CLeftHealinfoView::OnBnClickedBtnHealexpert()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealexpertview);
}


void CLeftHealinfoView::OnBnClickedBtnDrugman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


void CLeftHealinfoView::OnBnClickedBtnHealplat()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}


void CLeftHealinfoView::OnBnClickedBtnInput()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightinputview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightinputview;
}


void CLeftHealinfoView::OnBnClickedBtnLatest()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightlatestinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightlatestinfoview;
	//**********************查询最近信息**********************************
    theApp.socketclient.UserLatestHealRead();
	//**********************返回到最近信息界面****************************
// 	GetDlgItem(IDC_LATESTINFO)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_BTN_BLD)->SetWindowPos(this,176,449,178,64,SWP_NOZORDER);
// 	GetDlgItem(IDC_BTN_HRT)->SetWindowPos(this,360,449,178,64,SWP_NOZORDER);
// 	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_PREVIEW)->SetWindowPos(this,350,20,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_PREVIEW)->ShowWindow(SW_HIDE);
// 
// 	GetDlgItem(IDC_DOWN)->SetWindowPos(this,420,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_DOWN)->ShowWindow(SW_HIDE);
// 
// 	GetDlgItem(IDC_STATIC2)->SetWindowPos(this,200,40,0,0,SWP_NOZORDER|SWP_NOSIZE);
// 	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
// 
// 	GetDlgItem(IDC_RETURN)->SetWindowPos(this,250,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_RETURN)->ShowWindow(SW_HIDE);
}


void CLeftHealinfoView::OnBnClickedBtnHisque()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_righthisqueview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_righthisqueview;
}


void CLeftHealinfoView::OnBnClickedBtnHealrep()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_righthealrepview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_righthealrepview;
}





void CLeftHealinfoView::OnBnClickedBtnExcepinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightexcepinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightexcepinfoview;
}


void CLeftHealinfoView::OnBnClickedBtnHealtool()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_CalorieToolView);
	theApp.m_prightpreview=&theApp.m_prightpane->m_CalorieToolView;
}


BOOL CLeftHealinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CLeftHealinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_btnleftaccman.SubclassDlgItem(IDC_BTN_ACCMAN,this);
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//鼠标在按钮外背景颜色
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//鼠标在按钮外字体颜色
	//m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0,0,0));//鼠标在按钮内字体颜色
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//按钮按下后背景颜色
	//m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnleftdrugman.SubclassDlgItem(IDC_BTN_DRUGMAN,this);
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//鼠标在按钮外背景颜色
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//鼠标在按钮外字体颜色
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//按钮按下后背景颜色
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnlefthealexpert.SubclassDlgItem(IDC_BTN_HEALEXPERT,this);
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//鼠标在按钮外背景颜色
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//鼠标在按钮外字体颜色
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//按钮按下后背景颜色
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnhealinfo.SubclassDlgItem(IDC_BTN_HEALINFO,this);
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//鼠标在按钮外背景颜色
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//鼠标在按钮外字体颜色
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//按钮按下后背景颜色
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnhealplat.SubclassDlgItem(IDC_BTN_HEALPLAT,this);
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//鼠标在按钮外背景颜色
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//鼠标在按钮外字体颜色
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//按钮按下后背景颜色
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色




	m_btninput.SubclassDlgItem(IDC_BTN_INPUT,this);
	m_btninput.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btninput.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btninput.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btninput.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btninput.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnlatest.SubclassDlgItem(IDC_BTN_LATEST,this);
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnhisque.SubclassDlgItem(IDC_BTN_HISQUE,this);
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnhealrep.SubclassDlgItem(IDC_BTN_HEALREP,this);
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnexcepinfo.SubclassDlgItem(IDC_BTN_EXCEPINFO,this);
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnhealtool.SubclassDlgItem(IDC_BTN_HEALTOOL,this);
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CLeftHealinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
	return m_brush;
}


void CLeftHealinfoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CPen pen(PS_SOLID,1,RGB(205,231,208));
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_LEFT);   
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	CPen* pOldpen=dc.SelectObject(&pen);
	dc.FillRect(CRect(0,0,150,800),&brush);   
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldpen);
}
