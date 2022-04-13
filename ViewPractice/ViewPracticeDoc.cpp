// ViewPracticeDoc.cpp : CViewPracticeDoc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "ViewPractice.h"

#include "ViewPracticeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc

IMPLEMENT_DYNCREATE(CViewPracticeDoc, CDocument)

BEGIN_MESSAGE_MAP(CViewPracticeDoc, CDocument)
	//{{AFX_MSG_MAP(CViewPracticeDoc)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc クラスの構築/消滅

CViewPracticeDoc::CViewPracticeDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CViewPracticeDoc::~CViewPracticeDoc()
{
}

BOOL CViewPracticeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc シリアライゼーション

void CViewPracticeDoc::Serialize(CArchive& ar)
{
	// CEditView はすべてのシリアライゼーション ハンドルのどれかのエディットコントロールを含んでいます。
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc クラスの診断

#ifdef _DEBUG
void CViewPracticeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CViewPracticeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc コマンド
