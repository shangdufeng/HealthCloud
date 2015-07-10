#pragma once
#include "xpgroupbox.h"
#include "FTPCtrl.h"


// CRightInputView 对话框

class CRightInputView : public CDialog
{
	DECLARE_DYNAMIC(CRightInputView)

public:
	CRightInputView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightInputView();

// 对话框数据
	enum { IDD = IDD_RIGHT_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_weight;
	CString m_height;
	CString m_diastolic;
	CString m_systolic;
	CString m_sugar;
	CString m_oxygen;
	CString m_rate;
	CFTPCtrl ftpctrl;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnKillfocusHeight();
	CString m_BMI;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CXPGroupBox m_inputinfo;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBack();
	afx_msg void OnEnKillfocusWeight();
protected:
//	afx_msg LRESULT OnLatestinput(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHealinfoinput(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedBtnUploadfile();
	BOOL PutFile(CString strSourceName, CString strDestName);
	CString m_path;
	CString m_oxygen3;
};
