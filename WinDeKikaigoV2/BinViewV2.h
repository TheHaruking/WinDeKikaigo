#if !defined(AFX_BINVIEWV2_H__1AF60E83_BD99_48B6_A10F_FE56B093AF1F__INCLUDED_)
#define AFX_BINVIEWV2_H__1AF60E83_BD99_48B6_A10F_FE56B093AF1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BinViewV2.h : ヘッダー ファイル
//

#include "WinDeKikaigoV2Doc.h"
#include "AsmViewV2.h"

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 ビュー

class CBinViewV2 : public CScrollView
{
protected:
	CBinViewV2();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CBinViewV2)

// アトリビュート
protected:
	void CaretPosUpdate();
	void DigitDown();
	void DigitUp();

public:
	CWinDeKikaigoV2Doc* GetDocument();

// オペレーション
protected:
	CFont m_font;
	LONG  m_nFontWidth;
	LONG  m_nFontHeight;
	LONG  m_nRowMargin;
	LONG  m_nMaxColumn;
	LONG  m_nSel;
	LONG  m_nSelEnd;
	BOOL  m_bIsSecond;
	enum KINDDIGIT {
		DIGIT_BYTE = 1,
		DIGIT_WORD = 2,
		DIGIT_DWORD = 4,
		DIGIT_QWORD = 8
	};
	KINDDIGIT m_eDigit;
	LONG  m_nAddrWidth;
	LONG  m_nDataXOfs;

// 定数
protected:
	static const BYTE DATA_KEY2HEX[];
	static const BYTE DATA_KEY2HEX10[];
	static const LPTSTR DATA_HEX2FMT[];

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CBinViewV2)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CBinViewV2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CBinViewV2)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp ファイルがデバッグ環境の時使用されます。
inline CWinDeKikaigoV2Doc* CBinViewV2::GetDocument()
   { return (CWinDeKikaigoV2Doc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_BINVIEWV2_H__1AF60E83_BD99_48B6_A10F_FE56B093AF1F__INCLUDED_)
