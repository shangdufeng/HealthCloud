#pragma once


// CLeftHealexpertView 对话框

class CLeftHealexpertView : public CDialog
{
	DECLARE_DYNAMIC(CLeftHealexpertView)

public:
	CLeftHealexpertView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLeftHealexpertView();

// 对话框数据
	enum { IDD = IDD_LEFT_HEALEXPERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAccman();
	afx_msg void OnBnClickedBtnHealinfo();
	afx_msg void OnBnClickedBtnDrugman();
	afx_msg void OnBnClickedBtnHealplat();
//	afx_msg void OnBnClickedBtnExpertlist();
	afx_msg void OnBnClickedBtnDoclist();
	afx_msg void OnBnClickedBtnMydoc();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

	CButtonST m_btnleftaccman;
	CButtonST m_btnleftdrugman;
	CButtonST m_btnlefthealexpert;
	CButtonST m_btnhealinfo;
	CButtonST m_btnhealplat;

	CButtonST m_btndoclist;
	CButtonST m_btninvidoc;
	CButtonST m_btnmydoc;

	CBrush m_brush;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnInvidoc();
	afx_msg void OnPaint();
};
