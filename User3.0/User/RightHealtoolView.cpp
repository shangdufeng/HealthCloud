// RightHealtoolView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightHealtoolView.h"
#include "afxdialogex.h"


// CRightHealtoolView 对话框

IMPLEMENT_DYNAMIC(CRightHealtoolView, CDialog)

CRightHealtoolView::CRightHealtoolView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightHealtoolView::IDD, pParent)
{
/*	theApp.m_prighthealtoolview=this;*/
}

CRightHealtoolView::~CRightHealtoolView()
{
}

void CRightHealtoolView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT, m_input);
	DDX_Control(pDX, IDC_OUTPUT, m_output);
}


BEGIN_MESSAGE_MAP(CRightHealtoolView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightHealtoolView 消息处理程序


BOOL CRightHealtoolView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightHealtoolView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CPen pen(PS_SOLID,1,RGB(205,231,208));
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BKIN);   
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	CPen* pOldpen=dc.SelectObject(&pen);
	dc.FillRect(CRect(0,0,850,800),&brush);  
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldpen);
}


HBRUSH CRightHealtoolView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


BOOL CRightHealtoolView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_input.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_input.InsertColumn(0,_T("时间"),LVCFMT_CENTER,100);
	m_input.InsertColumn(1,_T("摄入名称"),LVCFMT_CENTER,150);
	m_input.InsertColumn(2,_T("摄入量"),LVCFMT_CENTER,100);
	m_input.InsertColumn(3,_T("摄入能量"),LVCFMT_CENTER,120);
	
	m_output.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_output.InsertColumn(0,_T("时间"),LVCFMT_CENTER,100);
	m_output.InsertColumn(1,_T("运动名称"),LVCFMT_CENTER,150);
	m_output.InsertColumn(2,_T("运动量"),LVCFMT_CENTER,100);
	m_output.InsertColumn(3,_T("消耗能量"),LVCFMT_CENTER,120);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
