
// UserView.cpp : CUserView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUserView 构造/析构

CUserView::CUserView()
{
	// TODO: 在此处添加构造代码

}

CUserView::~CUserView()
{
}

BOOL CUserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// CUserView 绘制

void CUserView::OnDraw(CDC* /*pDC*/)
{
	CUserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CUserView 打印

BOOL CUserView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CUserView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CUserView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CUserView 诊断

#ifdef _DEBUG
void CUserView::AssertValid() const
{
	CView::AssertValid();
}

void CUserView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserDoc* CUserView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserDoc)));
	return (CUserDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserView 消息处理程序
