#if !defined(AFX_VIEWPRACTICEFORMVIEW_H__48BF85F8_1990_4028_BB3C_DF32C71494E0__INCLUDED_)
#define AFX_VIEWPRACTICEFORMVIEW_H__48BF85F8_1990_4028_BB3C_DF32C71494E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeFormView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView フォーム ビュー

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CViewPracticeFormView : public CFormView
{
protected:
	CViewPracticeFormView();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(CViewPracticeFormView)

// フォーム データ
public:
	//{{AFX_DATA(CViewPracticeFormView)
	enum { IDD = IDD_FORMVIEW };
		// メモ: ClassWizard はこの位置にデータメンバを追加します。
	//}}AFX_DATA

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CViewPracticeFormView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CViewPracticeFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CViewPracticeFormView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICEFORMVIEW_H__48BF85F8_1990_4028_BB3C_DF32C71494E0__INCLUDED_)
