#pragma once


// CChoosedoc �Ի���

class CChoosedoc : public CDialog
{
	DECLARE_DYNAMIC(CChoosedoc)

public:
	CChoosedoc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChoosedoc();

// �Ի�������
	enum { IDD = IDD_RIGHT_INVIDOC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
