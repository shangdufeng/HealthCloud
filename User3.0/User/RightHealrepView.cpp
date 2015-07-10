// RightHealrepView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightHealrepView.h"
#include "afxdialogex.h"


// CRightHealrepView 对话框

IMPLEMENT_DYNAMIC(CRightHealrepView, CDialog)

CRightHealrepView::CRightHealrepView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightHealrepView::IDD, pParent)
{
	theApp.m_prighthealrepview=this;
}

CRightHealrepView::~CRightHealrepView()
{
}

void CRightHealrepView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HEALREPLIST, m_healreplist);
	//DDX_Control(pDX, IDC_PDFVIEWCTRL1, m_pdfView);
	DDX_Control(pDX, IDC_REPTYPE, m_reptype);
	DDX_Control(pDX, IDC_START, m_starttime);
	DDX_Control(pDX, IDC_END, m_endtime);
	DDX_Control(pDX, IDC_GROUP_REP, m_Rep);
}


BEGIN_MESSAGE_MAP(CRightHealrepView, CDialog)
	ON_BN_CLICKED(IDC_QUE, &CRightHealrepView::OnBnClickedQue)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BACK, &CRightHealrepView::OnBnClickedBack)
	ON_MESSAGE(WM_SUREPREAD, &CRightHealrepView::OnSurepread)
	ON_NOTIFY(NM_CLICK, IDC_HEALREPLIST, &CRightHealrepView::OnNMClickHealreplist)
	ON_BN_CLICKED(IDC_DOWN, &CRightHealrepView::OnBnClickedDown)
	ON_MESSAGE(WM_REPREADORNO,&CRightHealrepView::OnRepReadYesToNo)
END_MESSAGE_MAP()


// CRightHealrepView 消息处理程序


BOOL CRightHealrepView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightHealrepView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_healreplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_healreplist.InsertColumn(0,_T("序号"),LVCFMT_CENTER,40);
	m_healreplist.InsertColumn(1,_T("报告类型"),LVCFMT_CENTER,90);
	m_healreplist.InsertColumn(2,_T("报告生成时间"),LVCFMT_CENTER,140);
	m_healreplist.InsertColumn(3,_T("是否正常"),LVCFMT_CENTER,80);
	//m_healreplist.InsertItem(0,_T("1"));
	m_healreplist.InsertColumn(4,_T("是否签发"),LVCFMT_CENTER,80);
	m_healreplist.InsertColumn(5,_T("签发医生"),LVCFMT_CENTER,90);
	m_healreplist.InsertColumn(6,_T("是否已读"),LVCFMT_CENTER,70);

// 	m_pdfView.OpenPDF(_T("动态血压监测报告.pdf"),_T(""),_T(""));
// 	m_pdfView.SetMsgCallbackWnd((long)m_hWnd);
// 	m_pdfView.ShowHideBookmarks();
// 	m_pdfView.ZoomFitWidth();

	m_Rep.SetBorderColor(RGB(136,203,103));
	m_Rep.SetFontBold(TRUE);
	m_Rep.SetBackgroundColor(RGB(66,210,87));
	m_Rep.SetFontSize(13);

	//*********************设置开始时间为一个星期前******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_endtime.GetTime(et);
	st = et-SDayTime;
	m_starttime.SetTime(&st);

	//**************设置ComBox默认值*********************************
	m_reptype.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightHealrepView::OnBnClickedQue()
{
	// TODO: 在此添加控件通知处理程序代码



	CTime starttime;
	m_starttime.GetTime(starttime);
	CTime endtime;
	m_endtime.GetTime(endtime);

	CString RepType,str_st,str_et;

	str_st=starttime.Format(_T("%Y-%m-%d"));
	str_et=endtime.Format(_T("%Y-%m-%d"));

	GetDlgItemText(IDC_REPTYPE,RepType);
	//m_RepType = RepType;

	theApp.socketclient.UserRepRead(RepType,str_st,str_et);

	//******************查询报告*********************

	//‘UserRepRead’, CString reptype, CTime starttime, CTime endtime

	//******************查询报告*********************


	//******************接收报告*********************

	//‘SURepRead’,报告信息

	//******************接收报告*********************
}


void CRightHealrepView::OnPaint()
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


HBRUSH CRightHealrepView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightHealrepView::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}


afx_msg LRESULT CRightHealrepView::OnSurepread(WPARAM wParam, LPARAM lParam)
{
	m_healreplist.DeleteAllItems();
	vector<CString> vec;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
    if(vec.at(0)==_T("20")&&vec.at(1)!=_T("-1")&&vec.at(1)!=_T("对象关闭时，不允许操作。"))
	{
		vector<vector<CString>> vec1;
		theApp.ReOrder(vec,5,vec1);
		int num = vec1.size();
		for(int i=0;i<num;i++)
		{
			CString str;
			str.Format(_T("%d"),i+1);
			//theApp.SplitString(vec.at(i),_T(","),TRUE,vec1);
			m_healreplist.InsertItem(i,str);
// 			if(m_RepType==_T("")){m_healreplist.SetItemText(i,1,_T("分析报告"));}
// 			else{m_healreplist.SetItemText(i,1,m_RepType);}
			m_vecDocName.push_back(vec1.at(i).at(0));
			m_healreplist.SetItemText(i,2,vec1.at(i).at(1));
			if(vec1.at(i).at(2)==_T("1"))
			{
               m_healreplist.SetItemText(i,3,_T("是"));
			}
			else
			{
				m_healreplist.SetItemText(i,3,_T("否"));
			}
			if(vec1.at(i).at(3)==_T("1"))
			{
				m_healreplist.SetItemText(i,4,_T("已签发"));
			}
			else
			{
				m_healreplist.SetItemText(i,4,_T("未签发"));
			}
			m_healreplist.SetItemText(i,5,vec1.at(i).at(4));
			if(vec1.at(i).at(5)==_T("1"))
			{
				m_healreplist.SetItemText(i,6,_T("已读"));
			}
			else
			{
				m_healreplist.SetItemText(i,6,_T("未读"));
			}
			m_healreplist.SetItemText(i,1,vec1.at(i).at(6));
		}
	}
	else
	{
		AfxMessageBox(_T("无该报告！"));
	}
	return 0;
}

afx_msg LRESULT CRightHealrepView::OnRepReadYesToNo(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

void CRightHealrepView::OnNMClickHealreplist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码]
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	sel_item=pNMListView->iItem;
	if(sel_item!=-1)
	{
    /*sel_sourcename=m_healreplist.GetItemText(sel_item,2);*/
	 sel_sourcename = m_vecDocName.at(sel_item);
	//**************************获取文件名**********************************


	//**************************设置未读报告为已读状态**********************
	 CString str,time,reptype;
	 str = m_healreplist.GetItemText(sel_item,6);
     time = m_healreplist.GetItemText(sel_item,2);
	 reptype = m_healreplist.GetItemText(sel_item,1);
	    if(str==_T("未读"))
	   {
		  theApp.socketclient.UserRepNoToYes(time,reptype);
		  m_healreplist.SetItemText(sel_item,6,_T("已读"));
		  CString RepUnread;
		  RepUnread.Format(_T("您还有%d条消息未读，请尽快阅读。"),theApp.m_rightwelcomeview->m_RepUnread--);
		  theApp.m_rightwelcomeview->GetDlgItem(IDC_REPTEXT)->SetWindowText(RepUnread);
	   }
	}
	*pResult = 0;
}


void CRightHealrepView::OnBnClickedDown()
{
	// TODO: 在此添加控件通知处理程序代码
	if (sel_sourcename.GetAt(0)!='['&&sel_sourcename!=_T(""))
	{
		//选择的是文件
		CString strDestName;
		//sel_sourcename = _T("16088433510_2014-05-17-18.doc");
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
			//AfxMessageBox(_T("请写入文件名！"),MB_OK/*|MB_ICONSTOP*/);
		}
	}
	else
	{
		//选择的是目录
		AfxMessageBox(_T("不能下载目录!\n请重选!"),MB_OK|MB_ICONSTOP);
	}
}

BOOL CRightHealrepView::GetFile(CString strSourceName, CString strDestName)
{
	ftpctrl.FtpOpen();
	ftpctrl.FtpConnect(_T("112.124.48.81"),21,_T("ftp"),_T("ftp"));
	return ftpctrl.FtpDownloadFile(strSourceName,strDestName);
}

