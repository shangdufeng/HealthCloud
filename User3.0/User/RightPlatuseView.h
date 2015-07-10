#pragma once
#include "xpgroupbox.h"


// CRightPlatuseView 对话框

class CRightPlatuseView : public CDialog
{
	DECLARE_DYNAMIC(CRightPlatuseView)

public:
	CRightPlatuseView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightPlatuseView();

// 对话框数据
	enum { IDD = IDD_RIGHT_PLATUSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CXPGroupBox m_platuse;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBack();
protected:
	afx_msg LRESULT OnSuplatinforead(WPARAM wParam, LPARAM lParam);
public:
	CString m_usertype;
	CString m_freespace;
	CString m_deadline;
	CString m_total;
};
