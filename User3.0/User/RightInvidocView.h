#pragma once
#include "afxcmn.h"


// CRightInvidocView �Ի���

class CRightInvidocView : public CDialog
{
	DECLARE_DYNAMIC(CRightInvidocView)

public:
	CRightInvidocView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightInvidocView();

// �Ի�������
	enum { IDD = IDD_RIGHT_INVIDOC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_finddoclist;
	virtual BOOL OnInitDialog();
};
