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
		AfxMessageBox(_T("���ӷ�����ʧ��,�������������!"));
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
			AfxMessageBox(_T("����ʧ��,������������·���!"));
			return FALSE;
		}
		Sleep(200);
	}

	if (SOCKET_ERROR ==send(m_sockClient,T2A(m_strCmd),m_szOfCmd+1,0))
	{
		CloseSocket();//��������
		if(!InitialSocket())
		{
			AfxMessageBox(_T("����ʧ��,������������·���!"));
		}
		return FALSE;
	}
	return TRUE;
}

//��ҩ����
BOOL CSocketClientCtrl::UserDrugRead(CString startTime,CString endTime)//��ҩ��ѯ
{
	m_strCmd.Format(_T("%d;"),cmdUserDrugRead);
	m_strCmd+=startTime;
	m_strCmd+=_T(";");
	m_strCmd+=endTime;
	return SendCmd();
}

BOOL CSocketClientCtrl::UserDrugUpdate(vector<User_DrugInfo> userDrugInfo)//��ҩ����
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
//�޸ĸ�����Ϣ
BOOL CSocketClientCtrl::UserBaseInfoRead()//�û���Ϣ��ѯ
{
	m_strCmd.Format(_T("%d"),cmdUserBaseInfoRead);
	return SendCmd();
}
BOOL CSocketClientCtrl::UserBaseInfoInput(User_BaseInfo  userBaseInfo)//�û���Ϣ�޸�
{
	m_strCmd.Format(_T("%d;'"),cmdUserBaseInfoInput);
	m_strCmd+=userBaseInfo.username; 		//�û�����
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//�Ա�
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birthday; 		//��������
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.job;				//ְҵ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//Ѫ��
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;		//��ͥסַ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//��������
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//������ϵ��
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//������ϵ�˺���
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//��ҩʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//����ʷ
	m_strCmd+=_T("'");

	return SendCmd();
}
//ҽ���б�
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserDoctorInfo(int queType, CString  queText)	//ҽ����Ϣ��ѯ
{
	CString strTemp;
	m_strCmd.Format(_T("%d;"),cmdUserDoctorInfo);
	strTemp.Format(_T("%d;"),queType);
	m_strCmd+=strTemp;
	//m_strCmd+=_T(";");
	m_strCmd+=queText;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserDoctorChoose(CString  doctorCell)//ҽ��ѡ��
{	
	m_strCmd.Format(_T("%d;"),cmdUserDoctorChoose);
	m_strCmd+=doctorCell;
	return SendCmd();
}

//�ҵ�ҽ����Ϣ��
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserDocInfo()	//�ҵ�ר����Ϣ
{	
	m_strCmd.Format(_T("%d"),cmdUserDocInfo);
	return SendCmd();
}

//�������������Ϣ��
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserHealthInfoInput(User_HealInfo userHealthInfo)	//������Ϣ¼��
{	
	m_strCmd.Format(_T("%d;"),cmdUserHealInfoInput);
	
	m_strCmd+=_T("'");
	m_strCmd+=userHealthInfo.date_time.Format("%Y-%m-%d %H:%M:%S");		//�ļ��ϴ�ʱ�� 2013-10-30
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.weight;	//����
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.height;		//���
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.systolic;		//����ѹ
// 	m_strCmd+=_T(",");
// 	m_strCmd+=userHealthInfo.BMIindex;	//����ó���BMIֵ
// 	m_strCmd+=_T("','");
// 	m_strCmd+=userHealthInfo.waistline;	//��Χ
// 	m_strCmd+=_T("','");
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.diastolic;	//����ѹ
	m_strCmd+=_T("','");
/*	m_strCmd+=userHealthInfo.systolic;		//����ѹ*/
	m_strCmd+=userHealthInfo.sugar;		//Ѫ��
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.oxygen;		//Ѫ�����Ͷ�
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.oxygen3;     //���ʣ�Ѫ��ָ�꣩
	m_strCmd+=_T("','");
	m_strCmd+=userHealthInfo.rate;		//����
    m_strCmd+=_T("'");
// 	m_strCmd+=userHealthInfo.UA;		//����
// 	m_strCmd+=_T("','");
// 	m_strCmd+=userHealthInfo.filepath;//�ĵ��ļ�·��
// 	m_strCmd+=_T(",");
// 	m_strCmd+=userHealthInfo.filename;//�ĵ��ļ�����
// 	m_strCmd+=_T(",");
	

	return SendCmd();
}

//��¼��
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserLogOn(CString cellNumber,CString password)//����У�飨��¼��
{	
	m_strCmd.Format(_T("%d;"),cmdUserLogOn);
	m_strCmd+=cellNumber;
	m_strCmd+=_T(";");
	m_strCmd+=password;
	return SendCmd();
}

//ƽ̨ʹ�������
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserPlatInfoRead()//ƽ̨ʹ�������ѯ
{
	m_strCmd.Format(_T("%d"),cmdUserPlatInfoRead);
	return SendCmd();
}

//ע�᣺
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserRegVery(CString userCellNum) 	//�û�ע�������֤�����к�Ϊ�գ�
{	
	m_strCmd.Format(_T("%d;"),cmdUserRegVery);
	m_strCmd+=userCellNum;	
	return SendCmd();
}
BOOL CSocketClientCtrl::UserRegVery1(CString userCellNum, CString userSerialNum)//�û�ע�������֤�����кŲ�Ϊ�գ�	
{	
	m_strCmd.Format(_T("%d;"),cmdUserRegVery1);
	m_strCmd+=userCellNum;
	m_strCmd+=_T(";");
	m_strCmd+=userSerialNum;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserReg(User_BaseInfo userBaseInfo)//�����û�ע��
{	
	m_strCmd.Format(_T("%d;"),cmdUserReg);

	


// 	m_strCmd+=userBaseInfo.cellnumber; 		//�ֻ���
// 	m_strCmd+=_T("','1','");
// 	m_strCmd+=userBaseInfo.password;		//����
// 	m_strCmd+=_T("','");	
// 	m_strCmd+=userBaseInfo.username; 		//�û�����
// 	m_strCmd+=_T("','");
// 	m_strCmd+=userBaseInfo.gender;			//�Ա�
// 	m_strCmd+=_T("','");
// 	m_strCmd+=_T("'");

	m_strCmd+=userBaseInfo.username; 		//�û�����
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//�Ա�
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birthday; 			//���䣨�о��ó������±ȽϺã�  �����ʼû��Ҫ�ˣ���Ϊ���֤����������
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.cellnumber; 	//�ֻ���
	m_strCmd+=_T("','0','");
	m_strCmd+=userBaseInfo.password;		//����
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.job;				//ְҵ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//Ѫ��
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;	//��ͥסַ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//���֤����
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//������ϵ��
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//������ϵ�˺���
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//��ҩʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//����ʷ
	m_strCmd+=_T("'");





	return SendCmd();
}
BOOL CSocketClientCtrl::UserReg1(User_BaseInfo userBaseInfo, CString userSerialNum)	//�����û�ע��
{	
	m_strCmd.Format(_T("%d;"),cmdUserReg1);

	m_strCmd+=userBaseInfo.username; 		//�û�����
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//�Ա�
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birthday; 			//���䣨�о��ó������±ȽϺã�  �����ʼû��Ҫ�ˣ���Ϊ���֤����������
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.cellnumber; 	//�ֻ���
	m_strCmd+=_T("','1','");
	m_strCmd+=userBaseInfo.password;		//����
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.job;				//ְҵ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//Ѫ��
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;	//��ͥסַ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//���֤����
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//������ϵ��
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//������ϵ�˺���
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//��ҩʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//����ʷ
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//����ʷ
	m_strCmd+=_T("'");
	//m_strCmd+=userSerialNum;

	return SendCmd();
}

//�һ����룺
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserVeriCodeSend(CString strCell)//���������һ�
{	
	m_strCmd.Format(_T("%d;"),cmdUserVeriCodeSend);	
	m_strCmd+=strCell;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserVeriCodeSubmit(CString veryCode)//�ύ��֤��
{	
	m_strCmd.Format(_T("%d;"),cmdUserVeriCodeSubmit);
	m_strCmd+=veryCode;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserPWResetCode(CString strCell,CString password)	//�������ã������룩
{	
	m_strCmd.Format(_T("%d;"),cmdUserPWResetCode);
	m_strCmd+=strCell;
	m_strCmd+=_T(";");
	m_strCmd+=password;
	return SendCmd();
}

//��ӭҳ�棺
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserWel()//��ӭ��Ϣ��ѯ
{	
	m_strCmd.Format(_T("%d"),cmdUserWel);
	return SendCmd();
}

//���������Ϣ��
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserLatestHealRead()//�������ָ��
{
	m_strCmd.Format(_T("%d"),cmdUserLatestHealRead);
	return SendCmd();
}
//��ʷ������Ϣ��
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserHisHealRead(CString Type,CString startTime,CString endTime)//��ʷ������Ϣ��ѯ
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

//�����ѯ��
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserRepRead(CString repType, CString startTime, CString endTime)//�����ѯ
{
	m_strCmd.Format(_T("%d;"),cmdUserRepRead);
	m_strCmd+=repType;
	m_strCmd+=_T(";");
	m_strCmd+=startTime;//.Format("%Y-%m-%d");
	m_strCmd+=_T(";");
	m_strCmd+=endTime;//.Format("%Y-%m-%d");
	return SendCmd();
}

//�쳣��Ϣ��ѯ��
BOOL CSocketClientCtrl::UserExcepRead(CString startTime, CString endTime)//�쳣��Ϣ��ѯ
{
	m_strCmd.Format(_T("%d;"),cmdUserExcepRead);
// 	m_strCmd+=_T("2013-12-01;");
// 	m_strCmd+=_T("2014-12-17");
 	m_strCmd+=startTime;//.Format("%Y-%m-%d %H:%M:%S;");
	m_strCmd+=_T(";");
 	m_strCmd+=endTime;//.Format("%Y-%m-%d %H:%M:%S");
	return SendCmd();
}

//�޸����룺
BOOL CSocketClientCtrl::UserSendCode()//��������
{	
	m_strCmd.Format(_T("%d"),cmdUserSendCode);
	return SendCmd();
}
BOOL CSocketClientCtrl::UserSubCode(CString code)//�ύ��֤��
{
	m_strCmd.Format(_T("%d;"),cmdUserSubCode);
	m_strCmd+=code;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserNewPass(CString newPasscode)//�ύ������
{	
	m_strCmd.Format(_T("%d;"),cmdUserNewPass);
	m_strCmd+=newPasscode;
	return SendCmd();
}

//��Ϣ�Ķ���
//�û��ˡ�>������
BOOL CSocketClientCtrl::UserMessRead(CString startTime,CString endTime)//��Ϣ�Ķ�
{
	m_strCmd.Format(_T("%d;"),cmdUserMessRead);
	m_strCmd+=startTime;
	m_strCmd+=_T(";");
	m_strCmd+=endTime;
	return SendCmd();
}
BOOL CSocketClientCtrl::UserMessSend(CString docCell, CString message)	 //������Ϣ	
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