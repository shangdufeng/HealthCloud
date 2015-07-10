// LeftAccmanView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "LeftAccmanView.h"
#include "afxdialogex.h"



// CLeftAccmanView 对话框

IMPLEMENT_DYNAMIC(CLeftAccmanView, CDialog)

CLeftAccmanView::CLeftAccmanView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftAccmanView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
	
	m_font.CreatePointFont(200,_T("Arial"),NULL);///////////////这里有问题
	
}

CLeftAccmanView::~CLeftAccmanView()
{
}

void CLeftAccmanView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftAccmanView, CDialog)
//	ON_BN_CLICKED(IDC_BUTTON1, &CLeftAccmanView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftAccmanView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALINFO, &CLeftAccmanView::OnBnClickedBtnHealinfo)
	ON_BN_CLICKED(IDC_BTN_HEALEXPERT, &CLeftAccmanView::OnBnClickedBtnHealexpert)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftAccmanView::OnBnClickedBtnHealplat)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_CHGPERINFO, &CLeftAccmanView::OnBnClickedBtnChgperinfo)
	ON_BN_CLICKED(IDC_BTN_RESETPASS, &CLeftAccmanView::OnBnClickedBtnResetpass)
	ON_BN_CLICKED(IDC_BTN_PLATUSE, &CLeftAccmanView::OnBnClickedBtnPlatuse)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftAccmanView 消息处理程序


//void CLeftAccmanView::OnBnClickedButton1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}


void CLeftAccmanView::OnBnClickedBtnDrugman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


BOOL CLeftAccmanView::OnInitDialog()
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




	m_btnchangeinfo.SubclassDlgItem(IDC_BTN_CHGPERINFO,this);
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnresetpass.SubclassDlgItem(IDC_BTN_RESETPASS,this);
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnplatuse.SubclassDlgItem(IDC_BTN_PLATUSE,this);
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btncharge.SubclassDlgItem(IDC_BTN_CHARGE,this);
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CLeftAccmanView::OnBnClickedBtnHealinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealinfoview);
}


void CLeftAccmanView::OnBnClickedBtnHealexpert()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealexpertview);
}


void CLeftAccmanView::OnBnClickedBtnHealplat()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}


HBRUSH CLeftAccmanView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
	if(pWnd->GetDlgCtrlID()==IDC_BTN_ACCMAN)
	{


		pDC->SelectObject(&m_font);
		

	}
	
	return m_brush;
}


BOOL CLeftAccmanView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
	return CDialog::OnEraseBkgnd(pDC);
}


void CLeftAccmanView::OnBnClickedBtnChgperinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightchgperinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightchgperinfoview;

	theApp.socketclient.UserBaseInfoRead();
}


void CLeftAccmanView::OnBnClickedBtnResetpass()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightresetpassview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightresetpassview;
}


void CLeftAccmanView::OnBnClickedBtnPlatuse()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightplatuseview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightplatuseview;

	theApp.socketclient.UserPlatInfoRead();
}


BOOL CLeftAccmanView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLeftAccmanView::OnPaint()
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
