// RightDoclistView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "User.h"
#include "RightDoclistView.h"
#include "afxdialogex.h"
#include "SocketClientCtrl.h"
#include <vector>
using std::vector;


// CRightDoclistView �Ի���

IMPLEMENT_DYNAMIC(CRightDoclistView, CDialog)

CRightDoclistView::CRightDoclistView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightDoclistView::IDD, pParent)
	, m_doctorname(_T(""))
	, m_gender(_T(""))
	, m_cellnumber(_T(""))
	, m_title(_T(""))
	, m_hospital(_T(""))
	, m_duty(_T(""))
	, m_adminoffice(_T(""))
	, m_major(_T(""))
	, m_school(_T(""))
	, m_consulttime(_T(""))
	, m_eduback(_T(""))
	, m_replytime(_T(""))
	, m_row(0)
{
	theApp.m_prightdoclistview=this;
}

CRightDoclistView::~CRightDoclistView()
{
}

void CRightDoclistView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DOCLIST, m_doclist);
	DDX_Control(pDX, IDC_DOCPERINFO, m_docperinfo);
	DDX_Text(pDX, IDC_DOCNAME, m_doctorname);
	DDX_Text(pDX, IDC_GENDER, m_gender);
	DDX_Text(pDX, IDC_DOCCELL, m_cellnumber);
	DDX_Text(pDX, IDC_TITLE, m_title);
	DDX_Text(pDX, IDC_HOSPITAL, m_hospital);
	DDX_Text(pDX, IDC_DUTY, m_duty);
	DDX_Text(pDX, IDC_OFFICE, m_adminoffice);
	DDX_Text(pDX, IDC_MAJOR, m_major);
	DDX_Text(pDX, IDC_GRASCH, m_school);
	DDX_Text(pDX, IDC_CONTIME, m_consulttime);
	DDX_Text(pDX, IDC_EDUBAC, m_eduback);
	DDX_Text(pDX, IDC_REPTIME, m_replytime);
	DDX_Control(pDX, IDC_QUETYPE, m_quetype);
	DDX_Control(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_GROUP_DOC, m_doc);
}


BEGIN_MESSAGE_MAP(CRightDoclistView, CDialog)
//	ON_CBN_SELENDOK(IDC_QUETYPE, &CRightDoclistView::OnCbnSelendokQuetype)
	ON_BN_CLICKED(IDC_INVITE, &CRightDoclistView::OnBnClickedInvite)
	ON_BN_CLICKED(IDC_BTN_QUE, &CRightDoclistView::OnBnClickedBtnQue)
	ON_CBN_SELENDOK(IDC_QUETYPE, &CRightDoclistView::OnCbnSelendokQuetype)
//	ON_CBN_EDITCHANGE(IDC_QUETYPE, &CRightDoclistView::OnCbnEditchangeQuetype)
//ON_CBN_SELCHANGE(IDC_QUETYPE, &CRightDoclistView::OnCbnSelchangeQuetype)
ON_NOTIFY(NM_CLICK, IDC_DOCLIST, &CRightDoclistView::OnNMClickDoclist)
ON_BN_CLICKED(IDC_SDMGTODOC, &CRightDoclistView::OnBnClickedSdmgtodoc)
ON_WM_PAINT()
ON_WM_CTLCOLOR()
ON_MESSAGE(WM_DOCTORINFOLIST, &CRightDoclistView::OnDoctorinfolist)
ON_MESSAGE(WM_SUDOCTORCHOOSE, &CRightDoclistView::OnSudoctorchoose)
END_MESSAGE_MAP()


// CRightDoclistView ��Ϣ�������


BOOL CRightDoclistView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//�˳���Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CRightDoclistView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_doclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_doclist.InsertColumn(0,_T("���"),LVCFMT_CENTER,50);
	m_doclist.InsertColumn(1,_T("����"),LVCFMT_CENTER,100);
	m_doclist.InsertColumn(2,_T("�ֻ���"),LVCFMT_CENTER,110);
	m_doclist.InsertColumn(3,_T("����ҽԺ"),LVCFMT_CENTER,120);
	m_doclist.InsertColumn(4,_T("����"),LVCFMT_CENTER,135);
	m_doclist.InsertColumn(5,_T("����"),LVCFMT_CENTER,60);
// 	m_doclist.InsertItem(0,_T("1"));
// 	m_doclist.InsertItem(1,_T("2"));
// 	m_doclist.SetItemText(1,1,_T("aaa"));
// 	m_doclist.SetItemText(1,2,_T("bbb"));

	m_docperinfo.SetBorderColor(RGB(136,203,103));
	m_docperinfo.SetFontBold(TRUE);
	m_docperinfo.SetBackgroundColor(RGB(66,210,87));
	m_docperinfo.SetFontSize(13);
	
	m_doc.SetBorderColor(RGB(136,203,103));
	m_doc.SetFontBold(TRUE);
	m_doc.SetBackgroundColor(RGB(66,210,87));
	m_doc.SetFontSize(13);

	m_quetype.SetCurSel(4);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}





void CRightDoclistView::OnBnClickedInvite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox(_T("��ֻ������һλר�ң����뱾ר�ҽ��Զ�ȡ����֮ǰ�����ר��"),_T("��������"),MB_OKCANCEL)==IDCANCEL)
	{
		return;
	}
	else
	{
		theApp.socketclient.UserDoctorChoose(seldoc);

		//*******************�����׽���********************

		//��UserDoctorChoose��, doctorcell

		//*******************�����׽���********************


		/*CString docnamestr=_T("����ɹ��������ڵ�ר����");
		docnamestr=docnamestr+m_v_docbaseinfo.at(m_row).doctorname;
		GetDlgItem(IDC_INVIRESUL)->SetWindowText(docnamestr);
		GetDlgItem(IDC_INVIRESUL)->ShowWindow(SW_SHOW);*/

		
		//*******************����ҽ�����********************

		//��UserDoctorChoose��, exceptiontext

		//*******************����ҽ�����********************

	}
	
}


void CRightDoclistView::OnBnClickedBtnQue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index=m_quetype.GetCurSel();
	if (index==-1)
	{
		AfxMessageBox(_T("��ѡ���������"));
	}
	else
	{
		CString quetype,quetext;
		m_quetype.GetLBText(index,quetype);
		m_quetext.GetWindowText(quetext);

		//*********************�����׽���(ҽ����Ϣ��ѯ)**************************

		//��UserDoctorRead��, CString quetype, CString  quetext


		//*********************�����׽���(ҽ����Ϣ��ѯ)**************************
		
		theApp.socketclient.UserDoctorInfo(index, quetext);	

		



		
		//********************************************��β��ù�
// 		m_doclist.InsertItem(0,_T("1"));
// 		m_doclist.InsertItem(1,_T("2"));
// 		Doctor_BaseInfo docbaseinfo;
// 		m_v_docbaseinfo.push_back(docbaseinfo);
		//***********************************************


		//*****************����ҽ����Ϣ**********************************

		//��DoctorBaseInfoRead��,Vector<Doctor_BaseInfo> doctorbaseinfo


		//*****************����ҽ����Ϣ**********************************
	}
	
}


void CRightDoclistView::OnCbnSelendokQuetype()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index=m_quetype.GetCurSel();
	CString quetype;
	m_quetype.GetLBText(index,quetype);
	if (quetype==_T("ȫ��"))
	{
		m_quetext.SetReadOnly(TRUE);
	}
	else
	{
		m_quetext.SetReadOnly(FALSE);
	}
}





void CRightDoclistView::OnNMClickDoclist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem!=-1)
	{
		m_row=pNMListView->iItem;
		vector<CString> doc_sel;
		theApp.SplitString(vec_doclist.at(m_row+1),_T(","),TRUE,doc_sel);

		m_doctorname=doc_sel.at(0);
		m_gender=doc_sel.at(1);
		m_cellnumber=/*doc_sel.at(3)*/_T("******");
		m_title=doc_sel.at(7);
		m_hospital=doc_sel.at(6);
		m_duty=doc_sel.at(8);
		m_adminoffice=doc_sel.at(9);
		m_major=doc_sel.at(10);
		m_school=doc_sel.at(4);
		m_consulttime=doc_sel.at(11);
		m_eduback=doc_sel.at(5);
		m_replytime=doc_sel.at(12);
		seldoc=doc_sel.at(3);
		UpdateData(FALSE);
		//*pResult = 0;
	}
	pResult = 0;
}


void CRightDoclistView::OnBnClickedSdmgtodoc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.m_pleftpane->ShowView(&theApp.m_pleftpane->m_lefthealexpertview,&theApp.m_pleftpane->m_lefthealplatview);

	theApp.m_prightpane->ShowView(theApp.m_prightpreview,&theApp.m_prightpane->m_rightmessagereadview);
	theApp.m_prightpreview=&theApp.m_prightpane->m_rightmessagereadview;




}


void CRightDoclistView::OnPaint()
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


HBRUSH CRightDoclistView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID()==IDC_STATIC) 
	{ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}


	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


afx_msg LRESULT CRightDoclistView::OnDoctorinfolist(WPARAM wParam, LPARAM lParam)
{
		m_doclist.DeleteAllItems();
		vector<CString> vec;
		theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
		vec_doclist = vec;
		int num=vec.size();
		if(vec.at(0)==_T("4")&&vec.at(1)!=_T("-1"))
		{
			if (num!=1)
			{
				CString sequ;
				for (int i=1; i<num;i++)
				{
					sequ.Format(_T("%d"),i);
					m_doclist.InsertItem(i-1,sequ);
					vector<CString> docinfo;
					theApp.SplitString(vec.at(i),_T(","),TRUE,docinfo);
					// 			m_doclist.SetItemText(i-1,1,docinfo.at(0));
					// 			m_doclist.SetItemText(i-1,2,docinfo.at(3));
					// 			m_doclist.SetItemText(i-1,3,docinfo.at(6));
					// 			m_doclist.SetItemText(i-1,4,docinfo.at(9));
					// 			CString left;
					// 			left.Format(_T("%d"),_ttoi(docinfo.at(14))- _ttoi(docinfo.at(13)));
					// 			m_doclist.SetItemText(i-1,5,left);
					m_doclist.SetItemText(i-1,1,docinfo.at(0));
					m_doclist.SetItemText(i-1,2,/*docinfo.at(3)*/_T("******"));
					m_doclist.SetItemText(i-1,3,docinfo.at(6));
					m_doclist.SetItemText(i-1,4,docinfo.at(9));
					m_doclist.SetItemText(i-1,5,docinfo.at(13));
				}
			}
			else
			{
				AfxMessageBox(_T("û�в��ҵ�����"));
			}
		}
		else
		{
			AfxMessageBox(_T("û�в��ҵ�����"));
		}
		

	//m_doclist.SetItemText(1,1,);
	return 0;
}


afx_msg LRESULT CRightDoclistView::OnSudoctorchoose(WPARAM wParam, LPARAM lParam)
{
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_inviexcepinfo);
	AfxMessageBox(vec_inviexcepinfo.at(1));
	return 0;
}
