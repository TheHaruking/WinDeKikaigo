// MainFrm.cpp : CMainFrame クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "WinDeKikaigo.h"

#include "MainFrm.h"
#include "LeftView.h" // ForTest
#include "RightView.h" // ForTest

#include "BinView.h"
#include "BinViewV2.h"
#include "ValueView.h"
#include "AsmView.h"
#include "AsmViewV2.h"

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
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, OnUpdateViewStyles)
	ON_COMMAND_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, OnViewStyle)

	// テスト
	ON_COMMAND(ID_SPLIT_LEFT, OnSplitLeft)

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
}

CMainFrame::~CMainFrame()
{
}

// ※分割 Window はこの下の OnCreateClient で行う.
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
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

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

// ★分割ウインドウの作成 (splitter) はここで行う ★
BOOL CMainFrame::OnCreateClient(
	LPCREATESTRUCT /*lpcs*/, // 未使用
	CCreateContext* pContext)
{
#if 1
	// 親分割ウィンドウ (m_wndSplitter) を作成します
	if (!m_wndSplitter.CreateStatic(this, 1, 2)) // 縦x横
		return FALSE;

	if (!m_wndSplitter.CreateView(
			0, 0, RUNTIME_CLASS(CLeftView),
			CSize(100, 100),
			pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}

	// 子分割ウィンドウ (m_wndSplitter1) を作成します
	if (!m_wndSplitter1.CreateStatic(
//			&m_wndSplitter, 3, 1, // X 列 1行
			&m_wndSplitter, 2, 1, // X 列 1行
			WS_CHILD | WS_VISIBLE | WS_BORDER,  // スタイル WS_BORDER が必要です。
			m_wndSplitter.IdFromRowCol(0, 1)
			)) // 縦x横
		return FALSE;

	if (!m_wndSplitter1.CreateView(
			0, 0, RUNTIME_CLASS(CBinViewV2),
			CSize(100, 100),
			pContext) ||
/*		!m_wndSplitter1.CreateView(
			1, 0, RUNTIME_CLASS(CValueView), 
			CSize(100, 100), 
			pContext) ||
*/		!m_wndSplitter1.CreateView(
			1, 0, RUNTIME_CLASS(CAsmViewV2), 
			CSize(100, 100), 
			pContext)
			)
	{
		m_wndSplitter1.DestroyWindow();
		return FALSE;
	}

	// 起動時フォーカスを設定
	SetActiveView((CView*)m_wndSplitter1.GetPane(0,0));

	// 完了.
	return TRUE;
#else
	// 親分割ウィンドウ (m_wndSplitter) を作成します
	m_wndSplitter.Create(this, 1, 2, CSize(10, 10), pContext); // 縦x横
	return TRUE;
#endif
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
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

CRightView* CMainFrame::GetRightPane()
{
	CWnd* pWnd = m_wndSplitter.GetPane(0, 1);
	CRightView* pView = DYNAMIC_DOWNCAST(CRightView, pWnd);
	return pView;
}

void CMainFrame::OnUpdateViewStyles(CCmdUI* pCmdUI)
{

	CRightView* pView = GetRightPane(); 


	if (pView == NULL)
		pCmdUI->Enable(FALSE);
	else
	{
		DWORD dwStyle = pView->GetStyle() & LVS_TYPEMASK;

		if (pCmdUI->m_nID == ID_VIEW_LINEUP)
		{
			if (dwStyle == LVS_ICON || dwStyle == LVS_SMALLICON)
				pCmdUI->Enable();
			else
				pCmdUI->Enable(FALSE);
		}
		else
		{
			pCmdUI->Enable();
			BOOL bChecked = FALSE;

			switch (pCmdUI->m_nID)
			{
			case ID_VIEW_DETAILS:
				bChecked = (dwStyle == LVS_REPORT);
				break;

			case ID_VIEW_SMALLICON:
				bChecked = (dwStyle == LVS_SMALLICON);
				break;

			case ID_VIEW_LARGEICON:
				bChecked = (dwStyle == LVS_ICON);
				break;

			case ID_VIEW_LIST:
				bChecked = (dwStyle == LVS_LIST);
				break;

			default:
				bChecked = FALSE;
				break;
			}

			pCmdUI->SetRadio(bChecked ? 1 : 0);
		}
	}
}


void CMainFrame::OnViewStyle(UINT nCommandID)
{
	CRightView* pView = GetRightPane();

	if (pView != NULL)
	{
		DWORD dwStyle = -1;

		switch (nCommandID)
		{
		case ID_VIEW_LINEUP:
			{
				CListCtrl& refListCtrl = pView->GetListCtrl();
				refListCtrl.Arrange(LVA_SNAPTOGRID);
			}
			break;

		case ID_VIEW_DETAILS:
			dwStyle = LVS_REPORT;
			break;

		case ID_VIEW_SMALLICON:
			dwStyle = LVS_SMALLICON;
			break;

		case ID_VIEW_LARGEICON:
			dwStyle = LVS_ICON;
			break;

		case ID_VIEW_LIST:
			dwStyle = LVS_LIST;
			break;
		}

		if (dwStyle != -1)
			pView->ModifyStyle(LVS_TYPEMASK, dwStyle);
	}
}

/*******************************************************************/
// 左ペインをトグルする
void CMainFrame::OnSplitLeft()
{
//	MessageBox(L"Hello!");

	m_wndSplitter.SetColumnInfo(0, 100, 90);
	m_wndSplitter.RecalcLayout();

//	CWnd * pCurView = m_wndSplitter.GetPane(0, 0);
	
	//m_wndSplitter.DeleteView(0, 0);
/*
	if( !pCurView == NULL )
	{
		if(0)
		{
			pCurView->ShowWindow(SW_SHOW);
			m_wndSplitter.RecalcLayout();
		}
		else
		{
			pCurView->ShowWindow(SW_HIDE);
			m_wndSplitter.RecalcLayout();
		}
	}
	*/
}
