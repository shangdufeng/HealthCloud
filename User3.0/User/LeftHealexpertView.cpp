// LeftHealexpertView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "LeftHealexpertView.h"
#include "afxdialogex.h"


// CLeftHealexpertView 对话框

IMPLEMENT_DYNAMIC(CLeftHealexpertView, CDialog)

CLeftHealexpertView::CLeftHealexpertView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftHealexpertView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
}

CLeftHealexpertView::~CLeftHealexpertView()
{
}

void CLeftHealexpertView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftHealexpertView, CDialog)
	ON_BN_CLICKED(IDC_BTN_ACCMAN, &CLeftHealexpertView::OnBnClickedBtnAccman)
	ON_BN_CLICKED(IDC_BTN_HEALINFO, &CLeftHealexpertView::OnBnClickedBtnHealinfo)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftHealexpertView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftHealexpertView::OnBnClickedBtnHealplat)
//	ON_BN_CLICKED(IDC_BTN_EXPERTLIST, &CLeftHealexpertView::OnBnClickedBtnExpertlist)
ON_BN_CLICKED(IDC_BTN_DOCLIST, &CLeftHealexpertView::OnBnClickedBtnDoclist)
ON_BN_CLICKED(IDC_BTN_MYDOC, &CLeftHealexpertView::OnBnClickedBtnMydoc)
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_BTN_INVIDOC, &CLeftHealexpertView::OnBnClickedBtnInvidoc)
ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftHealexpertView 消息处理程序


void CLeftHealexpertView::OnBnClickedBtnAccman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftaccmanview);
}


void CLeftHealexpertView::OnBnClickedBtnHealinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealinfoview);
}


void CLeftHealexpertView::OnBnClickedBtnDrugman()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


void CLeftHealexpertView::OnBnClickedBtnHealplat()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}



void CLeftHealexpertView::OnBnClickedBtnDoclist()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightdoclistview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightdoclistview;
}


void CLeftHealexpertView::OnBnClickedBtnMydoc()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightmydocview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightmydocview;

	theApp.socketclient.UserDocInfo();
}


BOOL CLeftHealexpertView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CLeftHealexpertView::OnInitDialog()
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


	m_btndoclist.SubclassDlgItem(IDC_BTN_DOCLIST,this);
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btninvidoc.SubclassDlgItem(IDC_BTN_INVIDOC,this);
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色

	m_btnmydoc.SubclassDlgItem(IDC_BTN_MYDOC,this);
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//鼠标在按钮外背景颜色
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//鼠标在按钮内背景颜色
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//鼠标在按钮外字体颜色
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//按钮按下后背景颜色
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//按钮按下后字体颜色



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CLeftHealexpertView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
	return m_brush;
}


void CLeftHealexpertView::OnBnClickedBtnInvidoc()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightinvidocview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightinvidocview;
}


void CLeftHealexpertView::OnPaint()
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
