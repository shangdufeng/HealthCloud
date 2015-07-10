#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"
#include "xpgroupbox.h"
#include "afxwin.h"


// CRightHisqueView �Ի���

class CRightHisqueView : public CDialog
{
	DECLARE_DYNAMIC(CRightHisqueView)

public:
	CRightHisqueView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightHisqueView();

// �Ի�������
	enum { IDD = IDD_RIGHT_HISQUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	CListCtrl m_hisquelist;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedQue();
protected:
	afx_msg LRESULT OnSuhishealread(WPARAM wParam, LPARAM lParam);

	CString m_Type;
public:
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	CXPGroupBox m_HisQue;
	CComboBox m_type;
};
