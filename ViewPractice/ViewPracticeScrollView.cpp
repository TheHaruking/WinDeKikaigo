// ViewPracticeScrollView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "ViewPractice.h"
#include "ViewPracticeScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView

IMPLEMENT_DYNCREATE(ViewPracticeScrollView, CScrollView)

ViewPracticeScrollView::ViewPracticeScrollView()
{
}

ViewPracticeScrollView::~ViewPracticeScrollView()
{
}

BEGIN_MESSAGE_MAP(ViewPracticeScrollView, CScrollView)
	//{{AFX_MSG_MAP(ViewPracticeScrollView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView 描画

void ViewPracticeScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: このビュー全体のサイズを計算してください。
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void ViewPracticeScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView 診断

#ifdef _DEBUG
void ViewPracticeScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void ViewPracticeScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView メッセージ ハンドラ
