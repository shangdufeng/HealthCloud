#pragma once


// CRightContactView 对话框

class CRightContactView : public CDialog
{
	DECLARE_DYNAMIC(CRightContactView)

public:
	CRightContactView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightContactView();

// 对话框数据
	enum { IDD = IDD_RIGHT_CONTACTUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CXPGroupBox m_contgroup;
	virtual BOOL OnInitDialog();
};
