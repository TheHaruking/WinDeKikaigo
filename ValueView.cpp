// ValueView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "ValueView.h"

#include "WinDeKikaigoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CValueView

IMPLEMENT_DYNCREATE(CValueView, CFormView)

CValueView::CValueView()
	: CFormView(CValueView::IDD)
{
	//{{AFX_DATA_INIT(CValueView)
		// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//}}AFX_DATA_INIT
}

CValueView::~CValueView()
{
}

void CValueView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CValueView)
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_VALUE_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CValueView, CFormView)
	//{{AFX_MSG_MAP(CValueView)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValueView 診断

#ifdef _DEBUG
void CValueView::AssertValid() const
{
	CFormView::AssertValid();
}

void CValueView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CValueView メッセージ ハンドラ

void CValueView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	m_combo1.InsertString(-1, L"u�@�@�@�@ (uint8_t)"); // "-1" : 最後尾に追加
	m_combo1.InsertString(-1, L"u�A�A (uint16_t)");
	m_combo1.InsertString(-1, L"u�C (uint32_t)");
	m_combo1.InsertString(-1, L"s�@�@�@�@ (int8_t)");
	m_combo1.InsertString(-1, L"s�A�A (int16_t)");
	m_combo1.InsertString(-1, L"s�C (int32_t)");
	m_combo1.InsertString(-1, L"f�C (float)");
	m_combo1.InsertString(-1, L"------------------------");
	m_combo1.InsertString(-1, L"u�@のアドレス (uint8_t*)");
	m_combo1.InsertString(-1, L"u�Aのアドレス (uint16_t*)");
	m_combo1.InsertString(-1, L"u�Cのアドレス (uint32_t*)");
	m_combo1.InsertString(-1, L"s�@のアドレス (int8_t*)");
	m_combo1.InsertString(-1, L"s�Aのアドレス (int16_t*)");
	m_combo1.InsertString(-1, L"s�Cのアドレス (int32_t*)");
	m_combo1.InsertString(-1, L"f�Cのアドレス (float*)");
}

void CValueView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
}

void CValueView::OnChangeEdit1() 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();	
	
	UpdateData(TRUE);  // コントロールからデータを取得

	// 準備
	CString strBuf; // 入力文字列
	BYTE byteBuf;	// 入力文字列を数値化
	wchar_t* retp;	// wcstol の結果

	m_edit1.GetWindowText(strBuf);
	byteBuf = (BYTE)wcstol(strBuf, &retp, 10);

	// データ適用
	pDoc->testBytes[0] = byteBuf;
	pDoc->UpdateAllViews(NULL);
}
