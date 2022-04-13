// ViewPracticeView.cpp : CViewPracticeView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "ViewPractice.h"

#include "ViewPracticeDoc.h"
#include "ViewPracticeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView

IMPLEMENT_DYNCREATE(CViewPracticeView, CEditView)

BEGIN_MESSAGE_MAP(CViewPracticeView, CEditView)
	//{{AFX_MSG_MAP(CViewPracticeView)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView クラスの構築/消滅

CViewPracticeView::CViewPracticeView()
{
	// TODO: この場所に構築用のコードを追加してください。

}

CViewPracticeView::~CViewPracticeView()
{
}

BOOL CViewPracticeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ワード ラップを使用可能にします

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView クラスの描画

void CViewPracticeView::OnDraw(CDC* pDC)
{
	CViewPracticeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView クラスの診断

#ifdef _DEBUG
void CViewPracticeView::AssertValid() const
{
	CEditView::AssertValid();
}

void CViewPracticeView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CViewPracticeDoc* CViewPracticeView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewPracticeDoc)));
	return (CViewPracticeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView クラスのメッセージ ハンドラ

void CViewPracticeView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	// 
	CEdit& edit = GetEditCtrl();
	edit.SetWindowText(L"XX XX XX XX\r\nXX XX XX XX\r\n");
}

CPoint	g_ptChar;
INT	g_nChar;

void CViewPracticeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CEdit& edit = GetEditCtrl();
	CString buf;
	buf.Format(L"nChar : %ld\r\n", nChar);
	OutputDebugString(buf);
	
	switch (nChar) {
	case VK_LEFT:
//		edit.SetCaretPos(CPoint(1,0));
		g_nChar--;
		edit.SetSel(g_nChar, g_nChar);
		break;

	case VK_RIGHT:
		g_nChar++;		
		edit.SetSel(g_nChar, g_nChar);
		break;
	
	case VK_UP:
		break;
	
	case VK_DOWN:
		break;
	
	case 'Q':
		g_nChar = 0;
		edit.SetSel(g_nChar, g_nChar);
		break;
	
	case 'W': {
		int nCharPos = edit.CharFromPos(CPoint(20, 10));
		CPoint pos = edit.PosFromChar('X');
		buf.Format(L"CharFromPos: %ld\r\nCPoint.x: %d\r\n", nCharPos, pos.x);
		OutputDebugString(buf);
		break;
	}
	
	default:
		CEditView::OnKeyDown(nChar, nRepCnt, nFlags);
		return;
	}
}

void CViewPracticeView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CString buf;
	buf.Format(L"OnChar: %ld\r\n", nChar);
	OutputDebugString(buf);

	switch (nChar) {
	case 'q':
	case 'w':
		return;
	default:
		CEditView::OnChar(nChar, nRepCnt, nFlags);
		break;
	}
}
