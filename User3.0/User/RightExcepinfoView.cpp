// RightExcepinfoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightExcepinfoView.h"
#include "afxdialogex.h"


// CRightExcepinfoView �Ի���

IMPLEMENT_DYNAMIC(CRightExcepinfoView, CDialog)

CRightExcepinfoView::CRightExcepinfoView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightExcepinfoView::IDD, pParent)
{
	theApp.m_prightexcepinfoview=this;
}

CRightExcepinfoView::~CRightExcepinfoView()
{
}

void CRightExcepinfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXCEPINFOLIST, m_excepinfolist);
	DDX_Control(pDX, IDC_EXCEPINFOSD, m_start);
	DDX_Control(pDX, IDC_EXCEPINFOED, m_end);
	DDX_Control(pDX, IDC_GROUP_EXCEP, m_excep);
}


BEGIN_MESSAGE_MAP(CRightExcepinfoView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_SUEXCEPREAD, &CRightExcepinfoView::OnSuexcepread)
	ON_BN_CLICKED(IDC_QUE, &CRightExcepinfoView::OnBnClickedQue)
	ON_NOTIFY(NM_CLICK, IDC_EXCEPINFOLIST, &CRightExcepinfoView::OnNMClickExcepinfolist)
	ON_BN_CLICKED(IDC_DOWN, &CRightExcepinfoView::OnBnClickedDown)
END_MESSAGE_MAP()


// CRightExcepinfoView ��Ϣ�������


BOOL CRightExcepinfoView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightExcepinfoView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_excepinfolist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_excepinfolist.InsertColumn(0,_T("���"),LVCFMT_CENTER,40);
	m_excepinfolist.InsertColumn(1,_T("�����쳣ʱ��"),LVCFMT_CENTER,120);
	m_excepinfolist.InsertColumn(2,_T("�쳣����"),LVCFMT_CENTER,100);
	m_excepinfolist.InsertColumn(3,_T("ҽ������"),LVCFMT_CENTER,100);
	m_excepinfolist.InsertColumn(4,_T("ǩ��ҽ��"),LVCFMT_CENTER,100);
	m_excepinfolist.InsertColumn(5,_T("��鱨��"),LVCFMT_CENTER,100);
	
	m_excep.SetBorderColor(RGB(136,203,103));
	m_excep.SetFontBold(TRUE);
	m_excep.SetBackgroundColor(RGB(66,210,87));
	m_excep.SetFontSize(13);

	//*********************���ÿ�ʼʱ��Ϊһ������ǰ******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_end.GetTime(et);
	st = et-SDayTime;
	m_start.SetTime(&st);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightExcepinfoView::OnPaint()
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


HBRUSH CRightExcepinfoView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


afx_msg LRESULT CRightExcepinfoView::OnSuexcepread(WPARAM wParam, LPARAM lParam)
{
	m_excepinfolist.DeleteAllItems();
	vector<CString> vec_excep;
	vector<CString> vec_excepinfo;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_excep);
	int num=vec_excep.size();
	CString sequ;
	if(vec_excep.at(0)==_T("21")&&vec_excep.at(1)!=_T("-1"))
	{
		for (int i=1; i<num;i++)
		{
			sequ.Format(_T("%d"),i);
			m_excepinfolist.InsertItem(i-1,sequ);
			theApp.SplitString(vec_excep.at(i),_T(","),TRUE,vec_excepinfo);
			m_excepinfolist.SetItemText(i-1,1,vec_excepinfo.at(0));
			m_excepinfolist.SetItemText(i-1,2,vec_excepinfo.at(1));
			m_excepinfolist.SetItemText(i-1,3,vec_excepinfo.at(2));
			m_excepinfolist.SetItemText(i-1,4,vec_excepinfo.at(3));
			m_excepinfolist.SetItemText(i-1,5,vec_excepinfo.at(4));
		}
	}
	else
	{
		AfxMessageBox(_T("���쳣����"));
	}
	return 0;
}


void CRightExcepinfoView::OnBnClickedQue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTime st,et;
	CString str_st,str_et;
	m_start.GetTime(st);
	m_end.GetTime(et);
	str_st=st.Format(_T("%Y-%m-%d"));
	str_et=et.Format(_T("%Y-%m-%d"));
	theApp.socketclient.UserExcepRead(str_st,str_et);
}


void CRightExcepinfoView::OnNMClickExcepinfolist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	sel_item=pNMListView->iItem;
	sel_sourcename=m_excepinfolist.GetItemText(sel_item,5);


	*pResult = 0;
}


void CRightExcepinfoView::OnBnClickedDown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (sel_sourcename.GetAt(0)!='[')
	{
		//ѡ������ļ�
		sel_sourcename = _T("�����.docx");
		CString strDestName;
		CFileDialog dlg(FALSE,_T(".docx"),sel_sourcename,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,L"Word�ĵ�(*.docx)|*.docx|", this);
		if (dlg.DoModal()==IDOK)
		{
			//��������ļ��ڱ��ػ��ϴ洢��·��������
			strDestName=dlg.GetPathName();

			//���ú��������ļ�
			if (GetFile(sel_sourcename,strDestName))
				AfxMessageBox(_T("���سɹ���"),MB_OK|MB_ICONINFORMATION);
			else
				AfxMessageBox(_T("����ʧ�ܣ�"),MB_OK|MB_ICONSTOP);
		}
		else
		{
			//AfxMessageBox(_T("��д���ļ�����"),MB_OK|MB_ICONSTOP);
		}
	}
	else
	{
		//ѡ�����Ŀ¼
		AfxMessageBox(_T("��������Ŀ¼!\n����ѡ!"),MB_OK|MB_ICONSTOP);
	}


}


BOOL CRightExcepinfoView::GetFile(CString strSourceName, CString strDestName)
{
	ftpctrl.FtpOpen();
	ftpctrl.FtpConnect(_T("112.124.48.81"),21,_T("ftp"),_T("ftp"));
	return ftpctrl.FtpDownloadFile(strSourceName,strDestName);
// 	CInternetSession* pSession;
// 	CFtpConnection* pConnection;
// 
// 	pConnection=NULL;
// 
// 	//����Internet�Ự
// 	pSession=new CInternetSession(	AfxGetAppName(),
// 		1,
// 		PRE_CONFIG_INTERNET_ACCESS);
// 
// 	try
// 	{
// 		//����FTP����
// 		pConnection=pSession->GetFtpConnection(	_T("112.124.48.81"),
// 			_T("ftp"),
// 			_T("ftp"));
// 		//112.124.48.81
// 	}
// 	catch (CInternetException* e)
// 	{
// 		//������
// 		e->Delete();
// 		pConnection=NULL;
// 		return FALSE;
// 	}
// 
// 	if (pConnection!=NULL)
// 	{
// 		//�����ļ�
// 		if (!pConnection->GetFile(strSourceName,strDestName))
// 		{
// 			//�����ļ�����
// 			pConnection->Close();
// 			delete pConnection;
// 			delete pSession;
// 			return FALSE;
// 		}
// 	}
// 
// 	//�������
// 	if (pConnection!=NULL)
// 	{
// 		pConnection->Close();
// 		delete pConnection;
// 	}
// 	delete pSession;
// 
// 
// 	return TRUE;
}
