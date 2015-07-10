#include "StdAfx.h"
#include "FTPCtrl.h"

CFTPCtrl::CFTPCtrl(void)
{
}

CFTPCtrl::~CFTPCtrl(void)
{
	InternetCloseHandle(m_hSsetion);
	InternetCloseHandle(m_hConnect);
}

BOOL CFTPCtrl::FtpOpen()
{
	m_hSsetion= InternetOpen( _T("FtpClient"),INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0 );
	if ( NULL ==m_hSsetion )
	{
		AfxMessageBox(_T("FtpOpen failed"));
		return FALSE;
	}
	else
		return TRUE;
}

BOOL CFTPCtrl::FtpConnect(CString IPAddress,INTERNET_PORT FtpPort,CString FtpUserName,CString FtpPassWord)
{
	m_hConnect = InternetConnect( m_hSsetion, IPAddress,FtpPort,FtpUserName,FtpPassWord,
														INTERNET_SERVICE_FTP ,INTERNET_FLAG_PASSIVE, 0 );
	if ( NULL == m_hConnect )
	{
		AfxMessageBox(_T("Ftp connect failed"));
		return FALSE;
	}
	else
		return TRUE;
}

BOOL CFTPCtrl::FtpUploadFile(CString filePath)
{
	HANDLE hOpenFile = (HANDLE)CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	if(hOpenFile==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox(_T("���ļ�ʧ�ܣ������ļ�·��������!"));
		CloseHandle(hOpenFile);
		return FALSE;
	}

	CString fileName = GetFileName(filePath);

	HINTERNET hFtpOpen = FtpOpenFile( m_hConnect,fileName, GENERIC_WRITE, FTP_TRANSFER_TYPE_ASCII, 0 );
	if ( NULL == hFtpOpen )
	{
		AfxMessageBox(_T("FtpԶ���ļ���ʧ�ܣ�"));
		return FALSE;
	}
	
	DWORD fileSize=GetFileSize(hOpenFile,NULL);
	char *buffer=new char[fileSize];//���һλΪ'/0',C-Style�ַ����Ľ�������
	DWORD readSize;
	if (FALSE==ReadFile(hOpenFile,buffer,fileSize,&readSize,NULL))
	{
		AfxMessageBox(_T("��ȡ�����ļ�ʧ�ܣ�"));
		return FALSE;
	}	
	DWORD dwBytesWritten;
	if (FALSE==InternetWriteFile(  hFtpOpen, buffer,fileSize,&dwBytesWritten))
	{
		AfxMessageBox(_T("�ϴ��ļ�ʧ�ܣ�"));
		return FALSE;
	}

	CloseHandle( hOpenFile );
	InternetCloseHandle(hFtpOpen);
	return TRUE;

}

BOOL CFTPCtrl::FtpDownloadFile(CString ftpFileName,CString localFilePath)
{
	//localFilePath=CreateFilePath(ftpFileName,localFilePath);
	HANDLE hOpenFile = (HANDLE)CreateFile(localFilePath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, NULL, NULL);
	if(hOpenFile==INVALID_HANDLE_VALUE)
	{		
		if (IDYES==AfxMessageBox(_T("���������ļ�ʧ�ܣ�ָ��·���¿����Ѵ���ͬ���ļ����Ƿ񸲸�?"),MB_YESNO))
		{
			hOpenFile = (HANDLE)CreateFile(localFilePath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);
			if(hOpenFile==INVALID_HANDLE_VALUE)
			{		
				AfxMessageBox(_T("���������ļ�ʧ��,������ѡ���ļ�·��������!"));
				CloseHandle(hOpenFile);//һ��ע���ں����˳�֮ǰ�Ծ�������ͷš�
				return FALSE;	
			}
		}
		else
		{
			AfxMessageBox(_T("�����ļ�ʧ��!"));
			CloseHandle(hOpenFile);//һ��ע���ں����˳�֮ǰ�Ծ�������ͷš�
			return FALSE;
		}		
	}

	HINTERNET hFtpOpen = FtpOpenFile( m_hConnect, ftpFileName, GENERIC_READ, FTP_TRANSFER_TYPE_ASCII, 0 );
	if ( NULL == hFtpOpen )
	{
		AfxMessageBox(_T("FtpԶ���ļ���ʧ�ܣ�"));
		return FALSE;
	}
	
	DWORD fileSize=	FtpGetFileSize(hFtpOpen,NULL);//���ֵ���ֻ�ܻ�ȡ4GB���ڵ��ļ���FtpGetFileSize�ú����ڶ�������64λ�ļ���С�ĸ�32λ��
	DWORD readSize;
	char *buffer=new char[fileSize];	
	if (FALSE==InternetReadFile(hFtpOpen,buffer,fileSize,&readSize))
	{
		AfxMessageBox(_T("��ȡFtp�ļ�ʧ�ܣ�"));
		return FALSE;
	}

	DWORD dwBytesWritten;
	if (FALSE==WriteFile(  hOpenFile, buffer,fileSize,&dwBytesWritten,NULL))
	{
		AfxMessageBox(_T("�����ļ�ʧ�ܣ�"));
		return FALSE;
	}

	CloseHandle( hOpenFile );
	InternetCloseHandle(hFtpOpen);
	return TRUE;

}

CString CFTPCtrl::GetFileName(CString filePath)
{
	int index=filePath.ReverseFind('\\');
	if (-1!=index)
	{
		return filePath.Right(filePath.GetLength()-index-1);
	}
	else
		return _T("");
}

CString CFTPCtrl::CreateFilePath(CString ftpFileName,CString localFilePath)
{
	localFilePath+=_T("\\");
	return localFilePath+ftpFileName;
}