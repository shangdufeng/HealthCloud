
// UserView.cpp : CUserView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "User.h"
#endif

#include "UserDoc.h"
#include "UserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUserView

IMPLEMENT_DYNCREATE(CUserView, CView)

BEGIN_MESSAGE_MAP(CUserView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUserView ����/����

CUserView::CUserView()
{
	// TODO: �ڴ˴���ӹ������

}

CUserView::~CUserView()
{
}

BOOL CUserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// CUserView ����

void CUserView::OnDraw(CDC* /*pDC*/)
{
	CUserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CUserView ��ӡ

BOOL CUserView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CUserView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CUserView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CUserView ���

#ifdef _DEBUG
void CUserView::AssertValid() const
{
	CView::AssertValid();
}

void CUserView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserDoc* CUserView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserDoc)));
	return (CUserDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserView ��Ϣ�������
