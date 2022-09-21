// WinDeKikaigoV2Doc.cpp : CWinDeKikaigoV2Doc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "WinDeKikaigoV2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc

IMPLEMENT_DYNCREATE(CWinDeKikaigoV2Doc, CDocument)

BEGIN_MESSAGE_MAP(CWinDeKikaigoV2Doc, CDocument)
	//{{AFX_MSG_MAP(CWinDeKikaigoV2Doc)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc クラスの構築/消滅

CWinDeKikaigoV2Doc::CWinDeKikaigoV2Doc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CWinDeKikaigoV2Doc::~CWinDeKikaigoV2Doc()
{
}

BOOL CWinDeKikaigoV2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)
	int i;
	// Free エリア、VRAM は (確認しやすさの都合で) 0-255 の連番にしておく.
	for (i = 0; i < 0xDFFF; i++) {
		m_data[i] = i&0xFF;
	}

	// SpriteMem, 入力 IO 等は 0 にしておく.
	for (i = 0xE000; i < 0xFFFF; i++) {
		m_data[i] = 0x00;
	}

	m_nSel = 0;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc シリアライゼーション

void CWinDeKikaigoV2Doc::Serialize(CArchive& ar)
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
// CWinDeKikaigoV2Doc クラスの診断

#ifdef _DEBUG
void CWinDeKikaigoV2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinDeKikaigoV2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc コマンド
