#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "xpgroupbox.h"
#include <vector>
#include "afxdtctl.h"
using std::vector;


// CRightMessagereadView 对话框

class CRightMessagereadView : public CDialog
{
	DECLARE_DYNAMIC(CRightMessagereadView)

public:
	CRightMessagereadView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightMessagereadView();

// 对话框数据
	enum { IDD = IDD_RIGHT_MESSAGEREAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	CListBox m_messlist;
	virtual BOOL OnInitDialog();
//	CListCtrl m_messlist;
	CListCtrl m_messhis;
//	CListCtrl m_doclist;
//	afx_msg void OnBnClickedQue();
//	CComboBox m_quetype;
//	CEdit m_continfo;
	BOOL contactchosen;
//	afx_msg void OnNMClickDoclist(NMHDR *pNMHDR, LRESULT *pResult);
	int m_doclist_row;
	afx_msg void OnBnClickedSendmess();
	CEdit m_sendmesstext;
	afx_msg void OnBnClickedUpdate();
//	afx_msg void OnNMKillfocusDoclist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CXPGroupBox m_messhisgroup;
	CXPGroupBox m_messreadgroup;
	CXPGroupBox m_sendmessgroup;
	afx_msg void OnBnClickedBack();
	vector<CString> vec_messread;
	vector<CString> messread;
	vector<CString> vecSenderID;
	vector<vector<CString>> messinfo;
	CString ob_cell;
protected:
	afx_msg LRESULT OnSumesssend(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSumessread(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMessReadYesToNo(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnNMClickMesshis(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_editmessinfo;
	afx_msg void OnBnClickedQue();
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	afx_msg void OnBnClickedButton1();
	CString m_messsend1;
};
