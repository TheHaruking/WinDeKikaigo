// ViewPracticeListView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView

IMPLEMENT_DYNCREATE(CViewPracticeListView, CListView)

CViewPracticeListView::CViewPracticeListView()
{
}

CViewPracticeListView::~CViewPracticeListView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeListView, CListView)
	//{{AFX_MSG_MAP(CViewPracticeListView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView 描画

void CViewPracticeListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView 診断

#ifdef _DEBUG
void CViewPracticeListView::AssertValid() const
{
	CListView::AssertValid();
}

void CViewPracticeListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView メッセージ ハンドラ
