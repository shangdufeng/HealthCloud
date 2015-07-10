// RightLoginView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightLoginView.h"
#include "afxdialogex.h"


// CRightLoginView �Ի���

IMPLEMENT_DYNAMIC(CRightLoginView, CDialog)

CRightLoginView::CRightLoginView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightLoginView::IDD, pParent)
	, m_account(_T(""))
	, m_password(_T(""))
	
{
	m_brush.CreateSolidBrush(RGB(205,231,208));
	m_compfont.CreatePointFont(300,_T("����"));
	m_regfont.CreatePointFont(200,_T("����"));
	m_errfont.CreatePointFont(150,_T("����"));
	m_BKbitmap.LoadBitmap(IDB_LOGINBK);
	theApp.m_prightloginview=this;
}

int CRightLoginView::m_trynum=0;
CRightLoginView::~CRightLoginView()
{
}

void CRightLoginView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ACCO, m_account);
	DDX_Text(pDX, IDC_PASS, m_password);
	DDX_Control(pDX, IDC_REG, m_reg);
	DDX_Control(pDX, IDC_FINDPASS, m_findpass);
}


BEGIN_MESSAGE_MAP(CRightLoginView, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_FINDPASS, &CRightLoginView::OnBnClickedFindpass)
	ON_BN_CLICKED(IDC_SUBMIT, &CRightLoginView::OnBnClickedSubmit)
	ON_BN_CLICKED(IDC_REG, &CRightLoginView::OnBnClickedReg)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_MESSAGE(WM_SERVERLOGON, &CRightLoginView::OnServerlogon)
END_MESSAGE_MAP()


// CRightLoginView ��Ϣ�������


HBRUSH CRightLoginView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	if ((pWnd->GetDlgCtrlID()==IDC_CHECKTEXT)||(pWnd->GetDlgCtrlID()==IDC_CHECK)) 
	{ 

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}





	if (pWnd->GetDlgCtrlID()==IDC_COMP) 
	{ 
		pDC->SelectObject(&m_compfont);
		//pDC->SetBkColor(RGB(205,231,208));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		//pDC->SetTextColor(RGB(255,0,0)); 
	} 
	if ((pWnd->GetDlgCtrlID()==IDC_STA_ACC)||(pWnd->GetDlgCtrlID()==IDC_STA_PASS)) 
	{ 
		pDC->SelectObject(&m_regfont); 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	if (pWnd->GetDlgCtrlID()==IDC_ERRO) 
	{ 
		pDC->SelectObject(&m_errfont);  
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	} 

// 	if ((pWnd->GetDlgCtrlID()==IDC_ACCO)||(pWnd->GetDlgCtrlID()==IDC_PASS)) 
// 	{ 
// 		
// 		pDC->SetBkColor(RGB(255,255,255));
// 		 
// 	}

	











	
	if ((pWnd->GetDlgCtrlID()==IDC_REG)||(pWnd->GetDlgCtrlID()==IDC_FINDPASS)) 
	{ 

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//return hbr;
	return m_brush;
}


BOOL CRightLoginView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightLoginView::OnBnClickedFindpass()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightresetpassview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightresetpassview;

}


void CRightLoginView::OnBnClickedSubmit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//if (m_trynum==2)
	//{
		//PostQuitMessage(0);
	//}
	//else
	//{
		UpdateData(TRUE);
		//if (m_account==m_password)
		//{

			theApp.socketclient.UserLogOn(m_account,m_password);





 			theApp.m_plefthealplatview->m_btnleftaccman.EnableWindow(TRUE);
			theApp.m_plefthealplatview->m_btnleftdrugman.EnableWindow(TRUE);
			theApp.m_plefthealplatview->m_btnlefthealexpert.EnableWindow(TRUE);
			theApp.m_plefthealplatview->m_btnhealinfo.EnableWindow(TRUE);
			theApp.m_plefthealplatview->m_btnhealplat.EnableWindow(TRUE);
		    theApp.m_plefthealplatview->m_btnreg.EnableWindow(TRUE);
 			theApp.m_plefthealplatview->m_btnreadmess.EnableWindow(TRUE);
 			theApp.m_plefthealplatview->m_btncontact.EnableWindow(TRUE);
 			theApp.m_plefthealplatview->m_btnwelcome.EnableWindow(TRUE);

			CButton *pCheckbox = (CButton*)GetDlgItem(IDC_CHECK);
			if (BST_CHECKED==pCheckbox->GetCheck())
			{
				CStdioFile file(_T("accpass.txt"),CFile::modeCreate|CFile::modeWrite);
				file.WriteString(_T("TRUE\n"));
				file.WriteString(m_account+_T("\n"));
				file.WriteString(m_password);
				file.Close();
				/*CFile file(_T("accpass.txt"),CFile::modeCreate|CFile::modeWrite);
				file.Write(_T("TRUE"),4);
				file.Write(m_account,m_account.GetLength());
				file.Write(m_password,m_password.GetLength());*/
			}
			else
			{
				CStdioFile file(_T("accpass.txt"),CFile::modeCreate|CFile::modeWrite);
				file.WriteString(_T("FALSE\n"));
				file.Close();
			}
			

			//theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
			//theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
			
			//Invalidate();
			
			
		//}
		//else
		//{
			//GetDlgItem(IDC_ERRO)->ShowWindow(SW_SHOW);
			//GetDlgItem(IDC_FINDPASS)->ShowWindow(SW_SHOW);
			//m_trynum++;
		//}
	//}	
}


void CRightLoginView::OnBnClickedReg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightregview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightregview;
}


BOOL CRightLoginView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_reg.SetFlat(TRUE);
	m_findpass.SetFlat(TRUE);
	m_reg.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));
	//m_reg.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(205,231,208));//����ڰ�ť�ⱳ����ɫ
	//m_reg.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	//m_reg.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(205,231,208));
	//m_reg.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(71,132,43));
	m_reg.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(37,37,250));
	m_reg.DrawTransparent(TRUE);
	m_findpass.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_findpass.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(37,37,250));
	m_findpass.DrawTransparent(TRUE);
	CButton *pCheckbox = (CButton*)GetDlgItem(IDC_CHECK);
	
	CStdioFile file(_T("accpass.txt"),CFile::modeRead);
	CString text,acc,pass;
	file.ReadString(text);
// 	text.TrimLeft();
// 	text.TrimRight();
// 	acc.TrimLeft();
// 	acc.TrimRight();
// 	pass.TrimLeft();
// 	pass.TrimRight();
	CString checkstr=_T("TRUE");
//	MessageBox(_T("text"));
	if (text==checkstr)
	{	
		file.ReadString(acc);
		file.ReadString(pass);
		pCheckbox->SetCheck(1);
		m_account=acc;
		m_password=pass;
		UpdateData(FALSE);
		
	}
	else
	{
		pCheckbox->SetCheck(BST_UNCHECKED);
	}
	file.Close();


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CRightLoginView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if   (pWnd   ==   GetDlgItem(IDC_REG)||pWnd   ==   GetDlgItem(IDC_FINDPASS)||pWnd   ==   GetDlgItem(IDC_SUBMIT)  ) 
	{   
		SetCursor(LoadCursor(NULL,   IDC_HAND));   
		return   TRUE;   
	}   



	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightLoginView::OnPaint()
{
// 	CPaintDC dc(this); // device context for painting
// 	// TODO: �ڴ˴������Ϣ����������
// 	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
// 	

	
// 	CPaintDC   dc(this);   
// 	CRect   rect;   
// 	GetParent()->GetClientRect(&rect);   
// 	CDC   dcMem;   
// 	dcMem.CreateCompatibleDC(&dc);   
// 	CBitmap   bmpBackground;   
// 	bmpBackground.LoadBitmap(IDB_LOGINBK);    
// 	BITMAP   bitmap;   
// 	bmpBackground.GetBitmap(&bitmap);   
// 	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
// 	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
// 	bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  

	CPaintDC dc(this);
	CPen pen(PS_SOLID,1,RGB(160,90,205));
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_LOGINBK);   
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	CPen* pOldpen=dc.SelectObject(&pen);
	//CRect rec;
	//GetParent()->GetClientRect(rec);
	dc.FillRect(CRect(0,0,850,800),&brush);  
	//dc.FillRect(rec,&brush);

	//****************************���Ƶ�½��************************************
	CRect rt;
	GetParent()->GetClientRect(&rt);
	dc.RoundRect(rt.Width()/5,rt.Height()/3,rt.Width()*4/5,rt.Height()*2/3,15,15);

// 	GetDlgItem(IDC_PASSWORD)->GetClientRect(&rt1);
// 	GetDlgItem(IDC_ACCO)->SetWindowPos(this,rt.Width()/5+15,rt.Height()/3+10,0,0,SWP_NOSIZE);
// 	GetDlgItem(IDC_PASSWORD)->SetWindowPos(this,rt.Width()/5+15,rt.Height()/3+20+rt1.Height(),0,0,SWP_NOSIZE);
// 	GetDlgItem(IDC_CHECK)->SetWindowPos(this,rt.Width()/5+25,rt.Height()/3+30+rt1.Height(),0,0,SWP_NOSIZE);
// 	GetDlgItem(IDC_CHECKTEXT)->SetWindowPos(this,rt.Width()/5+30,rt.Height()/3+30+rt1.Height(),0,0,SWP_NOSIZE);
// 
// 	GetDlgItem(IDC_SUBMIT)->SetWindowPos(this,rt.Width()/5+15,rt.Height()/3+30+rt1.Height()/2,0,0,SWP_NOSIZE);

	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldpen);
	

}


afx_msg LRESULT CRightLoginView::OnServerlogon(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_login;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_login);
	if (vec_login.at(1)==_T("��½�ɹ�!"))
	{
		AfxMessageBox(_T("��¼�ɹ�"));

		theApp.socketclient.UserWel();
		theApp.m_plefthealplatview->m_btnleftaccman.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnleftdrugman.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnlefthealexpert.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnhealinfo.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnhealplat.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnreg.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnreadmess.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btncontact.EnableWindow(TRUE);
		theApp.m_plefthealplatview->m_btnwelcome.EnableWindow(TRUE);


		CButton *pCheckbox = (CButton*)GetDlgItem(IDC_CHECK);
			if (BST_CHECKED==pCheckbox->GetCheck())
			{
				CStdioFile file(_T("accpass.txt"),CFile::modeCreate|CFile::modeWrite);
				file.WriteString(_T("TRUE\n"));
				file.WriteString(m_account+_T("\n"));
				file.WriteString(m_password);

				/*CFile file(_T("accpass.txt"),CFile::modeCreate|CFile::modeWrite);
				file.Write(_T("TRUE"),4);
				file.Write(m_account,m_account.GetLength());
				file.Write(m_password,m_password.GetLength());*/

				file.Close();
			}
			else
			{
				CStdioFile file(_T("accpass.txt"),CFile::modeCreate|CFile::modeWrite);
				file.WriteString(_T("FALSE\n"));
				file.Close();
			}
			

			theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
			theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;

	}
	else 
	{
		AfxMessageBox(_T("��¼ʧ��"));
	}
	
	return 0;
}
