#pragma once
#include "afxext.h"
class CMySplitterWnd :
	public CSplitterWnd
{
public:
	CMySplitterWnd(void);
	~CMySplitterWnd(void);
	virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

