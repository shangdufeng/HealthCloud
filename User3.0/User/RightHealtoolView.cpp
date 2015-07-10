// RightHealtoolView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightHealtoolView.h"
#include "afxdialogex.h"


// CRightHealtoolView �Ի���

IMPLEMENT_DYNAMIC(CRightHealtoolView, CDialog)

CRightHealtoolView::CRightHealtoolView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightHealtoolView::IDD, pParent)
{
/*	theApp.m_prighthealtoolview=this;*/
}

CRightHealtoolView::~CRightHealtoolView()
{
}

void CRightHealtoolView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT, m_input);
	DDX_Control(pDX, IDC_OUTPUT, m_output);
}


BEGIN_MESSAGE_MAP(CRightHealtoolView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightHealtoolView ��Ϣ�������


BOOL CRightHealtoolView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightHealtoolView::OnPaint()
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


HBRUSH CRightHealtoolView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightHealtoolView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_input.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_input.InsertColumn(0,_T("ʱ��"),LVCFMT_CENTER,100);
	m_input.InsertColumn(1,_T("��������"),LVCFMT_CENTER,150);
	m_input.InsertColumn(2,_T("������"),LVCFMT_CENTER,100);
	m_input.InsertColumn(3,_T("��������"),LVCFMT_CENTER,120);
	
	m_output.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_output.InsertColumn(0,_T("ʱ��"),LVCFMT_CENTER,100);
	m_output.InsertColumn(1,_T("�˶�����"),LVCFMT_CENTER,150);
	m_output.InsertColumn(2,_T("�˶���"),LVCFMT_CENTER,100);
	m_output.InsertColumn(3,_T("��������"),LVCFMT_CENTER,120);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
