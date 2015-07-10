#pragma once


// CLeftDrugmanView �Ի���

class CLeftDrugmanView : public CDialog
{
	DECLARE_DYNAMIC(CLeftDrugmanView)

public:
	CLeftDrugmanView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLeftDrugmanView();

// �Ի�������
	enum { IDD = IDD_LEFT_DRUGMAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnAccman();
	afx_msg void OnBnClickedBtnHealinfo();
	afx_msg void OnBnClickedBtnHealexpert();
	afx_msg void OnBnClickedBtnHealplat();
	afx_msg void OnBnClickedBtnAdddrug();
	afx_msg void OnBnClickedBtnChangedrug();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CButtonST m_btnleftaccman;
	CButtonST m_btnleftdrugman;
	CButtonST m_btnlefthealexpert;
	CButtonST m_btnhealinfo;
	CButtonST m_btnhealplat;

	CButtonST m_btnaddinfo;
	CButtonST m_btnchginfo;

	CBrush m_brush;

	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
};
