
// User.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "User.h"
#include "MainFrm.h"

#include "UserDoc.h"
#include "UserView.h"
#include "CDPdfview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUserApp

BEGIN_MESSAGE_MAP(CUserApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CUserApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	
END_MESSAGE_MAP()


// CUserApp ����

CUserApp::CUserApp()
	: m_pleftpane(NULL)
	, m_prightpane(NULL)
	, m_prightpreview(NULL)
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("User.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��

	m_TextFont.CreatePointFont(150,_T("����"));
}

// Ψһ��һ�� CUserApp ����

CUserApp theApp;


// CUserApp ��ʼ��

BOOL CUserApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CUserDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CUserView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����


// 	WORD wVersionRequested;
// 	WSADATA wsaData;
// 	int err;
// 
// 	wVersionRequested = MAKEWORD( 1, 1 );
// 
// 	err = WSAStartup( wVersionRequested, &wsaData );
// 	if ( err != 0 ) 
// 	{
// 		return 0;
// 	}
// 
// 	if ( LOBYTE( wsaData.wVersion ) != 1 ||
// 		HIBYTE( wsaData.wVersion ) != 1 ) 
// 	{
// 		WSACleanup( );
// 		return 0; 
// 	}
// 
// 	m_sockClient=socket(AF_INET,SOCK_STREAM,0);
// 
// 	m_addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
// 	m_addrSrv.sin_family=AF_INET;
// 	m_addrSrv.sin_port=htons(6000);
// 
// 	//int rlt=;
// 	if (SOCKET_ERROR==connect(m_sockClient,(SOCKADDR*)&m_addrSrv,sizeof(SOCKADDR)))
// 	{
// 		AfxMessageBox(_T("jaohfiuwaef"));
// 	}
// 
// 	theApp.vecstr=new CString;


// 	RECVPARAM* pRecvParam=new RECVPARAM;
// 	pRecvParam->sock=m_sockClient;
// 	pRecvParam->hinstance=AfxGetInstanceHandle();
	HANDLE hThread=::CreateThread(NULL,0,( LPTHREAD_START_ROUTINE)RecvProc,NULL,0,NULL);
	CloseHandle(hThread);
		






	return TRUE;
}

int CUserApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);
	delete theApp.vecstr;

	return CWinApp::ExitInstance();
}

// CUserApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CUserApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CUserApp ��Ϣ�������



DWORD WINAPI RecvProc()

{


	
// 	SOCKADDR_IN addrClient;
// 	int len=sizeof(SOCKADDR);
// 
 	//SOCKET sockConn//=accept(theApp.m_sockClient,(SOCKADDR*)&addrClient,&len);//SOCKET m_sockSvr;��ͷ�ļ��ﶨ��

	USES_CONVERSION; 

	//CString strAddr=A2T(inet_ntoa(addrClient.sin_addr));
	int count=0;
	vector<CString> vec_str;
	while(1)
	{
		//CString strRecv;
		
		char  charRecv[4096];
		int  szData=recv(theApp.socketclient.m_sockClient,charRecv,4096,0);

		if (0!=szData&&-1!=szData)
		{
			theApp.strRecv=A2T(charRecv);
			//num=_ttoi(strRecv);
			int vec_str1;			
			
			//*(theApp.vecstr)=strRecv;

			/*CString *vec_str2;*/
			/*vec_str2=new CString;*/
			theApp.SplitString(theApp.strRecv,_T(";"),TRUE,vec_str);
			vec_str1=_ttoi(vec_str.at(0));
			/**vec_str2=vec_str.at(1);*/
			switch (vec_str1)
			{
			case -1:
				AfxMessageBox(vec_str.at(1));
				break;
			case cmdServerDrugRead:
				//::PostMessage(theApp.m_prightregview->m_hWnd,WM_REG,0,0);
				::PostMessage(theApp.m_prightchangeinfoview->m_hWnd,WM_SERVERDRUGREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUDrugUpdate:
				::PostMessage(theApp.m_prightchangeinfoview->m_hWnd,WM_SUDRUGUPDATE,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUBaseInfoRead:
				::PostMessage(theApp.m_prightchgperinfoview->m_hWnd,WM_SUBASEINFOREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUBaseInfoInput:
				::PostMessage(theApp.m_prightchgperinfoview->m_hWnd,WM_SUBASEINFOINPUT,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUDoctorInfo:
				::PostMessage(theApp.m_prightdoclistview->m_hWnd,WM_DOCTORINFOLIST,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUDoctorChoose:
				::PostMessage(theApp.m_prightdoclistview->m_hWnd,WM_SUDOCTORCHOOSE,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUDocInfo:
				::PostMessage(theApp.m_prightmydocview->m_hWnd,WM_SUDOCINFO,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUHealInfoInput:
				::PostMessage(theApp.m_prightinputview->m_hWnd,WM_HEALINFOINPUT,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdServerLogOn:
				::PostMessage(theApp.m_prightloginview->m_hWnd,WM_SERVERLOGON,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUPlatInfoRead:
				::PostMessage(theApp.m_prightplatuseview->m_hWnd,WM_SUPLATINFOREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSURegVery:
				::PostMessage(theApp.m_prightregview->m_hWnd,WM_SUREGVERY,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSURegVery1:
				::PostMessage(theApp.m_prightregview->m_hWnd,WM_SUREGVERY1,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUReg:
				::PostMessage(theApp.m_prightregview->m_hWnd,WM_SUREG,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUReg1:
				::PostMessage(theApp.m_prightreg2view->m_hWnd,WM_SUREG1,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdServerPWReset://����������
				AfxMessageBox(_T("sfe"));
				break;
			case cmdSUSubCode://��֤����֤
				::PostMessage(theApp.m_prightresetpassview->m_hWnd,WM_SUSUBCODE,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUSendCode://������֤����ֻ�����ʵ��������Ҫ��Ӧ��
				///AfxMessageBox(_T("��֤���ѷ������ֻ�"));
				::PostMessage(theApp.m_prightresetpassview->m_hWnd,WM_PWRESET,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUWel:
				::PostMessage(theApp.m_rightwelcomeview->m_hWnd,WM_SUWEL,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSULatestHealRead://**********************
				::PostMessage(theApp.m_prightlatestinfoview->m_hWnd,WM_SULATESTHEALREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUHisHealRead://**********************
				::PostMessage(theApp.m_prighthisqueview->m_hWnd,WM_SUHISHEALREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSURepRead://**********************
				::PostMessage(theApp.m_prighthealrepview->m_hWnd,WM_SUREPREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUExcepRead://**********************
				::PostMessage(theApp.m_prightexcepinfoview->m_hWnd,WM_SUEXCEPREAD,0,(LPARAM)&theApp.strRecv);
				break;
			//case 22://**********************
				break;
			//case 23://**********************
				break;
			//case 24://**********************
				break;
			case cmdSUMessRead:
				::PostMessage(theApp.m_prightmessagereadview->m_hWnd,WM_SUMESSREAD,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUMessSend:
				::PostMessage(theApp.m_prightmessagereadview->m_hWnd,WM_SUMESSSEND,0,(LPARAM)&theApp.strRecv);
				break;
				//**************************��ѯ�ĵ�ͼ����******************************************
			case cmdSUHrtRep:
				::PostMessage(theApp.m_prightlatestinfoview->m_hWnd,WM_SUHRTREP,0,(LPARAM)&theApp.strRecv);
			case cmdMessReadOrNo:
				::PostMessage(theApp.m_prightmessagereadview->m_hWnd,WM_MESSREADORNO,0,(LPARAM)&theApp.strRecv);
			case cmdRepReadOrNo:
				::PostMessage(theApp.m_prighthealrepview->m_hWnd,WM_REPREADORNO,0,(LPARAM)&theApp.strRecv);
			default:
				break;
			}
		}
	}
	return 1;
}

// enum{cmdUserDrugRead,cmdUserDrugUpdate,cmdUserBaseInfoRead,cmdUserBaseInfoInput,cmdUserDoctorInfo,cmdUserDoctorChoose,
// 	cmdUserDocInfo,cmdUserHealInfoInput,cmdUserLogOn,cmdUserPlatInfoRead,cmdUserRegVery,cmdUserRegVery1,cmdUserReg,cmdUserReg1,
// 	cmdUserVeriCodeSend,cmdUserVeriCodeSubmit,cmdUserPWResetCode,cmdUserWel,cmdUserLatestHealRead,cmdUserHisHealRead,cmdUserRepRead,
// 	cmdUserExcepRead,cmdUserSendCode,cmdUserSubCode,cmdUserNewPass,cmdUserMessRead,cmdUserMessSend} cmdClient;
// enum{cmdServerError=-1,cmdServerDrugRead,cmdSUDrugUpdate,cmdSUBaseInfoRead,cmdSUBaseInfoInput,cmdSUDoctorInfo,cmdSUDoctorChoose,cmdSUDocInfo,
// 	cmdSUHealInfoInput,cmdServerLogOn,cmdSUPlatInfoRead,cmdSURegVery,cmdSURegVery1,cmdSUReg,cmdSUReg1,cmdServerPWReset,
// 	cmdServerVeriCode,cmdSUPWResetCode,cmdSUWel,cmdSULatestHealRead,cmdSUHisHealRead,cmdSURepRead,cmdSUExcepRead,cmdSUSendCode,
// 	cmdSUSubCode,cmdSUNewPass,cmdSUMessRead,cmdSUMessSend} cmdServer;


int  CUserApp::SplitString(CString str_in, CString chSplit_in,
	BOOL bAllowNullString,vector<CString>& data)   
{   
	data.clear();

	str_in.TrimLeft();   
	str_in.TrimRight();   
	if(str_in.GetLength()==0)   
		return 0;    
	if(chSplit_in.GetLength() == 0)   
	{   
		data.push_back(str_in);
		return 1;   
	}   
	CString s;   
	int n;  
	do 
	{   
		n = str_in.Find(chSplit_in);   
		if(n > 0)   
		{   
			data.push_back(str_in.Left(n));
			str_in = str_in.Right(str_in.GetLength()-n-chSplit_in.GetLength());   
			str_in.TrimLeft();   
		}   
		else if(n==0)   
		{   
			if(bAllowNullString)    
				data.push_back(_T(""));
			str_in = str_in.Right(str_in.GetLength()-chSplit_in.GetLength());   
			str_in.TrimLeft();   
		}   
		else  
		{   
			if((str_in.GetLength()>0)||bAllowNullString)   
				data.push_back(str_in);
			break;   
		}   
	} while(1);   

	return data.size();   
} 

void CUserApp::ReOrder(vector<CString> vec,int Index,vector<vector<CString>> &MutiVec1)
{
	vector<CString> vec1;
	vector<vector<CString>> MutiVec;
	//SplitString(str,_T(";"),TRUE,vec);
	for(int i=1; i<vec.size(); i++)
	{
		SplitString(vec.at(i),_T(","),TRUE,vec1);
		MutiVec.push_back(vec1);
	}
	int num = MutiVec.size();

	//************��δ���ʼ�����ǰ��**************
	for(int i=0;i<num;i++)
	{
		if(MutiVec.at(i).at(Index)==_T("0"))                           //�Ѷ�Ϊ1��δ��Ϊ0
			MutiVec1.push_back(MutiVec.at(i));
	}
	for(int i=0;i<num;i++)
	{
		if(MutiVec.at(i).at(Index)==_T("1"))
			MutiVec1.push_back(MutiVec.at(i));
	}
	MutiVec.clear();
}