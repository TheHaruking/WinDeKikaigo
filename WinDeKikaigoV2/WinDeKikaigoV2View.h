// WinDeKikaigoV2View.h : CWinDeKikaigoV2View クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDEKIKAIGOV2VIEW_H__699D2E35_C571_4FA7_9194_42F47E612059__INCLUDED_)
#define AFX_WINDEKIKAIGOV2VIEW_H__699D2E35_C571_4FA7_9194_42F47E612059__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WinDeKikaigoV2Doc.h"

class CWinDeKikaigoV2View : public CView
{
protected: // シリアライズ機能のみから作成します。
	CWinDeKikaigoV2View();
	DECLARE_DYNCREATE(CWinDeKikaigoV2View)

// アトリビュート
public:
	CWinDeKikaigoV2Doc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CWinDeKikaigoV2View)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CWinDeKikaigoV2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CWinDeKikaigoV2View)
		// メモ -  ClassWizard はこの位置にメンバ関数を追加または削除します。
		//         この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WinDeKikaigoV2View.cpp ファイルがデバッグ環境の時使用されます。
inline CWinDeKikaigoV2Doc* CWinDeKikaigoV2View::GetDocument()
   { return (CWinDeKikaigoV2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_WINDEKIKAIGOV2VIEW_H__699D2E35_C571_4FA7_9194_42F47E612059__INCLUDED_)
