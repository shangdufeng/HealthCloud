// RightHealrepView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightHealrepView.h"
#include "afxdialogex.h"


// CRightHealrepView �Ի���

IMPLEMENT_DYNAMIC(CRightHealrepView, CDialog)

CRightHealrepView::CRightHealrepView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightHealrepView::IDD, pParent)
{
	theApp.m_prighthealrepview=this;
}

CRightHealrepView::~CRightHealrepView()
{
}

void CRightHealrepView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HEALREPLIST, m_healreplist);
	//DDX_Control(pDX, IDC_PDFVIEWCTRL1, m_pdfView);
	DDX_Control(pDX, IDC_REPTYPE, m_reptype);
	DDX_Control(pDX, IDC_START, m_starttime);
	DDX_Control(pDX, IDC_END, m_endtime);
	DDX_Control(pDX, IDC_GROUP_REP, m_Rep);
}


BEGIN_MESSAGE_MAP(CRightHealrepView, CDialog)
	ON_BN_CLICKED(IDC_QUE, &CRightHealrepView::OnBnClickedQue)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BACK, &CRightHealrepView::OnBnClickedBack)
	ON_MESSAGE(WM_SUREPREAD, &CRightHealrepView::OnSurepread)
	ON_NOTIFY(NM_CLICK, IDC_HEALREPLIST, &CRightHealrepView::OnNMClickHealreplist)
	ON_BN_CLICKED(IDC_DOWN, &CRightHealrepView::OnBnClickedDown)
	ON_MESSAGE(WM_REPREADORNO,&CRightHealrepView::OnRepReadYesToNo)
END_MESSAGE_MAP()


// CRightHealrepView ��Ϣ�������


BOOL CRightHealrepView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightHealrepView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_healreplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_healreplist.InsertColumn(0,_T("���"),LVCFMT_CENTER,40);
	m_healreplist.InsertColumn(1,_T("��������"),LVCFMT_CENTER,90);
	m_healreplist.InsertColumn(2,_T("��������ʱ��"),LVCFMT_CENTER,140);
	m_healreplist.InsertColumn(3,_T("�Ƿ�����"),LVCFMT_CENTER,80);
	//m_healreplist.InsertItem(0,_T("1"));
	m_healreplist.InsertColumn(4,_T("�Ƿ�ǩ��"),LVCFMT_CENTER,80);
	m_healreplist.InsertColumn(5,_T("ǩ��ҽ��"),LVCFMT_CENTER,90);
	m_healreplist.InsertColumn(6,_T("�Ƿ��Ѷ�"),LVCFMT_CENTER,70);

// 	m_pdfView.OpenPDF(_T("��̬Ѫѹ��ⱨ��.pdf"),_T(""),_T(""));
// 	m_pdfView.SetMsgCallbackWnd((long)m_hWnd);
// 	m_pdfView.ShowHideBookmarks();
// 	m_pdfView.ZoomFitWidth();

	m_Rep.SetBorderColor(RGB(136,203,103));
	m_Rep.SetFontBold(TRUE);
	m_Rep.SetBackgroundColor(RGB(66,210,87));
	m_Rep.SetFontSize(13);

	//*********************���ÿ�ʼʱ��Ϊһ������ǰ******************
	CTime st,et;
	CTimeSpan SDayTime = 604800;
	m_endtime.GetTime(et);
	st = et-SDayTime;
	m_starttime.SetTime(&st);

	//**************����ComBoxĬ��ֵ*********************************
	m_reptype.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CRightHealrepView::OnBnClickedQue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������



	CTime starttime;
	m_starttime.GetTime(starttime);
	CTime endtime;
	m_endtime.GetTime(endtime);

	CString RepType,str_st,str_et;

	str_st=starttime.Format(_T("%Y-%m-%d"));
	str_et=endtime.Format(_T("%Y-%m-%d"));

	GetDlgItemText(IDC_REPTYPE,RepType);
	//m_RepType = RepType;

	theApp.socketclient.UserRepRead(RepType,str_st,str_et);

	//******************��ѯ����*********************

	//��UserRepRead��, CString reptype, CTime starttime, CTime endtime

	//******************��ѯ����*********************


	//******************���ձ���*********************

	//��SURepRead��,������Ϣ

	//******************���ձ���*********************
}


void CRightHealrepView::OnPaint()
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


HBRUSH CRightHealrepView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightHealrepView::OnBnClickedBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightwelcomeview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightwelcomeview;
}


afx_msg LRESULT CRightHealrepView::OnSurepread(WPARAM wParam, LPARAM lParam)
{
	m_healreplist.DeleteAllItems();
	vector<CString> vec;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
    if(vec.at(0)==_T("20")&&vec.at(1)!=_T("-1")&&vec.at(1)!=_T("����ر�ʱ�������������"))
	{
		vector<vector<CString>> vec1;
		theApp.ReOrder(vec,5,vec1);
		int num = vec1.size();
		for(int i=0;i<num;i++)
		{
			CString str;
			str.Format(_T("%d"),i+1);
			//theApp.SplitString(vec.at(i),_T(","),TRUE,vec1);
			m_healreplist.InsertItem(i,str);
// 			if(m_RepType==_T("")){m_healreplist.SetItemText(i,1,_T("��������"));}
// 			else{m_healreplist.SetItemText(i,1,m_RepType);}
			m_vecDocName.push_back(vec1.at(i).at(0));
			m_healreplist.SetItemText(i,2,vec1.at(i).at(1));
			if(vec1.at(i).at(2)==_T("1"))
			{
               m_healreplist.SetItemText(i,3,_T("��"));
			}
			else
			{
				m_healreplist.SetItemText(i,3,_T("��"));
			}
			if(vec1.at(i).at(3)==_T("1"))
			{
				m_healreplist.SetItemText(i,4,_T("��ǩ��"));
			}
			else
			{
				m_healreplist.SetItemText(i,4,_T("δǩ��"));
			}
			m_healreplist.SetItemText(i,5,vec1.at(i).at(4));
			if(vec1.at(i).at(5)==_T("1"))
			{
				m_healreplist.SetItemText(i,6,_T("�Ѷ�"));
			}
			else
			{
				m_healreplist.SetItemText(i,6,_T("δ��"));
			}
			m_healreplist.SetItemText(i,1,vec1.at(i).at(6));
		}
	}
	else
	{
		AfxMessageBox(_T("�޸ñ��棡"));
	}
	return 0;
}

afx_msg LRESULT CRightHealrepView::OnRepReadYesToNo(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

void CRightHealrepView::OnNMClickHealreplist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������]
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	sel_item=pNMListView->iItem;
	if(sel_item!=-1)
	{
    /*sel_sourcename=m_healreplist.GetItemText(sel_item,2);*/
	 sel_sourcename = m_vecDocName.at(sel_item);
	//**************************��ȡ�ļ���**********************************


	//**************************����δ������Ϊ�Ѷ�״̬**********************
	 CString str,time,reptype;
	 str = m_healreplist.GetItemText(sel_item,6);
     time = m_healreplist.GetItemText(sel_item,2);
	 reptype = m_healreplist.GetItemText(sel_item,1);
	    if(str==_T("δ��"))
	   {
		  theApp.socketclient.UserRepNoToYes(time,reptype);
		  m_healreplist.SetItemText(sel_item,6,_T("�Ѷ�"));
		  CString RepUnread;
		  RepUnread.Format(_T("������%d����Ϣδ�����뾡���Ķ���"),theApp.m_rightwelcomeview->m_RepUnread--);
		  theApp.m_rightwelcomeview->GetDlgItem(IDC_REPTEXT)->SetWindowText(RepUnread);
	   }
	}
	*pResult = 0;
}


void CRightHealrepView::OnBnClickedDown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (sel_sourcename.GetAt(0)!='['&&sel_sourcename!=_T(""))
	{
		//ѡ������ļ�
		CString strDestName;
		//sel_sourcename = _T("16088433510_2014-05-17-18.doc");
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
			//AfxMessageBox(_T("��д���ļ�����"),MB_OK/*|MB_ICONSTOP*/);
		}
	}
	else
	{
		//ѡ�����Ŀ¼
		AfxMessageBox(_T("��������Ŀ¼!\n����ѡ!"),MB_OK|MB_ICONSTOP);
	}
}

BOOL CRightHealrepView::GetFile(CString strSourceName, CString strDestName)
{
	ftpctrl.FtpOpen();
	ftpctrl.FtpConnect(_T("112.124.48.81"),21,_T("ftp"),_T("ftp"));
	return ftpctrl.FtpDownloadFile(strSourceName,strDestName);
}

