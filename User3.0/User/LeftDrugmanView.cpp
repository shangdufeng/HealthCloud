// LeftDrugmanView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "LeftDrugmanView.h"
#include "afxdialogex.h"


// CLeftDrugmanView �Ի���

IMPLEMENT_DYNAMIC(CLeftDrugmanView, CDialog)

CLeftDrugmanView::CLeftDrugmanView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftDrugmanView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
}

CLeftDrugmanView::~CLeftDrugmanView()
{
}

void CLeftDrugmanView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftDrugmanView, CDialog)
//	ON_BN_CLICKED(IDC_BUTTON1, &CLeftDrugmanView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_ACCMAN, &CLeftDrugmanView::OnBnClickedBtnAccman)
	ON_BN_CLICKED(IDC_BTN_HEALINFO, &CLeftDrugmanView::OnBnClickedBtnHealinfo)
	ON_BN_CLICKED(IDC_BTN_HEALEXPERT, &CLeftDrugmanView::OnBnClickedBtnHealexpert)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftDrugmanView::OnBnClickedBtnHealplat)
	ON_BN_CLICKED(IDC_BTN_ADDDRUG, &CLeftDrugmanView::OnBnClickedBtnAdddrug)
	ON_BN_CLICKED(IDC_BTN_CHANGEDRUG, &CLeftDrugmanView::OnBnClickedBtnChangedrug)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftDrugmanView ��Ϣ�������


//void CLeftDrugmanView::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}


void CLeftDrugmanView::OnBnClickedBtnAccman()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftaccmanview);
}


void CLeftDrugmanView::OnBnClickedBtnHealinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealinfoview);
}


void CLeftDrugmanView::OnBnClickedBtnHealexpert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealexpertview);
}


void CLeftDrugmanView::OnBnClickedBtnHealplat()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}


void CLeftDrugmanView::OnBnClickedBtnAdddrug()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightaddinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightaddinfoview;
	
}


void CLeftDrugmanView::OnBnClickedBtnChangedrug()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightchangeinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightchangeinfoview;
}


BOOL CLeftDrugmanView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CLeftDrugmanView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_btnleftaccman.SubclassDlgItem(IDC_BTN_ACCMAN,this);
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//����ڰ�ť�ⱳ����ɫ
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//����ڰ�ť��������ɫ
	//m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//��ť���º󱳾���ɫ
	//m_btnleftaccman.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnleftdrugman.SubclassDlgItem(IDC_BTN_DRUGMAN,this);
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//����ڰ�ť�ⱳ����ɫ
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//����ڰ�ť��������ɫ
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//��ť���º󱳾���ɫ
	m_btnleftdrugman.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnlefthealexpert.SubclassDlgItem(IDC_BTN_HEALEXPERT,this);
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//����ڰ�ť�ⱳ����ɫ
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//����ڰ�ť��������ɫ
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//��ť���º󱳾���ɫ
	m_btnlefthealexpert.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnhealinfo.SubclassDlgItem(IDC_BTN_HEALINFO,this);
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//����ڰ�ť�ⱳ����ɫ
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//����ڰ�ť��������ɫ
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//��ť���º󱳾���ɫ
	m_btnhealinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnhealplat.SubclassDlgItem(IDC_BTN_HEALPLAT,this);
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(67,169,5));//����ڰ�ť�ⱳ����ɫ
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,255,255));//����ڰ�ť��������ɫ
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(67,169,5));//��ť���º󱳾���ɫ
	m_btnhealplat.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ




	m_btnchginfo.SubclassDlgItem(IDC_BTN_CHANGEDRUG,this);
	m_btnchginfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnchginfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnchginfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnchginfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnchginfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnaddinfo.SubclassDlgItem(IDC_BTN_ADDDRUG,this);
	m_btnaddinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnaddinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnaddinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnaddinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnaddinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CLeftDrugmanView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return hbr;
	return m_brush;
}


void CLeftDrugmanView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CPen pen(PS_SOLID,1,RGB(205,231,208));
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_LEFT);   
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	CPen* pOldpen=dc.SelectObject(&pen);
	dc.FillRect(CRect(0,0,150,800),&brush);  
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldpen);
}
