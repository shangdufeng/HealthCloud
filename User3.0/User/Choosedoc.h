#pragma once


// CChoosedoc 对话框

class CChoosedoc : public CDialog
{
	DECLARE_DYNAMIC(CChoosedoc)

public:
	CChoosedoc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChoosedoc();

// 对话框数据
	enum { IDD = IDD_RIGHT_INVIDOC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
