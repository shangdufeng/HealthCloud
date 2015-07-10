// RightChangeinfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightChangeinfoView.h"
#include "afxdialogex.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


// CRightChangeinfoView 对话框

IMPLEMENT_DYNAMIC(CRightChangeinfoView, CDialog)

CRightChangeinfoView::CRightChangeinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChangeinfoView::IDD, pParent)
	
	, m_row(0)
	, m_column(0)
	
	

{
	theApp.m_prightchangeinfoview=this;
}

int CRightChangeinfoView::stanum=1;
int  CRightChangeinfoView::m_judge=10000;
int  CRightChangeinfoView::m_judge1=1;
CRightChangeinfoView::~CRightChangeinfoView()
{
}

void CRightChangeinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DRUGUSEINFO, m_druguseinfo);
	DDX_Control(pDX, IDC_EDIT, m_edit);
	DDX_Control(pDX, IDC_DATE, m_date);
	DDX_Control(pDX, IDC_TIME, m_time);
	DDX_Control(pDX, IDC_SETGROUP, m_setgroup);
	DDX_Control(pDX, IDC_INFORMATION, m_information);
	DDX_Control(pDX, IDC_START, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_end);
}


BEGIN_MESSAGE_MAP(CRightChangeinfoView, CDialog)
	ON_BN_CLICKED(IDC_ADD, &CRightChangeinfoView::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &CRightChangeinfoView::OnBnClickedDel)
	ON_NOTIFY(NM_DBLCLK, IDC_DRUGUSEINFO, &CRightChangeinfoView::OnNMDblclkDruguseinfo)
//	ON_WM_KILLFOCUS()
	ON_EN_KILLFOCUS(IDC_EDIT, &CRightChangeinfoView::OnEnKillfocusEdit)
//	ON_NOTIFY(NM_CLICK, IDC_DRUGUSEINFO, &CRightChangeinfoView::OnNMClickDruguseinfo)
ON_NOTIFY(NM_KILLFOCUS, IDC_DRUGUSEINFO, &CRightChangeinfoView::OnNMKillfocusDruguseinfo)
ON_NOTIFY(NM_CLICK, IDC_DRUGUSEINFO, &CRightChangeinfoView::OnNMClickDruguseinfo)
ON_BN_CLICKED(IDC_OK, &CRightChangeinfoView::OnBnClickedOk)
ON_NOTIFY(NM_KILLFOCUS, IDC_DATE, &CRightChangeinfoView::OnNMKillfocusDate)
ON_NOTIFY(NM_KILLFOCUS, IDC_TIME, &CRightChangeinfoView::OnNMKillfocusTime)
//ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE, &CRightChangeinfoView::OnDtnDatetimechangeDate)
ON_WM_TIMER()
//ON_BN_CLICKED(IDC_UPDATE, &CRightChangeinfoView::OnBnClickedUpdate)
ON_WM_PAINT()
ON_WM_CTLCOLOR()
ON_MESSAGE(WM_SERVERDRUGREAD, &CRightChangeinfoView::OnServerdrugread)
ON_MESSAGE(WM_SUDRUGUPDATE, &CRightChangeinfoView::OnSudrugupdate)
//ON_BN_CLICKED(IDC_QUE, &CRightChangeinfoView::OnBnClickedQue)
ON_BN_CLICKED(IDC_QUE, &CRightChangeinfoView::OnBnClickedQue)
END_MESSAGE_MAP()


// CRightChangeinfoView 消息处理程序


BOOL CRightChangeinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightChangeinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_druguseinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_druguseinfo.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_druguseinfo.InsertColumn(1,_T("药品名称"),LVCFMT_CENTER,100);
	m_druguseinfo.InsertColumn(2,_T("用量/片"),LVCFMT_CENTER,60);
	m_druguseinfo.InsertColumn(3,_T("开始日期"),LVCFMT_CENTER,105);
	m_druguseinfo.InsertColumn(4,_T("结束日期"),LVCFMT_CENTER,105);
	m_druguseinfo.InsertColumn(5,_T("时间1"),LVCFMT_CENTER,100);
	m_druguseinfo.InsertColumn(6,_T("时间2"),LVCFMT_CENTER,100);
	m_druguseinfo.InsertColumn(7,_T("时间3"),LVCFMT_CENTER,100);

	m_setgroup.SetBorderColor(RGB(136,203,103));
	m_setgroup.SetFontBold(TRUE);
	m_setgroup.SetBackgroundColor(RGB(66,210,87));
	m_setgroup.SetFontSize(13);
	

	/*m_druguseinfo.SetItemText(0,1,_T("范例"));
	m_druguseinfo.SetItemText(0,2,_T("3"));
	m_druguseinfo.SetItemText(0,3,_T("2013.01.10"));
	m_druguseinfo.SetItemText(0,4,_T("2013.12.30"));
	m_druguseinfo.SetItemText(0,5,_T("08:00"));
	m_druguseinfo.SetItemText(0,6,_T("12:00"));
	m_druguseinfo.SetItemText(0,7,_T("18:00"));*/
	CTime currenttime=CTime::GetCurrentTime();
	m_date.SetTime(&currenttime);
	m_time.SetTime(&currenttime);



	m_setgroup.SetBorderColor(RGB(136,203,103));
	m_setgroup.SetFontBold(TRUE);

	m_information.SetBorderColor(RGB(136,203,103));
	m_information.SetFontBold(TRUE);
	m_information.SetBackgroundColor(RGB(66,210,87));
	m_information.SetFontSize(13);

	//*********************设置开始时间为一个星期前******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_end.GetTime(et);
	st = et-SDayTime;
	m_start.SetTime(&st);

	//********************发送套接字（查询用药信息）*********************************

	//‘UserDrugRead’

	//********************发送套接字（查询用药信息）*********************************





	//********************接收套接字（接收用药信息）*********************************


	//‘UserDrugRead’,vector<User_DrugInfo> m_User_DrugInfo_list

	m_druguseinfo.InsertItem(0,_T("1"));
	//


	//********************接收套接字（接收用药信息）*********************************
	




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightChangeinfoView::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	//stanum=stanum+1;
	stanum=m_druguseinfo.GetItemCount()+1;
	CString nm;
	nm.Format(_T("%d"),stanum);
	m_druguseinfo.InsertItem(stanum,_T("") );
	m_druguseinfo.SetItemText(stanum-1,0,nm);
	
	GetDlgItem(IDC_CHGSUSS)->ShowWindow(SW_HIDE);

}


void CRightChangeinfoView::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码

	if(m_judge<10000)
	{
		if (m_judge==0)
		{
			if (m_judge1==0)
			{
				m_druguseinfo.DeleteItem(m_judge);
			}
		}
		else
		{
			m_druguseinfo.DeleteItem(m_judge);
		}
		
	}
	m_judge=10000;
	m_judge1=1;


	stanum=m_druguseinfo.GetItemCount()+1;
	for (int i=1;i<stanum;i++)
	{
		CString nm;
		nm.Format(_T("%d"),i);
		m_druguseinfo.SetItemText(i-1,0,nm);
	}
	
	GetDlgItem(IDC_CHGSUSS)->ShowWindow(SW_HIDE);
	
}


void CRightChangeinfoView::OnNMDblclkDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_CHGSUSS)->ShowWindow(SW_HIDE);
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	CRect list;
	if(pNMListView->iItem!=-1)
	{
		m_row=pNMListView->iItem;//m_row为被选中行的行序号（int类型成员变量）
		m_column=pNMListView->iSubItem;//m_column为被选中行的列序号（int类型成员变量）
		m_druguseinfo.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//取得子项的矩形
		m_edit.SetParent(&m_druguseinfo);
		m_date.SetParent(&m_druguseinfo);
		m_time.SetParent(&m_druguseinfo);

		if ((m_column==1)|(m_column==2))
		{
			char *ch=new char [128];
			m_druguseinfo.GetItemText(pNMListView->iItem, pNMListView->iSubItem,LPTSTR(ch),128);//取得子项的内容
			m_edit.SetWindowText(LPTSTR(ch));//将子项的内容显示到编辑框中
			m_edit.ShowWindow(SW_SHOW);//显示编辑框
			m_edit.MoveWindow(rc);//将编辑框移动到子项上面，覆盖在子项上
			m_edit.SetFocus();//使编辑框取得焦点
			m_edit.CreateSolidCaret(1,rc.Height()-5);//创建一个光标
			m_edit.ShowCaret();//显示光标
			m_edit.SetSel(-1);//使光标移到最后面
		}
		else 
		{
			if ((m_column==3)|(m_column==4))
			{
				CString datetext;
				datetext=m_druguseinfo.GetItemText(pNMListView->iItem, pNMListView->iSubItem);//取得子项的内容

				if (datetext==_T(""))
				{
					m_date.ShowWindow(SW_SHOW);//显示编辑框
					m_date.MoveWindow(rc);//将编辑框移动到子项上面，覆盖在子项上
					m_date.SetFocus();
				}
				else
				{
					

					int year=_ttoi(datetext.Left(4));
					int month=_ttoi(datetext.Mid(5,6));
					int date=_ttoi(datetext.Right(2));
					CTime time(year,month,date,0,0,0);
 					m_date.SetTime(&time);


					m_date.ShowWindow(SW_SHOW);//显示编辑框
					m_date.MoveWindow(rc);//将编辑框移动到子项上面，覆盖在子项上
					m_date.SetFocus();
				}
				
				
			}
			else
			{
				m_time.ShowWindow(SW_SHOW);//显示编辑框
				m_time.MoveWindow(rc);//将编辑框移动到子项上面，覆盖在子项上
				m_time.SetFocus();
			}
		}
		
	}
	*pResult = 0;
}





void CRightChangeinfoView::OnEnKillfocusEdit()
{
	// TODO: 在此添加控件通知处理程序代码


	CString cstrText = _T("");
	m_edit.GetWindowText( cstrText );
	m_druguseinfo.SetItemText( m_row, m_column, cstrText );
	m_edit.ShowWindow(SW_HIDE);
	m_judge1=10000;
}





void CRightChangeinfoView::OnNMKillfocusDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem!=-1)
	{
		//m_row=NULL;
	}
	
	*pResult = 0;
}


void CRightChangeinfoView::OnNMClickDruguseinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem!=-1)
	{
		m_judge=pNMListView->iItem;
		if (m_judge==0)
		{
			m_judge1=0;
		}
		/*else
		{
			m_judge1=1;
		}*/
	}
	*pResult = 0;
}


void CRightChangeinfoView::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	
	m_User_DrugInfo_list.clear();
	int itemnum=m_druguseinfo.GetItemCount();
	

	for (int i=0;i<itemnum;i++)
	{
		User_DrugInfo item;
		

		item.drugname=m_druguseinfo.GetItemText(i,1);
		item.drugamount=m_druguseinfo.GetItemText(i,2);
		CString startdate=m_druguseinfo.GetItemText(i,3);
		CString enddate=m_druguseinfo.GetItemText(i,4);
		CString time1=m_druguseinfo.GetItemText(i,5);
		CString time2=m_druguseinfo.GetItemText(i,6);
		CString time3=m_druguseinfo.GetItemText(i,7);

		if (startdate==_T("")|enddate==_T(""))
		{
			
			AfxMessageBox(_T("请将日期填写完整"));
			return;
		}
		else if (time1==_T("")&&time2==_T("")&&time3==_T(""))
		{
			AfxMessageBox(_T("请至少填写一个时间"));
			return;
		}
		else
		{
			//**********************起始日期
			int syear,smonth,sday;
			BYTE syeart[4];
			memset(syeart,0,sizeof(syeart));  
			syeart[0]=startdate[0];   
			syeart[1]=startdate[1];   
			syeart[2]=startdate[2];   
			syeart[3]=startdate[3];
			syear=atoi((char*)syeart);

			BYTE smontht[2];
			memset(smontht,0,sizeof(smontht));  
			smontht[0]=startdate[5];   
			smontht[1]=startdate[6];   
			smonth=atoi((char*)smontht);

			BYTE sdayt[2];
			memset(sdayt,0,sizeof(sdayt));  
			sdayt[0]=startdate[8];   
			sdayt[1]=startdate[9];   
			sday=atoi((char*)sdayt);
			CTime startdate_ct(syear,smonth,sday,0,0,0);
			item.drugstartdate=startdate_ct;//***************************************************起始日期


			//CString szTime = item .drugstartdate.Format("%Y-%m-%d");
			//MessageBox(szTime);


			//******************************结束日期
			int eyear,emonth,eday;
			BYTE eyeart[4];
			memset(eyeart,0,sizeof(syeart));  
			eyeart[0]=enddate[0];   
			eyeart[1]=enddate[1];   
			eyeart[2]=enddate[2];   
			eyeart[3]=enddate[3];
			eyear=atoi((char*)eyeart);

			BYTE emontht[2];
			memset(emontht,0,sizeof(emontht));  
			emontht[0]=enddate[5];   
			emontht[1]=enddate[6];   
			emonth=atoi((char*)emontht);

			BYTE edayt[2];
			memset(edayt,0,sizeof(edayt));  
			edayt[0]=enddate[8];   
			edayt[1]=enddate[9];   
			eday=atoi((char*)edayt);//******************************结束日期
			CTime enddate_ct(eyear,emonth,eday,0,0,0);
			item.drugenddate=enddate_ct;

			//CString szTime = item .drugenddate.Format("%Y-%m-%d");
			//MessageBox(szTime);


			if (time1!=_T(""))
			{
				//******************************时间1
			int hour1,min1,sec1;
			BYTE hourt1[2];
			memset(hourt1,0,sizeof(hourt1));  
			hourt1[0]=time1[0];   
			hourt1[1]=time1[1];   
			hour1=atoi((char*)hourt1);

			BYTE mint1[2];
			memset( mint1,0,sizeof(mint1));  
			mint1[0]=time1[3];   
			mint1[1]=time1[4];   
			min1=atoi((char*)mint1);

			BYTE sect1[2];
			memset(sect1,0,sizeof(sect1));  
			sect1[0]=time1[6];   
			sect1[1]=time1[7];   
			sec1=atoi((char*)sect1);
			CTime time1_ct(1990,5,19,hour1,min1,sec1);
			item.drugtime= time1_ct;//******************************时间1

			//CString szTime = item.drugtime.Format("%H:%M:%S");
			//MessageBox(szTime);
			}
			else

			{
				item.drugtime=0;
			}

			
			if (time2!=_T(""))
			{
				//******************************时间2
			int hour2,min2,sec2;
			BYTE hourt2[2];
			memset(hourt2,0,sizeof(hourt2));  
			hourt2[0]=time2[0];   
			hourt2[1]=time2[1];   
			hour2=atoi((char*)hourt2);

			BYTE mint2[2];
			memset( mint2,0,sizeof(mint2));  
			mint2[0]=time2[3];   
			mint2[1]=time2[4];   
			min2=atoi((char*)mint2);

			BYTE sect2[2];
			memset(sect2,0,sizeof(sect2));  
			sect2[0]=time2[6];   
			sect2[1]=time2[7];   
			sec2=atoi((char*)sect2);
			CTime time2_ct(1990,5,19,hour2,min2,sec2);
			item.drugtime2= time2_ct;//******************************时间2
			}
			else

			{
				item.drugtime2=0;
			}
			


			//CString szTime = item.drugtime2.Format("%H:%M:%S");
			//MessageBox(szTime);

			if (time3!=_T(""))
			{
				//******************************时间3
			int hour3,min3,sec3;
			BYTE hourt3[2];
			memset(hourt3,0,sizeof(hourt3));  
			hourt3[0]=time3[0];   
			hourt3[1]=time3[1];   
			hour3=atoi((char*)hourt3);

			BYTE mint3[2];
			memset( mint3,0,sizeof(mint3));  
			mint3[0]=time3[3];   
			mint3[1]=time3[4];   
			min3=atoi((char*)mint3);

			BYTE sect3[2];
			memset(sect3,0,sizeof(sect3));  
			sect3[0]=time3[6];   
			sect3[1]=time3[7];   
			sec3=atoi((char*)sect3);
			CTime time3_ct(1990,5,19,hour3,min3,sec3);
			item.drugtime3= time3_ct;//******************************时间3
			}
			else

			{
				item.drugtime3=0;
			}

			//CString szTime = item.drugtime3.Format("%H:%M:%S");
			//MessageBox(szTime);

			if (startdate_ct>enddate_ct)
			{
				AfxMessageBox(_T("日期选择错误"));
				return;
			}
			else
			{
				m_User_DrugInfo_list.push_back(item);
			}					
		}
	}
	//GetDlgItem(IDC_CHGSUSS)->ShowWindow(SW_SHOW);
	SetTimer(1,1000,NULL);
	m_judge1=1;
	

	//*****************套接字发送(更新用药信息)************************

	theApp.socketclient.UserDrugUpdate(m_User_DrugInfo_list);
	

	//‘UserDrugUpdate’, vector<User_DrugInfo> m_User_DrugInfo_list


	//*****************套接字发送(更新用药信息)************************
	

	//*****************套接字接收(更新结果)************************
	
	//‘UserDrugUpdate’, ‘UserDrugUpdate’, CString exceptiontext



	//*****************套接字接收(更新结果)************************

}


void CRightChangeinfoView::OnNMKillfocusDate(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CTime date;
	m_date.GetTime(date);
	CString datestr=date.Format(_T("%Y-%m-%d"));
	m_druguseinfo.SetItemText(m_row,m_column,datestr);

	CTime currenttime=CTime::GetCurrentTime();
	m_date.SetTime(&currenttime);
	m_date.ShowWindow(SW_HIDE);

	m_judge1=10000;
	*pResult = 0;
}


void CRightChangeinfoView::OnNMKillfocusTime(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CTime time;
	m_time.GetTime(time);
	CString timestr=time.Format(_T("%H:%M:%S"));
	m_druguseinfo.SetItemText(m_row,m_column,timestr);

	CTime currenttime=CTime::GetCurrentTime();
	m_time.SetTime(&currenttime);
	m_time.ShowWindow(SW_HIDE);
	m_judge1=10000;
	*pResult = 0;
}




void CRightChangeinfoView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTime currenttime=CTime::GetCurrentTime();
	/*int currenthour=currenttime.GetHour();
	int currentmin=currenttime.GetMinute();
	int currentsec=currenttime.GetSecond();*/

	int drugnum=m_User_DrugInfo_list.size();
	for (int i=0;i<drugnum;i++)
	{
		if ((currenttime>m_User_DrugInfo_list.at(i).drugstartdate)&&(currenttime<m_User_DrugInfo_list.at(i).drugenddate))
		{
			
			if ((currenttime.GetHour()==m_User_DrugInfo_list.at(i).drugtime.GetHour())&&(currenttime.GetMinute()==m_User_DrugInfo_list.at(i).drugtime.GetMinute())&&(currenttime.GetSecond()==m_User_DrugInfo_list.at(i).drugtime.GetSecond()))
			{
				PlaySound(_T("Breath And Life.wav"),NULL,SND_FILENAME|SND_ASYNC);
				AfxMessageBox(_T("该吃药啦亲"));
				PlaySound(NULL,NULL,SND_FILENAME);
				
				
				
			}
			else 
				if ((currenttime.GetHour()==m_User_DrugInfo_list.at(i).drugtime2.GetHour())&&(currenttime.GetMinute()==m_User_DrugInfo_list.at(i).drugtime2.GetMinute())&&(currenttime.GetSecond()==m_User_DrugInfo_list.at(i).drugtime2.GetSecond()))
				{
					PlaySound(_T("Breath And Life.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
					AfxMessageBox(_T("该吃药啦亲"));
					PlaySound(NULL,NULL,SND_FILENAME);
				}
				else
					if ((currenttime.GetHour()==m_User_DrugInfo_list.at(i).drugtime3.GetHour())&&(currenttime.GetMinute()==m_User_DrugInfo_list.at(i).drugtime3.GetMinute())&&(currenttime.GetSecond()==m_User_DrugInfo_list.at(i).drugtime3.GetSecond()))
					{
						PlaySound(_T("Breath And Life.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
						AfxMessageBox(_T("该吃药啦亲"));
						PlaySound(NULL,NULL,SND_FILENAME);
					}

		}else
			if ((currenttime.Format(_T("%Y%m%d"))==m_User_DrugInfo_list.at(i).drugstartdate.Format(_T("%Y%m%d")))||(currenttime.Format(_T("%Y%m%d"))==m_User_DrugInfo_list.at(i).drugenddate.Format(_T("%Y%m%d"))))
			{
				if ((currenttime.GetHour()==m_User_DrugInfo_list.at(i).drugtime.GetHour())&&(currenttime.GetMinute()==m_User_DrugInfo_list.at(i).drugtime.GetMinute())&&(currenttime.GetSecond()==m_User_DrugInfo_list.at(i).drugtime.GetSecond()))
				{
					PlaySound(_T("Breath And Life.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
					AfxMessageBox(_T("该吃药啦亲"));
					PlaySound(NULL,NULL,SND_FILENAME);
				}
				else 
					if ((currenttime.GetHour()==m_User_DrugInfo_list.at(i).drugtime2.GetHour())&&(currenttime.GetMinute()==m_User_DrugInfo_list.at(i).drugtime2.GetMinute())&&(currenttime.GetSecond()==m_User_DrugInfo_list.at(i).drugtime2.GetSecond()))
					{
						PlaySound(_T("Breath And Life.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
						AfxMessageBox(_T("该吃药啦亲"));
						PlaySound(NULL,NULL,SND_FILENAME);
					}
					else
						if ((currenttime.GetHour()==m_User_DrugInfo_list.at(i).drugtime3.GetHour())&&(currenttime.GetMinute()==m_User_DrugInfo_list.at(i).drugtime3.GetMinute())&&(currenttime.GetSecond()==m_User_DrugInfo_list.at(i).drugtime3.GetSecond()))
						{
							PlaySound(_T("Breath And Life.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
							AfxMessageBox(_T("该吃药啦亲"));
							PlaySound(NULL,NULL,SND_FILENAME);
						}

			}

		
	}
	
	CDialog::OnTimer(nIDEvent);
}





void CRightChangeinfoView::OnPaint()
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


HBRUSH CRightChangeinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CRightChangeinfoView::OnServerdrugread(WPARAM wParam, LPARAM lParam)
{
	m_druguseinfo.DeleteAllItems();
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_drug);
	if(vec_drug.at(0)==_T("0")&&vec_drug.at(1)!=_T("-1"))
	{
		int num=vec_drug.size();
		CString sequ;
		for (int i=1; i<num;i++)
		{
			sequ.Format(_T("%d"),i);
			m_druguseinfo.InsertItem(i-1,sequ);
			vector<CString> docinfo;
			theApp.SplitString(vec_drug.at(i),_T(","),TRUE,docinfo);
			m_druguseinfo.SetItemText(i-1,1,docinfo.at(0));
			m_druguseinfo.SetItemText(i-1,2,docinfo.at(6));
			m_druguseinfo.SetItemText(i-1,3,docinfo.at(1));
			m_druguseinfo.SetItemText(i-1,4,docinfo.at(2));
			m_druguseinfo.SetItemText(i-1,5,docinfo.at(3));
			m_druguseinfo.SetItemText(i-1,6,docinfo.at(4));
			m_druguseinfo.SetItemText(i-1,7,docinfo.at(5));
		}
	}
	else
	{
		AfxMessageBox(_T("该时间段内无用药提醒！"));
	}
	
	return 0;
}


afx_msg LRESULT CRightChangeinfoView::OnSudrugupdate(WPARAM wParam, LPARAM lParam)
{
	vector<CString> excep;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,excep);
	AfxMessageBox(excep.at(1));
	return 0;
}


//void CRightChangeinfoView::OnBnClickedQue()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	theApp.socketclient.UserDrugRead();
//}


void CRightChangeinfoView::OnBnClickedQue()
{
	// TODO: 在此添加控件通知处理程序代码
	CString st,et;
	CTime cst,cet;
	m_start.GetTime(cst);
	m_end.GetTime(cet);
	st=cst.Format(_T("%Y-%m-%d"));
	et=cet.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserDrugRead(st,et);
}
