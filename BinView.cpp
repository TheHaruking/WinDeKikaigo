// BinView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "WinDeKikaigo.h"
#include "WinDeKikaigoDoc.h"
#include "BinView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBinView

IMPLEMENT_DYNCREATE(CBinView, CEditView)

/***************************************************************************/
// バイナリで表示 / 編集する View クラス
/***************************************************************************/
CBinView::CBinView()
{
}

CBinView::~CBinView()
{
}

BEGIN_MESSAGE_MAP(CBinView, CEditView)
	//{{AFX_MSG_MAP(CBinView)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinView 描画

void CBinView::OnDraw(CDC* pDC)
{
//	CDocument* pDoc = GetDocument();
	CWinDeKikaigoDoc* pDoc = GetDocument();

	// 初期化テスト！
	CEdit& edit = GetEditCtrl();
	CString buf;
	BYTE* testBytes = pDoc->testBytes;
	buf.Format(L"%02X %02X %02X %02X ",
		testBytes[0], testBytes[1], testBytes[2], testBytes[3]);
	edit.SetWindowText(buf);
}

/////////////////////////////////////////////////////////////////////////////
// CBinView 診断

#ifdef _DEBUG
void CBinView::AssertValid() const
{
	CEditView::AssertValid();
}

void CBinView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

// 追加！
CWinDeKikaigoDoc* CBinView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBinView メッセージ ハンドラ

BOOL CBinView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// ビューのフォントを SYSTEM_FIXED_FONT に変更します
	CFont *font = CFont::FromHandle((HFONT)::GetStockObject(SYSTEM_FIXED_FONT));
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
	SetFont(font);

	return bResult;
}

void CBinView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();

	// 初期化テスト！
	CEdit& edit = GetEditCtrl();
	CString buf;
	BYTE* testBytes = pDoc->testBytes;

	// 文字列処理
	buf.Format(L"%02X %02X %02X %02X ",
		testBytes[0], testBytes[1], testBytes[2], testBytes[-1]);

	// UI に反映
	edit.SetWindowText(buf);
}

void CBinView::OnChange() // EN_CHANGE
{
	CEdit& edit = GetEditCtrl();

	CPoint point = edit.GetCaretPos();
	INT lineCount = edit.GetLineCount();
	INT lineIndex = edit.LineIndex();

	CString buf;
	buf.Format(L"x:%d, y:%d, line:%d, index:%d\r\n", point.x, point.y, lineCount, lineIndex);
	OutputDebugString(buf);
}

void CBinView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
/*
	0-9,a-f, ↑↓←→		
*/
	CString buf;
	buf.Format(L"cChar: %lc\r\n", nChar);
	OutputDebugString(buf);

	switch (nChar) {
	case VK_LEFT:
		break;
	default:
		break;
	}
//	CEditView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CBinView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar) {
	default:
		return;
	}
//	CEditView::OnChar(nChar, nRepCnt, nFlags);
}

LRESULT CBinView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	switch (message) {
	case WM_PASTE:
		MessageBox(L"Hello!");
		return TRUE;
	}
	
	return CEditView::WindowProc(message, wParam, lParam);
}
