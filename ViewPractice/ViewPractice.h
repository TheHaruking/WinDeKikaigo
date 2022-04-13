// ViewPractice.h : VIEWPRACTICE アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_VIEWPRACTICE_H__0D481A1B_E082_4610_A3F2_A9FCDA7BBB74__INCLUDED_)
#define AFX_VIEWPRACTICE_H__0D481A1B_E082_4610_A3F2_A9FCDA7BBB74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeApp:
// このクラスの動作の定義に関しては ViewPractice.cpp ファイルを参照してください。
//

class CViewPracticeApp : public CWinApp
{
public:
	CViewPracticeApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CViewPracticeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CViewPracticeApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICE_H__0D481A1B_E082_4610_A3F2_A9FCDA7BBB74__INCLUDED_)
