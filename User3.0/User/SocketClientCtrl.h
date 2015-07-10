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

	//��ҩ����
	//�û��ˡ�>������
	BOOL UserDrugRead(CString startTime,CString endTime); //��ҩ��ѯ
	BOOL UserDrugUpdate(vector<User_DrugInfo> userDrugInfo);//��ҩ����

	//�޸ĸ�����Ϣ
	//�û��ˡ�>������
	BOOL UserBaseInfoRead();//�û���Ϣ��ѯ
	BOOL UserBaseInfoInput(User_BaseInfo  userBaseInfo);//�û���Ϣ�޸�

	//ҽ���б�
	//�û��ˡ�>������
	BOOL UserDoctorInfo(int queType, CString  queText);	//ҽ����Ϣ��ѯ
	BOOL UserDoctorChoose(CString  doctorCell);//ҽ��ѡ��

	//�ҵ�ҽ����Ϣ��
	//�û��ˡ�>������
	BOOL UserDocInfo();	//�ҵ�ר����Ϣ

	//�������������Ϣ��
	//�û��ˡ�>������
	BOOL UserHealthInfoInput(User_HealInfo userHealthInfo);	//������Ϣ¼��

	//��¼��
	//�û��ˡ�>������
	BOOL UserLogOn(CString cellNumber,CString password);//����У�飨��¼��

	//ƽ̨ʹ�������
	//�û��ˡ�>������
	BOOL UserPlatInfoRead();//ƽ̨ʹ�������ѯ

	//ע�᣺
	//�û��ˡ�>������
	BOOL UserRegVery(CString userCellNum); 	//�û�ע�������֤�����к�Ϊ�գ�
	BOOL UserRegVery1(CString userCellNum, CString userSerialNum);//�û�ע�������֤�����кŲ�Ϊ�գ�	
	BOOL UserReg(User_BaseInfo userBaseInfo);//�����û�ע��	
	BOOL UserReg1(User_BaseInfo userBaseInfo, CString userSerialNum);	//�����û�ע��

	//��������ʱ�һ����룺
	//�û��ˡ�>������
	BOOL UserVeriCodeSend(CString strCell);//������֤�뵽�ֻ�
	BOOL UserVeriCodeSubmit(CString veryCode);//�ύ��֤��
	BOOL UserPWResetCode(CString strCell,CString password);	//�������ã������룩

	//��ӭҳ�棺
	//�û��ˡ�>������
	BOOL UserWel();//��ӭ��Ϣ��ѯ

	//���������Ϣ��
	//�û��ˡ�>������
	BOOL UserLatestHealRead();//�������ָ��
	//	��̬Ѫѹ�Ͷ�̬�ĵ�	����������������������		

	//��ʷ������Ϣ��
	//�û��ˡ�>������
	BOOL UserHisHealRead(CString Type,CString startTime, CString endTime);//��ʷ������Ϣ��ѯ

	//�����ѯ��
	//�û��ˡ�>������
	BOOL UserRepRead(CString repType, CString startTime, CString endTime);//�����ѯ

	//�쳣��Ϣ��ѯ��
	//�û��ˡ�>������
	BOOL UserExcepRead(CString startTime, CString endTime);//�쳣��Ϣ��ѯ

	//�������ã�
	//�û��ˡ�>������
	BOOL UserSendCode();//������֤�뵽�ֻ�
	BOOL UserSubCode(CString code);//�ύ��֤��
	BOOL UserNewPass(CString newPasscode);//�ύ������

	//��Ϣ�Ķ���
	//�û��ˡ�>������
	BOOL UserMessRead(CString startTime,CString endTime);//��Ϣ�Ķ�
	BOOL UserMessSend(CString docCell, CString message);	 //������Ϣ	

	BOOL UserUploadFile(CString fileName);

	//��ѯ�ĵ�ͼ����
	BOOL UserHrtRepRead();

	BOOL UserMessNoToYes(CString time,CString SenderID);//����δ����ϢΪ�Ѷ�״̬
	BOOL UserRepNoToYes(CString time,CString reptype); //����δ������Ϊ�Ѷ�״̬
	
};
