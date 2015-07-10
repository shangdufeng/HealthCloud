
// User.cpp : 定义应用程序的类行为。
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
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	
END_MESSAGE_MAP()


// CUserApp 构造

CUserApp::CUserApp()
	: m_pleftpane(NULL)
	, m_prightpane(NULL)
	, m_prightpreview(NULL)
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则:
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("User.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中

	m_TextFont.CreatePointFont(150,_T("黑体"));
}

// 唯一的一个 CUserApp 对象

CUserApp theApp;


// CUserApp 初始化

BOOL CUserApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)


	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CUserDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CUserView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生


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
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);
	delete theApp.vecstr;

	return CWinApp::ExitInstance();
}

// CUserApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void CUserApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CUserApp 消息处理程序



DWORD WINAPI RecvProc()

{


	
// 	SOCKADDR_IN addrClient;
// 	int len=sizeof(SOCKADDR);
// 
 	//SOCKET sockConn//=accept(theApp.m_sockClient,(SOCKADDR*)&addrClient,&len);//SOCKET m_sockSvr;在头文件里定义

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
			case cmdServerPWReset://新密码设置
				AfxMessageBox(_T("sfe"));
				break;
			case cmdSUSubCode://验证码验证
				::PostMessage(theApp.m_prightresetpassview->m_hWnd,WM_SUSUBCODE,0,(LPARAM)&theApp.strRecv);
				break;
			case cmdSUSendCode://发送验证码给手机（其实这条不需要响应）
				///AfxMessageBox(_T("验证码已发送至手机"));
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
				//**************************查询心电图报告******************************************
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

	//************将未读邮件放在前部**************
	for(int i=0;i<num;i++)
	{
		if(MutiVec.at(i).at(Index)==_T("0"))                           //已读为1，未读为0
			MutiVec1.push_back(MutiVec.at(i));
	}
	for(int i=0;i<num;i++)
	{
		if(MutiVec.at(i).at(Index)==_T("1"))
			MutiVec1.push_back(MutiVec.at(i));
	}
	MutiVec.clear();
}