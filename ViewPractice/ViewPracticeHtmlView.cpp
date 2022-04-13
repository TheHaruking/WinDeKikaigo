// ViewPracticeHtmlView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeHtmlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView

IMPLEMENT_DYNCREATE(CViewPracticeHtmlView, CHtmlView)

CViewPracticeHtmlView::CViewPracticeHtmlView()
{
	//{{AFX_DATA_INIT(CViewPracticeHtmlView)
		// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

CViewPracticeHtmlView::~CViewPracticeHtmlView()
{
}

void CViewPracticeHtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewPracticeHtmlView)
		// メモ: ClassWizard はこの位置に DDX と DDV の呼び出しコードを追加します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewPracticeHtmlView, CHtmlView)
	//{{AFX_MSG_MAP(CViewPracticeHtmlView)
		// メモ: ClassWizard はこの位置にメッセージ マップ マクロを追加します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView diagnostics

#ifdef _DEBUG
void CViewPracticeHtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CViewPracticeHtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView message handlers
