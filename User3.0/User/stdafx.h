
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持
#include <afxdisp.h>




struct User_DrugInfo
{
	CString drugname;
	CTime drugstartdate;
	CTime drugenddate;
	CTime drugtime;
	CTime drugtime2;
	CTime drugtime3;
	CString drugamount;
};

struct Doctor_BaseInfo 
{
	CString cellnumber; 	//手机号
	CString password;		//密码
	CString doctorname; 	//医生姓名
	CString gender;			//性别
	CString IDcardnum;		//身份证号码
	CString school;			//毕业院校
	CString eduback;		//最高学历
	CString hospital;		//供职医院
	CString title;			//职称
	CString duty;			//职务
	CString adminoffice;		//科室
	CString major;			//专业擅长
	CString consulttime;		//门诊时间
	CString replytime;		//回复时间

};

struct User_BaseInfo 
{
	CString cellnumber; 	//手机号
	CString password;		//密码
	CString username; 		//用户姓名
	CString gender;			//性别
	CString birthday; 		//年龄（感觉用出生年月比较好）
	CString job;			//职业
	CString bloodtype;		//血型
	CString homeaddress;	//家庭住址
	CString regionCode;		//区域编码(暂时还没加入)
	CString emercontactor;	//紧急联系人
	CString emercontactornum;//紧急联系人号码
	CString surgeryhistory;	//手术史
	CString diseaseshistory;//疾病史
	CString familyhistory;	//家族史
	CString drughistory;	//用药史
	CString smokehistory;	//吸烟史
	CString drinkhistory;	//饮酒史

};

struct Welcome_Info
{
	int mess_unread;
	int rep_unread;
	CString unsi_rep;
	CString last_upload;
	CString member_deadline;
};

struct User_HealInfo 
{
	CString height;		//身高
	CString weight;	//体重
	CString BMIindex;	//计算得出的BMI值
	CString waistline;	//腰围
	CString diastolic;	//舒张压
	CString systolic;		//收缩压
	CString rate;
	CString sugar;		//血糖
	CString oxygen;		//血氧饱和度
	CString oxygen3;     //脉率（血氧指标）
	CString UA;		//尿酸
	CString filepath;//心电文件路径
	CString filename;//心电文件名称
	CTime date_time;		//文件上传时间 2013-10-30

};

struct MessInfo			//消息
{
	CString RS;
	CString object;
	CString time;
	CString messtext;
	CString ifread;
};

enum{cmdUserDrugRead,cmdUserDrugUpdate,cmdUserBaseInfoRead,cmdUserBaseInfoInput,cmdUserDoctorInfo,cmdUserDoctorChoose,
	cmdUserDocInfo,cmdUserHealInfoInput,cmdUserLogOn,cmdUserPlatInfoRead,cmdUserRegVery,cmdUserRegVery1,cmdUserReg,cmdUserReg1,
	cmdUserVeriCodeSend,cmdUserVeriCodeSubmit,cmdUserPWResetCode,cmdUserWel,cmdUserLatestHealRead,cmdUserHisHealRead,cmdUserRepRead,
	cmdUserExcepRead,cmdUserSendCode,cmdUserSubCode,cmdUserNewPass,cmdUserMessRead,cmdUserMessSend,cmdUserUploadFile,cmdUserDownLoadRep,//用户端发送
	cmdManAddUser,cmdManQueUser,cmdManChgUserBasInfo,cmdManQueUserDrug,cmdManChgUserDrug,cmdManQueUserExcep,cmdManQueUserMess,cmdManQueUserRep,cmdManQueUserUpload
	,cmdManAddDoc,cmdManQueDoc,cmdManChgDocBasInfo,cmdManQueDocRep,cmdManQueDocMess,cmdManQueUser1,cmdManQueDoc1,cmdManQueCSM,cmdManAddManSR
	,cmdManQueCSR,cmdManAddManSM,cmdManQueTM,cmdManAddManTP,cmdManQueTP,cmdManAddManTM,cmdManQueDM,cmdManAddManDP,cmdManQueDP,cmdManAddManDM
	,cmdManQueMan,cmdManQue,cmdManSendMess,cmdManSendMessOT,cmdManAddSeriManu,cmdManAddSeriBat,cmdManQueSeri,cmdManLogin,cmdManHrtRep//用户端接收
	} cmdClient;

enum{cmdServerDrugRead,cmdSUDrugUpdate,cmdSUBaseInfoRead,cmdSUBaseInfoInput,cmdSUDoctorInfo,cmdSUDoctorChoose,cmdSUDocInfo,
	cmdSUHealInfoInput,cmdServerLogOn,cmdSUPlatInfoRead,cmdSURegVery,cmdSURegVery1,cmdSUReg,cmdSUReg1,cmdServerPWReset,
	cmdServerVeriCode,cmdSUPWResetCode,cmdSUWel,cmdSULatestHealRead,cmdSUHisHealRead,cmdSURepRead,cmdSUExcepRead,cmdSUSendCode,
	cmdSUSubCode,cmdSUNewPass,cmdSUMessRead,cmdSUMessSend,cmdServerError,cmdSUHrtRep//管理端发送
	
	,cmdSMAddUserEx,cmdSMQueUser,cmdSMQueUserEx,cmdSMChgUserBasInfoEx,cmdSMQueUserDrug,cmdSMQueUserDrugEx,cmdSMChgUserDrugEx,cmdSMQueUserExcep,cmdSMQueUserExcepEx,cmdSMQueUserMess,cmdSMQueUserMessEx,cmdSMQueUserRep,cmdSMQueUserRepEx,cmdSMQueUserUpload,cmdSMQueUserUploadEx
	,cmdSMAddDocEx,cmdSMQueDoc,cmdSMQueDocEx,cmdSMChgDocBasInfoEx,cmdSMQueDocRep,cmdSMQueDocRepEx,cmdSMQueDocMess,cmdSMQueDocMessEx,cmdSMQueUser1,cmdSMQueUser1Ex,cmdSMQueDoc1,cmdSMQueDoc1Ex,cmdSMQueCSM,cmdSMQueCSMEx,cmdSMAddManSREx
	,cmdSMQueCSR,cmdSMQueCSREx,cmdSMAddManSMEx,cmdSMQueTM,cmdSMQueTMEx,cmdSMAddManTPEX,cmdSMQueTP,cmdSMQueTPEx,cmdSMAddManTMEx,cmdSMQueDM,cmdSMQueDMEx,cmdSMAddManDPEx,cmdSMQueDP,cmdSMQueDPEx,cmdSMAddManDMEx
	,cmdSMQueMan,cmdSMQueManEx,cmdSMQue,cmdSMQueEx,cmdSMSendMessEx,cmdSMSendMessOTEx,cmdSMAddSeriManuEx,cmdSMAddSeriBatEx,cmdSMQueSeri,cmdSMQueSeriEx,cmdSMLogin//管理端接收
	} cmdServer;

enum{cmdMessReadOrNo=100,cmdRepReadOrNo};//设置未读报告/信息为已读状态

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


#include "CApplication.h"
#include "CDocument0.h"
#include "CDocuments.h"
#include "CPageSetup.h"
#include "CSelection.h"
#include "CFont0.h"
#include "CParagraph.h"
#include "CParagraphs.h"
#include "CRange.h"
#include "CTable0.h"
#include "CTables0.h"
#include "CCell.h"
#include "CBorders.h"
#include "CRow.h"
#include "CRows.h"

//**************读取CSV文件******************
#include "Row.h"
#include "Sheet.h"
