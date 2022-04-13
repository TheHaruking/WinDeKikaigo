// ViewPractice.cpp : アプリケーション用クラスの機能定義を行います。
//

#include "stdafx.h"
#include "ViewPractice.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "ViewPracticeDoc.h"
#include "ViewPracticeView.h"
#include "ViewPracticeCView.h"
#include "ViewPracticeRichView.h"
#include "ViewPracticeScrollView.h"
#include "ViewPracticeHtmlView.h"
#include "ViewPracticeListView.h"
#include "ViewPracticeTreeView.h"
#include "ViewPracticeFormView.h"
#include "ViewPracticeMainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeApp

BEGIN_MESSAGE_MAP(CViewPracticeApp, CWinApp)
	//{{AFX_MSG_MAP(CViewPracticeApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
	// 標準のファイル基本ドキュメント コマンド
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeApp クラスの構築

CViewPracticeApp::CViewPracticeApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CViewPracticeApp オブジェクト

CViewPracticeApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeApp クラスの初期化

BOOL CViewPracticeApp::InitInstance()
{
	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さく
	// したければ以下の特定の初期化ルーチンの中から不必要なもの
	// を削除してください。

#ifdef _AFXDLL
	Enable3dControls();		// 共有 DLL の中で MFC を使用する場合にはここを呼び出してください。
#else
	Enable3dControlsStatic();	// MFC と静的にリンクしている場合にはここを呼び出してください。
#endif

	// 設定が保存される下のレジストリ キーを変更します。
	// TODO: この文字列を、会社名または所属など適切なものに
	// 変更してください。
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // 標準の INI ファイルのオプションをローﾄﾞします (MRU を含む)

	// アプリケーション用のドキュメント テンプレートを登録します。ドキュメント テンプレート
	//  はドキュメント、フレーム ウィンドウとビューを結合するために機能します。

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_VIEWPRTYPE,
		RUNTIME_CLASS(CViewPracticeDoc),
		RUNTIME_CLASS(CChildFrame), // カスタム MDI 子フレーム
//		RUNTIME_CLASS(CViewPracticeCView));		// CView
//		RUNTIME_CLASS(CViewPracticeView));		// CEdit
//		RUNTIME_CLASS(CViewPracticeRichView));	// CRichEditView
//		RUNTIME_CLASS(ViewPracticeScrollView));	// CScrollView
//		RUNTIME_CLASS(CViewPracticeHtmlView));	// CHtmlView
//		RUNTIME_CLASS(CViewPracticeListView));	// CListView
//		RUNTIME_CLASS(CViewPracticeTreeView));	// CTreeView
//		RUNTIME_CLASS(CViewPracticeFormView));	// CTreeView
//		RUNTIME_CLASS(CViewPracticeMainView));	// CMDIChildWnd *Error!*
	AddDocTemplate(pDocTemplate);

	// メイン MDI フレーム ウィンドウを作成
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// DDE、file open など標準のシェル コマンドのコマンドラインを解析します。
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// コマンドラインでディスパッチ コマンドを指定します。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// メイン ウィンドウが初期化されたので、表示と更新を行います。
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// アプリケーションのバージョン情報で使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard 仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//{{AFX_MSG(CAboutDlg)
		// メッセージ ハンドラはありません。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// メッセージ ハンドラはありません。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// ダイアログを実行するためのアプリケーション コマンド
void CViewPracticeApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeApp メッセージ ハンドラ
