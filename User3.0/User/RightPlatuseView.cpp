// RightPlatuseView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightPlatuseView.h"
#include "afxdialogex.h"


// CRightPlatuseView �Ի���

IMPLEMENT_DYNAMIC(CRightPlatuseView, CDialog)

CRightPlatuseView::CRightPlatuseView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightPlatuseView::IDD, pParent)
	, m_usertype(_T(""))
	, m_freespace(_T(""))
	, m_deadline(_T(""))
	, m_total(_T(""))
{
	theApp.m_prightplatuseview=this;
}

CRightPlatuseView::~CRightPlatuseView()
{
}

void CRightPlatuseView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PALTUSE, m_platuse);
	DDX_Text(pDX, IDC_EDIT1, m_usertype);
	DDX_Text(pDX, IDC_EDIT4, m_freespace);
	DDX_Text(pDX, IDC_EDIT3, m_deadline);
	DDX_Text(pDX, IDC_EDIT2, m_total);
}


BEGIN_MESSAGE_MAP(CRightPlatuseView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BACK, &CRightPlatuseView::OnBnClickedBack)
	ON_MESSAGE(WM_SUPLATINFOREAD, &CRightPlatuseView::OnSuplatinforead)
END_MESSAGE_MAP()


// CRightPlatuseView ��Ϣ�������


BOOL CRightPlatuseView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightPlatuseView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_platuse.SetBorderColor(RGB(136,203,103));
	//m_platuse.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW);
	//m_platuse.SetBackgroundColor(RGB(201, 201, 151));
	m_platuse.SetFontBold(TRUE);
	m_platuse.SetBackgroundColor(RGB(66,210,87));
	m_platuse.SetFontSize(13);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightPlatuseView::OnPaint()
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


HBRUSH CRightPlatuseView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)||(pWnd->GetDlgCtrlID()==IDC_PALTUSE)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}


	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CRightPlatuseView::OnBnClickedBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}


afx_msg LRESULT CRightPlatuseView::OnSuplatinforead(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_platuse;
	CString str_plat;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_platuse);
	str_plat=vec_platuse[1];
	vec_platuse.clear();
	theApp.SplitString(str_plat,_T(","),TRUE,vec_platuse);
	if (vec_platuse.at(0)==_T("1"))
	{
		m_usertype=_T("�����û�");
	}
	else if(vec_platuse.at(0)==_T("0"))
	{
		m_usertype=_T("�����û�");
	}
	else
	{
		m_usertype=vec_platuse.at(0);
	}
	
	m_deadline=vec_platuse.at(3);
	m_freespace=vec_platuse.at(2);
	m_total=vec_platuse.at(1);
// 	if (vec_platuse.at(0)==_T("�����û�"))
// 	{
// 		m_total=_T("100");
// 	}
// 	else
// 	{
// 		m_total=_T("1000");
	//}
	UpdateData(FALSE);
	return 0;
}
