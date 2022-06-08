// MainFrm.cpp : CMainFrame クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "BinViewV2.h"
#include "AsmViewV2.h"
#include "AsmInputBarDlg.h"

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

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの構築/消滅

CMainFrame::CMainFrame()
{
	// TODO: この位置にメンバの初期化処理コードを追加してください。
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

	// 右ペイン
	if (!m_wndDialogBar_R.Create(this,
			IDD_DIALOGBAR_R, CBRS_RIGHT, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}

	// 起動時のフォーカスを指定
	SetActiveView((CView*)m_wndSplitter.GetPane(0,0));

	// AsmView と AsmInputBar を連携させる
	((CAsmViewV2*)m_wndSplitter.GetPane(0,1))->RegisterAsmInputBar(&m_wndDialogBar_R);

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

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CBinViewV2), CSize(150, -1), pContext) ||
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

void CMainFrame::OnAppDebug() 
{
	CAsmInputBarDlg dlg;
	dlg.DoModal();
}
