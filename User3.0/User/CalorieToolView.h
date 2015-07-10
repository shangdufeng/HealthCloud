#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "xpgroupbox.h"


// CCalorieToolView 对话框

class CCalorieToolView : public CDialog
{
	DECLARE_DYNAMIC(CCalorieToolView)

public:
	CCalorieToolView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCalorieToolView();

// 对话框数据
	enum { IDD = IDD_CTEST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
private:
	CListCtrl m_lsc;
	CListCtrl m_lsc2;
	void Read();
	void Read1();

// 	CStatic stac;
// 	CStatic stac1;
	float m_hot;
	int m_nCount;//饭菜计数
	int m_mCount;//运动计数

	CString m_energyperg;//每克所含热量
	CString m_energyperhour;//每小时消耗热量
	double sum;
public:
	afx_msg void OnBnClickedButton1();
private:
	CComboBox m_combo2;
public:
	float m_weught1;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_combo1;
	afx_msg void OnBnClicked1017();
	float m_hour;
	afx_msg void OnBnClickedButton9();
	int m_age;
	CString m_sex;
	float m_weight4;
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	CStatic m_stac1;
	CStatic m_stac;
	CXPGroupBox m_cal;
	CXPGroupBox m_bas;
	CXPGroupBox m_total;
};
