#if !defined(AFX_VIEWPRACTICESCROLLVIEW_H__D0CF38C6_7303_4E7B_BEAC_F148F07A4BB5__INCLUDED_)
#define AFX_VIEWPRACTICESCROLLVIEW_H__D0CF38C6_7303_4E7B_BEAC_F148F07A4BB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeScrollView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView ビュー

class ViewPracticeScrollView : public CScrollView
{
protected:
	ViewPracticeScrollView();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(ViewPracticeScrollView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(ViewPracticeScrollView)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnInitialUpdate();     // 構築後、最初の処理。
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~ViewPracticeScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ViewPracticeScrollView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICESCROLLVIEW_H__D0CF38C6_7303_4E7B_BEAC_F148F07A4BB5__INCLUDED_)
