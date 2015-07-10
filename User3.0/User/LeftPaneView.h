#pragma once
#include "LeftAccmanView.h"
#include "LeftHealinfoView.h"
#include "LeftHealexpertView.h"
#include "LeftHealplatView.h"
#include "LeftDrugmanView.h"


// CLeftPaneView 窗体视图

class CLeftPaneView : public CFormView
{
	DECLARE_DYNCREATE(CLeftPaneView)
	
protected:
	CLeftPaneView();           // 动态创建所使用的受保护的构造函数
	virtual ~CLeftPaneView();
public:
	CLeftAccmanView		m_leftaccmanview;
	CLeftHealinfoView	m_lefthealinfoview;
	CLeftHealexpertView	m_lefthealexpertview;
	CLeftHealplatView	m_lefthealplatview;
	CLeftDrugmanView	m_leftdrugmanview;


public:
	enum { IDD = IDD_LEFT_PANE };
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
};


