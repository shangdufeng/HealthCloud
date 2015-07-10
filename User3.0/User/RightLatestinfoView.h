#pragma once
#include "afxcmn.h"
#include "cdpdfview.h"
#include "xpgroupbox.h"


// CRightLatestinfoView 对话框

class CRightLatestinfoView : public CDialog
{
	DECLARE_DYNAMIC(CRightLatestinfoView)

public:
	CRightLatestinfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightLatestinfoView();

// 对话框数据
	enum { IDD = IDD_RIGHT_LATESTINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	int nA4Width, nA4Hight;
	vector<CString> vec_HrtRep;
	CString strRecv;
	void GenerateWord(vector<CString> vec);
	void PreView(CDC* pDC,vector<CString> vec);
	CRect rt1,rt2;//存储心电/血压分析报告
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_latestinfo;
	virtual BOOL OnInitDialog();
	//CDPdfview m_pdfhealrep;
	afx_msg void OnBnClickedQue();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	afx_msg LRESULT OnSulatesthealread(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHrtRep(WPARAM wParam, LPARAM lParam);
public:
/*	afx_msg void OnNMClickLatestinfo(NMHDR *pNMHDR, LRESULT *pResult);*/
	afx_msg void OnBnClickedBtnBld();
	afx_msg void OnBnClickedBtnHrt();
	afx_msg void OnBnClickedDown();
	afx_msg void OnBnClickedReturn();
	CXPGroupBox m_Group;
};
