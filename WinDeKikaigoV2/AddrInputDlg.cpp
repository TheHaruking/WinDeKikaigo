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
	
	// ダイアログの位置調整
	POINT pos;
	GetCursorPos(&pos);

	RECT rect;
	this->GetWindowRect(&rect);
	DWORD width = rect.right - rect.left;
	DWORD height = rect.bottom - rect.top;
	
	this->MoveWindow(pos.x, pos.y - height/2, width, height);

	
//	return FALSE;
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CAddrInputDlg::OnOK()
{
	CString buf;
	m_edit1.GetWindowText(buf);
	m_dwAddr = wcstol(buf, NULL, 16);
	CDialog::OnOK();
}


DWORD CAddrInputDlg::GetAddr()
{
	return m_dwAddr;
}
