#if !defined(AFX_VALUEVIEW_H__62E19D42_D0EF_457E_83B4_A9E2FDC23C59__INCLUDED_)
#define AFX_VALUEVIEW_H__62E19D42_D0EF_457E_83B4_A9E2FDC23C59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ValueView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CValueView フォーム ビュー

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CWinDeKikaigoDoc;

class CValueView : public CFormView
{
protected:
	CValueView();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(CValueView)

// フォーム データ
public:
	//{{AFX_DATA(CValueView)
	enum { IDD = IDD_VALUEVIEW };
	CEdit	m_edit4;
	CEdit	m_edit3;
	CEdit	m_edit2;
	CEdit	m_edit1;
	CComboBox	m_combo1;
	//}}AFX_DATA

// アトリビュート
public:
	CWinDeKikaigoDoc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CValueView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CValueView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CValueView)
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

inline CWinDeKikaigoDoc* CValueView::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VALUEVIEW_H__62E19D42_D0EF_457E_83B4_A9E2FDC23C59__INCLUDED_)
