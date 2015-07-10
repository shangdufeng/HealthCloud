// RightChgperinfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightChgperinfoView.h"
#include "afxdialogex.h"


// CRightChgperinfoView 对话框

IMPLEMENT_DYNAMIC(CRightChgperinfoView, CDialog)

CRightChgperinfoView::CRightChgperinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgperinfoView::IDD, pParent)
	, m_cellnum(_T(""))
	, m_name(_T(""))
	//, m_idnum(_T(""))
	, m_gender(_T(""))
	, m_job(_T(""))
	, m_address(_T(""))
	, m_emercont(_T(""))
	, m_bloodtype(_T(""))
	, m_contactnum(_T(""))
	, m_surgery(_T(""))
	, m_disease(_T(""))
	, m_family(_T(""))
	, m_smoke(_T(""))
	, m_drink(_T(""))
	, m_drug(_T(""))
	, m_birth(_T(""))
{
	theApp.m_prightchgperinfoview=this;
}

CRightChgperinfoView::~CRightChgperinfoView()
{
}

void CRightChgperinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BASICINFO, m_chgperinfo);
	DDX_Control(pDX, IDC_CHGUSERINFO, m_chguserinfo);
	DDX_Text(pDX, IDC_CELLNUM, m_cellnum);
	DDX_Text(pDX, IDC_NAME, m_name);
	//DDX_Text(pDX, IDC_IDNUMBER, m_idnum);
	DDX_CBString(pDX, IDC_GENDER, m_gender);
	DDX_Text(pDX, IDC_JOB, m_job);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_EMERCONT, m_emercont);
	DDX_CBString(pDX, IDC_BLOODTYPE, m_bloodtype);
	DDX_Text(pDX, IDC_CONTACTNUM, m_contactnum);
	//  DDX_CBString(pDX, IDC_SURGERY, m_surgery);
	//  DDX_CBString(pDX, IDC_DISEASE, m_disease);
	//  DDX_CBString(pDX, IDC_FAMILY, m_family);
	DDX_CBString(pDX, IDC_SMOKE, m_smoke);
	DDX_CBString(pDX, IDC_DRINGK, m_drink);
	DDX_Text(pDX, IDC_SURGERY, m_surgery);
	DDX_Text(pDX, IDC_DISEASE, m_disease);
	DDX_Text(pDX, IDC_FAMILY, m_family);
	DDX_Text(pDX, IDC_DRUG, m_drug);
	DDX_Text(pDX, IDC_BIRTH, m_birth);
}


BEGIN_MESSAGE_MAP(CRightChgperinfoView, CDialog)
	ON_BN_CLICKED(IDC_REG, &CRightChgperinfoView::OnBnClickedReg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_SUBASEINFOREAD, &CRightChgperinfoView::OnSubaseinforead)
	ON_MESSAGE(WM_SUBASEINFOINPUT, &CRightChgperinfoView::OnSubaseinfoinput)
END_MESSAGE_MAP()


// CRightChgperinfoView 消息处理程序


BOOL CRightChgperinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightChgperinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_chgperinfo.SetBorderColor(RGB(136,203,103));
	m_chgperinfo.SetFontBold(TRUE);
	m_chgperinfo.SetBackgroundColor(RGB(66,210,87));
	m_chgperinfo.SetFontSize(13);

	m_chguserinfo.SetBorderColor(RGB(136,203,103));
	m_chguserinfo.SetFontBold(TRUE);
	m_chguserinfo.SetBackgroundColor(RGB(66,210,87));
	m_chguserinfo.SetFontSize(13);
	//*******************发送套接字（查询用户信息）******************************

	//‘UserBaseInfoRead’


	//*******************发送套接字（查询用户信息）******************************



	//*******************接收套接字（接收用户信息）******************************

	//‘UserBaseInfoRead’, User_BaseInfo  userbaseinfore


	//*******************接收套接字（接收用户信息）******************************
	User_BaseInfo userbaseinfore;
	m_cellnum=userbaseinfore.cellnumber;
	m_name=userbaseinfore.username;
	m_gender=userbaseinfore.gender;
	m_job=userbaseinfore.job;
	m_bloodtype=userbaseinfore.bloodtype;
	m_address=userbaseinfore.homeaddress;
	m_emercont=userbaseinfore.emercontactor;
	m_contactnum=userbaseinfore.emercontactornum;
	m_surgery=userbaseinfore.surgeryhistory;
	m_disease=userbaseinfore.diseaseshistory;
	m_family=userbaseinfore.familyhistory;
	//userbaseinfo.drughistory
	m_smoke=userbaseinfore.smokehistory;
	m_drink=userbaseinfore.drinkhistory;
	UpdateData(FALSE);





	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightChgperinfoView::OnBnClickedReg()
{
	// TODO: 在此添加控件通知处理程序代码
	User_BaseInfo userbaseinfoup;
	UpdateData(TRUE);
	userbaseinfoup.cellnumber=m_cellnum;
	userbaseinfoup.username=m_name;
	userbaseinfoup.gender=m_gender;
	userbaseinfoup.birthday=m_birth;
	userbaseinfoup.job=m_job;
	userbaseinfoup.bloodtype=m_bloodtype;
	userbaseinfoup.homeaddress=m_address;
	userbaseinfoup.emercontactor=m_emercont;
	userbaseinfoup.emercontactornum=m_contactnum;
	userbaseinfoup.surgeryhistory=m_surgery;
	userbaseinfoup.diseaseshistory=m_disease;
	userbaseinfoup.familyhistory=m_family;
	userbaseinfoup.drughistory=m_drug;
	userbaseinfoup.smokehistory=m_smoke;
	userbaseinfoup.drinkhistory=m_drink;

	theApp.socketclient.UserBaseInfoInput(userbaseinfoup);

	
}


void CRightChgperinfoView::OnPaint()
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


HBRUSH CRightChgperinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CRightChgperinfoView::OnSubaseinforead(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_chgperinfo;
	vector<CString> perinfo;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_chgperinfo);
	if(vec_chgperinfo.at(0)==_T("2")&&vec_chgperinfo.at(1)!=_T("-1"))
	{
		theApp.SplitString(vec_chgperinfo.at(1),_T(","),TRUE,perinfo);
		m_name=perinfo.at(0);
		m_gender=perinfo.at(1);
		m_cellnum=perinfo.at(3);
		m_birth=perinfo.at(2);
		//m_idnum=perinfo.at(3);
		m_job=perinfo.at(5);
		m_bloodtype=perinfo.at(6);
		m_address=perinfo.at(7);
		m_emercont=perinfo.at(8);
		m_contactnum=perinfo.at(9);
		m_surgery=perinfo.at(11);
		m_smoke=perinfo.at(15);
		m_family=perinfo.at(13);
		m_drink=perinfo.at(10);
		m_drug=perinfo.at(14);
		m_disease=perinfo.at(12);
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(_T("无法查询个人信息！"));
	}
	return 0;
}


afx_msg LRESULT CRightChgperinfoView::OnSubaseinfoinput(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_baseinfoinput;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_baseinfoinput);
	AfxMessageBox(vec_baseinfoinput.at(1));
	return 0;
}
