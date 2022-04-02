#if !defined(AFX_ASMVIEW_H__781864A8_7031_4C0C_B06B_8A1FDD852E61__INCLUDED_)
#define AFX_ASMVIEW_H__781864A8_7031_4C0C_B06B_8A1FDD852E61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CAsmView フォーム ビュー

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "WinDeKikaigoDoc.h"

class CAsmView : public CFormView
{
protected:
	CAsmView();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(CAsmView)

// フォーム データ
public:
	//{{AFX_DATA(CAsmView)
	enum { IDD = IDD_ASMVIEW };
	CComboBox	m_combo4;
	CComboBox	m_combo3;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	//}}AFX_DATA

// アトリビュート
public:
	CWinDeKikaigoDoc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAsmView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CAsmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAsmView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp ファイルがデバッグ環境の時使用されます。
inline CWinDeKikaigoDoc* CLeftView::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ASMVIEW_H__781864A8_7031_4C0C_B06B_8A1FDD852E61__INCLUDED_)
