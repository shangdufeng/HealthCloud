// RightInputView.cpp : 实现文件
//

#include "stdafx.h"
#include "User.h"
#include "RightInputView.h"
#include "afxdialogex.h"
#include <afxinet.h>
#include "FTPFILE.H"


// CRightInputView 对话框

IMPLEMENT_DYNAMIC(CRightInputView, CDialog)

CRightInputView::CRightInputView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightInputView::IDD, pParent)
	, m_weight(_T(""))
	, m_height(_T(""))
	, m_diastolic(_T(""))
	, m_systolic(_T(""))
	, m_sugar(_T(""))
	, m_oxygen(_T(""))
	, m_rate(_T(""))
	, m_BMI(_T(""))
	, m_path(_T(""))
{
	theApp.m_prightinputview=this;
	m_oxygen3 = _T("");
}

CRightInputView::~CRightInputView()
{
}

void CRightInputView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WEIGHT, m_weight);
	DDX_Text(pDX, IDC_HEIGHT, m_height);
	DDX_Text(pDX, IDC_DIASTOLIC, m_diastolic);
	DDX_Text(pDX, IDC_SYSTOLIC, m_systolic);
	DDX_Text(pDX, IDC_SUGAR, m_sugar);
	DDX_Text(pDX, IDC_OXYGEN, m_oxygen);
	DDX_Text(pDX, IDC_OXYGEN2, m_rate);
	DDX_Text(pDX, IDC_BMI, m_BMI);
	DDX_Control(pDX, IDC_STARTTIME, m_inputinfo);
	DDX_Text(pDX, IDC_PATH, m_path);
	DDX_Text(pDX, IDC_OXYGEN3, m_oxygen3);
}


BEGIN_MESSAGE_MAP(CRightInputView, CDialog)
	ON_BN_CLICKED(IDC_OK, &CRightInputView::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_HEIGHT, &CRightInputView::OnEnKillfocusHeight)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BACK, &CRightInputView::OnBnClickedBack)
	ON_EN_KILLFOCUS(IDC_WEIGHT, &CRightInputView::OnEnKillfocusWeight)
//	ON_MESSAGE(WM_LATESTINPUT, &CRightInputView::OnLatestinput)
ON_MESSAGE(WM_HEALINFOINPUT, &CRightInputView::OnHealinfoinput)
ON_BN_CLICKED(IDC_BTN_UPLOADFILE, &CRightInputView::OnBnClickedBtnUploadfile)
END_MESSAGE_MAP()


// CRightInputView 消息处理程序


BOOL CRightInputView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CRightInputView::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	User_HealInfo userhealinfo;
	userhealinfo.height=m_height;
	userhealinfo.weight=m_weight;
	//float BMIvalue;
	//BMIvalue=_tstof(userhealinfo.weight)/(_tstof(userhealinfo.height)*_tstof(userhealinfo.height));
	//userhealinfo.BMIindex.Format(_T("%0.2f"), BMIvalue);
	//GetDlgItem(IDC_BMI)->SetWindowText(userhealinfo.BMIindex);

	userhealinfo.BMIindex=m_BMI;
	userhealinfo.diastolic=m_diastolic;
	userhealinfo.systolic=m_systolic;
	userhealinfo.sugar=m_sugar;
	userhealinfo.oxygen=m_oxygen;
	userhealinfo.oxygen3=m_oxygen3;
	userhealinfo.rate=m_rate;
	userhealinfo.date_time=CTime::GetCurrentTime();
// 	
 	theApp.socketclient.UserHealthInfoInput(userhealinfo);
	//*********************发送最近健康信息************************
	//‘UserHealInfoInput’, 	struct User_HealInfo
	//*********************发送最近健康信息************************

	//*********************发送结果************************
	//‘UserHealInfoInput’, exceptiontext
	//*********************发送结果************************


}


void CRightInputView::OnEnKillfocusHeight()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	float BMIvalue1;
	CString BMIValue;
	if (m_height!=_T(""))
	{
		BMIvalue1=_tstof(m_weight)/(_tstof(m_height)*_tstof(m_height)/10000);
		BMIValue.Format(_T("%0.2f"), BMIvalue1);
		GetDlgItem(IDC_BMI)->SetWindowText(BMIValue);
	}
	
}


void CRightInputView::OnPaint()
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


HBRUSH CRightInputView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightInputView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_inputinfo.SetBorderColor(RGB(136,203,103));
	m_inputinfo.SetFontBold(TRUE);
	m_inputinfo.SetBackgroundColor(RGB(66,210,87));
	m_inputinfo.SetFontSize(13);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightInputView::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}


void CRightInputView::OnEnKillfocusWeight()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	float BMIvalue1;
	CString BMIValue;
	if (m_height!=_T(""))
	{
		BMIvalue1=_tstof(m_weight)/(_tstof(m_height)*_tstof(m_height)/10000);
		BMIValue.Format(_T("%0.2f"), BMIvalue1);
		GetDlgItem(IDC_BMI)->SetWindowText(BMIValue);
	}
}


//afx_msg LRESULT CRightInputView::OnLatestinput(WPARAM wParam, LPARAM lParam)
//{
//
//	return 0;
//}


afx_msg LRESULT CRightInputView::OnHealinfoinput(WPARAM wParam, LPARAM lParam)
{
// 	CString exceptiontext=*(CString*)lParam;
// 	GetDlgItem(IDC_STATIC1)->SetWindowText(exceptiontext);
	//*******************监测是否添加成功****************************
	vector<CString> vec;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
	if(vec.at(0)==_T("7"))
	{
		AfxMessageBox(vec.at(1));
	}
	else
	{
		AfxMessageBox(_T("数据有误，请重新提交数据！"));
	}
	return 0;
}


void CRightInputView::OnBnClickedBtnUploadfile()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSourceName;
	CString strDestName;
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT|OFN_EXPLORER,L"所有类型(*.*)|*.*|", this);  
	if (dlg.DoModal()==IDOK)
	{
		//获得待上传的本地机文件路径和文件名
		strSourceName=dlg.GetPathName();
		strDestName=dlg.GetFileName();

		//调用函数上传文件
		if (PutFile(strSourceName,strDestName))
			{AfxMessageBox(_T("上传成功！"),MB_OK|MB_ICONINFORMATION);
				m_path=	strSourceName+_T("/")+strDestName;
				UpdateData(FALSE);
				theApp.socketclient.UserUploadFile(strDestName);
			}
		else
			AfxMessageBox(_T("上传失败！"),MB_OK|MB_ICONSTOP);
	}
	else
	{
		//文件选择有错误
		AfxMessageBox(_T("请选择文件！"),MB_OK|MB_ICONSTOP);
	}
}


BOOL CRightInputView::PutFile(CString strSourceName, CString strDestName)
{
	ftpctrl.FtpOpen();
	ftpctrl.FtpConnect(_T("112.124.48.81"),21,_T("ftp"),_T("ftp"));
	return ftpctrl.FtpUploadFile(strSourceName);

// 	CInternetSession* pSession;
// 	CFtpConnection* pConnection;
// 
//    	pConnection=NULL;
// 	UpdateData(TRUE);
// 	//创建Internet会话
// 	pSession=new CInternetSession(	AfxGetAppName(),
// 		1,
// 		PRE_CONFIG_INTERNET_ACCESS);
// 
// 	try
// 	{
// 		//建立FTP连接
// 		pConnection=pSession->GetFtpConnection(	_T("112.124.48.81"),
// 			_T("ftp"),
// 			_T("ftp"));
// 		//112.124.48.81
// 	}
// 	catch (CInternetException* e)
// 	{
// 		//错误处理
// 		e->Delete();
// 		pConnection=NULL;
// 		return FALSE;
// 	}
// 
// 	if (pConnection!=NULL)
// 	{
// 		//上传文件
// 		if (!pConnection->PutFile(strSourceName,strDestName))
// 		{
// 			//上传文件错误
// 			pConnection->Close();
// 			delete pConnection;
// 			delete pSession;
// 			return FALSE;
// 		}
// 	}
// 
// 	//清除对象
// 	if (pConnection!=NULL)
// 	{
// 		pConnection->Close();
// 		delete pConnection;
// 	}
// 
// 	delete pSession;
// 
// 	return TRUE;


}
