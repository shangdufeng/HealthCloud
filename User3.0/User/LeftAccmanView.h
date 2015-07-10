#pragma once
#include "btnst.h"


// CLeftAccmanView 对话框

class CLeftAccmanView : public CDialog
{
	DECLARE_DYNAMIC(CLeftAccmanView)

public:
	CLeftAccmanView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLeftAccmanView();

// 对话框数据
	enum { IDD = IDD_LEFT_ACCMAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnDrugman();
	virtual BOOL OnInitDialog();
	CButtonST m_btnleftaccman;
	CButtonST m_btnleftdrugman;
	CButtonST m_btnlefthealexpert;
	CButtonST m_btnhealinfo;
	CButtonST m_btnhealplat;

	CButtonST m_btnchangeinfo;
	CButtonST m_btnresetpass;
	CButtonST m_btnplatuse;
	CButtonST m_btncharge;

	afx_msg void OnBnClickedBtnHealinfo();
	afx_msg void OnBnClickedBtnHealexpert();
	afx_msg void OnBnClickedBtnHealplat();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	CBrush m_brush;
	CFont m_font;
	afx_msg void OnBnClickedBtnChgperinfo();
	afx_msg void OnBnClickedBtnResetpass();
	afx_msg void OnBnClickedBtnPlatuse();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
};
