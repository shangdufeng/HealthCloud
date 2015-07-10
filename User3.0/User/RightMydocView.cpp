// RightMydocView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightMydocView.h"
#include "afxdialogex.h"


// CRightMydocView �Ի���

IMPLEMENT_DYNAMIC(CRightMydocView, CDialog)

CRightMydocView::CRightMydocView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightMydocView::IDD, pParent)
	
	, m_doctorname(_T(""))
	, m_gender(_T(""))
	, m_cellnumber(_T(""))
	, m_title(_T(""))
	, m_hospital(_T(""))
	, m_duty(_T(""))
	, m_adminoffice(_T(""))
	, m_major(_T(""))
	, m_school(_T(""))
	, m_consulttime(_T(""))
	, m_replytime(_T(""))
	, m_eduback(_T(""))
{
	theApp.m_prightmydocview=this;
}

CRightMydocView::~CRightMydocView()
{
}

void CRightMydocView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYDOC, m_mydoc);
	//  DDX_Text(pDX, IDC_EDIT1, m_name);
	//  DDX_Text(pDX, IDC_EDIT2, m_cellphone);
	DDX_Text(pDX, IDC_EDIT1, m_doctorname);
	DDX_Text(pDX, IDC_EDIT7, m_gender);
	DDX_Text(pDX, IDC_EDIT2, m_cellnumber);
	DDX_Text(pDX, IDC_EDIT4, m_title);
	DDX_Text(pDX, IDC_EDIT9, m_hospital);
	DDX_Text(pDX, IDC_EDIT10, m_duty);
	DDX_Text(pDX, IDC_EDIT5, m_adminoffice);
	DDX_Text(pDX, IDC_EDIT11, m_major);
	DDX_Text(pDX, IDC_EDIT8, m_school);
	DDX_Text(pDX, IDC_EDIT6, m_consulttime);
	DDX_Text(pDX, IDC_EDIT12, m_replytime);
	DDX_Text(pDX, IDC_EDIT3, m_eduback);
}


BEGIN_MESSAGE_MAP(CRightMydocView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_SUDOCINFO, &CRightMydocView::OnSudocinfo)
	ON_BN_CLICKED(IDC_SENDMESS, &CRightMydocView::OnBnClickedSendmess)
END_MESSAGE_MAP()


// CRightMydocView ��Ϣ�������


BOOL CRightMydocView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightMydocView::OnPaint()
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


HBRUSH CRightMydocView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID()==IDC_STATIC) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}


	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


BOOL CRightMydocView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_mydoc.SetBorderColor(RGB(136,203,103));
	m_mydoc.SetFontBold(TRUE);
	m_mydoc.SetBackgroundColor(RGB(66,210,87));
	m_mydoc.SetFontSize(13);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


afx_msg LRESULT CRightMydocView::OnSudocinfo(WPARAM wParam, LPARAM lParam)
{
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_mydocinfo);
	if(/*vec_mydocinfo.at(0)==_T("4")&&*/vec_mydocinfo.at(1)!=_T("-1"))
	{
		theApp.SplitString(vec_mydocinfo.at(1),_T(","),TRUE,mydocinfo);
		m_doctorname=mydocinfo.at(0);
		m_gender=mydocinfo.at(1);
		m_cellnumber=/*mydocinfo.at(3)*/_T("******");
		m_obcell = mydocinfo.at(3);
		m_title=mydocinfo.at(7);
		m_hospital=mydocinfo.at(6);
		m_duty=mydocinfo.at(8);
		m_adminoffice=mydocinfo.at(9);
		m_major=mydocinfo.at(10);
		m_school=mydocinfo.at(4);
		m_consulttime=mydocinfo.at(11);
		m_eduback=mydocinfo.at(5);
		m_replytime=mydocinfo.at(12);
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(_T("�޷���������ҽ����"));
	}

	return 0;
}


void CRightMydocView::OnBnClickedSendmess()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,theApp.m_prightmessagereadview);
	theApp.m_prightpreview = theApp.m_prightmessagereadview;

	theApp.m_prightmessagereadview->ob_cell=m_obcell;
}
