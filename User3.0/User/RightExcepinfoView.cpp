// RightExcepinfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightExcepinfoView.h"
#include "afxdialogex.h"


// CRightExcepinfoView 对话框

IMPLEMENT_DYNAMIC(CRightExcepinfoView, CDialog)

CRightExcepinfoView::CRightExcepinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightExcepinfoView::IDD, pParent)
{
	theApp.m_prightexcepinfoview=this;
}

CRightExcepinfoView::~CRightExcepinfoView()
{
}

void CRightExcepinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXCEPINFOLIST, m_excepinfolist);
	DDX_Control(pDX, IDC_EXCEPINFOSD, m_start);
	DDX_Control(pDX, IDC_EXCEPINFOED, m_end);
	DDX_Control(pDX, IDC_GROUP_EXCEP, m_excep);
}


BEGIN_MESSAGE_MAP(CRightExcepinfoView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_SUEXCEPREAD, &CRightExcepinfoView::OnSuexcepread)
	ON_BN_CLICKED(IDC_QUE, &CRightExcepinfoView::OnBnClickedQue)
	ON_NOTIFY(NM_CLICK, IDC_EXCEPINFOLIST, &CRightExcepinfoView::OnNMClickExcepinfolist)
	ON_BN_CLICKED(IDC_DOWN, &CRightExcepinfoView::OnBnClickedDown)
END_MESSAGE_MAP()


// CRightExcepinfoView 消息处理程序


BOOL CRightExcepinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightExcepinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_excepinfolist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_excepinfolist.InsertColumn(0,_T("序号"),LVCFMT_CENTER,40);
	m_excepinfolist.InsertColumn(1,_T("发生异常时间"),LVCFMT_CENTER,120);
	m_excepinfolist.InsertColumn(2,_T("异常种类"),LVCFMT_CENTER,100);
	m_excepinfolist.InsertColumn(3,_T("医生鉴定"),LVCFMT_CENTER,100);
	m_excepinfolist.InsertColumn(4,_T("签发医生"),LVCFMT_CENTER,100);
	m_excepinfolist.InsertColumn(5,_T("检查报告"),LVCFMT_CENTER,100);
	
	m_excep.SetBorderColor(RGB(136,203,103));
	m_excep.SetFontBold(TRUE);
	m_excep.SetBackgroundColor(RGB(66,210,87));
	m_excep.SetFontSize(13);

	//*********************设置开始时间为一个星期前******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_end.GetTime(et);
	st = et-SDayTime;
	m_start.SetTime(&st);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightExcepinfoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
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


HBRUSH CRightExcepinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


afx_msg LRESULT CRightExcepinfoView::OnSuexcepread(WPARAM wParam, LPARAM lParam)
{
	m_excepinfolist.DeleteAllItems();
	vector<CString> vec_excep;
	vector<CString> vec_excepinfo;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_excep);
	int num=vec_excep.size();
	CString sequ;
	if(vec_excep.at(0)==_T("21")&&vec_excep.at(1)!=_T("-1"))
	{
		for (int i=1; i<num;i++)
		{
			sequ.Format(_T("%d"),i);
			m_excepinfolist.InsertItem(i-1,sequ);
			theApp.SplitString(vec_excep.at(i),_T(","),TRUE,vec_excepinfo);
			m_excepinfolist.SetItemText(i-1,1,vec_excepinfo.at(0));
			m_excepinfolist.SetItemText(i-1,2,vec_excepinfo.at(1));
			m_excepinfolist.SetItemText(i-1,3,vec_excepinfo.at(2));
			m_excepinfolist.SetItemText(i-1,4,vec_excepinfo.at(3));
			m_excepinfolist.SetItemText(i-1,5,vec_excepinfo.at(4));
		}
	}
	else
	{
		AfxMessageBox(_T("无异常报告"));
	}
	return 0;
}


void CRightExcepinfoView::OnBnClickedQue()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime st,et;
	CString str_st,str_et;
	m_start.GetTime(st);
	m_end.GetTime(et);
	str_st=st.Format(_T("%Y-%m-%d"));
	str_et=et.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserExcepRead(str_st,str_et);
}


void CRightExcepinfoView::OnNMClickExcepinfolist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	sel_item=pNMListView->iItem;
	sel_sourcename=m_excepinfolist.GetItemText(sel_item,5);


	*pResult = 0;
}


void CRightExcepinfoView::OnBnClickedDown()
{
	// TODO: 在此添加控件通知处理程序代码
	if (sel_sourcename.GetAt(0)!='[')
	{
		//选择的是文件
		sel_sourcename = _T("管理端.docx");
		CString strDestName;
		CFileDialog dlg(FALSE,_T(".docx"),sel_sourcename,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,L"Word文档(*.docx)|*.docx|", this);
		if (dlg.DoModal()==IDOK)
		{
			//获得下载文件在本地机上存储的路径和名称
			strDestName=dlg.GetPathName();

			//调用函数下载文件
			if (GetFile(sel_sourcename,strDestName))
				AfxMessageBox(_T("下载成功！"),MB_OK|MB_ICONINFORMATION);
			else
				AfxMessageBox(_T("下载失败！"),MB_OK|MB_ICONSTOP);
		}
		else
		{
			//AfxMessageBox(_T("请写入文件名！"),MB_OK|MB_ICONSTOP);
		}
	}
	else
	{
		//选择的是目录
		AfxMessageBox(_T("不能下载目录!\n请重选!"),MB_OK|MB_ICONSTOP);
	}


}


BOOL CRightExcepinfoView::GetFile(CString strSourceName, CString strDestName)
{
	ftpctrl.FtpOpen();
	ftpctrl.FtpConnect(_T("112.124.48.81"),21,_T("ftp"),_T("ftp"));
	return ftpctrl.FtpDownloadFile(strSourceName,strDestName);
// 	CInternetSession* pSession;
// 	CFtpConnection* pConnection;
// 
// 	pConnection=NULL;
// 
// 	//创建Internet会话
// 	pSession=new CInternetSession(	AfxGetAppName(),
// 		1,
// 		PRE_CONFIG_INTERNET_ACCESS);
// 
// 	try
// 	{
// 		//建立FTP连接
// 		pConnection=pSession->GetFtpConnection(	_T("112.124.48.81"),
// 			_T("ftp"),
// 			_T("ftp"));
// 		//112.124.48.81
// 	}
// 	catch (CInternetException* e)
// 	{
// 		//错误处理
// 		e->Delete();
// 		pConnection=NULL;
// 		return FALSE;
// 	}
// 
// 	if (pConnection!=NULL)
// 	{
// 		//下载文件
// 		if (!pConnection->GetFile(strSourceName,strDestName))
// 		{
// 			//下载文件错误
// 			pConnection->Close();
// 			delete pConnection;
// 			delete pSession;
// 			return FALSE;
// 		}
// 	}
// 
// 	//清除对象
// 	if (pConnection!=NULL)
// 	{
// 		pConnection->Close();
// 		delete pConnection;
// 	}
// 	delete pSession;
// 
// 
// 	return TRUE;
}
