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
		AfxMessageBox(_T("打开文件失败，请检查文件路径后重试!"));
		CloseHandle(hOpenFile);
		return FALSE;
	}

	CString fileName = GetFileName(filePath);

	HINTERNET hFtpOpen = FtpOpenFile( m_hConnect,fileName, GENERIC_WRITE, FTP_TRANSFER_TYPE_ASCII, 0 );
	if ( NULL == hFtpOpen )
	{
		AfxMessageBox(_T("Ftp远程文件打开失败！"));
		return FALSE;
	}
	
	DWORD fileSize=GetFileSize(hOpenFile,NULL);
	char *buffer=new char[fileSize];//最后一位为'/0',C-Style字符串的结束符。
	DWORD readSize;
	if (FALSE==ReadFile(hOpenFile,buffer,fileSize,&readSize,NULL))
	{
		AfxMessageBox(_T("读取本地文件失败！"));
		return FALSE;
	}	
	DWORD dwBytesWritten;
	if (FALSE==InternetWriteFile(  hFtpOpen, buffer,fileSize,&dwBytesWritten))
	{
		AfxMessageBox(_T("上传文件失败！"));
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
		if (IDYES==AfxMessageBox(_T("创建本地文件失败，指定路径下可能已存在同名文件，是否覆盖?"),MB_YESNO))
		{
			hOpenFile = (HANDLE)CreateFile(localFilePath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);
			if(hOpenFile==INVALID_HANDLE_VALUE)
			{		
				AfxMessageBox(_T("创建本地文件失败,请重新选择文件路径后重试!"));
				CloseHandle(hOpenFile);//一定注意在函数退出之前对句柄进行释放。
				return FALSE;	
			}
		}
		else
		{
			AfxMessageBox(_T("下载文件失败!"));
			CloseHandle(hOpenFile);//一定注意在函数退出之前对句柄进行释放。
			return FALSE;
		}		
	}

	HINTERNET hFtpOpen = FtpOpenFile( m_hConnect, ftpFileName, GENERIC_READ, FTP_TRANSFER_TYPE_ASCII, 0 );
	if ( NULL == hFtpOpen )
	{
		AfxMessageBox(_T("Ftp远程文件打开失败！"));
		return FALSE;
	}
	
	DWORD fileSize=	FtpGetFileSize(hFtpOpen,NULL);//这种调用只能获取4GB以内的文件，FtpGetFileSize该函数第二个参数64位文件大小的高32位。
	DWORD readSize;
	char *buffer=new char[fileSize];	
	if (FALSE==InternetReadFile(hFtpOpen,buffer,fileSize,&readSize))
	{
		AfxMessageBox(_T("读取Ftp文件失败！"));
		return FALSE;
	}

	DWORD dwBytesWritten;
	if (FALSE==WriteFile(  hOpenFile, buffer,fileSize,&dwBytesWritten,NULL))
	{
		AfxMessageBox(_T("下载文件失败！"));
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