#if !defined(AFX_CHILDMYVIEW_H__4CC009EF_3F40_4FF0_80DE_47C82D27C6C9__INCLUDED_)
#define AFX_CHILDMYVIEW_H__4CC009EF_3F40_4FF0_80DE_47C82D27C6C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildMyView ウィンドウ

class CChildMyView : public CWnd
{
// コンストラクション
public:
	CChildMyView();
	DECLARE_DYNCREATE(CChildMyView)

// アトリビュート
public:
	CStatic m_static;
	CEdit m_edit;
	CFont m_font;

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CChildMyView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CChildMyView();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CChildMyView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CHILDMYVIEW_H__4CC009EF_3F40_4FF0_80DE_47C82D27C6C9__INCLUDED_)
