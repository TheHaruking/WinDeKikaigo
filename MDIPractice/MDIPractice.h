// MDIPractice.h : MDIPRACTICE アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_MDIPRACTICE_H__CA563FB8_1E2A_47EF_88FF_BD0C491AD9E8__INCLUDED_)
#define AFX_MDIPRACTICE_H__CA563FB8_1E2A_47EF_88FF_BD0C491AD9E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp:
// このクラスの動作の定義に関しては MDIPractice.cpp ファイルを参照してください。
//

class CMDIPracticeApp : public CWinApp
{
public:
	CMDIPracticeApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMDIPracticeApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	//{{AFX_MSG(CMDIPracticeApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MDIPRACTICE_H__CA563FB8_1E2A_47EF_88FF_BD0C491AD9E8__INCLUDED_)
