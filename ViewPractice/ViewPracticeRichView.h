#if !defined(AFX_VIEWPRACTICERICHVIEW_H__751A5613_D5BB_40FB_9493_D6A5D4B34625__INCLUDED_)
#define AFX_VIEWPRACTICERICHVIEW_H__751A5613_D5BB_40FB_9493_D6A5D4B34625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeRichView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView ビュー

class CViewPracticeRichView : public CRichEditView
{
protected:
	CViewPracticeRichView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CViewPracticeRichView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CViewPracticeRichView)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CViewPracticeRichView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CViewPracticeRichView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICERICHVIEW_H__751A5613_D5BB_40FB_9493_D6A5D4B34625__INCLUDED_)
