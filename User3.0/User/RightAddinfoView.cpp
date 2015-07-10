// RightAddinfoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightAddinfoView.h"
#include "afxdialogex.h"


// CRightAddinfoView �Ի���

IMPLEMENT_DYNAMIC(CRightAddinfoView, CDialog)

CRightAddinfoView::CRightAddinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAddinfoView::IDD, pParent)
	, m_drug()
	, m_drugstartdate()
	, m_drugenddate()
	, m_drugtime()
	, m_drugamount()
{

}

CRightAddinfoView::~CRightAddinfoView()
{
}

void CRightAddinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_DRUG, m_drug);
	//  DDX_Control(pDX, IDC_DRUGAMOUNT, m_drugamount);
	DDX_Control(pDX, IDC_STARTDATE, m_drugstartdate);
	DDX_Control(pDX, IDC_ENDDATE, m_drugenddate);
	DDX_Control(pDX, IDC_TIME, m_drugtime);
	DDX_Control(pDX, IDC_DRUG, m_drug);
	DDX_Control(pDX, IDC_DRUGAMOUNT, m_drugamount);
	DDX_Control(pDX, IDC_TIME2, m_drugtime2);
	DDX_Control(pDX, IDC_TIME3, m_drugtime3);
	DDX_Control(pDX, IDC_TIMES, m_times);
}


BEGIN_MESSAGE_MAP(CRightAddinfoView, CDialog)
	ON_BN_CLICKED(IDC_OK, &CRightAddinfoView::OnBnClickedOk)
	ON_CBN_SELENDOK(IDC_TIMES, &CRightAddinfoView::OnCbnSelendokTimes)
END_MESSAGE_MAP()


// CRightAddinfoView ��Ϣ�������


BOOL CRightAddinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightAddinfoView::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	User_DrugInfo adddruginfo;
	
	

	m_drug.GetWindowText(adddruginfo.drugname);
	m_drugstartdate.GetTime(adddruginfo.drugstartdate);
	m_drugenddate.GetTime(adddruginfo.drugenddate);
	m_drugtime.GetTime(adddruginfo.drugtime);
	m_drugtime2.GetTime(adddruginfo.drugtime2);
	m_drugtime3.GetTime(adddruginfo.drugtime3);



	m_drugamount.GetWindowText(adddruginfo.drugamount);
	//adddruginfo.times=m_times.GetCurSel()+1;
	//*****************�׽��ַ���************************





	//*****************�׽��ַ���************************
}


BOOL CRightAddinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CTime currentdate=CTime::GetCurrentTime();
	m_drugstartdate.SetTime(&currentdate);
	m_drugenddate.SetTime(&currentdate);
	m_drugtime.SetTime(&currentdate);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightAddinfoView::OnCbnSelendokTimes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nselect=m_times.GetCurSel();
	if (nselect==0)
	{
		m_drugtime2.ShowWindow(SW_HIDE);
		m_drugtime3.ShowWindow(SW_HIDE);
	}
	else if (nselect==1)
	{
		m_drugtime2.ShowWindow(SW_SHOW);
		m_drugtime3.ShowWindow(SW_HIDE);
	}
	else
	{
		m_drugtime2.ShowWindow(SW_SHOW);
		m_drugtime3.ShowWindow(SW_SHOW);
	}
}
