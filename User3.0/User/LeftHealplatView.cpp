// LeftHealplatView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "LeftHealplatView.h"
#include "afxdialogex.h"
#include "RightPaneView.h"


// CLeftHealplatView 对话框

IMPLEMENT_DYNAMIC(CLeftHealplatView, CDialog)

CLeftHealplatView::CLeftHealplatView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftHealplatView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
	theApp.m_plefthealplatview=this;
}

CLeftHealplatView::~CLeftHealplatView()
{
}

void CLeftHealplatView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BTN_WELCOME, m_welcome);
	DDX_Control(pDX, IDC_BTN_WELCOME, m_btnwelcome);
}


BEGIN_MESSAGE_MAP(CLeftHealplatView, CDialog)
	ON_BN_CLICKED(IDC_BTN_ACCMAN, &CLeftHealplatView::OnBnClickedBtnAccman)
	ON_BN_CLICKED(IDC_BTN_HEALINFO, &CLeftHealplatView::OnBnClickedBtnHealinfo)
	ON_BN_CLICKED(IDC_BTN_HEALEXPERT, &CLeftHealplatView::OnBnClickedBtnHealexpert)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftHealplatView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftHealplatView::OnBnClickedBtnHealplat)
	ON_BN_CLICKED(IDC_BTN_REG, &CLeftHealplatView::OnBnClickedBtnReg)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CLeftHealplatView::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_READMESS, &CLeftHealplatView::OnBnClickedBtnReadmess)
	ON_BN_CLICKED(IDC_BTN_CONTACT, &CLeftHealplatView::OnBnClickedBtnContact)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_EXIT, &CLeftHealplatView::OnBnClickedBtnExit)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_WELCOME, &CLeftHealplatView::OnBnClickedBtnWelcome)
END_MESSAGE_MAP()


// CLeftHealplatView 消息处理程序


void CLeftHealplatView::OnBnClickedBtnAccman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftaccmanview);
}


void CLeftHealplatView::OnBnClickedBtnHealinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealinfoview);
}


void CLeftHealplatView::OnBnClickedBtnHealexpert()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealexpertview);
}


void CLeftHealplatView::OnBnClickedBtnDrugman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


void CLeftHealplatView::OnBnClickedBtnHealplat()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CLeftHealplatView::OnBnClickedBtnReg()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightregview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightregview;
}


void CLeftHealplatView::OnBnClickedBtnLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightloginview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightloginview;
}


void CLeftHealplatView::OnBnClickedBtnReadmess()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightmessagereadview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightmessagereadview;

	CTime st,et;
	CTimeSpan TSp=60480000;
	theApp.m_prightmessagereadview->m_end.GetTime(et);
	st = et-TSp;
	CString str_start,str_end;
	str_end=et.Format(_T("%Y-%m-%d"));
	str_start=st.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserMessRead(str_start,str_end);
}


void CLeftHealplatView::OnBnClickedBtnContact()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightcontactview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightcontactview;
}


BOOL CLeftHealplatView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CLeftHealplatView::OnInitDialog()
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



	m_btnlogin.SubclassDlgItem(IDC_BTN_LOGIN,this);
	m_btnlogin.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnlogin.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnlogin.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnlogin.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnlogin.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnreg.SubclassDlgItem(IDC_BTN_REG,this);
	m_btnreg.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnreg.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnreg.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnreg.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnreg.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnreadmess.SubclassDlgItem(IDC_BTN_READMESS,this);
	m_btnreadmess.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnreadmess.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnreadmess.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnreadmess.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnreadmess.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btncontact.SubclassDlgItem(IDC_BTN_CONTACT,this);
	m_btncontact.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btncontact.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btncontact.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btncontact.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btncontact.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnexit.SubclassDlgItem(IDC_BTN_EXIT,this);
	m_btnexit.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnexit.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnexit.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnexit.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnexit.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

// 	m_btnwelcome.SubclassDlgItem(IDC_BTN_WELCOME,this);
 	m_btnwelcome.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
 	m_btnwelcome.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
 	m_btnwelcome.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
 	m_btnwelcome.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
 	m_btnwelcome.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnleftaccman.EnableWindow(FALSE);
	m_btnleftdrugman.EnableWindow(FALSE);
	m_btnlefthealexpert.EnableWindow(FALSE);
	m_btnhealinfo.EnableWindow(FALSE);
	m_btnhealplat.EnableWindow(FALSE);
	m_btnreadmess.EnableWindow(FALSE);
	m_btncontact.EnableWindow(FALSE);
	m_btnwelcome.EnableWindow(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CLeftHealplatView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
	return m_brush;
}


void CLeftHealplatView::OnBnClickedBtnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	PostQuitMessage(0);
}


void CLeftHealplatView::OnPaint()
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


void CLeftHealplatView::OnBnClickedBtnWelcome()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}
