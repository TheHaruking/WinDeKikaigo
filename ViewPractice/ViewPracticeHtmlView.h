#if !defined(AFX_VIEWPRACTICEHTMLVIEW_H__14EC81D2_3199_407F_BC6C_E20EF1F42082__INCLUDED_)
#define AFX_VIEWPRACTICEHTMLVIEW_H__14EC81D2_3199_407F_BC6C_E20EF1F42082__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeHtmlView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView HTML ビュー

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>

class CViewPracticeHtmlView : public CHtmlView
{
protected:
	CViewPracticeHtmlView();           // 動的生成で使用される protected コンストラクタ
	DECLARE_DYNCREATE(CViewPracticeHtmlView)

// html Data
public:
	//{{AFX_DATA(CViewPracticeHtmlView)
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CViewPracticeHtmlView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CViewPracticeHtmlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CViewPracticeHtmlView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICEHTMLVIEW_H__14EC81D2_3199_407F_BC6C_E20EF1F42082__INCLUDED_)
