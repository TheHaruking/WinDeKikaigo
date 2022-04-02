// AsmView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "AsmView.h"

#include "WinDeKikaigoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmView

IMPLEMENT_DYNCREATE(CAsmView, CFormView)

CAsmView::CAsmView()
	: CFormView(CAsmView::IDD)
{
	//{{AFX_DATA_INIT(CAsmView)
	//}}AFX_DATA_INIT
}

CAsmView::~CAsmView()
{
}

void CAsmView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmView)
	DDX_Control(pDX, IDC_COMBO4, m_combo4);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAsmView, CFormView)
	//{{AFX_MSG_MAP(CAsmView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmView 診断

#ifdef _DEBUG
void CAsmView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAsmView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

// 追加！
CWinDeKikaigoDoc* CAsmView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAsmView メッセージ ハンドラ

void CAsmView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	m_combo1.InsertString(-1, L"LDA #$XX");
	m_combo1.InsertString(-1, L"LDA $XXXX");
	m_combo1.InsertString(-1, L"LDA $XX, x");
	m_combo1.InsertString(-1, L"LDA $XX, y");

}

void CAsmView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();

	// 初期化テスト！
	BYTE* testBytes = pDoc->testBytes;

	// 文字列処理
	if (testBytes[0] == 0x34) {
		m_combo4.EnableWindow(TRUE);

	} else {
		m_combo4.EnableWindow(FALSE);
	}
}
