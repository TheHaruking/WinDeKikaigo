// AddrInputDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigov2.h"
#include "AddrInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddrInputDlg ダイアログ


CAddrInputDlg::CAddrInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddrInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddrInputDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CAddrInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddrInputDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddrInputDlg, CDialog)
	//{{AFX_MSG_MAP(CAddrInputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddrInputDlg メッセージ ハンドラ

BOOL CAddrInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください

	return FALSE;
//	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
