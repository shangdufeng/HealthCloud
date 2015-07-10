// CoverView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "CoverView.h"
#include "afxdialogex.h"


// CCoverView 对话框

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


// CCoverView 消息处理程序
