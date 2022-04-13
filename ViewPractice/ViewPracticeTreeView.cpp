// ViewPracticeTreeView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView

IMPLEMENT_DYNCREATE(CViewPracticeTreeView, CTreeView)

CViewPracticeTreeView::CViewPracticeTreeView()
{
}

CViewPracticeTreeView::~CViewPracticeTreeView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeTreeView, CTreeView)
	//{{AFX_MSG_MAP(CViewPracticeTreeView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView 描画

void CViewPracticeTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView 診断

#ifdef _DEBUG
void CViewPracticeTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CViewPracticeTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView メッセージ ハンドラ
