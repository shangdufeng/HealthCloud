// CalorieToolView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "CalorieToolView.h"
#include "afxdialogex.h"


// CCalorieToolView 对话框

IMPLEMENT_DYNAMIC(CCalorieToolView, CDialog)

CCalorieToolView::CCalorieToolView(CWnd* pParent /*=NULL*/)
	: CDialog(CCalorieToolView::IDD, pParent)
{
	theApp.m_pCalorieToolView = this;
	m_weught1 = 0.0f;
	m_hour = 0.0f;
	m_age = 18;
	m_sex = _T("男");
	m_weight4 = 0.0f;
	m_hot=0;
	m_nCount=0;
	sum=0;
	m_mCount=0;
}

CCalorieToolView::~CCalorieToolView()
{
}

void CCalorieToolView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lsc);
	DDX_Control(pDX, IDC_LIST2, m_lsc2);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Text(pDX, IDC_EDIT2, m_weught1);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Text(pDX, IDC_EDIT11, m_hour);
	DDV_MinMaxFloat(pDX, m_hour, 0, 5);
	DDX_Text(pDX, IDC_EDIT1, m_age);
	DDX_Text(pDX, IDC_EDIT13, m_sex);
	DDX_Text(pDX, IDC_EDIT14, m_weight4);
	DDX_Control(pDX, IDC_STATIC1, m_stac1);
	DDX_Control(pDX, IDC_STATIC6, m_stac);
	DDX_Control(pDX, IDC_GROUP_CAL, m_cal);
	DDX_Control(pDX, IDC_GROUP_CAL2, m_bas);
	DDX_Control(pDX, IDC_GROUP_CAL3, m_total);
}


BEGIN_MESSAGE_MAP(CCalorieToolView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalorieToolView::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CCalorieToolView::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CCalorieToolView::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(1017, &CCalorieToolView::OnBnClicked1017)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalorieToolView::OnBnClickedButton9)
	ON_BN_CLICKED(IDOK, &CCalorieToolView::OnBnClickedOk)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CCalorieToolView::OnNMDblclkList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CCalorieToolView::OnNMDblclkList2)
END_MESSAGE_MAP()


// CCalorieToolView 消息处理程序


void CCalorieToolView::OnPaint()
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


HBRUSH CCalorieToolView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if(   CTLCOLOR_STATIC   ==   nCtlColor  )  
	{
		//pDC->SetBkColor(RGB(255,0,0));  //需要指定背景色的时候用 
		pDC->SetTextColor(RGB(0,   0,   0));    //文字前景色
		pDC->SetBkMode(TRANSPARENT);    //设置透明
		hbr=(HBRUSH)GetStockObject(NULL_BRUSH);  //获取画笔颜色混合后的画笔，完成透明 
	}  

	return hbr;
}


BOOL CCalorieToolView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Read();
	Read1();

	m_lsc.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_lsc.InsertColumn(0,_T("序号"),LVCFMT_CENTER,40);
	m_lsc.InsertColumn(1,_T("饭菜名"),LVCFMT_CENTER,120);
	m_lsc.InsertColumn(2,_T("卡路里/大卡"),LVCFMT_CENTER,90);

	m_lsc2.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_lsc2.InsertColumn(0,_T("序号"),LVCFMT_CENTER,40);
	m_lsc2.InsertColumn(1,_T("运动种类"),LVCFMT_CENTER,130);
	m_lsc2.InsertColumn(2,_T("卡路里/大卡"),LVCFMT_CENTER,80);

	m_cal.SetBorderColor(RGB(136,203,103));
	m_bas.SetBorderColor(RGB(136,203,103));
	m_total.SetBorderColor(RGB(136,203,103));
// 	stac1.Create(_T(""),WS_CHILD|WS_VISIBLE|SS_CENTER, CRect(250,335,650,375),this);
// 	stac.Create(_T(""),WS_CHILD|WS_VISIBLE|SS_CENTER, CRect(120,465,520,505),this);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CCalorieToolView::Read()
{ 
	CSheet1 csvSheet;
	ifstream in("2.csv");
	csvSheet.loadFrom(in);
	int i;
	for(i=csvSheet.getRowCount()-1;i>=0;i--)
	{
		CRow1 row1 = csvSheet.getRow(csvSheet.getRowCount()-1-i); 
		CString str2 = row1.getColumn(row1.getColumnCount()-2);
		((CComboBox*)GetDlgItem(IDC_COMBO1))->InsertString(49-i,str2);
	}
}

void CCalorieToolView::Read1()
{
	CSheet1 csvSheet;
	ifstream in("1.csv");
	csvSheet.loadFrom(in);
	int i;
	for(i=csvSheet.getRowCount()-1;i>=0;i--)
	{
		CRow1 row1 = csvSheet.getRow(csvSheet.getRowCount()-1-i); 
		CString str2 = row1.getColumn(row1.getColumnCount()-2);
		((CComboBox*)GetDlgItem(IDC_COMBO2))->InsertString(607-i,str2);
	}
}


void CCalorieToolView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_nCount++;
	CString str1,str2,str3;
	//获得牛肉
	CString str4;
	GetDlgItemText(IDC_COMBO2,str4);
	double a2,a3;
	//获得克数
	GetDlgItemText(IDC_EDIT2,str1);
	a2=_wtof(m_energyperg);
	a3=m_weught1*a2;
	if(str4==_T("")||str1==_T("")||a3<=0||a3>=10000)
	{
		AfxMessageBox(_T("请正确输入饭菜名或克数"));
		m_nCount--;
	}
	else
	{
		sum+=a3;
		//格式化输出总大卡
		str3.Format(L"%d",INT(a3));
		int i=m_nCount;
		m_weught1=0;
		m_combo2.SetWindowTextW(_T(""));
		UpdateData(FALSE);
		CString number;
		int cc=m_lsc.GetItemCount( );
		number.Format(L"%d",m_nCount);
		m_lsc.InsertItem(m_nCount-1,number);
		m_lsc.SetItemText(m_nCount-1,1,str4);
		m_lsc.SetItemText(m_nCount-1,2,str3);
	}
}


void CCalorieToolView::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_BUTTON1)->EnableWindow();

	CSheet1 csvSheet;  
	//打开csv文件  
	// 	ifstream file2("c:\\pdos.def");//以输入方式打开文件
	// 	ofstream file3("c:\\x.123");//以输出方式打开文件　　
	// 所以，在实际应用中，根据需要的不同，选择不同的类来定义：
	// 如果想以输入方式打开，就用ifstream来定义;如果想以输出方式打开，就用ofstream来定义;
	// 如果想以输入/输出方式来打开，就用fstream来定义。
	ifstream in("1.csv");  
	//加载至CSheet  
	csvSheet.loadFrom(in);
	//m_showvalue
	int curcel2=m_combo2.GetCurSel();
	CRow1 row2 = csvSheet.getRow(curcel2);
	m_energyperg = row2.getColumn(row2.getColumnCount()-1);
}


void CCalorieToolView::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(1017)->EnableWindow();
	CSheet1 csvSheet;    
	ifstream in("2.csv"); 
	csvSheet.loadFrom(in);
	int curcel1=m_combo1.GetCurSel();
	CRow1 row2 = csvSheet.getRow(curcel1);
	m_energyperhour = row2.getColumn(row2.getColumnCount()-1);
}


void CCalorieToolView::OnBnClicked1017()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(1017)->EnableWindow();
	m_mCount++;
	UpdateData(TRUE);

	CString str1,str2,str3;
	//获得牛肉
	CString str4;
	GetDlgItemText(IDC_COMBO1,str4);
	double a1,a2,a3;
	//获得单位卡 
	//获得克数m_energyperhour
	a1=_wtof(m_energyperhour);
	a3=a1*m_hour;
	if(str4==_T("")||m_hour<=0||m_hour>5)
	{
		AfxMessageBox(_T("请正确输入运动或小时"));
		m_mCount--;
	}
	else
	{
		sum-=a3;
		//格式化输出总大卡
		str3.Format(L"%d",INT(a3)); 

		int j=m_mCount;
		m_hour=0;
		m_combo1.SetWindowTextW(_T(""));
		UpdateData(FALSE);
		CString number;
		int cc=m_lsc.GetItemCount( );
		number.Format(L"%d",m_mCount);
		m_lsc2.InsertItem(m_mCount-1,number);
		m_lsc2.SetItemText(m_mCount-1,1,str4);
		m_lsc2.SetItemText(m_mCount-1,2,str3);
	}
}


void CCalorieToolView::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	float a;//基本热量
	sum+=m_hot;
	m_hot=0;
	UpdateData(TRUE);
	if(m_sex==_T("女"))
	{
		if (m_age<18)
		{
			m_age=18;
			UpdateData(FALSE);
		}
		else
		{
			m_stac1.SetWindowTextW(_T(""));
			if(m_age<=30&&m_age>=18)
				a=14.6*m_weight4+450;
			else if(m_age<=60&&m_age>30)
				a=8.6*m_weight4+830;
			else if(m_age>60)
				a=10.4*m_weight4+600;

			CString str;
			str.Format(L"%d",(int)a);
			m_stac1.SetWindowTextW(_T("人体基础代谢所需热量为")+str+_T("大卡"));
			sum-=a;
		}
	}
	else if(m_sex==_T("男"))
	{
		if (m_age<18)
		{
			m_age=18;
			UpdateData(FALSE);
		}
		else
		{
			m_stac1.SetWindowTextW(_T(""));
			if(m_age<=30&&m_age>=18)
				a=15.2*m_weight4+680;
			else if(m_age<=60&&m_age>30)
				a=11.5*m_weight4+830;
			else
				a=13.4*m_weight4+490;
			CString str;
			str.Format(L"%d",(int)a);
			m_stac1.SetWindowTextW(_T("人体基础代谢所需热量为")+str+_T("大卡"));
			sum-=a;
		}
	}
	else 
		AfxMessageBox(_T("输入正确性别."));
	m_hot=a;
	
	CRect rtlbl;
	GetDlgItem(IDC_STATIC1)->GetWindowRect(&rtlbl);
	ScreenToClient(&rtlbl);
	InvalidateRect(&rtlbl);//最后刷新对话框背景 
	UpdateWindow();
}


void CCalorieToolView::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK();
	if(m_hot<10)
	{
		AfxMessageBox(_T("完整填写体重、性别和年龄"));
	}
	else
	{
		m_stac.SetWindowTextW(_T(""));
		CString str1,str2;

		int i=0;
		i=(int) sum;
		if(i>=0)
			str1.Format(L"%d",i); 
		else
			str2.Format(L"%d",-i); 

		if(i>=0)
			m_stac.SetWindowTextW(_T("人体一共摄入了")+str1+_T("大卡"));
		else
			m_stac.SetWindowTextW(_T("人体一共消耗了")+str2+_T("大卡"));

		CRect rtlbl;
		GetDlgItem(IDC_STATIC6)->GetWindowRect(&rtlbl);
		ScreenToClient(&rtlbl);
		InvalidateRect(&rtlbl);//最后刷新对话框背景 
		UpdateWindow();
	}
}


void CCalorieToolView::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	while(m_lsc.GetNextItem(-1,/*LVNI_ALL |*/ LVNI_SELECTED) != -1)
	{
		int nItem = m_lsc.GetNextItem(-1,/*LVNI_ALL | */LVNI_SELECTED);
		/**********************卡路里的加减******************************/
		CString energy;
		energy=m_lsc.GetItemText(nItem,2);
		double a=_wtof(energy);
		sum-=(int)a;
		m_lsc.DeleteItem(nItem);
		/************************行序号重排************************/
		int cc=m_lsc.GetItemCount( );
		for(int i=nItem;i<cc;i++)
		{
			CString number;
			number.Format(L"%d",i+1);
			m_lsc.SetItemText(i,0,number);
		}
	}
	/****************--***************************/
	m_nCount--;

	*pResult = 0;
}




void CCalorieToolView::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	while(m_lsc2.GetNextItem(-1,/*LVNI_ALL |*/ LVNI_SELECTED) != -1)
	{
		int nItem = m_lsc2.GetNextItem(-1,/*LVNI_ALL | */LVNI_SELECTED);
		/**********************卡路里的加减******************************/
		CString energy;
		energy=m_lsc2.GetItemText(nItem,2);
		double a=_wtof(energy);
		sum-=(int)a;
		m_lsc2.DeleteItem(nItem);
		/************************行序号重排************************/
		int cc=m_lsc2.GetItemCount( );
		for(int i=nItem;i<cc;i++)
		{
			CString number;
			number.Format(L"%d",i+1);
			m_lsc2.SetItemText(i,0,number);
		}
	}
	/****************--***************************/
	m_nCount--;

	*pResult = 0;
}
