// MainFrm.h : CMainFrame クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__C505CD39_5989_46DC_8B56_86DED598BDA6__INCLUDED_)
#define AFX_MAINFRM_H__C505CD39_5989_46DC_8B56_86DED598BDA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AsmInputBar.h"
#include "Emu6502.h"

class CMainFrame : public CFrameWnd
{
	
protected: // シリアライズ機能のみから作成します。
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	void OnInputLda();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // コントロール バー用メンバ
	CStatusBar   m_wndStatusBar;
	CToolBar     m_wndToolBar;
	// 追加
	CDialogBar   m_wndDialogBar_L;
	CAsmInputBar m_wndDialogBar_R;
	CSplitterWnd m_wndSplitter;

	CEmu6502 m_cpu;

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAppLeftpane();
	afx_msg void OnAppRightpane();
	afx_msg void OnAppDebug();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MAINFRM_H__C505CD39_5989_46DC_8B56_86DED598BDA6__INCLUDED_)
