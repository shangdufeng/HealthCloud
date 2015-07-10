#pragma once
#include "xpgroupbox.h"
#include "btnst.h"


// CRightWelcomeView 对话框

class CRightWelcomeView : public CDialog
{
	DECLARE_DYNAMIC(CRightWelcomeView)

public:
	CRightWelcomeView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightWelcomeView();

// 对话框数据
	enum { IDD = IDD_RIGHT_WELCOME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CBrush m_brushbk;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CFont m_info_font;
	CFont m_infotext_font;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnMess();
	afx_msg void OnBnClickedBtnRep();
	CButtonST m_messread;
	CButtonST m_repread;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedBtnUpload();
	afx_msg void OnBnClickedBtnInfo();
	CButtonST m_upload;
	CButtonST m_platinfo;

	int m_MessUnread;
	int m_RepUnread;
//	afx_msg void OnBtnPlatuse();
	afx_msg void OnBnClickedBtnPlatinfo();
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedButton1();
protected:
	afx_msg LRESULT OnSuwel(WPARAM wParam, LPARAM lParam);
};
