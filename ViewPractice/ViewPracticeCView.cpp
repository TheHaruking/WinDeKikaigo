// ViewPracticeCView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView

IMPLEMENT_DYNCREATE(CViewPracticeCView, CView)

CViewPracticeCView::CViewPracticeCView()
{
}

CViewPracticeCView::~CViewPracticeCView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeCView, CView)
	//{{AFX_MSG_MAP(CViewPracticeCView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView 描画

void CViewPracticeCView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView 診断

#ifdef _DEBUG
void CViewPracticeCView::AssertValid() const
{
	CView::AssertValid();
}

void CViewPracticeCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView メッセージ ハンドラ
