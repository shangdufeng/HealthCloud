#pragma once
#include "xpgroupbox.h"


// CRightChgperinfoView 对话框

class CRightChgperinfoView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgperinfoView)

public:
	CRightChgperinfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightChgperinfoView();

// 对话框数据
	enum { IDD = IDD_RIGHT_CHGPERINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	
	CXPGroupBox m_chgperinfo;
	CXPGroupBox m_chguserinfo;
	CString m_cellnum;
	afx_msg void OnBnClickedReg();
	CString m_name;
	//CString m_idnum;
	CString m_gender;
	CString m_job;
	CString m_address;
	CString m_emercont;
	CString m_bloodtype;
	CString m_contactnum;
//	CString m_surgery;
//	CString m_disease;
//	CString m_family;
	CString m_smoke;
	CString m_drink;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CString m_surgery;
	CString m_disease;
	CString m_family;
	CString m_drug;
protected:
	afx_msg LRESULT OnSubaseinforead(WPARAM wParam, LPARAM lParam);
public:
	CString m_birth;
protected:
	afx_msg LRESULT OnSubaseinfoinput(WPARAM wParam, LPARAM lParam);
};
