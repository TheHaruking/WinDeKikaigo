#if !defined(AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_)
#define AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VmWindow.h : ヘッダー ファイル
//

#include "WinDeKikaigoV2Doc.h"

#define VM_WIDTH	256
#define VM_HEIGHT	192
#define VM_BMPNUM	256
#define VM_SPRNUM	64 // 多くなるほど遅い. (VM 環境で顕著)

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

	struct VMBITMAP {
		HBITMAP hBitmap;
		HDC hBitmapDC;
		LONG hBitmapWidth;
		LONG hBitmapHeight;
		LONG x;
		LONG y;
	} m_vbmpList[VM_BMPNUM];

	struct SPRITEMEM {
		BYTE id;
		BYTE reserved;
		BYTE x;
		BYTE y;
	} *m_pSprList;

	struct PALETTEMEM {
		BYTE r;
		BYTE g;
		BYTE b;
		BYTE reserved;
	} *m_pPalette;

private:

	void LoadBitmapFileToArrayObj(VMBITMAP* vmBitmap, LONG n);

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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_)
