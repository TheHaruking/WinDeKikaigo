#if !defined(AFX_VIEWPRACTICECVIEW_H__7F76A666_8F1D_4FF0_973D_6E15F157D7E7__INCLUDED_)
#define AFX_VIEWPRACTICECVIEW_H__7F76A666_8F1D_4FF0_973D_6E15F157D7E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeCView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView ビュー

class CViewPracticeCView : public CView
{
protected:
	CViewPracticeCView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CViewPracticeCView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CViewPracticeCView)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CViewPracticeCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CViewPracticeCView)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICECVIEW_H__7F76A666_8F1D_4FF0_973D_6E15F157D7E7__INCLUDED_)
