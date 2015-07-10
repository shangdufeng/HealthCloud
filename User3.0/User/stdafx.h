
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��
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
	CString cellnumber; 	//�ֻ���
	CString password;		//����
	CString doctorname; 	//ҽ������
	CString gender;			//�Ա�
	CString IDcardnum;		//���֤����
	CString school;			//��ҵԺУ
	CString eduback;		//���ѧ��
	CString hospital;		//��ְҽԺ
	CString title;			//ְ��
	CString duty;			//ְ��
	CString adminoffice;		//����
	CString major;			//רҵ�ó�
	CString consulttime;		//����ʱ��
	CString replytime;		//�ظ�ʱ��

};

struct User_BaseInfo 
{
	CString cellnumber; 	//�ֻ���
	CString password;		//����
	CString username; 		//�û�����
	CString gender;			//�Ա�
	CString birthday; 		//���䣨�о��ó������±ȽϺã�
	CString job;			//ְҵ
	CString bloodtype;		//Ѫ��
	CString homeaddress;	//��ͥסַ
	CString regionCode;		//�������(��ʱ��û����)
	CString emercontactor;	//������ϵ��
	CString emercontactornum;//������ϵ�˺���
	CString surgeryhistory;	//����ʷ
	CString diseaseshistory;//����ʷ
	CString familyhistory;	//����ʷ
	CString drughistory;	//��ҩʷ
	CString smokehistory;	//����ʷ
	CString drinkhistory;	//����ʷ

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
	CString height;		//���
	CString weight;	//����
	CString BMIindex;	//����ó���BMIֵ
	CString waistline;	//��Χ
	CString diastolic;	//����ѹ
	CString systolic;		//����ѹ
	CString rate;
	CString sugar;		//Ѫ��
	CString oxygen;		//Ѫ�����Ͷ�
	CString oxygen3;     //���ʣ�Ѫ��ָ�꣩
	CString UA;		//����
	CString filepath;//�ĵ��ļ�·��
	CString filename;//�ĵ��ļ�����
	CTime date_time;		//�ļ��ϴ�ʱ�� 2013-10-30

};

struct MessInfo			//��Ϣ
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
	cmdUserExcepRead,cmdUserSendCode,cmdUserSubCode,cmdUserNewPass,cmdUserMessRead,cmdUserMessSend,cmdUserUploadFile,cmdUserDownLoadRep,//�û��˷���
	cmdManAddUser,cmdManQueUser,cmdManChgUserBasInfo,cmdManQueUserDrug,cmdManChgUserDrug,cmdManQueUserExcep,cmdManQueUserMess,cmdManQueUserRep,cmdManQueUserUpload
	,cmdManAddDoc,cmdManQueDoc,cmdManChgDocBasInfo,cmdManQueDocRep,cmdManQueDocMess,cmdManQueUser1,cmdManQueDoc1,cmdManQueCSM,cmdManAddManSR
	,cmdManQueCSR,cmdManAddManSM,cmdManQueTM,cmdManAddManTP,cmdManQueTP,cmdManAddManTM,cmdManQueDM,cmdManAddManDP,cmdManQueDP,cmdManAddManDM
	,cmdManQueMan,cmdManQue,cmdManSendMess,cmdManSendMessOT,cmdManAddSeriManu,cmdManAddSeriBat,cmdManQueSeri,cmdManLogin,cmdManHrtRep//�û��˽���
	} cmdClient;

enum{cmdServerDrugRead,cmdSUDrugUpdate,cmdSUBaseInfoRead,cmdSUBaseInfoInput,cmdSUDoctorInfo,cmdSUDoctorChoose,cmdSUDocInfo,
	cmdSUHealInfoInput,cmdServerLogOn,cmdSUPlatInfoRead,cmdSURegVery,cmdSURegVery1,cmdSUReg,cmdSUReg1,cmdServerPWReset,
	cmdServerVeriCode,cmdSUPWResetCode,cmdSUWel,cmdSULatestHealRead,cmdSUHisHealRead,cmdSURepRead,cmdSUExcepRead,cmdSUSendCode,
	cmdSUSubCode,cmdSUNewPass,cmdSUMessRead,cmdSUMessSend,cmdServerError,cmdSUHrtRep//����˷���
	
	,cmdSMAddUserEx,cmdSMQueUser,cmdSMQueUserEx,cmdSMChgUserBasInfoEx,cmdSMQueUserDrug,cmdSMQueUserDrugEx,cmdSMChgUserDrugEx,cmdSMQueUserExcep,cmdSMQueUserExcepEx,cmdSMQueUserMess,cmdSMQueUserMessEx,cmdSMQueUserRep,cmdSMQueUserRepEx,cmdSMQueUserUpload,cmdSMQueUserUploadEx
	,cmdSMAddDocEx,cmdSMQueDoc,cmdSMQueDocEx,cmdSMChgDocBasInfoEx,cmdSMQueDocRep,cmdSMQueDocRepEx,cmdSMQueDocMess,cmdSMQueDocMessEx,cmdSMQueUser1,cmdSMQueUser1Ex,cmdSMQueDoc1,cmdSMQueDoc1Ex,cmdSMQueCSM,cmdSMQueCSMEx,cmdSMAddManSREx
	,cmdSMQueCSR,cmdSMQueCSREx,cmdSMAddManSMEx,cmdSMQueTM,cmdSMQueTMEx,cmdSMAddManTPEX,cmdSMQueTP,cmdSMQueTPEx,cmdSMAddManTMEx,cmdSMQueDM,cmdSMQueDMEx,cmdSMAddManDPEx,cmdSMQueDP,cmdSMQueDPEx,cmdSMAddManDMEx
	,cmdSMQueMan,cmdSMQueManEx,cmdSMQue,cmdSMQueEx,cmdSMSendMessEx,cmdSMSendMessOTEx,cmdSMAddSeriManuEx,cmdSMAddSeriBatEx,cmdSMQueSeri,cmdSMQueSeriEx,cmdSMLogin//����˽���
	} cmdServer;

enum{cmdMessReadOrNo=100,cmdRepReadOrNo};//����δ������/��ϢΪ�Ѷ�״̬

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

//**************��ȡCSV�ļ�******************
#include "Row.h"
#include "Sheet.h"
