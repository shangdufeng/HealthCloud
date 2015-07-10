#pragma once
#include "afxwin.h"


// CRightReg2View 对话框

class CRightReg2View : public CDialog
{
	DECLARE_DYNAMIC(CRightReg2View)

public:
	CRightReg2View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightReg2View();

// 对话框数据
	enum { IDD = IDD_RIGHT_REG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPre();
	CString serinum;
	CXPGroupBox m_healgroup;
	CXPGroupBox m_latestgroup;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedReg();
	CString m_job;
	CString m_add;
	CString m_emercont;
	CString m_contnum;
	CComboBox m_bloodtype;
//	CComboBox m_surgery;
//	CComboBox m_disease;
//	CComboBox m_family;
	CComboBox m_smoke;
	CComboBox m_drink;
//	CString m_diastolic;
//	CString m_systolic;
//	CString m_sugar;
//	CString m_height;
//	CString m_weight;
//	CString m_waistline;
//	CString m_UA;
//	CString m_oxygen;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CString m_surgery;
	CString m_disease;
	CString m_family;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_drug;
	
protected:
//	afx_msg LRESULT OnSuregvery1(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSureg1(WPARAM wParam, LPARAM lParam);
};
