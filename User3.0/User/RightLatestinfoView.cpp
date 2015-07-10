// RightLatestinfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightLatestinfoView.h"
#include "afxdialogex.h"


// CRightLatestinfoView 对话框

IMPLEMENT_DYNAMIC(CRightLatestinfoView, CDialog)

CRightLatestinfoView::CRightLatestinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightLatestinfoView::IDD, pParent)
{
	theApp.m_prightlatestinfoview=this;
	nA4Width = 420;
	nA4Hight = 594;

//	strRecv = _T("张三,男,苏州紫金港,180,28,60,学生,2014-5-6,18:00,19:24,84,200,30,120,18:25,72,17:38,86,100,0,12,0,2,5,19:26,1,19:20,56,18,0,26,30,18:46,56,18:26,许医生,2014-5-6");
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


// CRightLatestinfoView 消息处理程序


BOOL CRightLatestinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightLatestinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_latestinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_latestinfo.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_latestinfo.InsertColumn(1,_T("指标"),LVCFMT_CENTER,90);
	m_latestinfo.InsertColumn(2,_T("数值"),LVCFMT_CENTER,120);
	m_latestinfo.InsertColumn(3,_T("检测日期"),LVCFMT_CENTER,188);

	m_latestinfo.InsertItem(0,_T("1"));
	m_latestinfo.InsertItem(1,_T("2"));
	m_latestinfo.InsertItem(2,_T("3"));
	m_latestinfo.InsertItem(3,_T("4"));
	m_latestinfo.InsertItem(4,_T("5"));
	m_latestinfo.InsertItem(5,_T("6"));
	m_latestinfo.InsertItem(6,_T("7"));
	m_latestinfo.InsertItem(7,_T("8"));

	m_latestinfo.SetItemText(0,1,_T("身高"));
	m_latestinfo.SetItemText(1,1,_T("体重"));
	m_latestinfo.SetItemText(2,1,_T("BMI"));
	m_latestinfo.SetItemText(3,1,_T("舒张压"));
	m_latestinfo.SetItemText(4,1,_T("收缩压"));
	m_latestinfo.SetItemText(5,1,_T("血糖"));
	m_latestinfo.SetItemText(6,1,_T("血氧"));
	m_latestinfo.SetItemText(7,1,_T("心率"));

	m_Group.SetBorderColor(RGB(136,203,103));
	m_Group.SetFontBold(TRUE);
	m_Group.SetBackgroundColor(RGB(66,210,87));
	m_Group.SetFontSize(13);
	
		//******************禁用血压报告按钮***************************
	GetDlgItem(IDC_BTN_BLD)->EnableWindow(FALSE);
	
// 	CRect rt;
// 	GetDlgItem(IDC_LATESTINFO)->GetWindowRect(rt);
// 	ScreenToClient(rt);


// 	m_pdfhealrep.OpenPDF(_T("动态血压监测报告.pdf"),_T(""),_T(""));
// 	m_pdfhealrep.SetMsgCallbackWnd((long)m_hWnd);
// 	m_pdfhealrep.ShowHideBookmarks();
// 	m_pdfhealrep.ZoomFitWidth();



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightLatestinfoView::OnBnClickedQue()
{
	// TODO: 在此添加控件通知处理程序代码
	//****************查询最近健康信息****************

	//‘UserHealInfoLatestRead’

	//****************查询最近健康信息****************




	//****************查询最近健康信息结果****************

	//‘SUHealInfoLatestRead’, User_HealInfo  userhealinfo

	//****************查询最近健康信息结果****************




}


void CRightLatestinfoView::OnPaint()
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


HBRUSH CRightLatestinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
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
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


afx_msg LRESULT CRightLatestinfoView::OnSulatesthealread(WPARAM wParam, LPARAM lParam)
{
	//**********************处理返回后的结果**************************
	/*CString str=_T("18;180,80,120,80,50,90,75,2014-5-8");*/
	vector<CString> vec,vec1;
	theApp.SplitString(*(CString*)lParam/*str*/,_T(";"),TRUE,vec);
	theApp.SplitString(vec.at(1),_T(","),TRUE,vec1);

	//******************计算BMI***************************************
	float BMIvalue1;
	CString BMIValue;
	if (vec1.at(0)!=_T("")&&vec1.at(0)!=_T("-1"))
	{
		BMIvalue1=_tstof(vec1.at(1))/(_tstof(vec1.at(0))*_tstof(vec1.at(0))/10000);
		BMIValue.Format(_T("%0.2f"), BMIvalue1);
	}
	
	//******************将信息写入各单元格****************************
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
		AfxMessageBox(_T("无最近信息！"));
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

	int nrMargin = 10;                                                 //上边距
	int ntMargin = 30;                                                 //右边距
	TEXTMETRIC tm1;

	pDC->GetTextMetrics(&tm1);
	//*****************显示表头*****************************
	CPen HeadPen;
	HeadPen.CreatePen(PS_SOLID,2,RGB(0,0,0));
	CPen* pOldPen = pDC->SelectObject(&HeadPen);

	CFont font1;
	font1.CreatePointFont(130,_T("黑体"));
	CFont* pOldFont1 = pDC->SelectObject(&font1);

	pDC->MoveTo(nrMargin,ntMargin-tm1.tmHeight/2);
	pDC->LineTo(nA4Width-nrMargin,ntMargin-tm1.tmHeight/2);
	pDC->TextOut(nA4Width/2-4*tm1.tmAveCharWidth,ntMargin,_T("分析报告"));
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont1);
	//*****************显示报告内容*************************
	CFont font;
	font.CreatePointFont(85,_T("宋体"));
	CFont* pOldFont = pDC->SelectObject(&font);

// 
// 	theApp.SplitString(strRecv,_T(","),TRUE,vec_HrtRep);
	PreView(pDC,vec_HrtRep);


	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	}
	else
	{
		AfxMessageBox(_T("无报告！"));
	}

    return 0;
}


// void CRightLatestinfoView::OnNMClickLatestinfo(NMHDR *pNMHDR, LRESULT *pResult)
// {
// 	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
// 	// TODO: 在此添加控件通知处理程序代码
// 	NMLISTVIEW* pList=(NMLISTVIEW*) pNMItemActivate;
// 	int row=pList->iItem;
// 	CString SelItem = m_latestinfo.GetItemText(row,1);
// 	if(SelItem == _T("体重"))
// 	{
// 		/*GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);*/
// 		CWnd * pWnd = GetDlgItem(IDC_STATIC1);   //IDC_STATIC1 specified in the dialog editor
// 		CDC * pControlDC = pWnd->GetDC();
// 		pControlDC->SelectStockObject(DKGRAY_BRUSH);
// 		//************设置映射模式*************************
//   		pControlDC->SetBkMode(MM_ANISOTROPIC);
// 		CRect rt;
// 		pWnd->GetClientRect(&rt);
//  		pControlDC->SetViewportExt(rt.Width(),-rt.Height());
//  		pControlDC->SetViewportOrg(rt.left+40,rt.bottom-40);
// 
// 		//*************绘制坐标系*************************
// 		//**************绘制X轴***************************
// 		pControlDC->LineTo(rt.Width()-40,0);
// 		pControlDC->LineTo(rt.Width()-40-10,5);
// 		pControlDC->MoveTo(rt.Width()-40,0);
// 		pControlDC->LineTo(rt.Width()-40-10,-5);
// 		pControlDC->TextOutW(rt.Width()-40-40,5,_T("日期"));
// 
// 		//*************绘制Y轴*****************************
// 		pControlDC->MoveTo(0,0);
// 		pControlDC->LineTo(0,-rt.Height()+40);
// 		pControlDC->LineTo(5,-rt.Height()+40+10);
// 		pControlDC->MoveTo(0,-rt.Height()+40);
// 		pControlDC->LineTo(-5,-rt.Height()+40+10);
// 		pControlDC->TextOutW(-20,-rt.Height()+40+10,_T("体"));
// 		pControlDC->TextOutW(-20,-rt.Height()+40+28,_T("重"));
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
	// TODO: 在此添加控件通知处理程序代码


}


void CRightLatestinfoView::OnBnClickedBtnHrt()
{
	//******************获取心电/血压按钮位置***********************
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



	//******************查询报告信息********************************
/*	theApp.socketclient.UserHrtRepRead();*/

}


void CRightLatestinfoView::OnBnClickedDown()
{
	// TODO: 在此添加控件通知处理程序代码
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

//*****************************生成Word报告************************************
void CRightLatestinfoView::GenerateWord(vector<CString> vec)
{
	// TODO: 在此添加控件通知处理程序代码
	COleVariant	covZero((short)0),
		covTrue((short)TRUE), 
		covFalse((short)FALSE), 
		covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR), 
		covDocxType((short)0);
	//*************定义Word变量*******************
	CApplication wordApp; // wordApp
	CDocuments docxs; // docxs
	CDocument0 docx, docx_active; // docx
	if ( !wordApp.CreateDispatch(_T("Word.Application")) ) // 实例化wordApp，必须有初始化
	{
		AfxMessageBox(_T("本机没有安装word产品！"));
		return;
	}
	else
	{
		wordApp.put_Visible(FALSE);  // 设置文档开始不可见
		CString wordVersion = wordApp.get_Version();	// 获得当前word的版本，比如word2010为14.0,2013为15.0
		docxs = wordApp.get_Documents();
		docx = docxs.Add(covOptional, covOptional, covOptional, covOptional);
		if ( NULL == docx.m_lpDispatch )
			return;

		//***************设置页边距***********************
		docx_active = wordApp.get_ActiveDocument();
		CPageSetup oPageSetup = docx_active.get_PageSetup();
		if ( oPageSetup.get_Orientation() == 1 )	// 若为纵向则设置为横向，纵向wdOrientPortrait=0，横向wdOrientLandscape=1
		{
			oPageSetup.put_Orientation(0);	// 横向
			// 设置上下左右变距，单位缇，以下参数设置的页边距是“适中”
			oPageSetup.put_TopMargin( (float) 72);	// 适中时72=2.54cm，默认时90=3.17cm；10≈0.35cm
			oPageSetup.put_BottomMargin( (float) 72);	// 适中时72=2.54cm，默认时90=3.17cm；10≈0.35cm
			oPageSetup.put_LeftMargin( (float) 54);	// 适中时54=1.9cm，默认时72=2.54cm
			oPageSetup.put_RightMargin( (float) 54);	// 适中时54=1.9cm，默认时72=2.54cm
		}

		//**********************声明CSelection对象，并实例化**************
		CSelection wordSelection = wordApp.get_Selection();

		//**********************设置文档内容***********************
		wordSelection.TypeText(_T("分析报告"));
		wordSelection.HomeKey(COleVariant((short)5), COleVariant((short)1)); // wdLine=5，返回当前行首，并选择当前行
		wordSelection.put_Style( COleVariant((short)-2) );// 设置为“标题1“样式，wdStyleHeading1=-2
		// 设置选择区域字体，一定要放在样式后，否则格式会被样式的覆盖
		CFont0 font = wordSelection.get_Font();
		font.put_Name(_T("宋体"));
		font.put_Size(12);	// 必须选择该行才可以修改，即必须有HomeKey那行
		// 获得当前段落，并设置对齐方式
		CParagraphs paragraphs = docx.get_Paragraphs();
		CParagraph lastPara = paragraphs.get_Last();
		lastPara.put_Alignment(1);	// wdAlignParagraphLeft=0, wdAlignParagraphCenter=1,wdAlignParagraphRight=2
		// 结束当前段落编辑，移动光标到段落后
		wordSelection.EndOf(COleVariant((short)4), COleVariant((short)0));	// wdParagraph=4,wdMove=0

		//****************填充Word***********************
		wordSelection.TypeParagraph(); 
		wordSelection.TypeText(_T("姓名: ")+vec.at(0)+_T("     "));
		wordSelection.TypeText(_T("性别: ")+vec.at(1)+_T("     "));
		wordSelection.TypeText(_T("单位: ")+vec.at(2)+_T("   "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("身高: ")+vec.at(3)+_T("CM    "));
		wordSelection.TypeText(_T("年龄: ")+vec.at(4)+_T("岁    "));
		wordSelection.TypeText(_T("体重: ")+vec.at(5)+_T("KG   "));
		wordSelection.TypeText(_T("职业: ")+vec.at(6)+_T("   "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("监测日期: ")+vec.at(7)+_T(" "));
		wordSelection.TypeText(_T("开始时间: ")+vec.at(8)+_T(" "));
		wordSelection.TypeText(_T("结束时间: ")+vec.at(9)+_T(" "));
		wordSelection.TypeText(_T("监测时长: ")+vec.at(10)+_T("Min"));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("总心搏数: ")+vec.at(11)+_T("   "));
		wordSelection.TypeText(_T("异常心搏数: ")+vec.at(12)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("_______________________________________________________________________________"));//划线
		wordSelection.TypeParagraph();
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("  最快: ")+vec.at(13)+_T("  "));
		wordSelection.TypeText(_T("时间: ")+vec.at(14)+_T("  "));
		wordSelection.TypeText(_T("最慢: ")+vec.at(15)+_T("  "));
		wordSelection.TypeText(_T("时间: ")+vec.at(16)+_T("  "));
		wordSelection.TypeText(_T("平均: ")+vec.at(17)+_T("  "));

		CTables0 wordTables = docx.get_Tables();
		CRange wordRange = wordSelection.get_Range();
		COleVariant covTrue((short)TRUE), covFalse((short)FALSE), covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
		CTable0 wordTable = wordTables.Add(wordRange, 3, 2, covTrue, covFalse); // 添加表格
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

		wordSelection.TypeText(_T("             室性早搏"));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("总数: ")+vec.at(18));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("成对: ")+vec.at(19)+_T("      "));
		wordSelection.TypeText(_T("室速: ")+vec.at(20)+_T("     "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("二联: ")+vec.at(21)+_T("      "));
		wordSelection.TypeText(_T("三联: ")+vec.at(22)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("每分钟最多: ")+vec.at(23));
		wordSelection.TypeText(_T("时间: ")+vec.at(24)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("每小时最多: ")+vec.at(25));
		wordSelection.TypeText(_T("时间: ")+vec.at(26)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("长时间: ")+vec.at(27));

		cell = wordTable.Cell(2,2);
		cell.Select();
		wordSelection.TypeText(_T("             房性早搏"));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("总数: ")+vec.at(28));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("成对: ")+vec.at(29)+_T("  "));
		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("房速: ")+vec.at(30)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("最大房速: ")+vec.at(31)+_T("    "));
		wordSelection.TypeText(_T("时间: ")+vec.at(32)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.TypeText(_T("最快房速心率: ")+vec.at(33));
		wordSelection.TypeText(_T("时间: ")+vec.at(34)+_T("  "));

		wordSelection.TypeParagraph();
		wordSelection.EndOf(COleVariant((short)5), COleVariant((short)0));	// wdParagraph=4,wdMove=0

		paragraphs = docx.get_Paragraphs();
		lastPara = paragraphs.get_Last();
		lastPara.put_Alignment(1);
		wordSelection.TypeText(_T("印象与结论"));
		wordSelection.EndOf(COleVariant((short)4), COleVariant((short)0));	// wdParagraph=4,wdMove=0

		wordSelection.TypeParagraph();
		paragraphs = docx.get_Paragraphs();
		lastPara = paragraphs.get_Last();
		lastPara.put_Alignment(0);
		wordTables = docx.get_Tables();
		wordRange = wordSelection.get_Range();
		wordTable = wordTables.Add(wordRange, 1, 1, covTrue, covFalse); // 添加表格

		rows = wordTable.get_Rows();
		row = rows.Item(1);
		row.SetHeight(250,1);
		wordSelection.EndOf(COleVariant((short)5), COleVariant((short)0));	// wdParagraph=4,wdMove=0
		wordSelection.TypeText(_T("                                              医生：")+vec.at(35));
		wordSelection.TypeText(_T("日期: ")+vec.at(36));

		//***************保存报告**********************
		CString strSavePath;
		CFileDialog dlg(FALSE);
		if(dlg.DoModal()==IDOK)
		{
			strSavePath = dlg.GetPathName();
/*			strSavePath += dlg.GetFileName();*/
		}

		//CString strSavePath = _T("D:\\健康云项目\\分析报告2.docx");
		docx.SaveAs(COleVariant(strSavePath),covOptional,covOptional,covOptional,covOptional,
			covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional,covOptional);
		// 退出word应用
		docx.Close(covFalse, covOptional, covOptional);
		wordApp.Quit(covOptional, covOptional, covOptional);
		wordApp.ReleaseDispatch();

		AfxMessageBox(_T("下载完成！"));
	}
}

//****************************生成Word预览*************************************
void CRightLatestinfoView::PreView(CDC* pDC,vector<CString> vec)
{
	int nrMargin = 10;                                                 //上边距
	int ntMargin = 30;                                                 //右边距
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	int nGap = (nA4Width-20)/4;                                       // 栏间距
	pDC->TextOut(nrMargin,ntMargin+2*tm.tmHeight,_T("姓名："));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+2*tm.tmHeight,vec.at(0));
	pDC->TextOut(nrMargin+nGap,ntMargin+2*tm.tmHeight,_T("性别："));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+2*tm.tmHeight,vec.at(1));
	pDC->TextOut(nrMargin+2*nGap,ntMargin+2*tm.tmHeight,_T("单位："));
	pDC->TextOut(nrMargin+2*nGap+5*tm.tmAveCharWidth,ntMargin+2*tm.tmHeight,vec.at(2));

	pDC->TextOut(nrMargin,ntMargin+3.5*tm.tmHeight,_T("身高："));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(3));
	pDC->TextOut(nrMargin+nGap,ntMargin+3.5*tm.tmHeight,_T("年龄："));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(4));
	pDC->TextOut(nrMargin+2*nGap,ntMargin+3.5*tm.tmHeight,_T("体重："));
	pDC->TextOut(nrMargin+2*nGap+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(6));
	pDC->TextOut(nrMargin+3*nGap,ntMargin+3.5*tm.tmHeight,_T("职业："));
	pDC->TextOut(nrMargin+3*nGap+5*tm.tmAveCharWidth,ntMargin+3.5*tm.tmHeight,vec.at(5));

	pDC->TextOut(nrMargin,ntMargin+5*tm.tmHeight,_T("监测日期："));
	pDC->TextOut(nrMargin+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(7));
	pDC->TextOut(nrMargin+nGap,ntMargin+5*tm.tmHeight,_T("开始时间："));
	pDC->TextOut(nrMargin+nGap+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(8));
	pDC->TextOut(nrMargin+2*nGap,ntMargin+5*tm.tmHeight,_T("结束时间："));
	pDC->TextOut(nrMargin+2*nGap+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(9));
	pDC->TextOut(nrMargin+3*nGap,ntMargin+5*tm.tmHeight,_T("监测时长："));
	pDC->TextOut(nrMargin+3*nGap+8*tm.tmAveCharWidth,ntMargin+5*tm.tmHeight,vec.at(10));

	pDC->TextOut(nrMargin,ntMargin+6.5*tm.tmHeight,_T("总心搏数："));
	pDC->TextOut(nrMargin+8*tm.tmAveCharWidth,ntMargin+6.5*tm.tmHeight,vec.at(11));
	pDC->TextOut(nrMargin+nGap,ntMargin+6.5*tm.tmHeight,_T("异常心搏数："));
	pDC->TextOut(nrMargin+nGap+10*tm.tmAveCharWidth,ntMargin+6.5*tm.tmHeight,vec.at(12));

	pDC->MoveTo(nrMargin,ntMargin+8*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin,ntMargin+8*tm.tmHeight);

	pDC->TextOut(nrMargin+10,ntMargin+8.5*tm.tmHeight,_T("最快："));
	pDC->TextOut(nrMargin+10+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(13));
	pDC->TextOut(nrMargin+10+nGap,ntMargin+8.5*tm.tmHeight,_T("时间："));
	pDC->TextOut(nrMargin+10+nGap+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(14));

	pDC->TextOut(nrMargin+10+2*nGap,ntMargin+8.5*tm.tmHeight,_T("最慢："));
	pDC->TextOut(nrMargin+10+2*nGap+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(15));
	pDC->TextOut(nrMargin+10+3*nGap,ntMargin+8.5*tm.tmHeight,_T("平均："));
	pDC->TextOut(nrMargin+10+3*nGap+5*tm.tmAveCharWidth,ntMargin+8.5*tm.tmHeight,vec.at(17));

	pDC->MoveTo(nrMargin,ntMargin+10*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin,ntMargin+10*tm.tmHeight);
	pDC->MoveTo(nA4Width/2,ntMargin+10*tm.tmHeight);
	pDC->LineTo(nA4Width/2,ntMargin+22*tm.tmHeight);
	pDC->MoveTo(nrMargin,ntMargin+22*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin,ntMargin+22*tm.tmHeight);

	pDC->TextOut((nA4Width/2-nrMargin)/2-3*tm.tmAveCharWidth,ntMargin+11*tm.tmHeight,_T("室性早搏"));
	pDC->TextOut(nA4Width/2+(nA4Width-2*nrMargin)/4-3*tm.tmAveCharWidth,ntMargin+11*tm.tmHeight,_T("房性早搏"));

	pDC->TextOut(nrMargin,ntMargin+13*tm.tmHeight,_T("总数："));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+13*tm.tmHeight,vec.at(18));
	pDC->TextOut(nrMargin,ntMargin+14.5*tm.tmHeight,_T("成对："));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+14.5*tm.tmHeight,vec.at(19));
	pDC->TextOut(nrMargin,ntMargin+16*tm.tmHeight,_T("二联："));
	pDC->TextOut(nrMargin+5*tm.tmAveCharWidth,ntMargin+16*tm.tmHeight,vec.at(21));
	pDC->TextOut(nrMargin,ntMargin+17.5*tm.tmHeight,_T("每分钟最多："));
	pDC->TextOut(nrMargin+11*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(23));
	pDC->TextOut(nrMargin,ntMargin+19*tm.tmHeight,_T("每小时最多："));
	pDC->TextOut(nrMargin+11*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(25));
	pDC->TextOut(nrMargin,ntMargin+20.5*tm.tmHeight,_T("长时期："));
	pDC->TextOut(nrMargin+8*tm.tmAveCharWidth,ntMargin+20.5*tm.tmHeight,vec.at(27));

	pDC->TextOut(nrMargin+nGap+5,ntMargin+14.5*tm.tmHeight,_T("室速："));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+14.5*tm.tmHeight,vec.at(20));
	pDC->TextOut(nrMargin+nGap+5,ntMargin+16*tm.tmHeight,_T("三联："));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+16*tm.tmHeight,vec.at(22));

	pDC->TextOut(nrMargin+nGap+5,ntMargin+17.5*tm.tmHeight,_T("时间："));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(24));
	pDC->TextOut(nrMargin+nGap+5,ntMargin+19*tm.tmHeight,_T("时间："));
	pDC->TextOut(nrMargin+nGap+5*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(26));

	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+13*tm.tmHeight,_T("总数："));
	pDC->TextOut(nrMargin+2*nGap+4+5*tm.tmAveCharWidth,ntMargin+13*tm.tmHeight,vec.at(28));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+14.5*tm.tmHeight,_T("成对:"));
	pDC->TextOut(nrMargin+2*nGap+4+5*tm.tmAveCharWidth,ntMargin+14.5*tm.tmHeight,vec.at(29));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+16*tm.tmHeight,_T("房速："));
	pDC->TextOut(nrMargin+2*nGap+4+5*tm.tmAveCharWidth,ntMargin+16*tm.tmHeight,vec.at(30));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+17.5*tm.tmHeight,_T("最大房速："));
	pDC->TextOut(nrMargin+2*nGap+4+8*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(31));
	pDC->TextOut(nrMargin+2*nGap+4,ntMargin+19*tm.tmHeight,_T("最快房速心率："));
	pDC->TextOut(nrMargin+2*nGap+4+11*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(33));

	pDC->TextOut(nrMargin+3*nGap+15,ntMargin+17.5*tm.tmHeight,_T("时间："));
	pDC->TextOut(nrMargin+3*nGap+15+5*tm.tmAveCharWidth,ntMargin+17.5*tm.tmHeight,vec.at(32));
	pDC->TextOut(nrMargin+3*nGap+15,ntMargin+19*tm.tmHeight,_T("时间："));
	pDC->TextOut(nrMargin+3*nGap+15+5*tm.tmAveCharWidth,ntMargin+19*tm.tmHeight,vec.at(34));

	pDC->TextOut(nA4Width/2-4*tm.tmAveCharWidth,ntMargin+24*tm.tmHeight,_T("印象与结论"));

	pDC->MoveTo(nrMargin+5,ntMargin+25.5*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin-5,ntMargin+25.5*tm.tmHeight);
	pDC->LineTo(nA4Width-nrMargin-5,ntMargin+42.5*tm.tmHeight);
	pDC->LineTo(nrMargin+5,ntMargin+42.5*tm.tmHeight);
	pDC->LineTo(nrMargin+5,ntMargin+25.5*tm.tmHeight);

	pDC->TextOut(nA4Width-nrMargin-16*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,_T("日期："));
	pDC->TextOut(nA4Width-nrMargin-16*tm.tmAveCharWidth+5*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,vec.at(36));
	pDC->TextOut(nA4Width-nrMargin-30*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,_T("医生："));
	pDC->TextOut(nA4Width-nrMargin-30*tm.tmAveCharWidth+5*tm.tmAveCharWidth,ntMargin+41*tm.tmHeight,vec.at(35));
}

void CRightLatestinfoView::OnBnClickedReturn()
{
	// TODO: 在此添加控件通知处理程序代码
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
