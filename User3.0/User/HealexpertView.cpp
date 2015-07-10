// HealexpertView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "HealexpertView.h"
#include "afxdialogex.h"


// CHealexpertView 对话框

IMPLEMENT_DYNAMIC(CHealexpertView, CDialog)

CHealexpertView::CHealexpertView(CWnd* pParent /*=NULL*/)
	: CDialog(CHealexpertView::IDD, pParent)
{

}

CHealexpertView::~CHealexpertView()
{
}

void CHealexpertView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHealexpertView, CDialog)
END_MESSAGE_MAP()


// CHealexpertView 消息处理程序
