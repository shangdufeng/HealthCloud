#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"
#include "afxdialogex.h"
#include <afxinet.h>
#include "FTPFILE.H"
#include "FTPCtrl.h"
#include "xpgroupbox.h"


// CRightExcepinfoView 对话框

class CRightExcepinfoView : public CDialog
{
	DECLARE_DYNAMIC(CRightExcepinfoView)

public:
	CRightExcepinfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightExcepinfoView();

// 对话框数据
	enum { IDD = IDD_RIGHT_EXCEPINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_excepinfolist;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	afx_msg LRESULT OnSuexcepread(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedQue();
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	afx_msg void OnNMClickExcepinfolist(NMHDR *pNMHDR, LRESULT *pResult);
	int sel_item;
	CString sel_sourcename;
	afx_msg void OnBnClickedDown();
	BOOL GetFile(CString strSourceName, CString strDestName);
	CString	m_strFtpSite;
	CString	m_strName;
	CString	m_strPwd;
	CFTPCtrl ftpctrl;
	CXPGroupBox m_excep;
};
