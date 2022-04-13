#if !defined(AFX_VIEWPRACTICELISTVIEW_H__E14251CF_9133_4588_902C_12EEF8552483__INCLUDED_)
#define AFX_VIEWPRACTICELISTVIEW_H__E14251CF_9133_4588_902C_12EEF8552483__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeListView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView ビュー

class CViewPracticeListView : public CListView
{
protected:
	CViewPracticeListView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CViewPracticeListView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CViewPracticeListView)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CViewPracticeListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CViewPracticeListView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICELISTVIEW_H__E14251CF_9133_4588_902C_12EEF8552483__INCLUDED_)
