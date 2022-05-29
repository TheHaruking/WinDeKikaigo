// SplitterPracticeDoc.cpp : CSplitterPracticeDoc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "SplitterPractice.h"

#include "SplitterPracticeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc

IMPLEMENT_DYNCREATE(CSplitterPracticeDoc, CDocument)

BEGIN_MESSAGE_MAP(CSplitterPracticeDoc, CDocument)
	//{{AFX_MSG_MAP(CSplitterPracticeDoc)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc クラスの構築/消滅

CSplitterPracticeDoc::CSplitterPracticeDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CSplitterPracticeDoc::~CSplitterPracticeDoc()
{
}

BOOL CSplitterPracticeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc シリアライゼーション

void CSplitterPracticeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください。
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください。
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc クラスの診断

#ifdef _DEBUG
void CSplitterPracticeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSplitterPracticeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc コマンド
