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
// 定数
const DWORD CBinViewV2::DATA_KEY2HEX[] = {
	// 0123456789:;<=>?
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0, 0, 0, 0, 0, 0,
	// @ABCDEF
	0, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
const DWORD CBinViewV2::DATA_KEY2HEX10[] = {
	0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0, 0, 0, 0, 0, 0,
	0, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0
};

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
	DWORD NEXT = m_dwFontHeight + m_dwRowMargin;
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
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// メンバ初期化
	m_dwFontHeight = 16;
//	m_dwFontWidth = 8; // m_font.CreateFont 関数後に取得する.
	m_dwRowMargin = 1;
	m_dwMaxColumn = 16;
	m_dwSel = 0;
	m_bIsSecond = FALSE;

	m_font.CreateFont(
		m_dwFontHeight, 0,	// 高さ、幅
		0, 0, FW_DONTCARE,		// 角度、角度、太さ
		FALSE, FALSE, FALSE,	// 斜体、下線、取消線
		ANSI_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,		// 出力精度
		CLIP_DEFAULT_PRECIS,	// クリッピング精度
		DEFAULT_QUALITY,		// 出力品質
		DEFAULT_PITCH,			// ピッチ
		_T("ＭＳ ゴシック")		// タイプフェイス名
		);

	// フォント横幅取得
	CDC* pDC = GetDC();
	CFont* oldFont = pDC->SelectObject(&m_font);
	SIZE size;
	::GetTextExtentPointW(pDC->m_hDC, L"0", 1 , &size);
	m_dwFontWidth = size.cx;
	pDC->SelectObject(&oldFont);
	ReleaseDC(pDC);

	// キャレット
	CreateSolidCaret(0, 16);
	ShowCaret();

	return bResult;
}

void CBinViewV2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
//	CWinDeKikaigoDoc* pDoc = GetDocument();
}

void CBinViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 座標計算
	DWORD x, row;
	x = (point.x + m_dwFontWidth/2) / m_dwFontWidth;
	x /= 3;	// "XX " で1単位とする
	row = point.y / (m_dwFontHeight + m_dwRowMargin);
	m_dwSel = row * m_dwMaxColumn + x;
	
	// 出力
	CString buf;
	buf.Format(L"Down! x:%d, y:%d, m_dwSel:%d, max:%d\r\n", point.x, point.y, m_dwSel, m_dwMaxColumn);
	OutputDebugString(buf);

	// キャレット設定
	CPoint fixPoint;
	fixPoint.x = (m_dwSel%m_dwMaxColumn) * (m_dwFontWidth*3);
	fixPoint.y = (m_dwSel/m_dwMaxColumn) * (m_dwFontHeight+m_dwRowMargin);
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
	CWinDeKikaigoDoc* pDoc = GetDocument();
	BYTE* b = pDoc->testBytes;

	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch (nChar) {
	case VK_LEFT: m_dwMaxColumn--; break;
	case VK_RIGHT: m_dwMaxColumn++; break;
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
	case '8': case '9': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
		if (!m_bIsSecond) {
			b[m_dwSel] = DATA_KEY2HEX10[nChar-0x30];
			m_bIsSecond = TRUE;
		} else {
			b[m_dwSel] |= DATA_KEY2HEX[nChar-0x30];
			m_bIsSecond = FALSE;
			m_dwSel++;
		}
		break;
	}
	RedrawWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
