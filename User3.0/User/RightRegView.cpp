// RightRegView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightRegView.h"
#include "afxdialogex.h"
#include "XPGroupBox.h"


// CRightRegView �Ի���

IMPLEMENT_DYNAMIC(CRightRegView, CDialog)

CRightRegView::CRightRegView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightRegView::IDD, pParent)
	, m_age(_T(""))
	, m_cell(_T(""))
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
	m_font.CreatePointFont(120,_T("����"));
	m_font_att.CreatePointFont(110,_T("����"));
	theApp.m_prightregview=this;
}

CRightRegView::~CRightRegView()
{
}

void CRightRegView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_HEALGROUP, m_healgroup);
	//  DDX_Control(pDX, IDC_HEALGROUP, m_healgroup);
	//  DDX_Control(pDX, IDC_LATESTGROUP, m_latestgroup);
	DDX_Control(pDX, IDC_VERYGROUP, m_verygroup);
	DDX_Control(pDX, IDC_BASICINFOGROUP, m_basicinfogroup);
	DDX_Control(pDX, IDC_CELLNUM, m_cellnum);
	DDX_Control(pDX, IDC_SERIALNUM, m_serialnum);
	DDX_Control(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_PASSWORDAG, m_passwordag);
	DDX_Control(pDX, IDC_NAME, m_name);
	//  DDX_Control(pDX, IDC_IDNUMBER, m_idnumber);
	DDX_Control(pDX, IDC_GENDER, m_gender);
	DDX_Text(pDX, IDC_EDIT1, m_age);
	DDX_Text(pDX, IDC_CELLNUM, m_cell);
}


BEGIN_MESSAGE_MAP(CRightRegView, CDialog)
	ON_WM_CTLCOLOR()
//	ON_STN_CLICKED(IDC_DRINK, &CRightRegView::OnStnClickedDrink)
//ON_BN_CLICKED(IDC_REG, &CRightRegView::OnBnClickedReg)
ON_BN_CLICKED(IDC_NEXT, &CRightRegView::OnBnClickedNext)
ON_BN_CLICKED(IDC_FINDPASS, &CRightRegView::OnBnClickedFindpass)
ON_BN_CLICKED(IDC_VERIFY, &CRightRegView::OnBnClickedVerify)
ON_BN_CLICKED(IDC_REG, &CRightRegView::OnBnClickedReg)
ON_WM_PAINT()

//ON_MESSAGE(WM_RECVDATA, &CRightRegView::OnRecvData)
//ON_MESSAGE(WM_REG, &CRightRegView::OnReg)
//ON_BN_CLICKED(IDC_BUTTON1, &CRightRegView::OnBnClickedButton1)
//ON_MESSAGE(WM_REG, &CRightRegView::OnReg)
ON_MESSAGE(WM_SUREGVERY, &CRightRegView::OnSuregvery)
ON_MESSAGE(WM_SUREGVERY1, &CRightRegView::OnSuregvery1)
ON_MESSAGE(WM_SUREG, &CRightRegView::OnSureg)
ON_BN_CLICKED(IDC_BTN_BACK, &CRightRegView::OnBnClickedBtnBack)
END_MESSAGE_MAP()


// CRightRegView ��Ϣ�������


HBRUSH CRightRegView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����


	if ((pWnd->GetDlgCtrlID()==IDC_STAR)|(pWnd->GetDlgCtrlID()==IDC_STAR2)|(pWnd->GetDlgCtrlID()==IDC_STAR3)|(pWnd->GetDlgCtrlID()==IDC_STAR4)|(pWnd->GetDlgCtrlID()==IDC_STAR5)|(pWnd->GetDlgCtrlID()==IDC_VERYINFO)
		|(pWnd->GetDlgCtrlID()==IDC_PASSERRO)) 
	{ 
		pDC->SelectObject(&m_font); 
		pDC->SetTextColor(RGB(255,0,0)); 
	} 

	if ((pWnd->GetDlgCtrlID()==IDC_ATT)|(pWnd->GetDlgCtrlID()==IDC_ATT1)|(pWnd->GetDlgCtrlID()==IDC_ATT2)|(pWnd->GetDlgCtrlID()==IDC_ATT3)) 
	{ 
		pDC->SelectObject(&m_font_att); 
		pDC->SetTextColor(RGB(99,154,44)); 
	} 

	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)||(pWnd->GetDlgCtrlID()==IDC_PALTUSE)
		||(pWnd->GetDlgCtrlID()==IDC_STAR)||(pWnd->GetDlgCtrlID()==IDC_STAR2)
		||(pWnd->GetDlgCtrlID()==IDC_STAR3)||(pWnd->GetDlgCtrlID()==IDC_STAR4)
		||(pWnd->GetDlgCtrlID()==IDC_STAR5)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}




	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return m_brush;
	return hbr;
}


BOOL CRightRegView::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_verygroup.SetBorderColor(RGB(136,203,103));
	m_verygroup.SetFontBold(TRUE);
	m_verygroup.SetBackgroundColor(RGB(66,210,87));
	m_verygroup.SetFontSize(13);

	m_basicinfogroup.SetBorderColor(RGB(136,203,103));
	m_basicinfogroup.SetFontBold(TRUE);
	m_basicinfogroup.SetBackgroundColor(RGB(66,210,87));
	m_basicinfogroup.SetFontSize(13);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightRegView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN) 
		{ 
			return true;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}





void CRightRegView::OnBnClickedNext()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_name.GetWindowText(theApp.m_prightregview->userbaseinfo.username);
	CString str_password,str_password2;
	m_password.GetWindowText(str_password);
	m_passwordag.GetWindowText(str_password2);
	if (str_password!=str_password2)
	{
		AfxMessageBox(_T("�������벻һ�£�"));
		return;
	}
	else
	{
		m_password.GetWindowText(theApp.m_prightregview->userbaseinfo.password);
	}
	CString gender_str;
	GetDlgItem(IDC_GENDER)->GetWindowText(gender_str);
	theApp.m_prightregview->userbaseinfo.gender=gender_str;
	theApp.m_prightregview->userbaseinfo.cellnumber=m_cell;
	theApp.m_prightregview->userbaseinfo.birthday=m_age;


	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightreg2view);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightreg2view;

	

}


void CRightRegView::OnBnClickedFindpass()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightresetpassview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightresetpassview;
}


void CRightRegView::OnBnClickedVerify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cellnumstr;
	m_cellnum.GetWindowText(cellnumstr);
	m_serialnum.GetWindowText(serialnumstr);
	if (cellnumstr==_T(""))
	{
		AfxMessageBox(_T("�������ֻ���"));
	}
	if (serialnumstr==_T("")&&cellnumstr!=_T(""))
	{
		//*************�����׽���**************���к�Ϊ��

		//��UserRegVery��, CString usercellnum

		//*************�����׽���**************

		theApp.socketclient.UserRegVery(cellnumstr);

	}
	else
	{
		//*************�����׽���**************���кŲ�Ϊ��

		//��UserRegVery1��, CString usercellnum, CString userserialnum


		//*************�����׽���**************
		theApp.socketclient.UserRegVery1(cellnumstr,serialnumstr);
		
	}




	//*****************�����׽���***************���к�Ϊ��

	//��SURegVery��,  CString verytext

	//*****************�����׽���***************���к�Ϊ��


	//*************�����׽���**************���кŲ�Ϊ��

		
	//��SURegVery1��,  CString verytext

	//*************�����׽���**************







}


void CRightRegView::OnBnClickedReg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	CString str_password,str_password2;
	m_password.GetWindowText(str_password);
	m_passwordag.GetWindowText(str_password2);
	if (str_password!=str_password2)
	{
		AfxMessageBox(_T("�������벻һ�£�"));
		return;
	}
	else
	{
		m_password.GetWindowText(userbaseinfo.password);
	}

	m_cellnum.GetWindowText(userbaseinfo.cellnumber);
	m_name.GetWindowText(userbaseinfo.username);
	int index=m_gender.GetCurSel();
	m_gender.GetLBText(index,userbaseinfo.gender);
	userbaseinfo.birthday=m_age;
	theApp.socketclient.UserReg(userbaseinfo);
	//******************�����׽��֣������û�ע�ᣩ***************************

	//��UserReg��, User_BaseInfo userbaseinfo, CString serialnumber

	//******************�����׽��֣������û�ע�ᣩ***************************




	//******************�����׽��֣������û�ע������***************************

	//��UserReg��, CString exceptiontext

	//******************�����׽��֣������û�ע������***************************
}


void CRightRegView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
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


//afx_msg LRESULT CRightRegView::OnRecvData(WPARAM wParam, LPARAM lParam)
//{
//	GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
//	return 1;
//}


// LRESULT CRightRegView::OnReg(WPARAM wParam, LPARAM lParam)
//{
//	GetDlgItem(IDC_REGRES)->ShowWindow(SW_SHOW);
//	return 0;
//}


// void CRightRegView::OnBnClickedButton1()
// {
//	 // TODO: �ڴ���ӿؼ�֪ͨ����������
//	 PostMessage(WM_REG,0,0);
// }


//afx_msg LRESULT CRightRegView::OnReg(WPARAM wParam, LPARAM lParam)
//{
//	GetDlgItem(IDC_REGRES)->ShowWindow(SW_SHOW);
//	return 0;
//}


afx_msg LRESULT CRightRegView::OnSuregvery(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_regvery;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_regvery);
	if (vec_regvery.at(1)==_T("��֤�ɹ�!"))
	{
		m_password.SetReadOnly(FALSE);
		m_passwordag.SetReadOnly(FALSE);
		m_name.SetReadOnly(FALSE);
		
		//m_cellnum.SetReadOnly(TRUE);
		//m_serialnum.SetReadOnly(TRUE);
		m_gender.EnableWindow(TRUE);
		GetDlgItem(IDC_REG)->ShowWindow(SW_SHOW);
	}
	else
	{
		AfxMessageBox(_T("�˺��Ѵ��ڣ�������"));
	}
	return 0;
}



afx_msg LRESULT CRightRegView::OnSuregvery1(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_regvery1;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_regvery1);
 	if (vec_regvery1.at(1)==_T("��֤�ɹ�!"))
 	{
		AfxMessageBox(_T("��֤�ɹ���������һ����Ϣ��"));
		m_password.SetReadOnly(FALSE);
		m_passwordag.SetReadOnly(FALSE);
		m_name.SetReadOnly(FALSE);
		m_gender.EnableWindow(TRUE);
// 		m_cellnum.SetReadOnly(TRUE);
// 		m_serialnum.SetReadOnly(TRUE);
		GetDlgItem(IDC_NEXT)->ShowWindow(SW_SHOW);
	}
//  	else if(vec_regvery1.at(1)==_T("1"))
// 	{
// 		AfxMessageBox(_T("���˻���δ��ע�ᣬ�������кŲ����ڣ���ȷ�Ϻ���������"));
// 	}
// 	else if (vec_regvery1.at(1)==_T("2"))
// 	{
// 		AfxMessageBox(_T("���˻���δ��ע��,�������к���ע������"));
// 	}
// 	else if (vec_regvery1.at(1)==_T("3"))
// 	{
// 		AfxMessageBox(_T("���˺��Ѵ��ڣ��������ظ�ע��"));
// 	}

	else
	{
		AfxMessageBox(vec_regvery1.at(1));
	}
	
	return 0;
}


afx_msg LRESULT CRightRegView::OnSureg(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_sureg;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_sureg);
	AfxMessageBox(vec_sureg.at(1));

	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;

	theApp.m_plefthealplatview->m_btnleftaccman.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnleftdrugman.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnlefthealexpert.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnhealinfo.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnhealplat.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnreg.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnreadmess.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btncontact.EnableWindow(TRUE);
	theApp.m_plefthealplatview->m_btnwelcome.EnableWindow(TRUE);


	return 0;
}


void CRightRegView::OnBnClickedBtnBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightloginview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightloginview;
}
