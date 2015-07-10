#pragma once
#include "atltime.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CRightAddinfoView 对话框

class CRightAddinfoView : public CDialog
{
	DECLARE_DYNAMIC(CRightAddinfoView)

public:
	CRightAddinfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAddinfoView();

// 对话框数据
	enum { IDD = IDD_RIGHT_ADDINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
//	CEdit m_drug;
//	CEdit m_drugamount;

	CDateTimeCtrl m_drugstartdate;
	CDateTimeCtrl m_drugenddate;
	CDateTimeCtrl m_drugtime;
	CEdit m_drug;
	CEdit m_drugamount;
	CDateTimeCtrl m_drugtime2;
	CDateTimeCtrl m_drugtime3;
	afx_msg void OnCbnSelendokTimes();
	CComboBox m_times;
};
