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
const BYTE CBinViewV2::DATA_KEY2HEX[] = {
	// 0123456789:;<=>?
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0, 0, 0, 0, 0, 0,
	// @ABCDEF
	0, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
const BYTE CBinViewV2::DATA_KEY2HEX10[] = {
	0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0, 0, 0, 0, 0, 0,
	0, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0
};
const LPTSTR CBinViewV2::DATA_HEX2FMT[] = {
	L"", L"%02X ", L"%04X ", L"%06X ", L"%08X ",
	L"%010X ", L"%012X ", L"%014X ", L"%016X "
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

	// フォント変更
	CFont* pFontOld;
	pFontOld = pDC->SelectObject(&m_font);

	// 
	DWORD NEXT = m_dwFontHeight + m_dwRowMargin;
	DWORD ofs = 0;
	DWORD height = 0;

	CString buf, bufLine;
	BYTE* b = pDoc->testBytes;
	DWORD dw;

	for (int i = 0; i < 8; i++) {
		ofs = i*m_dwMaxColumn;
		
		bufLine.Format(L"");
		for (DWORD j = 0; j < m_dwMaxColumn; j++) {
			switch (m_eDigit) {
			case DIGIT_BYTE: dw = b[ofs+j]; break;
			case DIGIT_WORD: dw = ((WORD*)b)[ofs+j]; break;
			case DIGIT_DWORD: dw = ((DWORD*)b)[ofs+j]; break;
			}
			buf.Format(DATA_HEX2FMT[m_eDigit], dw);
			bufLine += buf;
		}
		pDC->TextOut(0, height, bufLine);
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
// CBinViewV2 内部関数

void CBinViewV2::DigitUp()
{
	switch (m_eDigit) {
	case DIGIT_BYTE:
		m_eDigit = DIGIT_WORD;
		m_dwMaxColumn /= 2;
		break;
	case DIGIT_WORD:
		m_eDigit = DIGIT_DWORD;
		m_dwMaxColumn /= 2;
		break;
	}
}

void CBinViewV2::DigitDown()
{
	switch (m_eDigit) {
	case DIGIT_WORD:
		m_eDigit = DIGIT_BYTE;
		m_dwMaxColumn *= 2;
		break;
	case DIGIT_DWORD:
		m_eDigit = DIGIT_WORD;
		m_dwMaxColumn *= 2;
		break;
	}
}

void CBinViewV2::CaretPosUpdate()
{
	CPoint fixPoint;
	const DWORD GROUPNUM = m_eDigit*2+1; // "XX " で1単位とする

	DWORD sel = m_dwSel/m_eDigit;
	fixPoint.x = (sel%m_dwMaxColumn) * (m_dwFontWidth*GROUPNUM);
	fixPoint.y = (sel/m_dwMaxColumn) * (m_dwFontHeight+m_dwRowMargin);

	DWORD selmod = m_dwSel % m_eDigit;
	fixPoint.x += selmod * m_dwFontWidth*2;
	SetFocus();
	SetCaretPos(fixPoint);
}

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 メッセージ ハンドラ

BOOL CBinViewV2::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// メンバ初期化
	m_dwFontHeight = 16;	// フォントの高さ
//	m_dwFontWidth = 8;		// フォントの幅 (m_font.CreateFont 関数後に取得する)
	m_dwRowMargin = 1;		// フォントの行余白
	m_dwMaxColumn = 4;		// 列数
	m_dwSel = 0;			// 選択中の番号
	m_bIsSecond = FALSE;	// 下位4ビット編集中か？
	m_eDigit = DIGIT_BYTE; // 編集モード(桁)

	m_font.CreateFont(
		m_dwFontHeight, 0,		// 高さ、幅
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
	m_dwFontWidth = size.cx; // 横幅設定！
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
	DWORD x, row, xmod;
	const DWORD GROUPNUM = m_eDigit*2+1; // "XX " で1単位とする

	x = point.x / m_dwFontWidth;
	xmod = (x % GROUPNUM)/2; // 空白クリック時に次項を選択するが許容する。
	x /= GROUPNUM;
	row = point.y / (m_dwFontHeight + m_dwRowMargin);
	m_dwSel = row * m_dwMaxColumn + x;
	m_dwSel *= m_eDigit;
	m_dwSel += xmod;
	
	// 出力
	CString buf;
	buf.Format(L"Down! x:%d, y:%d, m_dwSel:%d, max:%d\r\n", point.x, point.y, m_dwSel, m_dwMaxColumn);
	OutputDebugString(buf);

	// キャレット設定
	CaretPosUpdate();

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
	case 'I': m_dwMaxColumn--; break;
	case 'O': m_dwMaxColumn++; break;
	case 'U': DigitDown(); break;
	case 'P': DigitUp(); break;

	case VK_LEFT:  m_dwSel--; break;
	case VK_RIGHT: m_dwSel++; break;
	case VK_UP:    m_dwSel -= m_dwMaxColumn*m_eDigit; break;
	case VK_DOWN:  m_dwSel += m_dwMaxColumn*m_eDigit; break;

	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
	case '8': case '9': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
		{
			// (例)DWORDの数列: 3210 7654 BA98...
			DWORD sel = m_dwSel^(m_eDigit-1);	// xor演算で期待値になる.
			// 開始
			if (!m_bIsSecond) {
				b[sel] = DATA_KEY2HEX[nChar-0x30] << 4;
				m_bIsSecond = TRUE;
			}
			// 終了
			else {
				b[sel] |= DATA_KEY2HEX[nChar-0x30];
				m_bIsSecond = FALSE;
				m_dwSel++;
			}
			break;
		}
	}

	// 画面に反映
	CaretPosUpdate();
	RedrawWindow();
	pDoc->UpdateAllViews(this);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
