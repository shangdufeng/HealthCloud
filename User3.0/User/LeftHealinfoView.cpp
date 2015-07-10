// LeftHealinfoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "LeftHealinfoView.h"
#include "afxdialogex.h"


// CLeftHealinfoView �Ի���

IMPLEMENT_DYNAMIC(CLeftHealinfoView, CDialog)

CLeftHealinfoView::CLeftHealinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftHealinfoView::IDD, pParent)
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
}

CLeftHealinfoView::~CLeftHealinfoView()
{
}

void CLeftHealinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLeftHealinfoView, CDialog)
	ON_BN_CLICKED(IDC_BTN_ACCMAN, &CLeftHealinfoView::OnBnClickedBtnAccman)
	ON_BN_CLICKED(IDC_BTN_HEALEXPERT, &CLeftHealinfoView::OnBnClickedBtnHealexpert)
	ON_BN_CLICKED(IDC_BTN_DRUGMAN, &CLeftHealinfoView::OnBnClickedBtnDrugman)
	ON_BN_CLICKED(IDC_BTN_HEALPLAT, &CLeftHealinfoView::OnBnClickedBtnHealplat)
	ON_BN_CLICKED(IDC_BTN_INPUT, &CLeftHealinfoView::OnBnClickedBtnInput)
	ON_BN_CLICKED(IDC_BTN_LATEST, &CLeftHealinfoView::OnBnClickedBtnLatest)
	ON_BN_CLICKED(IDC_BTN_HISQUE, &CLeftHealinfoView::OnBnClickedBtnHisque)
	ON_BN_CLICKED(IDC_BTN_HEALREP, &CLeftHealinfoView::OnBnClickedBtnHealrep)
//	ON_BN_CLICKED(IDC_BTN_HEALREP2, &CLeftHealinfoView::OnBnClickedBtnHealrep2)
ON_BN_CLICKED(IDC_BTN_EXCEPINFO, &CLeftHealinfoView::OnBnClickedBtnExcepinfo)
ON_BN_CLICKED(IDC_BTN_HEALTOOL, &CLeftHealinfoView::OnBnClickedBtnHealtool)
ON_WM_CTLCOLOR()
ON_WM_PAINT()
END_MESSAGE_MAP()


// CLeftHealinfoView ��Ϣ�������


void CLeftHealinfoView::OnBnClickedBtnAccman()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftaccmanview);
}


void CLeftHealinfoView::OnBnClickedBtnHealexpert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealexpertview);
}


void CLeftHealinfoView::OnBnClickedBtnDrugman()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_leftdrugmanview);
}


void CLeftHealinfoView::OnBnClickedBtnHealplat()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(this,&theApp.m_pleftpane->m_lefthealplatview);
}


void CLeftHealinfoView::OnBnClickedBtnInput()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightinputview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightinputview;
}


void CLeftHealinfoView::OnBnClickedBtnLatest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightlatestinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightlatestinfoview;
	//**********************��ѯ�����Ϣ**********************************
    theApp.socketclient.UserLatestHealRead();
	//**********************���ص������Ϣ����****************************
// 	GetDlgItem(IDC_LATESTINFO)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_BTN_BLD)->SetWindowPos(this,176,449,178,64,SWP_NOZORDER);
// 	GetDlgItem(IDC_BTN_HRT)->SetWindowPos(this,360,449,178,64,SWP_NOZORDER);
// 	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
// 	GetDlgItem(IDC_PREVIEW)->SetWindowPos(this,350,20,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_PREVIEW)->ShowWindow(SW_HIDE);
// 
// 	GetDlgItem(IDC_DOWN)->SetWindowPos(this,420,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_DOWN)->ShowWindow(SW_HIDE);
// 
// 	GetDlgItem(IDC_STATIC2)->SetWindowPos(this,200,40,0,0,SWP_NOZORDER|SWP_NOSIZE);
// 	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
// 
// 	GetDlgItem(IDC_RETURN)->SetWindowPos(this,250,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_RETURN)->ShowWindow(SW_HIDE);
}


void CLeftHealinfoView::OnBnClickedBtnHisque()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_righthisqueview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_righthisqueview;
}


void CLeftHealinfoView::OnBnClickedBtnHealrep()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_righthealrepview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_righthealrepview;
}





void CLeftHealinfoView::OnBnClickedBtnExcepinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightexcepinfoview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightexcepinfoview;
}


void CLeftHealinfoView::OnBnClickedBtnHealtool()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_CalorieToolView);
	theApp.m_prightpreview=&theApp.m_prightpane->m_CalorieToolView;
}


BOOL CLeftHealinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CLeftHealinfoView::OnInitDialog()
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




	m_btninput.SubclassDlgItem(IDC_BTN_INPUT,this);
	m_btninput.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btninput.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btninput.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btninput.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btninput.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnlatest.SubclassDlgItem(IDC_BTN_LATEST,this);
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnlatest.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnhisque.SubclassDlgItem(IDC_BTN_HISQUE,this);
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnhisque.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnhealrep.SubclassDlgItem(IDC_BTN_HEALREP,this);
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnhealrep.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnexcepinfo.SubclassDlgItem(IDC_BTN_EXCEPINFO,this);
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnexcepinfo.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ

	m_btnhealtool.SubclassDlgItem(IDC_BTN_HEALTOOL,this);
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0,0,0));//����ڰ�ť��������ɫ
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(198,252,165));//��ť���º󱳾���ɫ
	m_btnhealtool.SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, RGB(0,0,0));//��ť���º�������ɫ



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CLeftHealinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return hbr;
	return m_brush;
}


void CLeftHealinfoView::OnPaint()
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
