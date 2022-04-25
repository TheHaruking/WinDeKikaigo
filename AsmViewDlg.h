#if !defined(AFX_ASMVIEWDLG_H__31322062_8822_44BE_AA05_37489738ADAC__INCLUDED_)
#define AFX_ASMVIEWDLG_H__31322062_8822_44BE_AA05_37489738ADAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmViewDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg ダイアログ

class CAsmViewDlg : public CDialog
{
// コンストラクション
public:
	CAsmViewDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CAsmViewDlg)
	enum { IDD = IDD_ASMDLG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAsmViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAsmViewDlg)
		// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ASMVIEWDLG_H__31322062_8822_44BE_AA05_37489738ADAC__INCLUDED_)
