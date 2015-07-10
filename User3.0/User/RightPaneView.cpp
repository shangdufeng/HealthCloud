// RightPaneView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightPaneView.h"


// CRightPaneView

IMPLEMENT_DYNCREATE(CRightPaneView, CFormView)

CRightPaneView::CRightPaneView()
	: CFormView(CRightPaneView::IDD)
{
	theApp.m_prightpane=this;
}

CRightPaneView::~CRightPaneView()
{
}

void CRightPaneView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRightPaneView, CFormView)
END_MESSAGE_MAP()


// CRightPaneView 诊断

#ifdef _DEBUG
void CRightPaneView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightPaneView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRightPaneView 消息处理程序


void CRightPaneView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	// TODO: 在此添加专用代码和/或调用基类
	m_rightloginview.Create(IDD_RIGHT_LOGIN,this);
	m_rightloginview.ShowWindow(SW_SHOW);

	m_rightregview.Create(IDD_RIGHT_REG,this);
	m_rightregview.ShowWindow(SW_HIDE);

	m_rightmessagereadview.Create(IDD_RIGHT_MESSAGEREAD,this);
	m_rightmessagereadview.ShowWindow(SW_HIDE);

	m_rightcontactview.Create(IDD_RIGHT_CONTACTUS,this);
	m_rightcontactview.ShowWindow(SW_HIDE);

	m_rightinputview.Create(IDD_RIGHT_INPUT,this);
	m_rightinputview.ShowWindow(SW_HIDE);

	m_rightlatestinfoview.Create(IDD_RIGHT_LATESTINFO,this);
	m_rightlatestinfoview.ShowWindow(SW_HIDE);

	m_righthisqueview.Create(IDD_RIGHT_HISQUE,this);
	m_righthisqueview.ShowWindow(SW_HIDE);

	m_righthealrepview.Create(IDD_RIGHT_HEALREP,this);
	m_righthealrepview.ShowWindow(SW_HIDE);

	m_rightexcepinfoview.Create(IDD_RIGHT_EXCEPINFO,this);
	m_rightexcepinfoview.ShowWindow(SW_HIDE);

// 	m_righthealtoolview.Create(IDD_RIGHT_HEALTOOL,this);
// 	m_righthealtoolview.ShowWindow(SW_HIDE);

	//*******************创建健康工具界面********************
	m_CalorieToolView.Create(IDD_CTEST_DIALOG,this);
	m_CalorieToolView.ShowWindow(SW_HIDE);

	m_rightaddinfoview.Create(IDD_RIGHT_ADDINFO,this);
	m_rightaddinfoview.ShowWindow(SW_HIDE);

	m_rightchangeinfoview.Create(IDD_RIGHT_CHANGEINFO,this);
	m_rightchangeinfoview.ShowWindow(SW_HIDE);

	m_rightdoclistview.Create(IDD_RIGHT_DOCLIST,this);
	m_rightdoclistview.ShowWindow(SW_HIDE);

	m_rightmydocview.Create(IDD_RIGHT_MYDOC,this);
	m_rightdoclistview.ShowWindow(SW_HIDE);

	m_rightinvidocview.Create(IDD_RIGHT_INVIDOC,this);
	m_rightinvidocview.ShowWindow(SW_HIDE);

	m_rightchgperinfoview.Create(IDD_RIGHT_CHGPERINFO,this);
	m_rightchgperinfoview.ShowWindow(SW_HIDE);

	m_rightresetpassview.Create(IDD_RIGHT_RESETPASS,this);
	m_rightresetpassview.ShowWindow(SW_HIDE);

	m_rightplatuseview.Create(IDD_RIGHT_PLATUSE,this);
	m_rightplatuseview.ShowWindow(SW_HIDE);

	m_rightreg2view.Create(IDD_RIGHT_REG2,this);
	m_rightreg2view.ShowWindow(SW_HIDE);

	m_rightwelcomeview.Create(IDD_RIGHT_WELCOME,this);
	m_rightwelcomeview.ShowWindow(SW_HIDE);

	theApp.m_prightpreview=&m_rightloginview;
}


void CRightPaneView::ShowView(CDialog* pHideView, CDialog* pShowView)
{
	pHideView->ShowWindow(SW_HIDE);
	pShowView->ShowWindow(SW_SHOW);
}


BOOL CRightPaneView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CFormView::PreTranslateMessage(pMsg);
}
