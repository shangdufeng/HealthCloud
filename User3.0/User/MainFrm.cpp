
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "User.h"

#include "MainFrm.h"
#include "LeftPaneView.h"
#include "RightPaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	//cs.hMenu = NULL;
	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_SYSMENU;
	cs.cx=900;
	cs.cy=700;
	int iWidth = GetSystemMetrics(SM_CXSCREEN); 
	int iHeight = GetSystemMetrics(SM_CYSCREEN); 
	cs.x=0.5*iWidth-480;
	cs.y=0.5*iHeight-400;

	cs.style&=~WS_THICKFRAME;
	cs.style |= WS_MINIMIZEBOX; 
	cs.style &= ~WS_MAXIMIZEBOX;
	cs.style &= ~FWS_ADDTOTITLE;

	cs.hMenu = NULL;
	cs.lpszName = _T("���𽡿����û���");
	cs.lpszClass = AfxRegisterWndClass(0,0,0,LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1)));

	WCHAR* szAppName = new WCHAR[MAX_PATH];
	lstrcpy(szAppName,_T("����������������"));
	AfxGetApp()->m_pszAppName = szAppName;

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	CRect rect;
	GetClientRect(&rect);
	if(m_wndSplitter.CreateStatic(this,1,2)==NULL)
		return FALSE;
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftPaneView),CSize(150,rect.Height()), pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CRightPaneView),CSize(rect.Width()-150,rect.Height()),pContext);
	
	return TRUE;
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
// 	HICON hIcon = LoadIcon(theApp.m_hInstance,MAKEINTRESOURCE(IDI_ICON1));
// 	SetClassLong(m_hWnd,GCL_HICON,(LONG)hIcon);
	CenterWindow();
	return 0;
}
