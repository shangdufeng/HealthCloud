#pragma once
#include "afxcmn.h"
#include "xpgroupbox.h"
#include "afxwin.h"


// CRightDoclistView 对话框

class CRightDoclistView : public CDialog
{
	DECLARE_DYNAMIC(CRightDoclistView)

public:
	CRightDoclistView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightDoclistView();

// 对话框数据
	enum { IDD = IDD_RIGHT_DOCLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_doclist;
	virtual BOOL OnInitDialog();
	CXPGroupBox m_docperinfo;
	CString m_doctorname;
	CString m_gender;
	CString m_cellnumber;
	CString m_title;
	CString m_hospital;
	CString m_duty;
	CString m_adminoffice;
	CString m_major;
	CString m_school;
	CString m_consulttime;
	CString m_eduback;
	CString m_replytime;
//	afx_msg void OnCbnSelendokQuetype();
	CComboBox m_quetype;
	afx_msg void OnBnClickedInvite();
	afx_msg void OnBnClickedBtnQue();
	CEdit m_quetext;
	afx_msg void OnCbnSelendokQuetype();
//	afx_msg void OnCbnEditchangeQuetype();
//	afx_msg void OnCbnSelchangeQuetype();
	int m_row;
	CString seldoc;
	vector<CString> vec_doclist;
	vector<CString> vec_inviexcepinfo;
	afx_msg void OnNMClickDoclist(NMHDR *pNMHDR, LRESULT *pResult);
	
	vector<Doctor_BaseInfo> m_v_docbaseinfo;
	afx_msg void OnBnClickedSdmgtodoc();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	afx_msg LRESULT OnDoctorinfolist(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSudoctorchoose(WPARAM wParam, LPARAM lParam);
public:
	CXPGroupBox m_doc;
};
