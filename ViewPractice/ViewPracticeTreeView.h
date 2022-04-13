#if !defined(AFX_VIEWPRACTICETREEVIEW_H__9B38779B_6E75_4BD5_BB40_E161DCB4FFF5__INCLUDED_)
#define AFX_VIEWPRACTICETREEVIEW_H__9B38779B_6E75_4BD5_BB40_E161DCB4FFF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeTreeView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView ビュー

class CViewPracticeTreeView : public CTreeView
{
protected:
	CViewPracticeTreeView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CViewPracticeTreeView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CViewPracticeTreeView)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CViewPracticeTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CViewPracticeTreeView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICETREEVIEW_H__9B38779B_6E75_4BD5_BB40_E161DCB4FFF5__INCLUDED_)
