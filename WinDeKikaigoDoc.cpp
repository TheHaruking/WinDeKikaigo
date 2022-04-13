// WinDeKikaigoDoc.cpp : CWinDeKikaigoDoc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigo.h"

#include "WinDeKikaigoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoDoc

IMPLEMENT_DYNCREATE(CWinDeKikaigoDoc, CDocument)

BEGIN_MESSAGE_MAP(CWinDeKikaigoDoc, CDocument)
	//{{AFX_MSG_MAP(CWinDeKikaigoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoDoc クラスの構築/消滅

CWinDeKikaigoDoc::CWinDeKikaigoDoc()
{
}

CWinDeKikaigoDoc::~CWinDeKikaigoDoc()
{
}

BOOL CWinDeKikaigoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i = 0; i<256; i++) {
		testBytes[i] = i;
	}

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoDoc シリアライゼーション

void CWinDeKikaigoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoDoc クラスの診断

#ifdef _DEBUG
void CWinDeKikaigoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinDeKikaigoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoDoc コマンド
