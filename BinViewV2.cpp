// BinViewV2.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "WinDeKikaigoDoc.h"
#include "BinViewV2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2

IMPLEMENT_DYNCREATE(CBinViewV2, CView)

CBinViewV2::CBinViewV2()
{
}

CBinViewV2::~CBinViewV2()
{
}


BEGIN_MESSAGE_MAP(CBinViewV2, CView)
	//{{AFX_MSG_MAP(CBinViewV2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 描画

void CBinViewV2::OnDraw(CDC* pDC)
{
	CWinDeKikaigoDoc* pDoc = GetDocument();

	// TODO: この位置に描画用のコードを追加してください
	CFont* pFontOld;
	pFontOld = pDC->SelectObject(&m_font);

	// 初期化テスト！
	DWORD NEXT = m_fontHeight + m_fontRowMargin;
	DWORD ofs = 0;
	DWORD height = 0;

	CString buf;
	BYTE* b = pDoc->testBytes;

	for (int i = 0; i < 8; i++) {
		ofs = i*m_dwMaxColumn;
		switch (m_dwMaxColumn) {
		case  1: buf.Format(L"%02X", b[ofs+0]); break;
		case  2: buf.Format(L"%02X %02X", b[ofs+0], b[ofs+1]); break;
		case  3: buf.Format(L"%02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2]); break;
		case  4: buf.Format(L"%02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3]); break;
		case  5: buf.Format(L"%02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4]); break;
		case  6: buf.Format(L"%02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5]); break;
		case  7: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6]); break;
		case  8: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7]); break;
		case  9: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8]); break;
		case 10: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9]); break;
		case 11: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10]); break;
		case 12: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11]); break;
		case 13: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12]); break;
		case 14: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12], b[ofs+13]); break;
		case 15: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12], b[ofs+13], b[ofs+14]); break;
		case 16: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12], b[ofs+13], b[ofs+14], b[ofs+15]); break;
		}
		pDC->TextOut(0, height, buf);
		height += NEXT;
	}

	// 後処理
	pDC->SelectObject(&m_font);
}

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 診断

#ifdef _DEBUG
void CBinViewV2::AssertValid() const
{
	CView::AssertValid();
}

void CBinViewV2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// 追加！
CWinDeKikaigoDoc* CBinViewV2::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 メッセージ ハンドラ

BOOL CBinViewV2::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// ビューのフォントを SYSTEM_FIXED_FONT に変更します
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// メンバ初期化
	m_fontHeight = 16;
//	m_fontWidth = 8; // m_font.CreateFont 関数後に取得する.
	m_fontRowMargin = 1;
	m_dwMaxColumn = 4;
	m_dwSel = 0;

	m_font.CreateFont(
		m_fontHeight, 0,	// 高さ、幅
		0, 0, FW_DONTCARE,		// 角度、角度、太さ
		FALSE, FALSE, FALSE,	// 斜体、下線、取消線
		ANSI_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,		// 出力精度
		CLIP_DEFAULT_PRECIS,	// クリッピング精度
		DEFAULT_QUALITY,		// 出力品質
		DEFAULT_PITCH,			// ピッチ
		_T("ＭＳ ゴシック")		// タイプフェイス名
		);

	// 横幅取得
	CDC* pDC = GetDC();
	CFont* oldFont = pDC->SelectObject(&m_font);
	SIZE size;
	::GetTextExtentPointW(pDC->m_hDC, L"0", 1 , &size);
	m_fontWidth = size.cx;
	pDC->SelectObject(&oldFont);
	ReleaseDC(pDC);

	// キャレット
	CreateSolidCaret(0, 16);
	ShowCaret();

	return bResult;
}

void CBinViewV2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();
}

void CBinViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 座標計算
	DWORD x, row, n;
	x = (point.x + m_fontWidth/2) / m_fontWidth;
	x /= 3;	// "XX " を1単位とする
	row = point.y / (m_fontHeight + m_fontRowMargin);
	m_dwSel = row * m_dwMaxColumn + x;
	
	// 出力
	CString buf;
	buf.Format(L"Down! x:%d, y:%d, n:%d, max:%d\r\n", point.x, point.y, n, m_dwMaxColumn);
	OutputDebugString(buf);

	// キャレット設定
	CPoint fixPoint;
	fixPoint.x = (m_dwSel%m_dwMaxColumn) * (m_fontWidth*3);
	fixPoint.y = (m_dwSel/m_dwMaxColumn) * (m_fontHeight+m_fontRowMargin);
	SetFocus();
	SetCaretPos(fixPoint);

	CView::OnLButtonDown(nFlags, point);
}

void CBinViewV2::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	CView::OnLButtonUp(nFlags, point);
}

void CBinViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch (nChar) {
	case '9': m_dwMaxColumn--; break;
	case '0': m_dwMaxColumn++; break;
	}
	RedrawWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
