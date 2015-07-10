// RightWelcomeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightWelcomeView.h"
#include "afxdialogex.h"


// CRightWelcomeView �Ի���

IMPLEMENT_DYNAMIC(CRightWelcomeView, CDialog)

CRightWelcomeView::CRightWelcomeView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightWelcomeView::IDD, pParent)
{
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 150;
	lf.lfWeight = FW_BOLD;
	::lstrcpy(lf.lfFaceName, _T("����"));
	m_info_font.CreatePointFontIndirect(&lf);
	m_infotext_font.CreatePointFont(125,_T("����"));
	theApp.m_rightwelcomeview=this;
}

CRightWelcomeView::~CRightWelcomeView()
{
}

void CRightWelcomeView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_MESS, m_messread);
	DDX_Control(pDX, IDC_BTN_REP, m_repread);
	DDX_Control(pDX, IDC_BTN_UPLOAD, m_upload);
	DDX_Control(pDX, IDC_BTN_PLATINFO, m_platinfo);
}


BEGIN_MESSAGE_MAP(CRightWelcomeView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
//	ON_WM_MOVE()
ON_BN_CLICKED(IDC_BTN_MESS, &CRightWelcomeView::OnBnClickedBtnMess)
ON_BN_CLICKED(IDC_BTN_REP, &CRightWelcomeView::OnBnClickedBtnRep)
ON_WM_SETCURSOR()
ON_BN_CLICKED(IDC_BTN_UPLOAD, &CRightWelcomeView::OnBnClickedBtnUpload)
ON_BN_CLICKED(IDC_BTN_PLATUSE, &CRightWelcomeView::OnBnClickedBtnInfo)
//ON_COMMAND(IDC_BTN_PLATUSE, &CRightWelcomeView::OnBtnPlatuse)
ON_BN_CLICKED(IDC_BTN_PLATINFO, &CRightWelcomeView::OnBnClickedBtnPlatinfo)
//ON_BN_CLICKED(IDC_BUTTON1, &CRightWelcomeView::OnBnClickedButton1)
//ON_BN_CLICKED(IDC_BUTTON1, &CRightWelcomeView::OnBnClickedButton1)
ON_MESSAGE(WM_SUWEL, &CRightWelcomeView::OnSuwel)
END_MESSAGE_MAP()


// CRightWelcomeView ��Ϣ�������


void CRightWelcomeView::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()

	//2222222222222
// 	CPaintDC   dc(this);   
// 	CRect   rect/*(0,0,633,548)*/;   
// 	GetParent()->GetClientRect(&rect);   
// 	CDC   dcMem;   
// 	dcMem.CreateCompatibleDC(&dc);   
// 	CBitmap   bmpBackground;   
// 	bmpBackground.LoadBitmap(IDB_WELCOME);    
// 	BITMAP   bitmap;   
// 	bmpBackground.GetBitmap(&bitmap);   
// 	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
// 	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
// 		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);


	//3333333333333
	CPaintDC dc(this);
	CPen pen(PS_SOLID,1,RGB(205,231,208));
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BKIN);    //���IDB_BITMAP1Ҫ�Լ����
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	CPen* pOldpen=dc.SelectObject(&pen);
	CRect rec;
	GetParent()->GetClientRect(rec);
	dc.FillRect(CRect(0,0,850,800),&brush);   // ��Щ�������Ե���ͼƬ���λ�úʹ�С
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldpen);

}


BOOL CRightWelcomeView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
//111111
// 	CBitmap bmp;
// 	bmp.LoadBitmap(IDB_WELCOME);
// 	m_brushbk.CreatePatternBrush(&bmp);
// 	bmp.DeleteObject();
	m_messread.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_messread.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_messread.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(37,37,250));
	m_messread.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(66,210,87));//��ť���º󱳾���ɫ
	
	m_repread.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_repread.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_repread.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(37,37,250));
	
	m_upload.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_upload.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_upload.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(37,37,250));

	m_platinfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(66,210,87));//����ڰ�ť�ⱳ����ɫ
	m_platinfo.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(152,216,105));//����ڰ�ť�ڱ�����ɫ
	m_platinfo.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(37,37,250));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CRightWelcomeView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
//111111
//	if (pWnd == this)
// 
// 	{
// 
// 		return m_brushbk;
// 
// 	}
	if (pWnd->GetDlgCtrlID()==IDC_INFO) 
	{ 
		pDC->SelectObject(&m_info_font); 
		
	} 
	if ((pWnd->GetDlgCtrlID()==IDC_UPLOADDATA)||(pWnd->GetDlgCtrlID()==IDC_UPLOADDATADATE)
		||(pWnd->GetDlgCtrlID()==IDC_AUTHO)||(pWnd->GetDlgCtrlID()==IDC_AUTHODATE)
		||(pWnd->GetDlgCtrlID()==IDC_INFOTEXT)||(pWnd->GetDlgCtrlID()==IDC_REPTEXT))
	{ 
		pDC->SelectObject(&m_infotext_font); 

	} 


	if ((pWnd->GetDlgCtrlID()==IDC_INFO)||(pWnd->GetDlgCtrlID()==IDC_INFOTEXT)
		||(pWnd->GetDlgCtrlID()==IDC_BTN_MESS)||(pWnd->GetDlgCtrlID()==IDC_BTN_REP)
		||(pWnd->GetDlgCtrlID()==IDC_UPLOADDATA)||(pWnd->GetDlgCtrlID()==IDC_UPLOADDATADATE)
		||(pWnd->GetDlgCtrlID()==IDC_AUTHO)||(pWnd->GetDlgCtrlID()==IDC_AUTHODATE)
		||(pWnd->GetDlgCtrlID()==IDC_REPTEXT) )
	{ 
		
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	if ((pWnd->GetDlgCtrlID()==IDC_BTN_MESS)||(pWnd->GetDlgCtrlID()==IDC_BTN_REP)) 
	{ 

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}



	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


BOOL CRightWelcomeView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	


// 		CPaintDC   dc(this);   
// 		CRect   rect;   
// 		GetClientRect(&rect);   
// 		CDC   dcMem;   
// 		dcMem.CreateCompatibleDC(&dc);   
// 		CBitmap   bmpBackground;   
// 		bmpBackground.LoadBitmap(IDB_WELCOME);    
// 		BITMAP   bitmap;   
// 		bmpBackground.GetBitmap(&bitmap);   
// 		CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
// 		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,  bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
// 		return TRUE;



	return CDialog::OnEraseBkgnd(pDC);
}




BOOL CRightWelcomeView::PreTranslateMessage(MSG* pMsg)
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


void CRightWelcomeView::OnBnClickedBtnMess()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightmessagereadview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightmessagereadview;

	//*****************��ѯδ����Ϣ******************************
	CTime st,et;
	CTimeSpan TSp=60480000;
	theApp.m_prightmessagereadview->m_end.GetTime(et);
	st = et-TSp;
	CString str_start,str_end;
	str_end=et.Format(_T("%Y-%m-%d"));
	str_start=st.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserMessRead(str_start,str_end);
	
}


void CRightWelcomeView::OnBnClickedBtnRep()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_righthealrepview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_righthealrepview;

	//***************************��ȡδ������********************************
	CTime st,et;
	CTimeSpan TSp=60480000;
	theApp.m_prightmessagereadview->m_end.GetTime(et);
	st = et-TSp;
	CString str_start,str_end;
	str_end=et.Format(_T("%Y-%m-%d"));
	str_start=st.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserRepRead(_T("��������"),str_start,str_end);
}


BOOL CRightWelcomeView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if   (pWnd   ==   GetDlgItem(IDC_BTN_MESS)||pWnd   ==   GetDlgItem(IDC_BTN_REP) 
		||pWnd   ==   GetDlgItem(IDC_BTN_UPLOAD)||pWnd   ==   GetDlgItem(IDC_BTN_PLATINFO)) 
	{   
		SetCursor(LoadCursor(NULL,   IDC_HAND));   
		return   TRUE;   
	}   
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightWelcomeView::OnBnClickedBtnUpload()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightinputview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightinputview;
}


void CRightWelcomeView::OnBnClickedBtnInfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightplatuseview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightplatuseview;
}


//void CRightWelcomeView::OnBtnPlatuse()
//{
//	// TODO: �ڴ���������������
//	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightplatuseview);
//	theApp.m_prightpreview=&theApp.m_prightpane->m_rightplatuseview;
//}


void CRightWelcomeView::OnBnClickedBtnPlatinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightplatuseview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightplatuseview;
}


//void CRightWelcomeView::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	/*theApp.m_prightregview->GetDlgItem(IDC_REGRES)->*/
//	::PostMessage(theApp.m_prightregview->m_hWnd,WM_REG,0,0);
//}


//void CRightWelcomeView::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	GetDlgItem(IDC_INFOTEXT)->SetWindowText(_T(""));
//	GetDlgItem(IDC_REPTEXT)->SetWindowText(_T(""));
//}


afx_msg LRESULT CRightWelcomeView::OnSuwel(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_wel;
	vector<CString> welinfo;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_wel);
	theApp.SplitString(vec_wel.at(1),_T(","),TRUE,welinfo);
	CString mess_unread;
	CString rep_unread;
	int mess_num=_ttoi(welinfo.at(0));
	int rep_num=_ttoi(welinfo.at(1));

	m_MessUnread = mess_num;
	m_RepUnread = rep_num;

	mess_unread.Format(_T("������%d����Ϣδ�����뾡���Ķ���"),mess_num);
	rep_unread.Format(_T("������%d�ⱨ��δ�����뾡���Ķ���"),rep_num);
	GetDlgItem(IDC_INFOTEXT)->SetWindowText(mess_unread);
	GetDlgItem(IDC_REPTEXT)->SetWindowText(rep_unread);
	GetDlgItem(IDC_UPLOADDATADATE)->SetWindowText(welinfo.at(3));
	GetDlgItem(IDC_AUTHODATE)->SetWindowText(welinfo.at(4));
	return 0;
}
