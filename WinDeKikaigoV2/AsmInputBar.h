#if !defined(AFX_ASMINPUTDLG_H__AEFAE611_F6CA_4A17_B1A3_34D5042F681E__INCLUDED_)
#define AFX_ASMINPUTDLG_H__AEFAE611_F6CA_4A17_B1A3_34D5042F681E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmInputDlg.h : ヘッダー ファイル
//

// 宣言
#include "WinDeKikaigoV2Doc.h"

class CAsmViewV2; // 相互参照

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBar ダイアログ

class CAsmInputBar : public CDialogBar
{
// コンストラクション
public:
	CAsmInputBar();   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CAsmInputBar)
	enum { IDD = IDD_DIALOGBAR_R };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAsmInputBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

public:
	CWinDeKikaigoV2Doc* m_pDoc; // AsmView から取得.
	CAsmViewV2* m_pAsmView;

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAsmInputBar)
	afx_msg void OnInputLda();
	//}}AFX_MSG
	afx_msg LONG OnInitDialog(UINT, LONG);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ASMINPUTDLG_H__AEFAE611_F6CA_4A17_B1A3_34D5042F681E__INCLUDED_)
