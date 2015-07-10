#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "atltime.h"
//#include "User.h"
#include <vector>
#include "xpgroupbox.h"
using namespace std;


// CRightChangeinfoView 对话框

class CRightChangeinfoView : public CDialog
{
	DECLARE_DYNAMIC(CRightChangeinfoView)

public:
	CRightChangeinfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightChangeinfoView();
	
// 对话框数据
	enum { IDD = IDD_RIGHT_CHANGEINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_druguseinfo;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAdd();
	static int stanum;
	afx_msg void OnBnClickedDel();
	CEdit m_edit;
	afx_msg void OnNMDblclkDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult);
	int m_row;
	int m_column;
//	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnEnKillfocusEdit();
//	afx_msg void OnNMClickDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMKillfocusDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult);
	static int m_judge;
	static int m_judge1;
	afx_msg void OnBnClickedOk();
	CDateTimeCtrl m_date;
	CDateTimeCtrl m_time;
	afx_msg void OnNMKillfocusDate(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMKillfocusTime(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnDtnDatetimechangeDate(NMHDR *pNMHDR, LRESULT *pResult);
//	CTime m_getdate;
//	CTime m_gettime;
	CXPGroupBox m_setgroup;
	CXPGroupBox m_information;
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	

	vector<User_DrugInfo> m_User_DrugInfo_list;
	vector<CString> vec_drug;
	
//	afx_msg void OnBnClickedUpdate();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	afx_msg LRESULT OnServerdrugread(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSudrugupdate(WPARAM wParam, LPARAM lParam);
public:
//	afx_msg void OnBnClickedQue();
	afx_msg void OnBnClickedQue();
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
};
