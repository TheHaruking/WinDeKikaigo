// AsmViewV2.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "windekikaigodoc.h"
#include "AsmViewV2.h"

#include "AsmViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// 定数
const DWORD CAsmViewV2::BIN2OP[256] = {
//	0       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
// 40
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
// 80
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_LDA, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
// C0
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND
};

const DWORD CAsmViewV2::BIN2ADR[256] = {
//  0         1         2         3         4         5         6         7         8         9         A         B         C         D         E         F
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
// 40
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
// 80
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_IMM,  ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
// C0
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE
};


/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2

IMPLEMENT_DYNCREATE(CAsmViewV2, CView)

CAsmViewV2::CAsmViewV2()
{
}

CAsmViewV2::~CAsmViewV2()
{
}


BEGIN_MESSAGE_MAP(CAsmViewV2, CView)
	//{{AFX_MSG_MAP(CAsmViewV2)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 描画

void CAsmViewV2::OnDraw(CDC* pDC)
{
	CWinDeKikaigoDoc* pDoc = GetDocument();
	
	// TODO: この位置に描画用のコードを追加してください
	// ここのコードは後にデーブル化する.
	DWORD dwOutput = 0;
	switch (pDoc->testBytes[0]) {
	case 0xA9:
		pDC->TextOut(0, 0, L"LDA ");
		dwOutput = 1;
		break;
	case 0xAD:
		pDC->TextOut(0, 0, L"LDA ");
		dwOutput = 2;
		break;
	case 0xB5:
		pDC->TextOut(0, 0, L"LDA     ,x");
		dwOutput = 1;
		break;
	}
	// オペランド.
	CString buf;
	switch (dwOutput) {
	case 1:
		buf.Format(L"%02X", pDoc->testBytes[1]);
		pDC->TextOut(4*8, 0, buf);
		break;
	case 2:
		buf.Format(L"%02X%02X", pDoc->testBytes[2], pDoc->testBytes[1]);
		pDC->TextOut(4*8, 0, buf);
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 診断

#ifdef _DEBUG
void CAsmViewV2::AssertValid() const
{
	CView::AssertValid();
}

void CAsmViewV2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// 追加！
CWinDeKikaigoDoc* CAsmViewV2::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 メッセージ ハンドラ

void CAsmViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CAsmViewDlg dlg;
	dlg.DoModal();

	CView::OnLButtonDown(nFlags, point);
}
