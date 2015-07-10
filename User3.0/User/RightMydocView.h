#pragma once
#include "xpgroupbox.h"


// CRightMydocView �Ի���

class CRightMydocView : public CDialog
{
	DECLARE_DYNAMIC(CRightMydocView)

public:
	CRightMydocView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightMydocView();

// �Ի�������
	enum { IDD = IDD_RIGHT_MYDOC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	CXPGroupBox m_mydoc;
	vector<CString> vec_mydocinfo;
	vector<CString> mydocinfo;
protected:
	afx_msg LRESULT OnSudocinfo(WPARAM wParam, LPARAM lParam);
public:
//	CString m_name;
//	CString m_cellphone;
	CString m_doctorname;
	CString m_gender;
	CString m_cellnumber;
	CString m_obcell;
	CString m_title;
	CString m_hospital;
	CString m_duty;
	CString m_adminoffice;
	CString m_major;
	CString m_school;
	CString m_consulttime;
	CString m_replytime;
	CString m_eduback;
	afx_msg void OnBnClickedSendmess();
};
