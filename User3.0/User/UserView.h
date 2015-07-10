
// UserView.h : CUserView ��Ľӿ�
//

#pragma once


class CUserView : public CView
{
protected: // �������л�����
	CUserView();
	DECLARE_DYNCREATE(CUserView)

// ����
public:
	CUserDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CUserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UserView.cpp �еĵ��԰汾
inline CUserDoc* CUserView::GetDocument() const
   { return reinterpret_cast<CUserDoc*>(m_pDocument); }
#endif

