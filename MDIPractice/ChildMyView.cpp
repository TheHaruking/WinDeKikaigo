// ChildMyView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "MDIPractice.h"
#include "ChildMyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildMyView

IMPLEMENT_DYNCREATE(CChildMyView, CWnd)

BEGIN_MESSAGE_MAP(CChildMyView, CWnd)
	//{{AFX_MSG_MAP(CChildMyView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CChildMyView::CChildMyView()
{
}

CChildMyView::~CChildMyView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CChildMyView メッセージ ハンドラ

BOOL CChildMyView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	// CEdit版
/*	if (!CEdit::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
*/
	// CEditView 版 (実行時エラー！)
/*	if (!CEditView::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ワード ラップを使用可能にします
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
*/
	return TRUE;
}



void CChildMyView::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	CFont* pFontOld;
	
	pFontOld = dc.SelectObject(&m_font);

	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	CString buf;

	dc.SetBkColor(RGB(255, 255, 0));
	buf.Format(L" ADDRESS   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F    0123456789ABCDEF");
	dc.TextOut(0, 0, buf);

	dc.SetBkColor(RGB(128, 128, 128));
	dc.SetTextColor(RGB(255, 255, 255));
	buf.Format(L" 00000000 ");
	dc.TextOut(0, 16, buf);

	// 元に戻す
	dc.SelectObject(pFontOld);
	
}
// 描画用メッセージとして CWnd::OnPaint() を呼び出してはいけません


BOOL CChildMyView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{

	CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
/*
	m_static.Create(L"hello!!", WS_CHILD | WS_VISIBLE,
		CRect(10, 10, 150, 50), this);
	m_edit.Create(WS_CHILD | WS_VISIBLE, 
		CRect(30, 30, 150, 50), this, 0);
*/
	// フォント編集！
	m_font.CreateFont(
		16, 0, 0, 0, FW_DONTCARE, // 高さ、幅、角度、角度、太さ
		FALSE, FALSE, FALSE,	// 斜体、下線、取消線
		SHIFTJIS_CHARSET,		// 文字セット
		OUT_DEFAULT_PRECIS,		// 出力精度
		CLIP_DEFAULT_PRECIS,	// クリッピング精度
		DRAFT_QUALITY,			// 出力品質
		DEFAULT_PITCH,			// ピッチ
		_T("ＭＳ ゴシック")		// タイプフェイス名
		);

	return TRUE;
}
