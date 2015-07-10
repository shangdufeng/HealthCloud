// RightHisqueView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightHisqueView.h"
#include "afxdialogex.h"


// CRightHisqueView 对话框

IMPLEMENT_DYNAMIC(CRightHisqueView, CDialog)

CRightHisqueView::CRightHisqueView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightHisqueView::IDD, pParent)
{
	theApp.m_prighthisqueview=this;
}

CRightHisqueView::~CRightHisqueView()
{
}

void CRightHisqueView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HISQUELIST, m_hisquelist);
	DDX_Control(pDX, IDC_STARTDATE, m_start);
	DDX_Control(pDX, IDC_ENDDATE, m_end);
	DDX_Control(pDX, IDC_GROUP_HISQUE, m_HisQue);
	DDX_Control(pDX, IDC_COMBO2, m_type);
}


BEGIN_MESSAGE_MAP(CRightHisqueView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_QUE, &CRightHisqueView::OnBnClickedQue)
	ON_MESSAGE(WM_SUHISHEALREAD, &CRightHisqueView::OnSuhishealread)
END_MESSAGE_MAP()


// CRightHisqueView 消息处理程序


BOOL CRightHisqueView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightHisqueView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_hisquelist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_hisquelist.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_hisquelist.InsertColumn(1,_T("指标"),LVCFMT_CENTER,130);
	m_hisquelist.InsertColumn(2,_T("数值"),LVCFMT_CENTER,180);
	m_hisquelist.InsertColumn(3,_T("检测时间"),LVCFMT_CENTER,240);

	m_HisQue.SetBorderColor(RGB(136,203,103));
	m_HisQue.SetFontBold(TRUE);
	m_HisQue.SetBackgroundColor(RGB(66,210,87));
	m_HisQue.SetFontSize(13);

	//*********************设置开始时间为一个星期前******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_end.GetTime(et);
	st = et-SDayTime;
	m_start.SetTime(&st);

	m_type.SetCurSel(2);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightHisqueView::OnPaint()
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


HBRUSH CRightHisqueView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightHisqueView::OnBnClickedQue()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime st,et;
	CString str_st,str_et;
	CString Type;
	GetDlgItemText(IDC_COMBO2,Type);
	m_Type = Type;
	m_start.GetTime(st);
	m_end.GetTime(et);
	str_st=st.Format(_T("%Y-%m-%d"));
	str_et=et.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserHisHealRead(Type,str_st,str_et);
}


afx_msg LRESULT CRightHisqueView::OnSuhishealread(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec,vec1;
	CString str,str1;
	CString str2;
/*	str2 = _T("19;1,2012,2,2013,3,2015,4,2016");*/
	theApp.SplitString(*(CString*)lParam/*str2*/,_T(";"),TRUE,vec);
/*	theApp.SplitString(vec.at(1),_T(","),TRUE,vec1);*/

	m_hisquelist.DeleteAllItems();
	if(vec.at(0)==_T("19")&&vec.at(1)!=_T("-1"))
	{
		for(int i=1;i<vec.size();i++)
		{
 			str.Format(_T("%d"),i);
 			/*str1.Format(_T("%d"),i+1);*/

			vec1.clear();
			theApp.SplitString(vec.at(i),_T(","),TRUE,vec1);
			m_hisquelist.InsertItem(i-1,str);
			/*m_hisquelist.InsertItem(i,str1);*/
			m_hisquelist.SetItemText(i-1,1,m_Type);
			m_hisquelist.SetItemText(i-1,2,vec1.at(0));
			m_hisquelist.SetItemText(i-1,3,vec1.at(1));
		}
	}
	else
	{
		AfxMessageBox(_T("无该信息！"));
	}
	return 0;
}
