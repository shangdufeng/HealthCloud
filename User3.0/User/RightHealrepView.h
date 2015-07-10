#pragma once
#include "afxcmn.h"
#include "cdpdfview.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CRightHealrepView 对话框

class CRightHealrepView : public CDialog
{
	DECLARE_DYNAMIC(CRightHealrepView)

public:
	CRightHealrepView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightHealrepView();

// 对话框数据
	enum { IDD = IDD_RIGHT_HEALREP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_healreplist;
	virtual BOOL OnInitDialog();
	//CDPdfview m_pdfView;
	afx_msg void OnBnClickedQue();
	CComboBox m_reptype;
	CDateTimeCtrl m_starttime;
	CDateTimeCtrl m_endtime;
	int sel_item;
	vector<CString> m_vecDocName;
	CString sel_sourcename;
	CFTPCtrl ftpctrl;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBack();
protected:
	afx_msg LRESULT OnSurepread(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRepReadYesToNo(WPARAM wParam, LPARAM lParam);
	//CString m_RepType;
	BOOL GetFile(CString strSourceName, CString strDestName);
public:
	CXPGroupBox m_Rep;
	afx_msg void OnNMClickHealreplist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDown();
};
