// SplitterPracticeView.h : CSplitterPracticeView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLITTERPRACTICEVIEW_H__199E4CA4_01FE_402A_94C7_F58D1178CE18__INCLUDED_)
#define AFX_SPLITTERPRACTICEVIEW_H__199E4CA4_01FE_402A_94C7_F58D1178CE18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSplitterPracticeView : public CListView
{
protected: // シリアライズ機能のみから作成します。
	CSplitterPracticeView();
	DECLARE_DYNCREATE(CSplitterPracticeView)

// アトリビュート
public:
	CSplitterPracticeDoc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSplitterPracticeView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // 構築後の最初の１度だけ呼び出されます。
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CSplitterPracticeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CSplitterPracticeView)
		// メモ -  ClassWizard はこの位置にメンバ関数を追加または削除します。
		//         この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SplitterPracticeView.cpp ファイルがデバッグ環境の時使用されます。
inline CSplitterPracticeDoc* CSplitterPracticeView::GetDocument()
   { return (CSplitterPracticeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SPLITTERPRACTICEVIEW_H__199E4CA4_01FE_402A_94C7_F58D1178CE18__INCLUDED_)
