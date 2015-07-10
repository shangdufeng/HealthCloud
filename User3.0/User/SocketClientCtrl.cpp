#include "StdAfx.h"
#include "SocketClientCtrl.h"
//#include "TCPClientDlg.h"

CSocketClientCtrl::CSocketClientCtrl(void)
{
	InitialSocket();
}

CSocketClientCtrl::~CSocketClientCtrl(void)
{
	CloseSocket();
}

BOOL CSocketClientCtrl::InitialSocket()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 1, 1 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) 
	{
		return FALSE;
	}

	if ( LOBYTE( wsaData.wVersion ) != 1 ||
		HIBYTE( wsaData.wVersion ) != 1 ) 
	{
		WSACleanup( );
		return FALSE; 
	}

	m_sockClient=socket(AF_INET,SOCK_STREAM,0);

	m_addrSrv.sin_addr.S_un.S_addr=inet_addr("112.124.48.81");
	//112.124.48.81
	//m_addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	//m_addrSrv.sin_addr.S_un.S_addr=inet_addr("10.11.20.88");
	m_addrSrv.sin_family=AF_INET;
	m_addrSrv.sin_port=htons(6000);

	if (SOCKET_ERROR==connect(m_sockClient,(SOCKADDR*)&m_addrSrv,sizeof(SOCKADDR)))
	{
		AfxMessageBox(_T("连接服务器失败,请检查后重新连接!"));
		return FALSE;
	}

	return TRUE;
}
void CSocketClientCtrl::CloseSocket()
{
	closesocket(m_sockClient);
	WSACleanup();
}

int CSocketClientCtrl::GetStringLength(CString strInput)
{
	int szInput=0;
	int len=strInput.GetLength();
	for (int i=0;i<len;i++)
	{
		if (0!=HIBYTE(strInput[i]))
			szInput+=2;
		else
			szInput+=1;
	}
	return szInput;
}

BOOL CSocketClientCtrl::SendCmd()
{
	USES_CONVERSION; 
	m_szOfCmd=GetStringLength(m_strCmd);
	
	if (m_szOfCmd>4095)
	{
		CString szCmd;
		szCmd.Format(_T("%d;%d"),-1,m_szOfCmd+1);
		if (SOCKET_ERROR ==send(m_sockClient,T2A(szCmd),szCmd.GetLength()+1,0))
		{
			AfxMessageBox(_T("发送失败,请检查网络后重新发送!"));
			return FALSE;
		}
		Sleep(200);
	}

	if (SOCKET_ERROR ==send(m_sockClient,T2A(m_strCmd),m_szOfCmd+1,0))
	{
		CloseSocket();//断线重连
		if(!InitialSocket())
		{
			AfxMessageBox(_T("发送失败,请检查网络后重新发送!"));
		}
		return FALSE;
	}
	return TRUE;
}

//用药提醒
BOOL CSocketClientCtrl::UserDrugRead(CString startTime,CString endTime)//用药查询
{
	m_strCmd.Format(_T("%d;"),cmdUserDrugRead);
	m_strCmd+=startTime;
	m_strCmd+=_T(";");
	m_strCmd+=endTime;
	return SendCmd();
}

BOOL CSocketClientCtrl::UserDrugUpdate(vector<User_DrugInfo> userDrugInfo)//用药更新
{
	m_strCmd.Format(_T("%d;"),cmdUserDrugUpdate);
	CString str_drugstartdate,str_drugenddate,str_drugtime,str_drugtime2,str_drugtime3;
	int szInfo=userDrugInfo.size();
	for (int i=0;i<szInfo;i++)
	{
		str_drugstartdate=userDrugInfo[i].drugstartdate.Format(_T("%Y-%m-%d"));
		str_drugenddate=userDrugInfo[i].drugenddate.Format(_T("%Y-%m-%d"));
		str_drugtime=userDrugInfo[i].drugtime.Format(_T("%H:%M:%S"));
		str_drugtime2=userDrugInfo[i].drugtime2.Format(_T("%H:%M:%S"));
		str_drugtime3=userDrugInfo[i].drugtime3.Format(_T("%H:%M:%S"));

		m_strCmd+=userDrugInfo[i].drugname;
		m_strCmd+=_T("','");
		m_strCmd+=str_drugstartdate;//.Format("%Y-%m-%d','");
		m_strCmd+=_T("','");
		m_strCmd+=str_drugenddate;//.Format("%Y-%m-%d','");
		m_strCmd+=_T("','");
		m_strCmd+=str_drugtime;//.Format("%H:%M:%S','");
		m_strCmd+=_T("','");
		m_strCmd+=str_drugtime2;//.Format("%H:%M:%S','");
		m_strCmd+=_T("','");
		m_strCmd+=str_drugtime3;//.Format("%H:%M:%S','");
		m_strCmd+=_T("','");
		m_strCmd+=userDrugInfo[i].drugamount;
		m_strCmd+=_T("');");
	}
	m_strCmd=m_strCmd.Left(m_strCmd.GetLength()-1);
	return SendCmd();
}
//修改个人信息
BOOL CSocketClientCtrl::UserBaseInfoRead()//用户信息查询
{
	m_strCmd.Format(_T("%d"),cmdUserBaseInfoRead);
	return SendCmd();
}
BOOL CSocketClientCtrl::UserBaseInfoInput(User_BaseInfo  userBaseInfo)//用户信息修改
{
	m_strCmd.Format(_T("%d;'"),cmdUserBaseInfoInput);
	m_strCmd+=userBaseInfo.username; 		//用户姓名
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//性别
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birthday; 		//出生年月
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.job;				//职业
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//血型
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;		//家庭住址
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//地区编码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//紧急联系人
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//紧急联系人号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//手术史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//疾病史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//家族史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//用药史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//吸烟史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//饮酒史
	m_strCmd+=_T("'");

	return SendCmd();
}
//医生列表
//用户端—>服务器
BOOL CSocketClientCtrl::UserDoctorInfo(int queType, CString  queText)	//医生信息查询
{
	CString strTemp;
	m_strCmd.Format(_T("%d;"),cmdUserDoctorInfo);
	strTemp.Format(_T("%d;"),queType);
	m_strCmd+=strTemp;
	//m_strCmd+=_T(";");
	m_strCmd+=queText;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserDoctorChoose(CString  doctorCell)//医生选择
{	
	m_strCmd.Format(_T("%d;"),cmdUserDoctorChoose);
	m_strCmd+=doctorCell;
	return SendCmd();
}

//我的医生信息：
//用户端—>服务器
BOOL CSocketClientCtrl::UserDocInfo()	//我的专家信息
{	
	m_strCmd.Format(_T("%d"),cmdUserDocInfo);
	return SendCmd();
}

//输入最近健康信息：
//用户端—>服务器
BOOL CSocketClientCtrl::UserHealthInfoInput(User_HealInfo userHealthInfo)	//健康信息录入
{	
	m_strCmd.Format(_T("%d;"),cmdUserHealInfoInput);
	
	m_strCmd+=_T("'");
	m_strCmd+=userHealthInfo.date_time.Format("%Y-%m-%d %H:%M:%S");		//文件上传时间 2013-10-30
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.weight;	//体重
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.height;		//身高
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.systolic;		//收缩压
// 	m_strCmd+=_T(",");
// 	m_strCmd+=userHealthInfo.BMIindex;	//计算得出的BMI值
// 	m_strCmd+=_T("','");
// 	m_strCmd+=userHealthInfo.waistline;	//腰围
// 	m_strCmd+=_T("','");
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.diastolic;	//舒张压
	m_strCmd+=_T("','");
/*	m_strCmd+=userHealthInfo.systolic;		//收缩压*/
	m_strCmd+=userHealthInfo.sugar;		//血糖
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.oxygen;		//血氧饱和度
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.oxygen3;     //脉率（血氧指标）
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.rate;		//心率
    m_strCmd+=_T("'");
// 	m_strCmd+=userHealthInfo.UA;		//尿酸
// 	m_strCmd+=_T("','");
// 	m_strCmd+=userHealthInfo.filepath;//心电文件路径
// 	m_strCmd+=_T(",");
// 	m_strCmd+=userHealthInfo.filename;//心电文件名称
// 	m_strCmd+=_T(",");
	

	return SendCmd();
}

//登录：
//用户端—>服务器
BOOL CSocketClientCtrl::UserLogOn(CString cellNumber,CString password)//密码校验（登录）
{	
	m_strCmd.Format(_T("%d;"),cmdUserLogOn);
	m_strCmd+=cellNumber;
	m_strCmd+=_T(";");
	m_strCmd+=password;
	return SendCmd();
}

//平台使用情况：
//用户端—>服务器
BOOL CSocketClientCtrl::UserPlatInfoRead()//平台使用情况查询
{
	m_strCmd.Format(_T("%d"),cmdUserPlatInfoRead);
	return SendCmd();
}

//注册：
//用户端—>服务器
BOOL CSocketClientCtrl::UserRegVery(CString userCellNum) 	//用户注册号码验证（序列号为空）
{	
	m_strCmd.Format(_T("%d;"),cmdUserRegVery);
	m_strCmd+=userCellNum;	
	return SendCmd();
}
BOOL CSocketClientCtrl::UserRegVery1(CString userCellNum, CString userSerialNum)//用户注册号码验证（序列号不为空）	
{	
	m_strCmd.Format(_T("%d;"),cmdUserRegVery1);
	m_strCmd+=userCellNum;
	m_strCmd+=_T(";");
	m_strCmd+=userSerialNum;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserReg(User_BaseInfo userBaseInfo)//体验用户注册
{	
	m_strCmd.Format(_T("%d;"),cmdUserReg);

	


// 	m_strCmd+=userBaseInfo.cellnumber; 		//手机号
// 	m_strCmd+=_T("','1','");
// 	m_strCmd+=userBaseInfo.password;		//密码
// 	m_strCmd+=_T("','");	
// 	m_strCmd+=userBaseInfo.username; 		//用户姓名
// 	m_strCmd+=_T("','");
// 	m_strCmd+=userBaseInfo.gender;			//性别
// 	m_strCmd+=_T("','");
// 	m_strCmd+=_T("'");

	m_strCmd+=userBaseInfo.username; 		//用户姓名
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//性别
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birthday; 			//年龄（感觉用出生年月比较好）  这个起始没必要了，因为身份证号码里面有
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.cellnumber; 	//手机号
	m_strCmd+=_T("','0','");
	m_strCmd+=userBaseInfo.password;		//密码
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.job;				//职业
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//血型
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;	//家庭住址
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//身份证号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//紧急联系人
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//紧急联系人号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//手术史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//疾病史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//家族史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//用药史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//吸烟史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//饮酒史
	m_strCmd+=_T("'");





	return SendCmd();
}
BOOL CSocketClientCtrl::UserReg1(User_BaseInfo userBaseInfo, CString userSerialNum)	//付费用户注册
{	
	m_strCmd.Format(_T("%d;"),cmdUserReg1);

	m_strCmd+=userBaseInfo.username; 		//用户姓名
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//性别
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birthday; 			//年龄（感觉用出生年月比较好）  这个起始没必要了，因为身份证号码里面有
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.cellnumber; 	//手机号
	m_strCmd+=_T("','1','");
	m_strCmd+=userBaseInfo.password;		//密码
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.job;				//职业
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//血型
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;	//家庭住址
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//身份证号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//紧急联系人
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//紧急联系人号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//手术史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//疾病史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//家族史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//用药史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//吸烟史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//饮酒史
	m_strCmd+=_T("'");
	//m_strCmd+=userSerialNum;

	return SendCmd();
}

//找回密码：
//用户端—>服务器
BOOL CSocketClientCtrl::UserVeriCodeSend(CString strCell)//忘记密码找回
{	
	m_strCmd.Format(_T("%d;"),cmdUserVeriCodeSend);	
	m_strCmd+=strCell;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserVeriCodeSubmit(CString veryCode)//提交验证码
{	
	m_strCmd.Format(_T("%d;"),cmdUserVeriCodeSubmit);
	m_strCmd+=veryCode;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserPWResetCode(CString strCell,CString password)	//密码重置（新密码）
{	
	m_strCmd.Format(_T("%d;"),cmdUserPWResetCode);
	m_strCmd+=strCell;
	m_strCmd+=_T(";");
	m_strCmd+=password;
	return SendCmd();
}

//欢迎页面：
//用户端—>服务器
BOOL CSocketClientCtrl::UserWel()//欢迎信息查询
{	
	m_strCmd.Format(_T("%d"),cmdUserWel);
	return SendCmd();
}

//最近健康信息：
//用户端—>服务器
BOOL CSocketClientCtrl::UserLatestHealRead()//最近健康指标
{
	m_strCmd.Format(_T("%d"),cmdUserLatestHealRead);
	return SendCmd();
}
//历史健康信息：
//用户端—>服务器
BOOL CSocketClientCtrl::UserHisHealRead(CString Type,CString startTime,CString endTime)//历史健康信息查询
{
	m_strCmd.Format(_T("%d;"),cmdUserHisHealRead);
	m_strCmd += "'";
	m_strCmd += Type;
	m_strCmd += "','";
	m_strCmd += startTime;
	m_strCmd +="','";
	m_strCmd += endTime;
	m_strCmd += "'";
	return SendCmd();
}

//报告查询：
//用户端—>服务器
BOOL CSocketClientCtrl::UserRepRead(CString repType, CString startTime, CString endTime)//报告查询
{
	m_strCmd.Format(_T("%d;"),cmdUserRepRead);
	m_strCmd+=repType;
	m_strCmd+=_T(";");
	m_strCmd+=startTime;//.Format("%Y-%m-%d");
	m_strCmd+=_T(";");
	m_strCmd+=endTime;//.Format("%Y-%m-%d");
	return SendCmd();
}

//异常信息查询：
BOOL CSocketClientCtrl::UserExcepRead(CString startTime, CString endTime)//异常信息查询
{
	m_strCmd.Format(_T("%d;"),cmdUserExcepRead);
// 	m_strCmd+=_T("2013-12-01;");
// 	m_strCmd+=_T("2014-12-17");
 	m_strCmd+=startTime;//.Format("%Y-%m-%d %H:%M:%S;");
	m_strCmd+=_T(";");
 	m_strCmd+=endTime;//.Format("%Y-%m-%d %H:%M:%S");
	return SendCmd();
}

//修改密码：
BOOL CSocketClientCtrl::UserSendCode()//重置密码
{	
	m_strCmd.Format(_T("%d"),cmdUserSendCode);
	return SendCmd();
}
BOOL CSocketClientCtrl::UserSubCode(CString code)//提交验证码
{
	m_strCmd.Format(_T("%d;"),cmdUserSubCode);
	m_strCmd+=code;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserNewPass(CString newPasscode)//提交新密码
{	
	m_strCmd.Format(_T("%d;"),cmdUserNewPass);
	m_strCmd+=newPasscode;
	return SendCmd();
}

//消息阅读：
//用户端—>服务器
BOOL CSocketClientCtrl::UserMessRead(CString startTime,CString endTime)//消息阅读
{
	m_strCmd.Format(_T("%d;"),cmdUserMessRead);
	m_strCmd+=startTime;
	m_strCmd+=_T(";");
	m_strCmd+=endTime;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserMessSend(CString docCell, CString message)	 //发送消息	
{	
	m_strCmd.Format(_T("%d;"),cmdUserMessSend);
	m_strCmd+=docCell;
	m_strCmd+=_T(";");
	m_strCmd+=message;
	return SendCmd();
}

BOOL CSocketClientCtrl::UserUploadFile(CString fileName)
{
	m_strCmd.Format(_T("%d;"),cmdUserUploadFile);
	m_strCmd+=fileName;
	return SendCmd();
}

BOOL CSocketClientCtrl::UserHrtRepRead()
{
	m_strCmd.Format(_T("%d;"),cmdUserDownLoadRep);
	return SendCmd();
}

BOOL CSocketClientCtrl::UserMessNoToYes(CString time,CString SenderID)
{
	m_strCmd.Format(_T("%d;"),cmdMessReadOrNo);
	m_strCmd += SenderID;
	m_strCmd += _T(";");
	m_strCmd += time;
	return SendCmd();
}

BOOL CSocketClientCtrl::UserRepNoToYes(CString time,CString reptype)
{
	m_strCmd.Format(_T("%d;"),cmdRepReadOrNo);
	m_strCmd += reptype;
	m_strCmd += _T(";");
	m_strCmd += time;
	return SendCmd();
}