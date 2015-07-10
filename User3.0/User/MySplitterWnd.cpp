#include "StdAfx.h"
#include "MySplitterWnd.h"


CMySplitterWnd::CMySplitterWnd(void)
{
}


CMySplitterWnd::~CMySplitterWnd(void)
{
}


void CMySplitterWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pDC==NULL)
	{
		RedrawWindow(rect,NULL,RDW_INVALIDATE|RDW_NOCHILDREN);
		return;
	}
	ASSERT_VALID(pDC);
	CRect rc=rect;
	switch(nType)
	{
	case splitBorder:
		//�ػ��ָ�ڱ߽�
		pDC->FillSolidRect(rc,RGB(220,220,220));
		return;
	case splitBox:
		//pDC->FillSolidRect(rc,RGB(0,0,255));
		return;
	case splitBar:
		//�ػ��ָ���
		pDC->FillSolidRect(rc,RGB(108,106,106));
		return;
	default:
		ASSERT(FALSE);
	}
}
BEGIN_MESSAGE_MAP(CMySplitterWnd, CSplitterWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CMySplitterWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWnd::OnLButtonDown(nFlags, point);
}
