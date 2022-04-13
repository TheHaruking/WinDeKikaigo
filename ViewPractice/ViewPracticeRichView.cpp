// ViewPracticeRichView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "ViewPractice.h"
#include "ViewPracticeRichView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView

IMPLEMENT_DYNCREATE(CViewPracticeRichView, CRichEditView)

CViewPracticeRichView::CViewPracticeRichView()
{
}

CViewPracticeRichView::~CViewPracticeRichView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeRichView, CRichEditView)
	//{{AFX_MSG_MAP(CViewPracticeRichView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView 描画

void CViewPracticeRichView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView 診断

#ifdef _DEBUG
void CViewPracticeRichView::AssertValid() const
{
	CView::AssertValid();
}

void CViewPracticeRichView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView メッセージ ハンドラ
