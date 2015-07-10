// LeftAccmanView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "LeftAccmanView.h"
#include "afxdialogex.h"



// CLeftAccmanView �Ի���

IMPLEMENT_DYNAMIC(CLeftAccmanView, CDialog)

CLeftAccmanView::CLeftAccmanView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftAccmanView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
	
	m_font.CreatePointFont(200,_T("Arial"),NULL);///////////////����������
	
}

CLeftAccmanView::~CLeftAccmanView()
{
}

void CLeftAccmanView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftAccmanView, CDialog)
//	ON_BN_CLICKED(IDC_BUTTON1, &CLeftAccmanView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftAccmanView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALINFO, &CLeftAccmanView::OnBnClickedBtnHealinfo)
	ON_BN_CLICKED(IDC_BTN_HEALEXPERT, &CLeftAccmanView::OnBnClickedBtnHealexpert)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftAccmanView::OnBnClickedBtnHealplat)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_CHGPERINFO, &CLeftAccmanView::OnBnClickedBtnChgperinfo)
	ON_BN_CLICKED(IDC_BTN_RESETPASS, &CLeftAccmanView::OnBnClickedBtnResetpass)
	ON_BN_CLICKED(IDC_BTN_PLATUSE, &CLeftAccmanView::OnBnClickedBtnPlatuse)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftAccmanView ��Ϣ�������


//void CLeftAccmanView::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}


void CLeftAccmanView::OnBnClickedBtnDrugman()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


BOOL CLeftAccmanView::OnInitDialog()
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




	m_btnchangeinfo.SubclassDlgItem(IDC_BTN_CHGPERINFO,this);
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnchangeinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnresetpass.SubclassDlgItem(IDC_BTN_RESETPASS,this);
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnresetpass.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnplatuse.SubclassDlgItem(IDC_BTN_PLATUSE,this);
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnplatuse.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btncharge.SubclassDlgItem(IDC_BTN_CHARGE,this);
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btncharge.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CLeftAccmanView::OnBnClickedBtnHealinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealinfoview);
}


void CLeftAccmanView::OnBnClickedBtnHealexpert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealexpertview);
}


void CLeftAccmanView::OnBnClickedBtnHealplat()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}


HBRUSH CLeftAccmanView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return hbr;
	if(pWnd->GetDlgCtrlID()==IDC_BTN_ACCMAN)
	{


		pDC->SelectObject(&m_font);
		

	}
	
	return m_brush;
}


BOOL CLeftAccmanView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	
	return CDialog::OnEraseBkgnd(pDC);
}


void CLeftAccmanView::OnBnClickedBtnChgperinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightchgperinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightchgperinfoview;

	theApp.socketclient.UserBaseInfoRead();
}


void CLeftAccmanView::OnBnClickedBtnResetpass()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightresetpassview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightresetpassview;
}


void CLeftAccmanView::OnBnClickedBtnPlatuse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightplatuseview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightplatuseview;

	theApp.socketclient.UserPlatInfoRead();
}


BOOL CLeftAccmanView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLeftAccmanView::OnPaint()
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
