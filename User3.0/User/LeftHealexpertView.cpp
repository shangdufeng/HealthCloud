// LeftHealexpertView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "LeftHealexpertView.h"
#include "afxdialogex.h"


// CLeftHealexpertView �Ի���

IMPLEMENT_DYNAMIC(CLeftHealexpertView, CDialog)

CLeftHealexpertView::CLeftHealexpertView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftHealexpertView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
}

CLeftHealexpertView::~CLeftHealexpertView()
{
}

void CLeftHealexpertView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftHealexpertView, CDialog)
	ON_BN_CLICKED(IDC_BTN_ACCMAN, &CLeftHealexpertView::OnBnClickedBtnAccman)
	ON_BN_CLICKED(IDC_BTN_HEALINFO, &CLeftHealexpertView::OnBnClickedBtnHealinfo)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftHealexpertView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftHealexpertView::OnBnClickedBtnHealplat)
//	ON_BN_CLICKED(IDC_BTN_EXPERTLIST, &CLeftHealexpertView::OnBnClickedBtnExpertlist)
ON_BN_CLICKED(IDC_BTN_DOCLIST, &CLeftHealexpertView::OnBnClickedBtnDoclist)
ON_BN_CLICKED(IDC_BTN_MYDOC, &CLeftHealexpertView::OnBnClickedBtnMydoc)
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_BTN_INVIDOC, &CLeftHealexpertView::OnBnClickedBtnInvidoc)
ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftHealexpertView ��Ϣ�������


void CLeftHealexpertView::OnBnClickedBtnAccman()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftaccmanview);
}


void CLeftHealexpertView::OnBnClickedBtnHealinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealinfoview);
}


void CLeftHealexpertView::OnBnClickedBtnDrugman()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


void CLeftHealexpertView::OnBnClickedBtnHealplat()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}



void CLeftHealexpertView::OnBnClickedBtnDoclist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightdoclistview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightdoclistview;
}


void CLeftHealexpertView::OnBnClickedBtnMydoc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightmydocview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightmydocview;

	theApp.socketclient.UserDocInfo();
}


BOOL CLeftHealexpertView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CLeftHealexpertView::OnInitDialog()
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


	m_btndoclist.SubclassDlgItem(IDC_BTN_DOCLIST,this);
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btndoclist.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btninvidoc.SubclassDlgItem(IDC_BTN_INVIDOC,this);
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btninvidoc.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnmydoc.SubclassDlgItem(IDC_BTN_MYDOC,this);
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnmydoc.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CLeftHealexpertView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return hbr;
	return m_brush;
}


void CLeftHealexpertView::OnBnClickedBtnInvidoc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightinvidocview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightinvidocview;
}


void CLeftHealexpertView::OnPaint()
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
