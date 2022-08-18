#if !defined(AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_)
#define AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VmWindow.h : ヘッダー ファイル
//

#include "WinDeKikaigoV2Doc.h"

/////////////////////////////////////////////////////////////////////////////
// CVmWindow ウィンドウ

class CVmWindow : public CWnd
{
// コンストラクション
public:
	CVmWindow();

// アトリビュート
public:

// オペレーション
private:
	CWinDeKikaigoV2Doc* m_pDoc;
	BYTE* m_pBytes;
	BITMAPINFO* m_pBmi;
	DWORD m_dwScale;

// 定数
private:
	static const LONG WIDTH;
	static const LONG HEIGHT;

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CVmWindow)
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	BOOL CreateEx(CWnd* pParentWnd);
	void SetDocument(CWinDeKikaigoV2Doc* pDoc);
	virtual ~CVmWindow();
	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CVmWindow)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_)
