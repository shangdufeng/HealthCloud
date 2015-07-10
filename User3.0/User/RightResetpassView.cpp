// RightResetpassView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightResetpassView.h"
#include "afxdialogex.h"


// CRightResetpassView �Ի���

IMPLEMENT_DYNAMIC(CRightResetpassView, CDialog)

CRightResetpassView::CRightResetpassView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightResetpassView::IDD, pParent)
	, m_verycode(_T(""))
	, m_newpass1(_T(""))
	, m_pass2(_T(""))
{
	theApp.m_prightresetpassview=this;
}

CRightResetpassView::~CRightResetpassView()
{
}

void CRightResetpassView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CELLVERI, m_cellveri);
	DDX_Control(pDX, IDC_NEWPASS, m_newpass);
	DDX_Control(pDX, IDC_RESETPASS, m_resetpass);
	DDX_Text(pDX, IDC_EDIT1, m_verycode);
	DDX_Control(pDX, IDC_NEWCODE, m_newcode);
	DDX_Control(pDX, IDC_NEWCODE2, m_newcode2);
	DDX_Control(pDX, IDC_SUBNEWCODE, m_subnewcode);
	DDX_Text(pDX, IDC_NEWCODE, m_newpass1);
	DDX_Text(pDX, IDC_NEWCODE2, m_pass2);
}


BEGIN_MESSAGE_MAP(CRightResetpassView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CRightResetpassView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRightResetpassView::OnBnClickedButton2)
	ON_MESSAGE(WM_SUSUBCODE, &CRightResetpassView::OnSusubcode)
	ON_BN_CLICKED(IDC_SUBNEWCODE, &CRightResetpassView::OnBnClickedSubnewcode)
	ON_MESSAGE(WM_PWRESET, &CRightResetpassView::OnPWReset)
END_MESSAGE_MAP()


// CRightResetpassView ��Ϣ�������


BOOL CRightResetpassView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightResetpassView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_resetpass.SetBorderColor(RGB(136,203,103));
	m_resetpass.SetFontBold(TRUE);

	m_cellveri.SetBorderColor(RGB(136,203,103));
	m_cellveri.SetFontBold(TRUE);
	m_cellveri.SetBackgroundColor(RGB(66,210,87));
	m_cellveri.SetFontSize(13);

	m_newpass.SetBorderColor(RGB(136,203,103));
	m_newpass.SetFontBold(TRUE);
	m_newpass.SetBackgroundColor(RGB(66,210,87));
	m_newpass.SetFontSize(13);

	m_newcode.EnableWindow(FALSE);
	m_newcode2.EnableWindow(FALSE);
	m_subnewcode.EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightResetpassView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CPen pen(PS_SOLID,1,RGB(205,231,208));
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BKIN);   
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	CPen* pOldpen=dc.SelectObject(&pen);
	dc.FillRect(CRect(0,0,850,800),&brush);  
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldpen);
}


HBRUSH CRightResetpassView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_REGCODE)) 
	{ 

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CRightResetpassView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.socketclient.UserSendCode();
}


void CRightResetpassView::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	theApp.socketclient.UserSubCode(m_verycode);
}


afx_msg LRESULT CRightResetpassView::OnSusubcode(WPARAM wParam, LPARAM lParam)
{
	    vector<CString> vec;
		
	    theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
		AfxMessageBox(vec.at(1));
		m_newcode.EnableWindow(TRUE);
		m_newcode2.EnableWindow(TRUE);
		m_subnewcode.EnableWindow(TRUE);



	return 0;
}

afx_msg LRESULT CRightResetpassView::OnPWReset(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
	GetDlgItem(IDC_REGCODE)->SetWindowText(vec.at(1));
	return 0;
}


void CRightResetpassView::OnBnClickedSubnewcode()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_pass2==m_newpass1)
	{
		theApp.socketclient.UserNewPass(m_newpass1);
	}
	else
	{
		AfxMessageBox(_T("�������벻һ�£�"));
	}
}
