#if !defined(AFX_MYEDIT_H__EE7BBB39_0990_4166_B782_B980727FC033__INCLUDED_)
#define AFX_MYEDIT_H__EE7BBB39_0990_4166_B782_B980727FC033__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEdit.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CMyEdit ウィンドウ

class CMyEdit : public CEdit
{
// コンストラクション
public:
	CMyEdit();

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMyEdit)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CMyEdit();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CMyEdit)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MYEDIT_H__EE7BBB39_0990_4166_B782_B980727FC033__INCLUDED_)
