// WinDeKikaigoV2.h : WINDEKIKAIGOV2 アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_WINDEKIKAIGOV2_H__B21DA008_3D09_49AB_A83A_AC1F3995BD4C__INCLUDED_)
#define AFX_WINDEKIKAIGOV2_H__B21DA008_3D09_49AB_A83A_AC1F3995BD4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2App:
// このクラスの動作の定義に関しては WinDeKikaigoV2.cpp ファイルを参照してください。
//

class CWinDeKikaigoV2App : public CWinApp
{
public:
	CWinDeKikaigoV2App();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CWinDeKikaigoV2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CWinDeKikaigoV2App)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_WINDEKIKAIGOV2_H__B21DA008_3D09_49AB_A83A_AC1F3995BD4C__INCLUDED_)
