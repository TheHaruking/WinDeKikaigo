// AsmInputDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "AsmInputBar.h"
#include "AsmInputBarDlg.h"

#include "AsmViewV2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBar ダイアログ

CAsmInputBar::CAsmInputBar()
{
	//{{AFX_DATA_INIT(CAsmInputBar)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}

void CAsmInputBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmInputBar)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAsmInputBar, CDialogBar)
	//{{AFX_MSG_MAP(CAsmInputBar)
	ON_BN_CLICKED(IDC_INPUT_LDA, OnInputLda)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)   // 追加！
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBar メッセージ ハンドラ

LONG CAsmInputBar::OnInitDialog(UINT wParam, LONG lParam)
{
	BOOL bRet = HandleInitDialog(wParam, lParam);

	if (!UpdateData(FALSE))
	{
		TRACE0("Warning: UpdateDate failed.");
	}

	return bRet;
}

void CAsmInputBar::OnInputLda()
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CAsmInputBarDlg dlg;

	dlg.DoModal();
	
	CString buf;
	buf.Format(L"GetAsmSel() : %d, dwSelect: %d", m_pAsmView->GetAsmSel(), dlg.m_dwSelect);

	// 書き込み
	// m_pDoc->m_data[m_nCurIp] = 0xEA;
	BYTE data[] = { 0xEA };
	m_pAsmView->SetAsmObj(m_pAsmView->GetAsmSel(), data, sizeof(data));
	m_pAsmView->AsmObjToBin();

	OutputDebugString(buf);

	m_pDoc->UpdateAllViews(NULL);
}
