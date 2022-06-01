// AsmViewDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
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
	DDX_Control(pDX, IDC_BUTTON1, m_btnLda);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAsmViewDlg, CDialog)
	//{{AFX_MSG_MAP(CAsmViewDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg メッセージ ハンドラ

BOOL CAsmViewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: この位置に初期化の補足処理を追加してください
/*	m_imageList.Create(IDB_BITMAP1, 32, 64, ILC_COLOR8);
	
	CString buf;
	buf.Format(L"m_imageList.GetImageCount() : %d", m_imageList.GetImageCount());
	OutputDebugString(buf);

	HICON hIcon;
	CBitmapButton* m_btn;
	DWORD button_tbl[] = {
		IDC_BUTTON1, IDC_BUTTON2, IDC_BUTTON3, 
		IDC_BUTTON4, IDC_BUTTON5, IDC_BUTTON6, 
	};
	for (int i = 0; i < 6; i++) {
		m_btn = (CBitmapButton*)GetDlgItem(button_tbl[i]);
		hIcon = m_imageList.ExtractIcon(1+i);
		m_btn->SetIcon(hIcon);
	}
*/			
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
