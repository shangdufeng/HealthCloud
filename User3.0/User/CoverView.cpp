// CoverView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "CoverView.h"
#include "afxdialogex.h"


// CCoverView �Ի���

IMPLEMENT_DYNAMIC(CCoverView, CDialogEx)

CCoverView::CCoverView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCoverView::IDD, pParent)
{

}

CCoverView::~CCoverView()
{
}

void CCoverView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCoverView, CDialogEx)
END_MESSAGE_MAP()


// CCoverView ��Ϣ�������
