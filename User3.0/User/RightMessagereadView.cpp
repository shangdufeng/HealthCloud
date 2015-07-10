// RightMessagereadView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightMessagereadView.h"
#include "afxdialogex.h"


// CRightMessagereadView 对话框

IMPLEMENT_DYNAMIC(CRightMessagereadView, CDialog)

CRightMessagereadView::CRightMessagereadView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightMessagereadView::IDD, pParent)
	, contactchosen(FALSE)
	, m_doclist_row(0)
	, m_messsend1(_T(""))
{
	theApp.m_prightmessagereadview=this;
}

CRightMessagereadView::~CRightMessagereadView()
{
}

void CRightMessagereadView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_MESSLIST, m_messlist);
	//  DDX_Control(pDX, IDC_MESSLIST, m_messlist);
	DDX_Control(pDX, IDC_MESSHIS, m_messhis);
	//  DDX_Control(pDX, IDC_DOCLIST, m_doclist);
	//  DDX_Control(pDX, IDC_QUETYPE, m_quetype);
	//  DDX_Control(pDX, IDC_CONTINFO, m_continfo);
	DDX_Control(pDX, IDC_SENDMESSTEXT, m_sendmesstext);
	DDX_Control(pDX, IDC_MESSHISGROUP, m_messhisgroup);
	DDX_Control(pDX, IDC_MESSREADGROUP, m_messreadgroup);
	DDX_Control(pDX, IDC_SENDMESSGROUP, m_sendmessgroup);
	DDX_Control(pDX, IDC_MESSREADTEXT, m_editmessinfo);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_Text(pDX, IDC_SENDMESSTEXT, m_messsend1);
}


BEGIN_MESSAGE_MAP(CRightMessagereadView, CDialog)
//	ON_BN_CLICKED(IDC_QUE, &CRightMessagereadView::OnBnClickedQue)
//	ON_NOTIFY(NM_CLICK, IDC_DOCLIST, &CRightMessagereadView::OnNMClickDoclist)
	ON_BN_CLICKED(IDC_SENDMESS, &CRightMessagereadView::OnBnClickedSendmess)
	ON_BN_CLICKED(IDC_UPDATE, &CRightMessagereadView::OnBnClickedUpdate)
//	ON_NOTIFY(NM_KILLFOCUS, IDC_DOCLIST, &CRightMessagereadView::OnNMKillfocusDoclist)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BACK, &CRightMessagereadView::OnBnClickedBack)
	ON_MESSAGE(WM_SUMESSSEND, &CRightMessagereadView::OnSumesssend)
	ON_MESSAGE(WM_SUMESSREAD, &CRightMessagereadView::OnSumessread)
	ON_NOTIFY(NM_CLICK, IDC_MESSHIS, &CRightMessagereadView::OnNMClickMesshis)
	ON_BN_CLICKED(IDC_QUE, &CRightMessagereadView::OnBnClickedQue)
	ON_BN_CLICKED(IDC_BUTTON1, &CRightMessagereadView::OnBnClickedButton1)
	ON_MESSAGE(WM_MESSREADORNO,&CRightMessagereadView::OnMessReadYesToNo)
END_MESSAGE_MAP()


// CRightMessagereadView 消息处理程序


BOOL CRightMessagereadView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightMessagereadView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
// 	m_doclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
// 	m_doclist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,70);
// 	m_doclist.InsertColumn(1,_T("手机号"),LVCFMT_CENTER,100);
// 	m_doclist.InsertItem(0,_T("1"));
// 	m_doclist.InsertItem(1,_T("2"));
// 	m_doclist.InsertItem(2,_T("3"));
// 
// 	m_messhis.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
// 	m_messhis.InsertColumn(0,_T("消息对象"),LVCFMT_CENTER,70);
// 	m_messhis.InsertColumn(1,_T("时间"),LVCFMT_CENTER,80);
// 	m_messhis.InsertColumn(2,_T("内容摘要"),LVCFMT_CENTER,125);
// 	m_messhis.InsertColumn(3,_T("已读"),LVCFMT_CENTER,50);
// 
// 	m_messhis.InsertItem(0,_T("1"));



	//************************套接字返回消息记录********************************









	//************************套接字返回消息记录********************************

	m_messhis.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_messhis.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_messhis.InsertColumn(1,_T("信息对象"),LVCFMT_CENTER,80);
	m_messhis.InsertColumn(2,_T("发件/收件"),LVCFMT_CENTER,100);
	m_messhis.InsertColumn(3,_T("时间"),LVCFMT_CENTER,100);
	m_messhis.InsertColumn(4,_T("摘要"),LVCFMT_LEFT,140);
	m_messhis.InsertColumn(5,_T("已读"),LVCFMT_CENTER,50);
	

	m_messhisgroup.SetBorderColor(RGB(136,203,103));
	m_messhisgroup.SetFontBold(TRUE);
	m_messhisgroup.SetBackgroundColor(RGB(66,210,87));
	m_messhisgroup.SetFontSize(12);

	m_messreadgroup.SetBorderColor(RGB(136,203,103));
	m_messreadgroup.SetFontBold(TRUE);
	m_messreadgroup.SetBackgroundColor(RGB(66,210,87));
	m_messreadgroup.SetFontSize(12);

	m_sendmessgroup.SetBorderColor(RGB(136,203,103));
	m_sendmessgroup.SetFontBold(TRUE);
	m_sendmessgroup.SetBackgroundColor(RGB(66,210,87));
	m_sendmessgroup.SetFontSize(12);

	//*********************设置开始时间为一个星期前******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_end.GetTime(et);
	st = et-SDayTime;
	m_start.SetTime(&st);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


//void CRightMessagereadView::OnBnClickedQue()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	int index=m_quetype.GetCurSel();
//	CString quetype,quetext;
//	m_quetype.GetLBText(index,quetype);
//	GetDlgItem(IDC_CONTINFO)->GetWindowText(quetext);
//	
//	//************************套接字查询联系人******************************
//
//
//
//
//
//	m_doclist.InsertItem(1,_T("2"));
//	//************************套接字查询联系人******************************
//
//
//
//}


//void CRightMessagereadView::OnNMClickDoclist(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
//	if(pNMListView->iItem!=-1)
//	{
//		m_doclist_row=pNMListView->iItem;
//		contactchosen=TRUE;
//	}
//	*pResult = 0;
//}


void CRightMessagereadView::OnBnClickedSendmess()
{
	// TODO: 在此添加控件通知处理程序代码
// 	if (contactchosen==FALSE)
// 	{
// 		MessageBox(_T("请先选择您要发送的对象"));
// 		return;
// 	}
// 	else
// 	{
// 		
// 
// 		//******************套接字发送信息内容****************************
// 
// 
// 
// 
// 		//******************套接字发送信息内容****************************
// 
// 	}
	UpdateData(TRUE);
	if(ob_cell!=_T("")){theApp.socketclient.UserMessSend(ob_cell,m_messsend1);}
	else{AfxMessageBox(_T("请单击列表选择收件人！"));}

}


void CRightMessagereadView::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	//************************套接字返回消息记录********************************









	//************************套接字返回消息记录********************************


}


//void CRightMessagereadView::OnNMKillfocusDoclist(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// TODO: 在此添加控件通知处理程序代码
//	contactchosen=FALSE;
//	*pResult = 0;
//}


void CRightMessagereadView::OnPaint()
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


HBRUSH CRightMessagereadView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightMessagereadView::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}


afx_msg LRESULT CRightMessagereadView::OnSumesssend(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_messsend;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_messsend);
	AfxMessageBox(vec_messsend.at(1));
	return 0;
}


afx_msg LRESULT CRightMessagereadView::OnSumessread(WPARAM wParam, LPARAM lParam)
{
	m_messhis.DeleteAllItems();
	
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_messread);

	if(vec_messread.at(0)==_T("25")/*&&vec_messread.size()>2*/&&vec_messread.at(1)!=_T("-1"))
	{
		//vec_messread.erase(vec_messread.begin()/*+1*/);
		theApp.ReOrder(vec_messread,4,messinfo);
		int num=messinfo.size();
		CString sequ;
		for (int i=0; i<num;i++)
		{
			if(messinfo.at(i).at(1)==_T("接收")/*&&messinfo.at(i).size()==6*/)
			{
				vecSenderID.push_back(messinfo.at(i).at(6));
			}
			else
			{
				vecSenderID.push_back(_T(""));
			}
			sequ.Format(_T("%d"),i+1);
			m_messhis.InsertItem(i,sequ);
// 			vector<CString> messinfo;
// 			theApp.SplitString(vec_messread.at(i),_T(","),TRUE,messinfo);
			m_messhis.SetItemText(i,1,messinfo.at(i).at(0));
			m_messhis.SetItemText(i,2,messinfo.at(i).at(1));
			m_messhis.SetItemText(i,3,messinfo.at(i).at(2));
			m_messhis.SetItemText(i,4,messinfo.at(i).at(3));
			if(messinfo.at(i).at(4)==_T("0")){m_messhis.SetItemText(i,5,_T("未读"));}
			else{m_messhis.SetItemText(i,5,_T("已读"));}
			
		}
	}
	else
	{
		AfxMessageBox(_T("无可查询信息"));
	}
	return 0;
}

afx_msg LRESULT CRightMessagereadView::OnMessReadYesToNo(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

void CRightMessagereadView::OnNMClickMesshis(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem!=-1)
	{
		m_doclist_row=pNMListView->iItem;
		vector<CString> doc_sel;
/*		theApp.SplitString(vec_messread.at(m_doclist_row+1),_T(","),TRUE,messread);*/

/*		m_editmessinfo.SetWindowText(messread.at(3));*/
		m_editmessinfo.SetWindowText(messinfo.at(m_doclist_row).at(3));
		ob_cell=messinfo.at(m_doclist_row).at(5);
		//*************将未读报告设为已读***************************
		CString str,time,str1,SenderID;
		str = m_messhis.GetItemText(m_doclist_row,5);
		time = m_messhis.GetItemText(m_doclist_row,3);
		str1 = m_messhis.GetItemText(m_doclist_row,2);
		SenderID = vecSenderID.at(m_doclist_row);
		if(str1==_T("接收")&&str==_T("未读"))
		{
			theApp.socketclient.UserMessNoToYes(time,SenderID);
			m_messhis.SetItemText(m_doclist_row,5,_T("已读"));
			CString MessUnread;
			MessUnread.Format(_T("您还有%d封报告未读，请尽快阅读。"),theApp.m_rightwelcomeview->m_MessUnread--);
			theApp.m_rightwelcomeview->GetDlgItem(IDC_INFOTEXT)->SetWindowText(MessUnread);
		}
		//*pResult = 0;
	}

	*pResult = 0;
}


void CRightMessagereadView::OnBnClickedQue()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CTime st,et;
	CString str_st,str_et;
	m_start.GetTime(st);
	m_end.GetTime(et);
	str_st=st.Format(_T("%Y-%m-%d"));
	str_et=et.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserMessRead(str_st,str_et);
}


void CRightMessagereadView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
