// RightInvidocView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightInvidocView.h"
#include "afxdialogex.h"
#include "Choosedoc.h"


// CRightInvidocView �Ի���

IMPLEMENT_DYNAMIC(CRightInvidocView, CDialog)

CRightInvidocView::CRightInvidocView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightInvidocView::IDD, pParent)
{

}

CRightInvidocView::~CRightInvidocView()
{
}

void CRightInvidocView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FINDDOCLIST, m_finddoclist);
}


BEGIN_MESSAGE_MAP(CRightInvidocView, CDialog)
END_MESSAGE_MAP()


// CRightInvidocView ��Ϣ�������


BOOL CRightInvidocView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightInvidocView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_finddoclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_finddoclist.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);
	m_finddoclist.InsertColumn(1,_T("ҽ������"),LVCFMT_CENTER,100);
	m_finddoclist.InsertColumn(2,_T("����ҽԺ"),LVCFMT_CENTER,150);
	m_finddoclist.InsertColumn(3,_T("����"),LVCFMT_CENTER,100);
	m_finddoclist.InsertColumn(4,_T("�ֻ���"),LVCFMT_CENTER,100);
	m_finddoclist.InsertColumn(5,_T("������"),LVCFMT_CENTER,60);


	/*CChoosedoc box1;
	box1.Create(IDC_CHOOSEDOC,this);
	box1.ShowWindow(SW_SHOW);*/






	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
