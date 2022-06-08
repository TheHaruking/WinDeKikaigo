#if !defined(AFX_ASMINPUTBARDLG_H__57558B06_D8C8_474E_8667_ACB6070937C5__INCLUDED_)
#define AFX_ASMINPUTBARDLG_H__57558B06_D8C8_474E_8667_ACB6070937C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmInputBarDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg ダイアログ

class CAsmInputBarDlg : public CDialog
{
// コンストラクション
public:
	CAsmInputBarDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CAsmInputBarDlg)
	enum { IDD = IDD_ASMINPUTBARDLG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAsmInputBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

public:
	DWORD m_dwSelect;

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAsmInputBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAsmdlg1();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ASMINPUTBARDLG_H__57558B06_D8C8_474E_8667_ACB6070937C5__INCLUDED_)
