// WinDeKikaigoV2View.cpp : CWinDeKikaigoV2View クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "WinDeKikaigoV2Doc.h"
#include "WinDeKikaigoV2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View

IMPLEMENT_DYNCREATE(CWinDeKikaigoV2View, CView)

BEGIN_MESSAGE_MAP(CWinDeKikaigoV2View, CView)
	//{{AFX_MSG_MAP(CWinDeKikaigoV2View)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View クラスの構築/消滅

CWinDeKikaigoV2View::CWinDeKikaigoV2View()
{
	// TODO: この場所に構築用のコードを追加してください。

}

CWinDeKikaigoV2View::~CWinDeKikaigoV2View()
{
}

BOOL CWinDeKikaigoV2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View クラスの描画

void CWinDeKikaigoV2View::OnDraw(CDC* pDC)
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
	pDC->TextOut(0, 0, L"こんにちは★★★");
}

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View クラスの診断

#ifdef _DEBUG
void CWinDeKikaigoV2View::AssertValid() const
{
	CView::AssertValid();
}

void CWinDeKikaigoV2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinDeKikaigoV2Doc* CWinDeKikaigoV2View::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoV2Doc)));
	return (CWinDeKikaigoV2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View クラスのメッセージ ハンドラ

