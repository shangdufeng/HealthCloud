// RightInvidocView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightInvidocView.h"
#include "afxdialogex.h"
#include "Choosedoc.h"


// CRightInvidocView 对话框

IMPLEMENT_DYNAMIC(CRightInvidocView, CDialog)

CRightInvidocView::CRightInvidocView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightInvidocView::IDD, pParent)
{

}

CRightInvidocView::~CRightInvidocView()
{
}

void CRightInvidocView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FINDDOCLIST, m_finddoclist);
}


BEGIN_MESSAGE_MAP(CRightInvidocView, CDialog)
END_MESSAGE_MAP()


// CRightInvidocView 消息处理程序


BOOL CRightInvidocView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightInvidocView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_finddoclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_finddoclist.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_finddoclist.InsertColumn(1,_T("医生姓名"),LVCFMT_CENTER,100);
	m_finddoclist.InsertColumn(2,_T("所在医院"),LVCFMT_CENTER,150);
	m_finddoclist.InsertColumn(3,_T("科室"),LVCFMT_CENTER,100);
	m_finddoclist.InsertColumn(4,_T("手机号"),LVCFMT_CENTER,100);
	m_finddoclist.InsertColumn(5,_T("邀请他"),LVCFMT_CENTER,60);


	/*CChoosedoc box1;
	box1.Create(IDC_CHOOSEDOC,this);
	box1.ShowWindow(SW_SHOW);*/






	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
