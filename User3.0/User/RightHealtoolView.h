#pragma once
#include "afxcmn.h"


// CRightHealtoolView �Ի���

class CRightHealtoolView : public CDialog
{
	DECLARE_DYNAMIC(CRightHealtoolView)

public:
	CRightHealtoolView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightHealtoolView();

// �Ի�������
	enum { IDD = IDD_RIGHT_HEALTOOL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl m_input;
	virtual BOOL OnInitDialog();
	CListCtrl m_output;
};
