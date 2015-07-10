// RightContactView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightContactView.h"
#include "afxdialogex.h"


// CRightContactView �Ի���

IMPLEMENT_DYNAMIC(CRightContactView, CDialog)

CRightContactView::CRightContactView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightContactView::IDD, pParent)
{
	theApp.m_prightcontactview=this;
}

CRightContactView::~CRightContactView()
{
}

void CRightContactView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONTGROUP, m_contgroup);
}


BEGIN_MESSAGE_MAP(CRightContactView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightContactView ��Ϣ�������


BOOL CRightContactView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightContactView::OnPaint()
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


HBRUSH CRightContactView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


BOOL CRightContactView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_contgroup.SetBorderColor(RGB(136,203,103));
	m_contgroup.SetFontBold(TRUE);
	m_contgroup.SetBackgroundColor(RGB(66,210,87));
	m_contgroup.SetFontSize(13);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
