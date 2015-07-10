#pragma once
#include "wininet.h"

class CFTPCtrl
{
public:
	CFTPCtrl(void);
	~CFTPCtrl(void);

	BOOL FtpOpen();
	BOOL FtpConnect(CString IPAddress,INTERNET_PORT FtpPort,CString FtpUserName,CString FtpPassWord);

	BOOL FtpUploadFile(CString filePath);

	BOOL FtpDownloadFile(CString ftpFileName,CString localFilePath);

private:
	HANDLE m_hOpenFile;
	HINTERNET m_hSsetion;
	HINTERNET m_hConnect;

	CString GetFileName(CString filePath);
	CString CreateFilePath(CString ftpFileName,CString localFilePath);
	

};
