// AsmViewDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "AsmViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg ダイアログ


CAsmViewDlg::CAsmViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAsmViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAsmViewDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CAsmViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmViewDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAsmViewDlg, CDialog)
	//{{AFX_MSG_MAP(CAsmViewDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg メッセージ ハンドラ
