#pragma once
#include "afxwin.h"
#include "btnst.h"


// CRightLoginView 对话框

class CRightLoginView : public CDialog
{
	DECLARE_DYNAMIC(CRightLoginView)

public:
	CRightLoginView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightLoginView();

// 对话框数据
	enum { IDD = IDD_RIGHT_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedFindpass();
	afx_msg void OnBnClickedSubmit();
	CString m_account;
	CString m_password;

	CFont m_compfont;
	CFont m_regfont;
	CFont m_errfont;
	static int m_trynum;
	afx_msg void OnBnClickedReg();
	CButtonST m_reg;
	CButtonST m_findpass;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CBitmap m_BKbitmap;
	afx_msg void OnPaint();
protected:
	afx_msg LRESULT OnServerlogon(WPARAM wParam, LPARAM lParam);
};
