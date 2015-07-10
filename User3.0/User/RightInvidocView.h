#pragma once
#include "afxcmn.h"


// CRightInvidocView 对话框

class CRightInvidocView : public CDialog
{
	DECLARE_DYNAMIC(CRightInvidocView)

public:
	CRightInvidocView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightInvidocView();

// 对话框数据
	enum { IDD = IDD_RIGHT_INVIDOC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_finddoclist;
	virtual BOOL OnInitDialog();
};
