// RightLatestinfoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightLatestinfoView.h"
#include "afxdialogex.h"


// CRightLatestinfoView �Ի���

IMPLEMENT_DYNAMIC(CRightLatestinfoView, CDialog)

CRightLatestinfoView::CRightLatestinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightLatestinfoView::IDD, pParent)
{
	theApp.m_prightlatestinfoview=this;
	nA4Width = 420;
	nA4Hight = 594;

//	strRecv = _T("����,��,�����Ͻ��,180,28,60,ѧ��,2014-5-6,18:00,19:24,84,200,30,120,18:25,72,17:38,86,100,0,12,0,2,5,19:26,1,19:20,56,18,0,26,30,18:46,56,18:26,��ҽ��,2014-5-6");
}

CRightLatestinfoView::~CRightLatestinfoView()
{
}

void CRightLatestinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LATESTINFO, m_latestinfo);
	//DDX_Control(pDX, IDC_PDF_HEALREP, m_pdfhealrep);
	DDX_Control(pDX, IDC_GROUP_MESS, m_Group);
}


BEGIN_MESSAGE_MAP(CRightLatestinfoView, CDialog)
	ON_BN_CLICKED(IDC_QUE, &CRightLatestinfoView::OnBnClickedQue)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_SULATESTHEALREAD, &CRightLatestinfoView::OnSulatesthealread)
	ON_MESSAGE(WM_SUHRTREP,&CRightLatestinfoView::OnHrtRep)
/*	ON_NOTIFY(NM_CLICK, IDC_LATESTINFO, &CRightLatestinfoView::OnNMClickLatestinfo)*/
	ON_BN_CLICKED(IDC_BTN_BLD, &CRightLatestinfoView::OnBnClickedBtnBld)
	ON_BN_CLICKED(IDC_BTN_HRT, &CRightLatestinfoView::OnBnClickedBtnHrt)
	ON_BN_CLICKED(IDC_DOWN, &CRightLatestinfoView::OnBnClickedDown)
	ON_BN_CLICKED(IDC_RETURN, &CRightLatestinfoView::OnBnClickedReturn)
END_MESSAGE_MAP()


// CRightLatestinfoView ��Ϣ�������


BOOL CRightLatestinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightLatestinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_latestinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_latestinfo.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);
	m_latestinfo.InsertColumn(1,_T("ָ��"),LVCFMT_CENTER,90);
	m_latestinfo.InsertColumn(2,_T("��ֵ"),LVCFMT_CENTER,120);
	m_latestinfo.InsertColumn(3,_T("�������"),LVCFMT_CENTER,188);

	m_latestinfo.InsertItem(0,_T("1"));
	m_latestinfo.InsertItem(1,_T("2"));
	m_latestinfo.InsertItem(2,_T("3"));
	m_latestinfo.InsertItem(3,_T("4"));
	m_latestinfo.InsertItem(4,_T("5"));
	m_latestinfo.InsertItem(5,_T("6"));
	m_latestinfo.InsertItem(6,_T("7"));
	m_latestinfo.InsertItem(7,_T("8"));

	m_latestinfo.SetItemText(0,1,_T("���"));
	m_latestinfo.SetItemText(1,1,_T("����"));
	m_latestinfo.SetItemText(2,1,_T("BMI"));
	m_latestinfo.SetItemText(3,1,_T("����ѹ"));
	m_latestinfo.SetItemText(4,1,_T("����ѹ"));
	m_latestinfo.SetItemText(5,1,_T("Ѫ��"));
	m_latestinfo.SetItemText(6,1,_T("Ѫ��"));
	m_latestinfo.SetItemText(7,1,_T("����"));

	m_Group.SetBorderColor(RGB(136,203,103));
	m_Group.SetFontBold(TRUE);
	m_Group.SetBackgroundColor(RGB(66,210,87));
	m_Group.SetFontSize(13);
	
		//******************����Ѫѹ���水ť***************************
	GetDlgItem(IDC_BTN_BLD)->EnableWindow(FALSE);
	
// 	CRect rt;
// 	GetDlgItem(IDC_LATESTINFO)->GetWindowRect(rt);
// 	ScreenToClient(rt);


// 	m_pdfhealrep.OpenPDF(_T("��̬Ѫѹ��ⱨ��.pdf"),_T(""),_T(""));
// 	m_pdfhealrep.SetMsgCallbackWnd((long)m_hWnd);
// 	m_pdfhealrep.ShowHideBookmarks();
// 	m_pdfhealrep.ZoomFitWidth();



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightLatestinfoView::OnBnClickedQue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//****************��ѯ���������Ϣ****************

	//��UserHealInfoLatestRead��

	//****************��ѯ���������Ϣ****************




	//****************��ѯ���������Ϣ���****************

	//��SUHealInfoLatestRead��, User_HealInfo  userhealinfo

	//****************��ѯ���������Ϣ���****************




}


void CRightLatestinfoView::OnPaint()
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


HBRUSH CRightLatestinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	if ((pWnd->GetDlgCtrlID()==IDC_STATIC1)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	if ((pWnd->GetDlgCtrlID()==IDC_STATIC2)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(WHITE_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC3)) 
	{ 
		pDC->SelectObject(&theApp.m_TextFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC4)) 
	{ 
		pDC->SelectObject(&theApp.m_TextFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC5)) 
	{ 
		pDC->SelectObject(&theApp.m_TextFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_PREVIEW)) 
	{ 
		pDC->SelectObject(&theApp.m_TextFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


afx_msg LRESULT CRightLatestinfoView::OnSulatesthealread(WPARAM wParam, LPARAM lParam)
{
	//**********************�����غ�Ľ��**************************
	/*CString str=_T("18;180,80,120,80,50,90,75,2014-5-8");*/
	vector<CString> vec,vec1;
	theApp.SplitString(*(CString*)lParam/*str*/,_T(";"),TRUE,vec);
	theApp.SplitString(vec.at(1),_T(","),TRUE,vec1);

	//******************����BMI***************************************
	float BMIvalue1;
	CString BMIValue;
	if (vec1.at(0)!=_T("")&&vec1.at(0)!=_T("-1"))
	{
		BMIvalue1=_tstof(vec1.at(1))/(_tstof(vec1.at(0))*_tstof(vec1.at(0))/10000);
		BMIValue.Format(_T("%0.2f"), BMIvalue1);
	}
	
	//******************����Ϣд�����Ԫ��****************************
	if(vec.at(0)==_T("18")&&vec.at(1)!=_T("-1"))
	{
		m_latestinfo.SetItemText(0,2,vec1.at(0)+_T("cm"));
		m_latestinfo.SetItemText(0,3,vec1.at(1));
		m_latestinfo.SetItemText(1,2,vec1.at(2)+_T("kg"));
		m_latestinfo.SetItemText(1,3,vec1.at(3));
		m_latestinfo.SetItemText(2,2,BMIValue);
		m_latestinfo.SetItemText(2,3,vec1.at(3));
		m_latestinfo.SetItemText(3,2,vec1.at(6)+_T("kpa"));
		m_latestinfo.SetItemText(3,3,vec1.at(7));
		m_latestinfo.SetItemText(4,2,vec1.at(4)+_T("kpa"));
		m_latestinfo.SetItemText(4,3,vec1.at(5));
		m_latestinfo.SetItemText(5,2,vec1.at(10)+_T("mg/dl"));
		m_latestinfo.SetItemText(5,3,vec1.at(11));
		m_latestinfo.SetItemText(6,2,vec1.at(12));
		m_latestinfo.SetItemText(6,3,vec1.at(13));
		m_latestinfo.SetItemText(7,2,vec1.at(8)+_T("bmp"));
		m_latestinfo.SetItemText(7,3,vec1.at(9));
	}
	else
	{
		AfxMessageBox(_T("�������Ϣ��"));
	}
	return 0;
}

afx_msg LRESULT CRightLatestinfoView::OnHrtRep(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
	theApp.SplitString(vec.at(1),_T(","),TRUE,vec_HrtRep);
	if(vec.at(0)==_T("28")&&vec.at(1)!=_T("-1"))
	{
	CWnd* pWnd = GetDlgItem(IDC_STATIC2);
	CDC* pDC = pWnd->GetDC();

	pDC->Rectangle(0,0,nA4Width,nA4Hight);

	int nrMargin = 10;                                                 //�ϱ߾�
	int ntMargin = 30;                                                 //�ұ߾�
	TEXTMETRIC tm1;

	pDC->GetTextMetrics(&tm1);
	//*****************��ʾ��ͷ*****************************
	CPen HeadPen;
	HeadPen.CreatePen(PS_SOLID,2,RGB(0,0,0));
	CPen* pOldPen = pDC->SelectObject(&HeadPen);

	CFont font1;
	font1.CreatePointFont(130,_T("����"));
	CFont* pOldFont1 = pDC->SelectObject(&font1);

	pDC->MoveTo(nrMargin,ntMargin-tm1.tmHeight/2);
	pDC->LineTo(nA4Width-nrMargin,ntMargin-tm1.tmHeight/2);
	pDC->TextOut(nA4Width/2-4*tm1.tmAveCharWidth,ntMargin,_T("��������"));
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont1);
	//*****************��ʾ��������*************************
	CFont font;
	font.CreatePointFont(85,_T("����"));
	CFont* pOldFont = pDC->SelectObject(&font);

// 
// 	theApp.SplitString(strRecv,_T(","),TRUE,vec_HrtRep);
	PreView(pDC,vec_HrtRep);


	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	}
	else
	{
		AfxMessageBox(_T("�ޱ��棡"));
	}

    return 0;
}


// void CRightLatestinfoView::OnNMClickLatestinfo(NMHDR *pNMHDR, LRESULT *pResult)
// {
// 	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
// 	// TODO: �ڴ���ӿؼ�֪ͨ����������
// 	NMLISTVIEW* pList=(NMLISTVIEW*) pNMItemActivate;
// 	int row=pList->iItem;
// 	CString SelItem = m_latestinfo.GetItemText(row,1);
// 	if(SelItem == _T("����"))
// 	{
// 		/*GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);*/
// 		CWnd * pWnd = GetDlgItem(IDC_STATIC1);   //IDC_STATIC1 specified in the dialog editor
// 		CDC * pControlDC = pWnd->GetDC();
// 		pControlDC->SelectStockObject(DKGRAY_BRUSH);
// 		//************����ӳ��ģʽ*************************
//   		pControlDC->SetBkMode(MM_ANISOTROPIC);
// 		CRect rt;
// 		pWnd->GetClientRect(&rt);
//  		pControlDC->SetViewportExt(rt.Width(),-rt.Height());
//  		pControlDC->SetViewportOrg(rt.left+40,rt.bottom-40);
// 
// 		//*************��������ϵ*************************
// 		//**************����X��***************************
// 		pControlDC->LineTo(rt.Width()-40,0);
// 		pControlDC->LineTo(rt.Width()-40-10,5);
// 		pControlDC->MoveTo(rt.Width()-40,0);
// 		pControlDC->LineTo(rt.Width()-40-10,-5);
// 		pControlDC->TextOutW(rt.Width()-40-40,5,_T("����"));
// 
// 		//*************����Y��*****************************
// 		pControlDC->MoveTo(0,0);
// 		pControlDC->LineTo(0,-rt.Height()+40);
// 		pControlDC->LineTo(5,-rt.Height()+40+10);
// 		pControlDC->MoveTo(0,-rt.Height()+40);
// 		pControlDC->LineTo(-5,-rt.Height()+40+10);
// 		pControlDC->TextOutW(-20,-rt.Height()+40+10,_T("��"));
// 		pControlDC->TextOutW(-20,-rt.Height()+40+28,_T("��"));
// 
// 		vector<int> m_Hight;
// 		for(int i=0;i<30;i++)
// 		{
// 			int data = rand()%80;
// 			m_Hight.push_back(data);
// 		}
// 		for(int i=0;i<450;i+=15)
// 		{
// 			// 		pControlDC->MoveTo(i,0);
// 			// 		pControlDC->LineTo(i,m_Hight.at(i/15));
// 			pControlDC->Rectangle(i,0,i+5,-m_Hight.at(i/15));
// 		}
// 
// 			pWnd->ReleaseDC(pControlDC);
// 	}
// 	else
// 	{
// /*		GetDlgItem(IDC_STATIC1)->SetDlgItemText(IDC_STATIC1,_T(""));*/
// 		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
// 		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
// 	}
// 	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
// 	GetDlgItem(IDC_DOWN)->ShowWindow(SW_HIDE);
// 	*pResult = 0;
// }


void CRightLatestinfoView::OnBnClickedBtnBld()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


}


void CRightLatestinfoView::OnBnClickedBtnHrt()
{
	//******************��ȡ�ĵ�/Ѫѹ��ťλ��***********************
// 	GetDlgItem(IDC_BTN_HRT)->GetWindowRect(&rt1);
// 	GetDlgItem(IDC_BTN_BLD)->GetWindowRect(&rt2);
// 
// 	ScreenToClient(&rt1);
// 	ScreenToClient(&rt2);

// 	GetDlgItem(IDC_LATESTINFO)->ShowWindow(SW_HIDE);
// 	GetDlgItem(IDC_BTN_BLD)->SetWindowPos(this,260,15,100,25,SWP_NOZORDER);
// 	GetDlgItem(IDC_BTN_HRT)->SetWindowPos(this,160,15,100,25,SWP_NOZORDER);
// 	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
// 	GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
// 	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
// 	GetDlgItem(IDC_PREVIEW)->SetWindowPos(this,350,40,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_PREVIEW)->ShowWindow(SW_SHOW);
// 
// 	GetDlgItem(IDC_DOWN)->SetWindowPos(this,420,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_DOWN)->ShowWindow(SW_SHOW);
// 
// 	GetDlgItem(IDC_STATIC2)->SetWindowPos(this,160,40,nA4Width,nA4Hight,SWP_NOZORDER);
// 	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
// 
// 	GetDlgItem(IDC_RETURN)->SetWindowPos(this,250,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
// 	GetDlgItem(IDC_RETURN)->ShowWindow(SW_SHOW);
// 
// 	GetDlgItem(IDC_GROUP_MESS)->ShowWindow(SW_HIDE);
// 	GetDlgItem(IDC_GROUP_REP)->ShowWindow(SW_HIDE);



	//******************��ѯ������Ϣ********************************
/*	theApp.socketclient.UserHrtRepRead();*/

}


void CRightLatestinfoView::OnBnClickedDown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
/*	theApp.SplitString(strRecv,_T(","),TRUE,vec_HrtRep);*/
// 	for(int i=0;i<vec_HrtRep.size();i++)
// 	{
// 		for(int j=0;j<13-vec_HrtRep.at(i).GetLength();j++)
// 		{
// 			vec_HrtRep.at(i) += _T(" "); 
// 		}
// 	}
// 	GenerateWord(vec_HrtRep);
}

//*****************************����Word����************************************
void CRightLatestinfoView::GenerateWord(vector<CString> vec)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	COleVariant	covZero((short)0),
		covTrue((short)TRUE), 
		covFalse((short)FALSE), 
		covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR), 
		covDocxType((short)0);
	//*************����Word����*******************
	CApplication wordApp; // wordApp
	CDocuments docxs; // docxs
	CDocument0 docx, docx_active; // docx
	if ( !wordApp.CreateDispatch(_T("Word.Application")) ) // ʵ����wordApp�������г�ʼ��
	{
		AfxMessageBox(_T("����û�а�װword��Ʒ��"));
		return;
	}
	else
	{
		wordApp.put_Visible(FALSE);  // �����ĵ���ʼ���ɼ�
		CString wordVersion = wordApp.get_Version();	// ��õ�ǰword�İ汾������word2010Ϊ14.0,2013Ϊ15.0
		docxs = wordApp.get_Documents();
		docx = docxs.Add(covOptional, covOptional, covOptional, covOptional);
		if ( NULL == docx.m_lpDispatch )
			return;

		//***************����ҳ�߾�***********************
		docx_active = wordApp.get_ActiveDocument();
		CPageSetup oPageSetup = docx_active.get_PageSetup();
		if ( oPageSetup.get_Orientation() == 1 )	// ��Ϊ����������Ϊ��������wdOrientPortrait=0������wdOrientLandscape=1
		{
			oPageSetup.put_Orientation(0);	// ����
			// �����������ұ�࣬��λ羣����²������õ�ҳ�߾��ǡ����С�
			oPageSetup.put_TopMargin( (float) 72);	// ����ʱ72=2.54cm��Ĭ��ʱ90=3.17cm��10��0.35cm
			oPageSetup.put_BottomMargin( (float) 72);	// ����ʱ72=2.54cm��Ĭ��ʱ90=3.17cm��10��0.35cm
			oPageSetup.put_LeftMargin( (float) 54);	// ����ʱ54=1.9cm��Ĭ��ʱ72=2.54cm
			oPageSetup.put_RightMargin( (float) 54);	// ����ʱ54=1.9cm��Ĭ��ʱ72=2.54cm
		}

		//**********************����CSelection���󣬲�ʵ����**************
		CSelection wordSelection = wordApp.get_Selection();

		//**********************�����ĵ�����***********************
		wordSelection.TypeText(_T("��������"));
		wordSelection.HomeKey(COleVariant((short)5), COleVariant((short)1)); // wdLine=5�����ص�ǰ���ף���ѡ��ǰ��
		wordSelection.put_Style( COleVariant((short)-2) );// ����Ϊ������1����ʽ��wdStyleHeading1=-2
		// ����ѡ���������壬һ��Ҫ������ʽ�󣬷����ʽ�ᱻ��ʽ�ĸ���
		CFont0 font = wordSelection.get_Font();
		font.put_Name(_T("����"));
		font.put_Size(12);	// ����ѡ����вſ����޸ģ���������HomeKey����
		// ��õ�ǰ���䣬�����ö��뷽ʽ
		CParagraphs paragraphs = docx.get_Paragraphs();
		CParagraph lastPara = paragraphs.get_Last();
		lastPara.put_Alignment(1);	// wdAlignParagraphLeft=0, wdAlignParagraphCenter=1,wdAlignParagraphRight=2
		// ������ǰ����༭���ƶ���굽�����
		wordSelection.EndOf(COleVariant((short)4), COleVariant((short)0));	// wdParagraph=4,wdMove=0

		//****************���Word***********************
		wordSelection.TypeParagraph(); 
		wordSelection.TypeText(_T("����: ")+vec.at(0)+_T("     "));
		wordSelection.TypeText(_T("�Ա�: ")+vec.at(1)+_T("     "));
		wordSelection.TypeText(_T("��λ: ")+vec.at(2)+_T("   "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("���: ")+vec.at(3)+_T("CM    "));
		wordSelection.TypeText(_T("����: ")+vec.at(4)+_T("��    "));
		wordSelection.TypeText(_T("����: ")+vec.at(5)+_T("KG   "));
		wordSelection.TypeText(_T("ְҵ: ")+vec.at(6)+_T("   "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("�������: ")+vec.at(7)+_T(" "));
		wordSelection.TypeText(_T("��ʼʱ��: ")+vec.at(8)+_T(" "));
		wordSelection.TypeText(_T("����ʱ��: ")+vec.at(9)+_T(" "));
		wordSelection.TypeText(_T("���ʱ��: ")+vec.at(10)+_T("Min"));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("���Ĳ���: ")+vec.at(11)+_T("   "));
		wordSelection.TypeText(_T("�쳣�Ĳ���: ")+vec.at(12)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("_______________________________________________________________________________"));//����
		wordSelection.TypeParagraph();
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("  ���: ")+vec.at(13)+_T("  "));
		wordSelection.TypeText(_T("ʱ��: ")+vec.at(14)+_T("  "));
		wordSelection.TypeText(_T("����: ")+vec.at(15)+_T("  "));
		wordSelection.TypeText(_T("ʱ��: ")+vec.at(16)+_T("  "));
		wordSelection.TypeText(_T("ƽ��: ")+vec.at(17)+_T("  "));

		CTables0 wordTables = docx.get_Tables();
		CRange wordRange = wordSelection.get_Range();
		COleVariant covTrue((short)TRUE), covFalse((short)FALSE), covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
		CTable0 wordTable = wordTables.Add(wordRange, 3, 2, covTrue, covFalse); // ��ӱ��
		wordRange = wordTable.get_Range();
		CBorders TblBorsers;
		TblBorsers = wordTable.get_Borders();
		TblBorsers.put_OutsideLineStyle(0);

		CRows rows;
		rows = wordTable.get_Rows();
		CRow row;
		row = rows.Item(1);
		TblBorsers = row.get_Borders();
		TblBorsers.put_InsideLineStyle(0);

		row = rows.Item(3);
		TblBorsers = row.get_Borders();
		TblBorsers.put_InsideLineStyle(0);

		CCell cell;

		cell = wordTable.Cell(2,1);
		cell.Select();

		wordSelection.TypeText(_T("             �����粫"));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("����: ")+vec.at(18));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("�ɶ�: ")+vec.at(19)+_T("      "));
		wordSelection.TypeText(_T("����: ")+vec.at(20)+_T("     "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("����: ")+vec.at(21)+_T("      "));
		wordSelection.TypeText(_T("����: ")+vec.at(22)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("ÿ�������: ")+vec.at(23));
		wordSelection.TypeText(_T("ʱ��: ")+vec.at(24)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("ÿСʱ���: ")+vec.at(25));
		wordSelection.TypeText(_T("ʱ��: ")+vec.at(26)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("��ʱ��: ")+vec.at(27));

		cell = wordTable.Cell(2,2);
		cell.Select();
		wordSelection.TypeText(_T("             �����粫"));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("����: ")+vec.at(28));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("�ɶ�: ")+vec.at(29)+_T("  "));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("����: ")+vec.at(30)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("�����: ")+vec.at(31)+_T("    "));
		wordSelection.TypeText(_T("ʱ��: ")+vec.at(32)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("��췿������: ")+vec.at(33));
		wordSelection.TypeText(_T("ʱ��: ")+vec.at(34)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.EndOf(COleVariant((short)5), COleVariant((short)0));	// wdParagraph=4,wdMove=0

		paragraphs = docx.get_Paragraphs();
		lastPara = paragraphs.get_Last();
		lastPara.put_Alignment(1);
		wordSelection.TypeText(_T("ӡ�������"));
		wordSelection.EndOf(COleVariant((short)4), COleVariant((short)0));	// wdParagraph=4,wdMove=0

		wordSelection.TypeParagraph();
		paragraphs = docx.get_Paragraphs();
		lastPara = paragraphs.get_Last();
		lastPara.put_Alignment(0);
		wordTables = docx.get_Tables();
		wordRange = wordSelection.get_Range();
		wordTable = wordTables.Add(wordRange, 1, 1, covTrue, covFalse); // ��ӱ��

		rows = wordTable.get_Rows();
		row = rows.Item(1);
		row.SetHeight(250,1);
		wordSelection.EndOf(COleVariant((short)5), COleVariant((short)0));	// wdParagraph=4,wdMove=0
		wordSelection.TypeText(_T("                                              ҽ����")+vec.at(35));
		wordSelection.TypeText(_T("����: ")+vec.at(36));

		//***************���汨��**********************
		CString strSavePath;
		CFileDialog dlg(FALSE);
		if(dlg.DoModal()==IDOK)
		{
			strSavePath = dlg.GetPathName();
/*			strSavePath += dlg.GetFileName();*/
		}

		//CString strSavePath = _T("D:\\��������Ŀ\\��������2.docx");
		docx.SaveAs(COleVariant(strSavePath),covOptional,covOptional,covOptional,covOptional,
			covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional);
		// �˳�wordӦ��
		docx.Close(covFalse, covOptional, covOptional);
		wordApp.Quit(covOptional, covOptional, covOptional);
		wordApp.ReleaseDispatch();

		AfxMessageBox(_T("������ɣ�"));
	}
}

//****************************����WordԤ��*************************************
void CRightLatestinfoView::PreView(CDC* pDC,vector<CString> vec)
{
	int nrMargin = 10;                                                 //�ϱ߾�
	int ntMargin = 30;                                                 //�ұ߾�
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	int nGap = (nA4Width-20)/4;                                       // �����
	pDC->TextOut(nrMargin,ntMargin+2*tm.tmHeight,_T("������"));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+2*tm.tmHeight,vec.at(0));
	pDC->TextOut(nrMargin+nGap,ntMargin+2*tm.tmHeight,_T("�Ա�"));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+2*tm.tmHeight,vec.at(1));
	pDC->TextOut(nrMargin+2*nGap,ntMargin+2*tm.tmHeight,_T("��λ��"));
	pDC->TextOut(nrMargin+2*nGap+5*tm.tmAveCharWidth,ntMargin+2*tm.tmHeight,vec.at(2));

	pDC->TextOut(nrMargin,ntMargin+3.5*tm.tmHeight,_T("��ߣ�"));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(3));
	pDC->TextOut(nrMargin+nGap,ntMargin+3.5*tm.tmHeight,_T("���䣺"));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(4));
	pDC->TextOut(nrMargin+2*nGap,ntMargin+3.5*tm.tmHeight,_T("���أ�"));
	pDC->TextOut(nrMargin+2*nGap+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(6));
	pDC->TextOut(nrMargin+3*nGap,ntMargin+3.5*tm.tmHeight,_T("ְҵ��"));
	pDC->TextOut(nrMargin+3*nGap+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(5));

	pDC->TextOut(nrMargin,ntMargin+5*tm.tmHeight,_T("������ڣ�"));
	pDC->TextOut(nrMargin+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(7));
	pDC->TextOut(nrMargin+nGap,ntMargin+5*tm.tmHeight,_T("��ʼʱ�䣺"));
	pDC->TextOut(nrMargin+nGap+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(8));
	pDC->TextOut(nrMargin+2*nGap,ntMargin+5*tm.tmHeight,_T("����ʱ�䣺"));
	pDC->TextOut(nrMargin+2*nGap+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(9));
	pDC->TextOut(nrMargin+3*nGap,ntMargin+5*tm.tmHeight,_T("���ʱ����"));
	pDC->TextOut(nrMargin+3*nGap+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(10));

	pDC->TextOut(nrMargin,ntMargin+6.5*tm.tmHeight,_T("���Ĳ�����"));
	pDC->TextOut(nrMargin+8*tm.tmAveCharWidth,ntMargin+6.5*tm.tmHeight,vec.at(11));
	pDC->TextOut(nrMargin+nGap,ntMargin+6.5*tm.tmHeight,_T("�쳣�Ĳ�����"));
	pDC->TextOut(nrMargin+nGap+10*tm.tmAveCharWidth,ntMargin+6.5*tm.tmHeight,vec.at(12));

	pDC->MoveTo(nrMargin,ntMargin+8*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin,ntMargin+8*tm.tmHeight);

	pDC->TextOut(nrMargin+10,ntMargin+8.5*tm.tmHeight,_T("��죺"));
	pDC->TextOut(nrMargin+10+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(13));
	pDC->TextOut(nrMargin+10+nGap,ntMargin+8.5*tm.tmHeight,_T("ʱ�䣺"));
	pDC->TextOut(nrMargin+10+nGap+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(14));

	pDC->TextOut(nrMargin+10+2*nGap,ntMargin+8.5*tm.tmHeight,_T("������"));
	pDC->TextOut(nrMargin+10+2*nGap+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(15));
	pDC->TextOut(nrMargin+10+3*nGap,ntMargin+8.5*tm.tmHeight,_T("ƽ����"));
	pDC->TextOut(nrMargin+10+3*nGap+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(17));

	pDC->MoveTo(nrMargin,ntMargin+10*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin,ntMargin+10*tm.tmHeight);
	pDC->MoveTo(nA4Width/2,ntMargin+10*tm.tmHeight);
	pDC->LineTo(nA4Width/2,ntMargin+22*tm.tmHeight);
	pDC->MoveTo(nrMargin,ntMargin+22*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin,ntMargin+22*tm.tmHeight);

	pDC->TextOut((nA4Width/2-nrMargin)/2-3*tm.tmAveCharWidth,ntMargin+11*tm.tmHeight,_T("�����粫"));
	pDC->TextOut(nA4Width/2+(nA4Width-2*nrMargin)/4-3*tm.tmAveCharWidth,ntMargin+11*tm.tmHeight,_T("�����粫"));

	pDC->TextOut(nrMargin,ntMargin+13*tm.tmHeight,_T("������"));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+13*tm.tmHeight,vec.at(18));
	pDC->TextOut(nrMargin,ntMargin+14.5*tm.tmHeight,_T("�ɶԣ�"));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+14.5*tm.tmHeight,vec.at(19));
	pDC->TextOut(nrMargin,ntMargin+16*tm.tmHeight,_T("������"));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+16*tm.tmHeight,vec.at(21));
	pDC->TextOut(nrMargin,ntMargin+17.5*tm.tmHeight,_T("ÿ������ࣺ"));
	pDC->TextOut(nrMargin+11*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(23));
	pDC->TextOut(nrMargin,ntMargin+19*tm.tmHeight,_T("ÿСʱ��ࣺ"));
	pDC->TextOut(nrMargin+11*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(25));
	pDC->TextOut(nrMargin,ntMargin+20.5*tm.tmHeight,_T("��ʱ�ڣ�"));
	pDC->TextOut(nrMargin+8*tm.tmAveCharWidth,ntMargin+20.5*tm.tmHeight,vec.at(27));

	pDC->TextOut(nrMargin+nGap+5,ntMargin+14.5*tm.tmHeight,_T("���٣�"));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+14.5*tm.tmHeight,vec.at(20));
	pDC->TextOut(nrMargin+nGap+5,ntMargin+16*tm.tmHeight,_T("������"));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+16*tm.tmHeight,vec.at(22));

	pDC->TextOut(nrMargin+nGap+5,ntMargin+17.5*tm.tmHeight,_T("ʱ�䣺"));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(24));
	pDC->TextOut(nrMargin+nGap+5,ntMargin+19*tm.tmHeight,_T("ʱ�䣺"));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(26));

	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+13*tm.tmHeight,_T("������"));
	pDC->TextOut(nrMargin+2*nGap+4+5*tm.tmAveCharWidth,ntMargin+13*tm.tmHeight,vec.at(28));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+14.5*tm.tmHeight,_T("�ɶ�:"));
	pDC->TextOut(nrMargin+2*nGap+4+5*tm.tmAveCharWidth,ntMargin+14.5*tm.tmHeight,vec.at(29));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+16*tm.tmHeight,_T("���٣�"));
	pDC->TextOut(nrMargin+2*nGap+4+5*tm.tmAveCharWidth,ntMargin+16*tm.tmHeight,vec.at(30));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+17.5*tm.tmHeight,_T("����٣�"));
	pDC->TextOut(nrMargin+2*nGap+4+8*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(31));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+19*tm.tmHeight,_T("��췿�����ʣ�"));
	pDC->TextOut(nrMargin+2*nGap+4+11*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(33));

	pDC->TextOut(nrMargin+3*nGap+15,ntMargin+17.5*tm.tmHeight,_T("ʱ�䣺"));
	pDC->TextOut(nrMargin+3*nGap+15+5*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(32));
	pDC->TextOut(nrMargin+3*nGap+15,ntMargin+19*tm.tmHeight,_T("ʱ�䣺"));
	pDC->TextOut(nrMargin+3*nGap+15+5*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(34));

	pDC->TextOut(nA4Width/2-4*tm.tmAveCharWidth,ntMargin+24*tm.tmHeight,_T("ӡ�������"));

	pDC->MoveTo(nrMargin+5,ntMargin+25.5*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin-5,ntMargin+25.5*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin-5,ntMargin+42.5*tm.tmHeight);
	pDC->LineTo(nrMargin+5,ntMargin+42.5*tm.tmHeight);
	pDC->LineTo(nrMargin+5,ntMargin+25.5*tm.tmHeight);

	pDC->TextOut(nA4Width-nrMargin-16*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,_T("���ڣ�"));
	pDC->TextOut(nA4Width-nrMargin-16*tm.tmAveCharWidth+5*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,vec.at(36));
	pDC->TextOut(nA4Width-nrMargin-30*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,_T("ҽ����"));
	pDC->TextOut(nA4Width-nrMargin-30*tm.tmAveCharWidth+5*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,vec.at(35));
}

void CRightLatestinfoView::OnBnClickedReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_LATESTINFO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_BLD)->SetWindowPos(this,176,449,178,64,SWP_NOZORDER);
	GetDlgItem(IDC_BTN_HRT)->SetWindowPos(this,360,449,178,64,SWP_NOZORDER);
	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PREVIEW)->SetWindowPos(this,350,20,0,0,SWP_NOSIZE|SWP_NOZORDER);
	GetDlgItem(IDC_PREVIEW)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_DOWN)->SetWindowPos(this,420,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
	GetDlgItem(IDC_DOWN)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC2)->SetWindowPos(this,200,40,nA4Width,nA4Hight,SWP_NOZORDER);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_RETURN)->SetWindowPos(this,250,634,0,0,SWP_NOSIZE|SWP_NOZORDER);
	GetDlgItem(IDC_RETURN)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_GROUP_MESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_REP)->ShowWindow(SW_HIDE);
}
