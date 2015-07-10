#pragma once


// CLeftHealinfoView �Ի���

class CLeftHealinfoView : public CDialog
{
	DECLARE_DYNAMIC(CLeftHealinfoView)

public:
	CLeftHealinfoView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLeftHealinfoView();

// �Ի�������
	enum { IDD = IDD_LEFT_HEALINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAccman();
	afx_msg void OnBnClickedBtnHealexpert();
	afx_msg void OnBnClickedBtnDrugman();
	afx_msg void OnBnClickedBtnHealplat();
	afx_msg void OnBnClickedBtnInput();
	afx_msg void OnBnClickedBtnLatest();
	afx_msg void OnBnClickedBtnHisque();
	afx_msg void OnBnClickedBtnHealrep();
//	afx_msg void OnBnClickedBtnHealrep2();
	afx_msg void OnBnClickedBtnExcepinfo();
	afx_msg void OnBnClickedBtnHealtool();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

	CButtonST m_btnleftaccman;
	CButtonST m_btnleftdrugman;
	CButtonST m_btnlefthealexpert;
	CButtonST m_btnhealinfo;
	CButtonST m_btnhealplat;

	CButtonST m_btninput;
	CButtonST m_btnlatest;
	CButtonST m_btnhisque;
	CButtonST m_btnhealrep;
	CButtonST m_btnexcepinfo;
	CButtonST m_btnhealtool;

	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
};
