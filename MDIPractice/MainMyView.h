#if !defined(AFX_MAINMYVIEW_H__612DD5AB_4111_4FA8_94F4_5033EDCC1719__INCLUDED_)
#define AFX_MAINMYVIEW_H__612DD5AB_4111_4FA8_94F4_5033EDCC1719__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainMyView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CMainMyView フォーム ビュー

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMainMyView : public CFormView
{
protected:
	DECLARE_DYNCREATE(CMainMyView)

// フォーム データ
public:
	CMainMyView();           // 動的生成に使用されるプロテクト コンストラクタ。

	//{{AFX_DATA(CMainMyView)
	enum { IDD = IDD_FORMVIEW };
		// メモ: ClassWizard はこの位置にデータメンバを追加します。
	//}}AFX_DATA

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMainMyView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CMainMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CMainMyView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MAINMYVIEW_H__612DD5AB_4111_4FA8_94F4_5033EDCC1719__INCLUDED_)
