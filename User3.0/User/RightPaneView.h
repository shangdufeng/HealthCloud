#pragma once
#include "RightLoginView.h"
#include "RightRegView.h"
#include "rightmessagereadview.h"
#include "rightcontactview.h"
#include "rightinputview.h"
#include "rightlatestinfoview.h"
#include "righthisqueview.h"
#include "righthealrepview.h"
#include "rightexcepinfoview.h"
/*#include "righthealtoolview.h"*/
#include "CalorieToolView.h"
#include "rightaddinfoview.h"
#include "rightchangeinfoview.h"
#include "rightmydocview.h"
#include "rightdoclistview.h"
#include "rightinvidocview.h"
#include "rightresetpassview.h"
#include "rightchgperinfoview.h"
#include "rightplatuseview.h"
#include "rightReg2View.h"
#include "RightWelcomeView.h"



// CRightPaneView 窗体视图

class CRightPaneView : public CFormView
{
	DECLARE_DYNCREATE(CRightPaneView)

protected:
	CRightPaneView();           // 动态创建所使用的受保护的构造函数
	virtual ~CRightPaneView();

public:
	CRightLoginView m_rightloginview;
	CRightRegView m_rightregview;

public:
	enum { IDD = IDD_RIGHT_PANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void ShowView(CDialog* pHideView, CDialog* pShowView);
	CRightMessagereadView m_rightmessagereadview;
	CRightContactView m_rightcontactview;
	CRightInputView m_rightinputview;
	CRightLatestinfoView m_rightlatestinfoview;
	CRightHisqueView m_righthisqueview;
	CRightHealrepView m_righthealrepview;
	CRightExcepinfoView m_rightexcepinfoview;
	CCalorieToolView m_CalorieToolView;
/*	CRightHealtoolView m_righthealtoolview;*/
	CRightAddinfoView m_rightaddinfoview;
	CRightChangeinfoView m_rightchangeinfoview;
	CRightMydocView m_rightmydocview;
	CRightDoclistView m_rightdoclistview;
	CRightInvidocView m_rightinvidocview;
	CRightResetpassView m_rightresetpassview;
	CRightChgperinfoView m_rightchgperinfoview;
	CRightPlatuseView m_rightplatuseview;
	CRightReg2View m_rightreg2view;
	CRightWelcomeView m_rightwelcomeview;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


