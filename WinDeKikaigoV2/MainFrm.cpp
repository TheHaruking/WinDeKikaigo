// MainFrm.cpp : CMainFrame クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "BinViewV2.h"
#include "AsmViewV2.h"
#include "AsmInputBarDlg.h"
#include "Emu6502.h"
#include "Emu6502OutputV2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_APP_LEFTPANE, OnAppLeftpane)
	ON_COMMAND(ID_APP_RIGHTPANE, OnAppRightpane)
	ON_COMMAND(ID_APP_DEBUG, OnAppDebug)
	ON_COMMAND(ID_APP_RESET, OnAppReset)
	ON_COMMAND(ID_APP_VM, OnAppVm)
	ON_UPDATE_COMMAND_UI(ID_APP_LEFTPANE, OnUpdateAppLeftpane)
	ON_UPDATE_COMMAND_UI(ID_APP_RIGHTPANE, OnUpdateAppRightpane)
	ON_UPDATE_COMMAND_UI(ID_APP_VM, OnUpdateAppVm)
	ON_COMMAND(ID_APP_TEST, OnAppTest)
	ON_COMMAND(ID_APP_RUN, OnAppRun)
	ON_UPDATE_COMMAND_UI(ID_APP_RUN, OnUpdateAppRun)
	ON_COMMAND(ID_APP_BOTTOMPANE, OnAppBottompane)
	ON_UPDATE_COMMAND_UI(ID_APP_BOTTOMPANE, OnUpdateAppBottompane)
	ON_COMMAND(ID_APP_SPEED1, OnAppSpeed1)
	ON_UPDATE_COMMAND_UI(ID_APP_SPEED1, OnUpdateAppSpeed1)
	ON_COMMAND(ID_APP_SPEED2, OnAppSpeed2)
	ON_UPDATE_COMMAND_UI(ID_APP_SPEED2, OnUpdateAppSpeed2)
	ON_COMMAND(ID_APP_SPEEDMAX, OnAppSpeedmax)
	ON_UPDATE_COMMAND_UI(ID_APP_SPEEDMAX, OnUpdateAppSpeedmax)
	ON_COMMAND(ID_APP_UPDATEUI, OnAppUpdateUi)
	ON_COMMAND(ID_APP_SPEED3, OnAppSpeed3)
	ON_UPDATE_COMMAND_UI(ID_APP_SPEED3, OnUpdateAppSpeed3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ステータス ライン インジケータ
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

const LONG CMainFrame::SPEED2WAITTICK_TBL[sizeof(SPEED_MODE)] = {
	0, 600, 60, 1
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの構築/消滅

CMainFrame::CMainFrame()
{
	// TODO: この位置にメンバの初期化処理コードを追加してください。
	m_bRunning = FALSE;
	m_dwRunningSpeed = SPEED_2;
	m_tick = GetTickCount();
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1) // OnCreateClient はここ
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		/*| CBRS_GRIPPER*/ | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // 作成に失敗
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}

	// TODO: ツール バーをドッキング可能にしない場合は以下の３行を削除
	//       してください。
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	// 左ペイン
	if (!m_wndDialogBar_L.Create(this,
			IDD_DIALOGBAR_L, CBRS_LEFT, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}

	// 非表示にしておく.
	this->ShowControlBar(&m_wndDialogBar_L, FALSE, FALSE);

	// 右ペイン
	if (!m_wndDialogBar_R.Create(this,
			IDD_DIALOGBAR_R, CBRS_RIGHT, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}

	// 下ペイン
	if (!m_wndCpuOutput.Create(this,
			IDD_EMU6502OUTPUTV2_FORM, CBRS_BOTTOM, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}

	// 起動時のフォーカスを指定
	SetActiveView((CView*)m_wndSplitter.GetPane(0,0));

	// AsmInputBar <- AsmView
	m_wndDialogBar_R.m_pAsmView = (CAsmViewV2*)m_wndSplitter.GetPane(0,1);

	// CPU モジュールの初期化
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_cpu.Init(pDoc->GetDataAddr(0x0000));

	// CEmu6502Output <- CEmu6502
	m_wndCpuOutput.m_cpu = &m_cpu;
	m_wndCpuOutput.Update();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: この位置で CREATESTRUCT cs を修正して、Window クラスやスタイルを
	//       修正してください。

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの診断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame メッセージ ハンドラ


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	// return CFrameWnd::OnCreateClient(lpcs, pContext);
	
	// 親分割ウィンドウ (m_wndSplitter) を作成します
	if (!m_wndSplitter.CreateStatic(this, 1, 2)) // 縦x横
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CBinViewV2), CSize(200, -1), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CAsmViewV2), CSize(-1, -1), pContext)	
		)
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}

	// 完了.
	return TRUE;
}

void CMainFrame::OnAppLeftpane() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndDialogBar_L.IsWindowVisible();
	this->ShowControlBar(&m_wndDialogBar_L, bVisible^1, FALSE);
}

void CMainFrame::OnAppRightpane() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndDialogBar_R.IsWindowVisible();
	this->ShowControlBar(&m_wndDialogBar_R, bVisible^1, FALSE);
}

void CMainFrame::OnAppBottompane() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndCpuOutput.IsWindowVisible();
	this->ShowControlBar(&m_wndCpuOutput, bVisible^1, FALSE);
}

void CMainFrame::OnAppDebug() 
{
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_cpu.Exec();
	m_wndCpuOutput.Update();
	pDoc->m_nSel = m_cpu.GetRegPC();
	pDoc->m_nSelEnd = m_cpu.GetRegPC();
	pDoc->UpdateAllViews(NULL);
	
	// 仮想マシンウィンドウが開いている場合.
	if (m_wndVmWnd.m_hWnd != NULL) {
		m_wndVmWnd.Invalidate(FALSE); // 削除はしない.
		m_wndVmWnd.UpdateWindow();
	}
}

void CMainFrame::OnAppReset() 
{
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_cpu.Reset();
	m_wndCpuOutput.Update();
	pDoc->UpdateAllViews(NULL);	
}

void CMainFrame::OnAppVm() 
{
	// 未 Create 状態であれば VmWnd を表示させる
	if (m_wndVmWnd.GetSafeHwnd() == NULL)
	{
		m_wndVmWnd.CreateEx(this);
		m_wndVmWnd.ShowWindow(SW_SHOW);

		// Document クラスをセット
		CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
		m_wndVmWnd.SetDocument(pDoc);
	}
	else // すでに Create されている場合は Destroy する.
	{
		m_wndVmWnd.DestroyWindow();
	}
}

void CMainFrame::OnUpdateAppLeftpane(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndDialogBar_L.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);
}

void CMainFrame::OnUpdateAppRightpane(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndDialogBar_R.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);	
}

void CMainFrame::OnUpdateAppBottompane(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndCpuOutput.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);
}

void CMainFrame::OnUpdateAppVm(CCmdUI* pCmdUI) 
{
	// 未 Create (Destroy 後) であれば FALSE.
	if (m_wndVmWnd.GetSafeHwnd() == NULL) {
		pCmdUI->SetCheck(FALSE);
		return;
	}

	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bVisible = m_wndVmWnd.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);		
}

// 機能確認用関数.
void CMainFrame::OnAppTest() 
{
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	
	// 数値を入力できる CAddrInputDlg を流用してページを指定してしまうことにする.
	CAddrInputDlg dlg;

	dlg.DoModal();
	pDoc->SetPage(dlg.GetAddr());
	pDoc->UpdateAllViews(NULL);
}

UINT MyThreadProc(LPVOID pParam)
{
	CMainFrame* self = (CMainFrame*)pParam;
	self->m_tick = GetTickCount();

	// 実行ループ
	for (;;) {
		if (self->m_cpu.Exec())
			self->m_bRunning = FALSE; // エラー発生時.

		// 画面更新は 16ms に 1 回に制限する.
		DWORD tick = GetTickCount();
		if ((tick - self->m_tick) >= 16) {
			// レジスタ情報、BinView、AsmView を更新			
/*			self->m_wndCpuOutput.Update();
			の用に別スレッド側で直接 UI の Update 処理を呼び出すと例外が発生する。
			下記のように、SendMessage 経由で呼び出すこと。
*/
			AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_APP_UPDATEUI, 0L);

			// 仮想マシンウィンドウを更新 (開いている場合)
			if (self->m_wndVmWnd.m_hWnd != NULL) {
				self->m_wndVmWnd.Invalidate(FALSE); // 削除はしない.
				self->m_wndVmWnd.UpdateWindow();
			}

			// tick 更新
			self->m_tick = tick;
		}
		
		// 停止ボタン確認.
		DWORD dwRunWaitTicks = self->SPEED2WAITTICK_TBL[self->m_dwRunningSpeed];
		Sleep(dwRunWaitTicks);

		if (self->m_bRunning == FALSE)
			break;
	}

	return 0;
}

void CMainFrame::OnAppRun() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	switch (m_bRunning)
	{
	case FALSE:
		m_clock = AfxBeginThread(MyThreadProc, this);
		m_bRunning = TRUE;
		break;
	default:
		m_bRunning = FALSE;
		m_wndCpuOutput.Update();
		break;
	}
}

void CMainFrame::OnAppStop() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	m_bRunning = FALSE;
	// 更新.
	m_wndCpuOutput.Update();
}

void CMainFrame::OnUpdateAppRun(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	pCmdUI->SetCheck(m_bRunning);
}


void CMainFrame::OnAppSpeed1() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	m_dwRunningSpeed = SPEED_1;
}

void CMainFrame::OnAppSpeed2() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	m_dwRunningSpeed = SPEED_2;
}

void CMainFrame::OnAppSpeed3() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	m_dwRunningSpeed = SPEED_3;	
}

void CMainFrame::OnAppSpeedmax() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	m_dwRunningSpeed = SPEED_MAX;
}

void CMainFrame::OnUpdateAppSpeed1(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bCheck = (m_dwRunningSpeed == SPEED_1);
	pCmdUI->SetCheck(bCheck);
}

void CMainFrame::OnUpdateAppSpeed2(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bCheck = (m_dwRunningSpeed == SPEED_2);
	pCmdUI->SetCheck(bCheck);
}

void CMainFrame::OnUpdateAppSpeed3(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bCheck = (m_dwRunningSpeed == SPEED_3);
	pCmdUI->SetCheck(bCheck);
}

void CMainFrame::OnUpdateAppSpeedmax(CCmdUI* pCmdUI) 
{
	// TODO: この位置に command update UI ハンドラ用のコードを追加してください
	BOOL bCheck = (m_dwRunningSpeed == SPEED_MAX);
	pCmdUI->SetCheck(bCheck);	
}

void CMainFrame::OnAppUpdateUi() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_wndCpuOutput.Update();
	pDoc->UpdateAllViews(NULL);	
}
