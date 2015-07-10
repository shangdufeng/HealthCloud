#pragma once
#include "xpgroupbox.h"
#include "afxwin.h"


// CRightResetpassView 对话框

class CRightResetpassView : public CDialog
{
	DECLARE_DYNAMIC(CRightResetpassView)

public:
	CRightResetpassView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightResetpassView();

// 对话框数据
	enum { IDD = IDD_RIGHT_RESETPASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CXPGroupBox m_cellveri;
	CXPGroupBox m_newpass;
	virtual BOOL OnInitDialog();
	CXPGroupBox m_resetpass;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton1();
	CString m_verycode;
	afx_msg void OnBnClickedButton2();
protected:
	afx_msg LRESULT OnSusubcode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnPWReset(WPARAM wParam, LPARAM lParam);
public:
	CEdit m_newcode;
	CEdit m_newcode2;
	CButton m_subnewcode;
	afx_msg void OnBnClickedSubnewcode();
	CString m_newpass1;
	CString m_pass2;
};
