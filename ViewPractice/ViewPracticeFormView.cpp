// ViewPracticeFormView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView

IMPLEMENT_DYNCREATE(CViewPracticeFormView, CFormView)

CViewPracticeFormView::CViewPracticeFormView()
	: CFormView(CViewPracticeFormView::IDD)
{
	//{{AFX_DATA_INIT(CViewPracticeFormView)
		// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//}}AFX_DATA_INIT
}

CViewPracticeFormView::~CViewPracticeFormView()
{
}

void CViewPracticeFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewPracticeFormView)
		// メモ: ClassWizard はこの位置に DDX および DDV の呼び出しを追加します
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewPracticeFormView, CFormView)
	//{{AFX_MSG_MAP(CViewPracticeFormView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView 診断

#ifdef _DEBUG
void CViewPracticeFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CViewPracticeFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView メッセージ ハンドラ
