// AsmInputBarDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "AsmInputBarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg ダイアログ


CAsmInputBarDlg::CAsmInputBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAsmInputBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAsmInputBarDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CAsmInputBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmInputBarDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAsmInputBarDlg, CDialog)
	//{{AFX_MSG_MAP(CAsmInputBarDlg)
	ON_BN_CLICKED(IDC_ASMDLG_1, OnAsmdlg1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg メッセージ ハンドラ

BOOL CAsmInputBarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	POINT pos;
	GetCursorPos(&pos);

	RECT rect;
	this->GetWindowRect(&rect);
	DWORD width = rect.right - rect.left;
	DWORD height = rect.bottom - rect.top;
	
//	this->SetWindowPos(this, pos.x, pos.y, pos.x, pos.y, SWP_SHOWWINDOW);
	this->MoveWindow(pos.x - width/2, pos.y - height/2, width, height);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CAsmInputBarDlg::OnAsmdlg1() 
{
	m_dwSelect = 1;
	this->OnOK();
}
