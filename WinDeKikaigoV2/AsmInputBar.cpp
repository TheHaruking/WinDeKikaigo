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
//	ON_BN_CLICKED(IDC_INPUT_LDA, OnInputLda)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)   // 追加！
	ON_COMMAND_RANGE(IDC_PANE_LDA, IDC_PANE_NOP, OnInputLda)
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

void CAsmInputBar::OnInputLda(UINT nID)
{
	/*
		#define IDC_PANE_LDA                    5000
		#define IDC_PANE_LDX                    5001
		...
		#define IDC_PANE_NOP                    5055
		→ nID の順は ASMVIEW の enum OP_LDA らに準ずるように手作業で設定している。
	*/
	DWORD id = nID - IDC_PANE_LDA + 1;
	const LONG* OPADRTABLE = m_pAsmView->ASM2ADR[id];
	BYTE data[3] = { 0x00, 0x00, 0x00 };

	// 単一のアドレッシングモードのみのオペコードだった場合
	if (OPADRTABLE[0] >= 0x00) {
		data[0] = (BYTE)OPADRTABLE[0];
	}
	// 複数のアドレッシングモードを有するオペコードだった場合
	else /*(OPADRTABLE[0] == -1)*/ {
		CAsmInputBarDlg dlg;

		dlg.SetAdressingModeDataTable(OPADRTABLE);
		if (dlg.DoModal() == IDCANCEL)
			return;

		data[0] = (BYTE)OPADRTABLE[dlg.GetSelected() + 1];
	}

	// 反映
	m_pAsmView->SetAsmObj(m_pAsmView->GetAsmSel(), data);
	m_pAsmView->AsmObjToBin();
	m_pAsmView->GetDocument()->UpdateAllViews(NULL);
}
