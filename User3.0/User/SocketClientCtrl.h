#pragma once
/*#include "TCPClientDlg.h"*/
#include <vector>
using std::vector;

class CSocketClientCtrl
{
public:
	CSocketClientCtrl(void);
	~CSocketClientCtrl(void);

	SOCKET m_sockClient;
	SOCKADDR_IN m_addrSrv;
	int m_szOfCmd;
	CString m_strCmd;

	BOOL InitialSocket();
	void CloseSocket();
	int GetStringLength(CString strInput);
	BOOL SendCmd();

	//用药提醒
	//用户端—>服务器
	BOOL UserDrugRead(CString startTime,CString endTime); //用药查询
	BOOL UserDrugUpdate(vector<User_DrugInfo> userDrugInfo);//用药更新

	//修改个人信息
	//用户端—>服务器
	BOOL UserBaseInfoRead();//用户信息查询
	BOOL UserBaseInfoInput(User_BaseInfo  userBaseInfo);//用户信息修改

	//医生列表
	//用户端—>服务器
	BOOL UserDoctorInfo(int queType, CString  queText);	//医生信息查询
	BOOL UserDoctorChoose(CString  doctorCell);//医生选择

	//我的医生信息：
	//用户端—>服务器
	BOOL UserDocInfo();	//我的专家信息

	//输入最近健康信息：
	//用户端—>服务器
	BOOL UserHealthInfoInput(User_HealInfo userHealthInfo);	//健康信息录入

	//登录：
	//用户端—>服务器
	BOOL UserLogOn(CString cellNumber,CString password);//密码校验（登录）

	//平台使用情况：
	//用户端—>服务器
	BOOL UserPlatInfoRead();//平台使用情况查询

	//注册：
	//用户端—>服务器
	BOOL UserRegVery(CString userCellNum); 	//用户注册号码验证（序列号为空）
	BOOL UserRegVery1(CString userCellNum, CString userSerialNum);//用户注册号码验证（序列号不为空）	
	BOOL UserReg(User_BaseInfo userBaseInfo);//体验用户注册	
	BOOL UserReg1(User_BaseInfo userBaseInfo, CString userSerialNum);	//付费用户注册

	//忘记密码时找回密码：
	//用户端—>服务器
	BOOL UserVeriCodeSend(CString strCell);//发送验证码到手机
	BOOL UserVeriCodeSubmit(CString veryCode);//提交验证码
	BOOL UserPWResetCode(CString strCell,CString password);	//密码重置（新密码）

	//欢迎页面：
	//用户端—>服务器
	BOOL UserWel();//欢迎信息查询

	//最近健康信息：
	//用户端—>服务器
	BOOL UserLatestHealRead();//最近健康指标
	//	动态血压和动态心电	？？？？？？？？？？？		

	//历史健康信息：
	//用户端—>服务器
	BOOL UserHisHealRead(CString Type,CString startTime, CString endTime);//历史健康信息查询

	//报告查询：
	//用户端—>服务器
	BOOL UserRepRead(CString repType, CString startTime, CString endTime);//报告查询

	//异常信息查询：
	//用户端—>服务器
	BOOL UserExcepRead(CString startTime, CString endTime);//异常信息查询

	//密码重置：
	//用户端—>服务器
	BOOL UserSendCode();//发送验证码到手机
	BOOL UserSubCode(CString code);//提交验证码
	BOOL UserNewPass(CString newPasscode);//提交新密码

	//消息阅读：
	//用户端—>服务器
	BOOL UserMessRead(CString startTime,CString endTime);//消息阅读
	BOOL UserMessSend(CString docCell, CString message);	 //发送消息	

	BOOL UserUploadFile(CString fileName);

	//查询心电图报告
	BOOL UserHrtRepRead();

	BOOL UserMessNoToYes(CString time,CString SenderID);//设置未读消息为已读状态
	BOOL UserRepNoToYes(CString time,CString reptype); //设置未读报告为已读状态
	
};
