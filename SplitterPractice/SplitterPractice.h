// SplitterPractice.h : SPLITTERPRACTICE アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_SPLITTERPRACTICE_H__82DC7C3A_88C8_4DDB_9B97_56F9391E7A58__INCLUDED_)
#define AFX_SPLITTERPRACTICE_H__82DC7C3A_88C8_4DDB_9B97_56F9391E7A58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeApp:
// このクラスの動作の定義に関しては SplitterPractice.cpp ファイルを参照してください。
//

class CSplitterPracticeApp : public CWinApp
{
public:
	CSplitterPracticeApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSplitterPracticeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CSplitterPracticeApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SPLITTERPRACTICE_H__82DC7C3A_88C8_4DDB_9B97_56F9391E7A58__INCLUDED_)
