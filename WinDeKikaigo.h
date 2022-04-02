// WinDeKikaigo.h : WINDEKIKAIGO アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_WINDEKIKAIGO_H__654291BD_8A9B_424C_8374_E46633D6A3D2__INCLUDED_)
#define AFX_WINDEKIKAIGO_H__654291BD_8A9B_424C_8374_E46633D6A3D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoApp:
// このクラスの動作の定義に関しては WinDeKikaigo.cpp ファイルを参照してください。
//

class CWinDeKikaigoApp : public CWinApp
{
public:
	CWinDeKikaigoApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CWinDeKikaigoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CWinDeKikaigoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_WINDEKIKAIGO_H__654291BD_8A9B_424C_8374_E46633D6A3D2__INCLUDED_)
