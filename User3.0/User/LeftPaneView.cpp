// LeftPaneView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "LeftPaneView.h"


// CLeftPaneView

IMPLEMENT_DYNCREATE(CLeftPaneView, CFormView)

CLeftPaneView::CLeftPaneView()
	: CFormView(CLeftPaneView::IDD)
{
	theApp.m_pleftpane=this;
}

CLeftPaneView::~CLeftPaneView()
{
}

void CLeftPaneView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLeftPaneView, CFormView)
END_MESSAGE_MAP()


// CLeftPaneView 诊断

#ifdef _DEBUG
void CLeftPaneView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftPaneView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftPaneView 消息处理程序


void CLeftPaneView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_leftaccmanview.Create(IDD_LEFT_ACCMAN,this);
	m_leftaccmanview.ShowWindow(SW_HIDE);

	m_lefthealinfoview.Create(IDD_LEFT_HEALINFO,this);
	m_lefthealinfoview.ShowWindow(SW_HIDE);

	m_lefthealexpertview.Create(IDD_LEFT_HEALEXPERT,this);
	m_lefthealexpertview.ShowWindow(SW_HIDE);

	m_leftdrugmanview.Create(IDD_LEFT_DRUGMAN,this);
	m_leftdrugmanview.ShowWindow(SW_HIDE);

	m_lefthealplatview.Create(IDD_LEFT_HEALPLAT,this);
	m_lefthealplatview.ShowWindow(SW_SHOW);
}


void CLeftPaneView::ShowView(CDialog* pHideView, CDialog* pShowView)
{
	pHideView->ShowWindow(SW_HIDE);
	pShowView->ShowWindow(SW_SHOW);
}
