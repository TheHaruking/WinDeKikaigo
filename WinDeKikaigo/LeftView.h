// LeftView.h : CLeftView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__CC94AD99_D5B3_49F8_918B_F13A0D7904A7__INCLUDED_)
#define AFX_LEFTVIEW_H__CC94AD99_D5B3_49F8_918B_F13A0D7904A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWinDeKikaigoDoc;

class CLeftView : public CTreeView
{
protected: // シリアライズ機能のみから作成します。
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// アトリビュート
public:
	CWinDeKikaigoDoc* GetDocument();

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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LeftView.cpp ファイルがデバッグ環境の時使用されます。
inline CWinDeKikaigoDoc* CLeftView::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_LEFTVIEW_H__CC94AD99_D5B3_49F8_918B_F13A0D7904A7__INCLUDED_)
