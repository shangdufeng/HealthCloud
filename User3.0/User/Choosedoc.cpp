// Choosedoc.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "Choosedoc.h"
#include "afxdialogex.h"


// CChoosedoc 对话框

IMPLEMENT_DYNAMIC(CChoosedoc, CDialog)

CChoosedoc::CChoosedoc(CWnd* pParent /*=NULL*/)
	: CDialog(CChoosedoc::IDD, pParent)
{

}

CChoosedoc::~CChoosedoc()
{
}

void CChoosedoc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChoosedoc, CDialog)
END_MESSAGE_MAP()


// CChoosedoc 消息处理程序
