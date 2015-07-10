#pragma once
#include "btnst.h"


// CLeftHealplatView 对话框

class CLeftHealplatView : public CDialog
{
	DECLARE_DYNAMIC(CLeftHealplatView)

public:
	CLeftHealplatView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLeftHealplatView();

// 对话框数据
	enum { IDD = IDD_LEFT_HEALPLAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAccman();
	afx_msg void OnBnClickedBtnHealinfo();
	afx_msg void OnBnClickedBtnHealexpert();
	afx_msg void OnBnClickedBtnDrugman();
	afx_msg void OnBnClickedBtnHealplat();
	afx_msg void OnBnClickedBtnReg();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnReadmess();
	afx_msg void OnBnClickedBtnContact();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

	CButtonST m_btnleftaccman;
	CButtonST m_btnleftdrugman;
	CButtonST m_btnlefthealexpert;
	CButtonST m_btnhealinfo;
	CButtonST m_btnhealplat;

	CButtonST m_btnlogin;
	CButtonST m_btnreg;
	CButtonST m_btnreadmess;
	CButtonST m_btncontact;
	CButtonST m_btnexit;
	CButtonST m_btnwelcome;

	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnWelcome();
//	CButtonST m_welcome;
	
};
