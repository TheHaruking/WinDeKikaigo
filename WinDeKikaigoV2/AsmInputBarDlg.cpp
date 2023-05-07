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
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDC_ASMDLG_0, IDC_ASMDLG_9, OnClickedPanel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg メッセージ ハンドラ

BOOL CAsmInputBarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// ダイアログの位置調整
	POINT pos;
	GetCursorPos(&pos);

	RECT rect;
	this->GetWindowRect(&rect);
	DWORD width = rect.right - rect.left;
	DWORD height = rect.bottom - rect.top;
	
	this->MoveWindow(pos.x - width/2, pos.y - height/2, width, height);

	// ボタンの無効化処理
	for (int i = 0; i < 10; i++) {
		if (m_ADRTABLE[1+i /* HEAD は除く*/] == 0) {
			GetDlgItem(IDC_ASMDLG_0+i)->ShowWindow(SW_HIDE);
		}
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CAsmInputBarDlg::OnClickedPanel(UINT nID) 
{
	// #define IDC_ASMDLG_0                    5100
	UINT id = nID - IDC_ASMDLG_0;
	m_dwSelect = id;

	this->OnOK();
}

void CAsmInputBarDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmInputBarDlg::SetAdressingModeDataTable(const LONG* ADRTABLE)
{
	m_ADRTABLE = ADRTABLE;
}

DWORD CAsmInputBarDlg::GetSelected()
{
	return m_dwSelect;
}
