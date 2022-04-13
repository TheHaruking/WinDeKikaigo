// ViewPracticeView.h : CViewPracticeView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWPRACTICEVIEW_H__866D9FCA_E348_4638_9217_9CB59E2FDE33__INCLUDED_)
#define AFX_VIEWPRACTICEVIEW_H__866D9FCA_E348_4638_9217_9CB59E2FDE33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewPracticeView : public CEditView
{
protected: // シリアライズ機能のみから作成します。
	CViewPracticeView();
	DECLARE_DYNCREATE(CViewPracticeView)

// アトリビュート
public:
	CViewPracticeDoc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CViewPracticeView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CViewPracticeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CViewPracticeView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ViewPracticeView.cpp ファイルがデバッグ環境の時使用されます。
inline CViewPracticeDoc* CViewPracticeView::GetDocument()
   { return (CViewPracticeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICEVIEW_H__866D9FCA_E348_4638_9217_9CB59E2FDE33__INCLUDED_)
