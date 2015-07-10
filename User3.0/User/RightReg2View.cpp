// RightReg2View.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightReg2View.h"
#include "afxdialogex.h"


// CRightReg2View 对话框

IMPLEMENT_DYNAMIC(CRightReg2View, CDialog)

CRightReg2View::CRightReg2View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightReg2View::IDD, pParent)
	, m_job(_T(""))
	, m_add(_T(""))
	, m_emercont(_T(""))
	, m_contnum(_T(""))
	, m_surgery(_T(""))
	, m_disease(_T(""))
	, m_family(_T(""))
	, m_drug(_T(""))
{
	theApp.m_prightreg2view=this;
}

CRightReg2View::~CRightReg2View()
{
}

void CRightReg2View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HEALGROUP, m_healgroup);
	DDX_Control(pDX, IDC_LATESTGROUP, m_latestgroup);
	DDX_Text(pDX, IDC_JOB, m_job);
	DDX_Text(pDX, IDC_ADDRESS, m_add);
	DDX_Text(pDX, IDC_EMERCONT, m_emercont);
	DDX_Text(pDX, IDC_CONTACTNUM, m_contnum);
	DDX_Control(pDX, IDC_BLOODTYPE, m_bloodtype);
	//  DDX_Control(pDX, IDC_SURGERY, m_surgery);
	//  DDX_Control(pDX, IDC_DISEASE, m_disease);
	//  DDX_Control(pDX, IDC_FAMILY, m_family);
	DDX_Control(pDX, IDC_SMOKE, m_smoke);
	DDX_Control(pDX, IDC_DRINGK, m_drink);
	//  DDX_Text(pDX, IDC_DIASTOLIC, m_diastolic);
	//  DDX_Text(pDX, IDC_SYSTOLIC, m_systolic);
	//  DDX_Text(pDX, IDC_SUGAR, m_sugar);
	//  DDX_Text(pDX, IDC_HEIGHT, m_height);
	//  DDX_Text(pDX, IDC_WEIGHT, m_weight);
	//  DDX_Text(pDX, IDC_WAISTLINE, m_waistline);
	//  D//  DX_Text(p//  DX, I//  DC_UA, m_UA);
	//  DDX_Text(pDX, IDC_OXYGEN, m_oxygen);
	DDX_Text(pDX, IDC_SURGERY, m_surgery);
	DDX_Text(pDX, IDC_DISEASE, m_disease);
	DDX_Text(pDX, IDC_FAMILY, m_family);
	DDX_Text(pDX, IDC_DRUG, m_drug);
}


BEGIN_MESSAGE_MAP(CRightReg2View, CDialog)
	ON_BN_CLICKED(IDC_PRE, &CRightReg2View::OnBnClickedPre)
	ON_BN_CLICKED(IDC_REG, &CRightReg2View::OnBnClickedReg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
//	ON_MESSAGE(WM_SUREGVERY1, &CRightReg2View::OnSuregvery1)
ON_MESSAGE(WM_SUREG1, &CRightReg2View::OnSureg1)
END_MESSAGE_MAP()


// CRightReg2View 消息处理程序


void CRightReg2View::OnBnClickedPre()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightregview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightregview;
}


BOOL CRightReg2View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_healgroup.SetBorderColor(RGB(136,203,103));
	m_healgroup.SetFontBold(TRUE);
	m_healgroup.SetBackgroundColor(RGB(66,210,87));
	m_healgroup.SetFontSize(13);
	//m_healgroup.SetFont("微软雅黑");


// 	m_latestgroup.SetBorderColor(RGB(136,203,103));
// 	m_latestgroup.SetFontBold(TRUE);
// 	m_latestgroup.SetBackgroundColor(RGB(66,210,87));
// 	m_latestgroup.SetFontSize(13);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightReg2View::OnBnClickedReg()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	theApp.m_prightregview->userbaseinfo.job=m_job;
	theApp.m_prightregview->userbaseinfo.homeaddress=m_add;
	theApp.m_prightregview->userbaseinfo.emercontactor=m_emercont;
	theApp.m_prightregview->userbaseinfo.emercontactornum=m_contnum;

// 	User_HealInfo userhealinfo;
// 	userhealinfo.height=m_height;
// 	userhealinfo.weight=m_weight;
// 	float height_f=_tstof(m_height);
// 	float weight_f=_tstof(m_weight);
// 	float bmi_f;
// 	bmi_f= weight_f* weight_f/height_f;
// 	userhealinfo.BMIindex.Format(_T("0.4f"),bmi_f);
// 	userhealinfo.waistline=m_waistline;
// 	userhealinfo.diastolic=m_diastolic;
// 	userhealinfo.systolic=m_systolic;
// 	userhealinfo.sugar=m_sugar;
// 	userhealinfo.oxygen=m_oxygen;
// 	userhealinfo.UA=m_UA;

	theApp.m_prightregview->userbaseinfo.surgeryhistory=m_surgery;
	theApp.m_prightregview->userbaseinfo.diseaseshistory=m_disease;
	theApp.m_prightregview->userbaseinfo.familyhistory=m_family;
	theApp.m_prightregview->userbaseinfo.drughistory=m_drug;

// 	int sur_index=m_surgery.GetCurSel();
// 	m_surgery.GetLBText(sur_index,theApp.m_prightregview->userbaseinfo.surgeryhistory);
// 	int dis_index=m_disease.GetCurSel();
// 	m_disease.GetLBText(dis_index,theApp.m_prightregview->userbaseinfo.diseaseshistory);
// 	int fam_index=m_family.GetCurSel();
// 	m_family.GetLBText(fam_index,theApp.m_prightregview->userbaseinfo.familyhistory);


	int bt_index=m_bloodtype.GetCurSel();
	m_bloodtype.GetLBText(bt_index,theApp.m_prightregview->userbaseinfo.bloodtype);
	int smo_index=m_smoke.GetCurSel();
	m_smoke.GetLBText(smo_index,theApp.m_prightregview->userbaseinfo.smokehistory);
	int dri_index=m_drink.GetCurSel();
	m_drink.GetLBText(dri_index,theApp.m_prightregview->userbaseinfo.drinkhistory);

	theApp.socketclient.UserReg1(theApp.m_prightregview->userbaseinfo,theApp.m_prightregview->serialnumstr);

	//*****************发送付费用户注册信息************************
	
	//‘UserReg1’, User_BaseInfo userbaseinfo, User_HealInfo userhealinfo, CString serialnumber

	//*****************发送付费用户注册信息************************




	//*****************接收付费用户注册信息************************

	//‘SUReg1’, CString  exceptiontext

	//*****************接收付费用户注册信息************************
}


void CRightReg2View::OnPaint()
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


HBRUSH CRightReg2View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightReg2View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN) 
		{ 
			return true;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


//afx_msg LRESULT CRightReg2View::OnSuregvery1(WPARAM wParam, LPARAM lParam)
//{
//	m_password.SetReadOnly(FALSE);
//	m_passwordag.SetReadOnly(FALSE);
//	m_name.SetReadOnly(FALSE);
//	m_idnumber.SetReadOnly(FALSE);
//	m_cellnum.SetReadOnly(TRUE);
//	m_serialnum.SetReadOnly(TRUE);
//	GetDlgItem(IDC_NEXT)->ShowWindow(SW_SHOW);
//	return 0;
//}


afx_msg LRESULT CRightReg2View::OnSureg1(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_sureg1;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_sureg1);
	AfxMessageBox(vec_sureg1.at(1));

	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightloginview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightloginview;

// 	theApp.m_plefthealplatview->m_btnleftaccman.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnleftdrugman.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnlefthealexpert.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnhealinfo.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnhealplat.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnreg.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnreadmess.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btncontact.EnableWindow(TRUE);
// 	theApp.m_plefthealplatview->m_btnwelcome.EnableWindow(TRUE);


	return 0;
}
