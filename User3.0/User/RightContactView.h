#pragma once


// CRightContactView �Ի���

class CRightContactView : public CDialog
{
	DECLARE_DYNAMIC(CRightContactView)

public:
	CRightContactView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRightContactView();

// �Ի�������
	enum { IDD = IDD_RIGHT_CONTACTUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CXPGroupBox m_contgroup;
	virtual BOOL OnInitDialog();
};
