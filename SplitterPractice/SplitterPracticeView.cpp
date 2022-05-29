// SplitterPracticeView.cpp : CSplitterPracticeView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "SplitterPractice.h"

#include "SplitterPracticeDoc.h"
#include "SplitterPracticeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView

IMPLEMENT_DYNCREATE(CSplitterPracticeView, CListView)

BEGIN_MESSAGE_MAP(CSplitterPracticeView, CListView)
	//{{AFX_MSG_MAP(CSplitterPracticeView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView クラスの構築/消滅

CSplitterPracticeView::CSplitterPracticeView()
{
	// TODO: この場所に構築用のコードを追加してください。

}

CSplitterPracticeView::~CSplitterPracticeView()
{
}

BOOL CSplitterPracticeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView クラスの描画

void CSplitterPracticeView::OnDraw(CDC* pDC)
{
	CSplitterPracticeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, L"Item!");
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

void CSplitterPracticeView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl() メンバ関数の呼び出しを通して直接そのリスト コントロールに
	//  アクセスすることによって ListView をアイテムで固定できます。
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView クラスの診断

#ifdef _DEBUG
void CSplitterPracticeView::AssertValid() const
{
	CListView::AssertValid();
}

void CSplitterPracticeView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CSplitterPracticeDoc* CSplitterPracticeView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitterPracticeDoc)));
	return (CSplitterPracticeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView クラスのメッセージ ハンドラ
void CSplitterPracticeView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	// TODO: ユーザーによるウインドウのビュー スタイル変更に対応するコードを追加してください
}
