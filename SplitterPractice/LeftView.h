// LeftView.h : CLeftView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__3F53A6A5_DF4B_4200_B00E_A30041FD0591__INCLUDED_)
#define AFX_LEFTVIEW_H__3F53A6A5_DF4B_4200_B00E_A30041FD0591__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSplitterPracticeDoc;

class CLeftView : public CTreeView
{
protected: // シリアライズ機能のみから作成します。
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// アトリビュート
public:
	CSplitterPracticeDoc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // 構築後の最初の１度だけ呼び出されます。
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CLeftView)
		// メモ -  ClassWizard はこの位置にメンバ関数を追加または削除します。
		//         この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LeftView.cpp ファイルがデバッグ環境の時使用されます。
inline CSplitterPracticeDoc* CLeftView::GetDocument()
   { return (CSplitterPracticeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_LEFTVIEW_H__3F53A6A5_DF4B_4200_B00E_A30041FD0591__INCLUDED_)
