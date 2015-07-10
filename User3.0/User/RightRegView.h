#pragma once
#include "afxwin.h"
#include "xpgroupbox.h"
#include "user.h"


// CRightRegView 对话框

class CRightRegView : public CDialog
{
	DECLARE_DYNAMIC(CRightRegView)

public:
	CRightRegView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightRegView();

// 对话框数据
	enum { IDD = IDD_RIGHT_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
//	afx_msg LRESULT OnReg(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	CBrush m_brush;
	CFont  m_font;
	CFont  m_font_att;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	CStatic m_healgroup;
	virtual BOOL OnInitDialog();
//	CXPGroupBox m_healgroup;
//	CXPGroupBox m_latestgroup;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnStnClickedDrink();
//	afx_msg void OnBnClickedReg();
	afx_msg void OnBnClickedNext();
	CXPGroupBox m_verygroup;
	CXPGroupBox m_basicinfogroup;
	afx_msg void OnBnClickedFindpass();
	afx_msg void OnBnClickedVerify();
	CEdit m_cellnum;
	CEdit m_serialnum;
	CEdit m_password;
	CEdit m_passwordag;
	CEdit m_name;
//	CEdit m_idnumber;
	afx_msg void OnBnClickedReg();
	CComboBox m_gender;
	CString serialnumstr;
	User_BaseInfo userbaseinfo;
	afx_msg void OnPaint();
protected:
//	afx_msg LRESULT OnRecvData(WPARAM wParam, LPARAM lParam);
	
public:
//	afx_msg void OnBnClickedButton1();
protected:
//	afx_msg LRESULT OnReg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSuregvery(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSuregvery1(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSureg(WPARAM wParam, LPARAM lParam);
public:
	CString m_age;
	CString m_cell;
	afx_msg void OnBnClickedBtnBack();
};
