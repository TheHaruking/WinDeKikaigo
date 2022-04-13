// MainMyView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "MDIPractice.h"
#include "MainMyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainMyView

IMPLEMENT_DYNCREATE(CMainMyView, CFormView)

CMainMyView::CMainMyView()
	: CFormView(CMainMyView::IDD)
{
	//{{AFX_DATA_INIT(CMainMyView)
		// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//}}AFX_DATA_INIT
}

CMainMyView::~CMainMyView()
{
}

void CMainMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainMyView)
		// メモ: ClassWizard はこの位置に DDX および DDV の呼び出しを追加します
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainMyView, CFormView)
	//{{AFX_MSG_MAP(CMainMyView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainMyView 診断

#ifdef _DEBUG
void CMainMyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMainMyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainMyView メッセージ ハンドラ
