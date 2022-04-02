// RightView.cpp : CRightView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigo.h"

#include "WinDeKikaigoDoc.h"
#include "RightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightView

IMPLEMENT_DYNCREATE(CRightView, CListView)

BEGIN_MESSAGE_MAP(CRightView, CListView)
	//{{AFX_MSG_MAP(CRightView)
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightView クラスの構築/消滅

// *****************************************
// ※ テスト用クラス (未使用！)
// *****************************************
CRightView::CRightView()
{
}

CRightView::~CRightView()
{
}

BOOL CRightView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRightView クラスの描画

void CRightView::OnDraw(CDC* pDC)
{
	CWinDeKikaigoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, L"Item!");
}

void CRightView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CRightView クラスの印刷

BOOL CRightView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CRightView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CRightView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CRightView クラスの診断

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CListView::AssertValid();
}

void CRightView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CWinDeKikaigoDoc* CRightView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRightView クラスのメッセージ ハンドラ
void CRightView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
}
