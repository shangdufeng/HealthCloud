// RightPlatuseView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightPlatuseView.h"
#include "afxdialogex.h"


// CRightPlatuseView 对话框

IMPLEMENT_DYNAMIC(CRightPlatuseView, CDialog)

CRightPlatuseView::CRightPlatuseView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightPlatuseView::IDD, pParent)
	, m_usertype(_T(""))
	, m_freespace(_T(""))
	, m_deadline(_T(""))
	, m_total(_T(""))
{
	theApp.m_prightplatuseview=this;
}

CRightPlatuseView::~CRightPlatuseView()
{
}

void CRightPlatuseView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PALTUSE, m_platuse);
	DDX_Text(pDX, IDC_EDIT1, m_usertype);
	DDX_Text(pDX, IDC_EDIT4, m_freespace);
	DDX_Text(pDX, IDC_EDIT3, m_deadline);
	DDX_Text(pDX, IDC_EDIT2, m_total);
}


BEGIN_MESSAGE_MAP(CRightPlatuseView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BACK, &CRightPlatuseView::OnBnClickedBack)
	ON_MESSAGE(WM_SUPLATINFOREAD, &CRightPlatuseView::OnSuplatinforead)
END_MESSAGE_MAP()


// CRightPlatuseView 消息处理程序


BOOL CRightPlatuseView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightPlatuseView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_platuse.SetBorderColor(RGB(136,203,103));
	//m_platuse.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW);
	//m_platuse.SetBackgroundColor(RGB(201, 201, 151));
	m_platuse.SetFontBold(TRUE);
	m_platuse.SetBackgroundColor(RGB(66,210,87));
	m_platuse.SetFontSize(13);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightPlatuseView::OnPaint()
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


HBRUSH CRightPlatuseView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)||(pWnd->GetDlgCtrlID()==IDC_PALTUSE)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}


	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CRightPlatuseView::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}


afx_msg LRESULT CRightPlatuseView::OnSuplatinforead(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_platuse;
	CString str_plat;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_platuse);
	str_plat=vec_platuse[1];
	vec_platuse.clear();
	theApp.SplitString(str_plat,_T(","),TRUE,vec_platuse);
	if (vec_platuse.at(0)==_T("1"))
	{
		m_usertype=_T("付费用户");
	}
	else if(vec_platuse.at(0)==_T("0"))
	{
		m_usertype=_T("体验用户");
	}
	else
	{
		m_usertype=vec_platuse.at(0);
	}
	
	m_deadline=vec_platuse.at(3);
	m_freespace=vec_platuse.at(2);
	m_total=vec_platuse.at(1);
// 	if (vec_platuse.at(0)==_T("体验用户"))
// 	{
// 		m_total=_T("100");
// 	}
// 	else
// 	{
// 		m_total=_T("1000");
	//}
	UpdateData(FALSE);
	return 0;
}
