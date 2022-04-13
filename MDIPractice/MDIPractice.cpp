// MDIPractice.cpp : アプリケーション用クラスの機能定義を行います。
//

#include "stdafx.h"
#include "MDIPractice.h"

#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp

BEGIN_MESSAGE_MAP(CMDIPracticeApp, CWinApp)
	//{{AFX_MSG_MAP(CMDIPracticeApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp クラスの構築

CMDIPracticeApp::CMDIPracticeApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CMDIPracticeApp オブジェクト

CMDIPracticeApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp クラスの初期化

BOOL CMDIPracticeApp::InitInstance()
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

	// メイン ウインドウを作成するとき、このコードは新しいフレーム ウインドウ オブジェクトを作成し、
	// それをアプリケーションのメイン ウインドウにセットします
	CMDIFrameWnd* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	// メイン MDI フレームを作成します
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;

	// 共通の MDI メニューとアクセラレータ テーブルを読み込みます
	//TODO: 追加のメンバ変数を加えて、アプリケーションが必要とする
	//      追加のメニュータイプのために呼び出しをロードしてください。 
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_MDIPRATYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_MDIPRATYPE));

	// メイン ウィンドウが初期化されたので、表示と更新を行います。
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp message handlers

int CMDIPracticeApp::ExitInstance() 
{
	//TODO: 追加したリソースがある場合にはそれらも処理してください
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinApp::ExitInstance();
}

void CMDIPracticeApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);

	// 新しい MDI 子ウィンドウを作成します
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_MDIPRATYPE, m_hMDIMenu, m_hMDIAccel);
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
void CMDIPracticeApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp メッセージ ハンドラ
