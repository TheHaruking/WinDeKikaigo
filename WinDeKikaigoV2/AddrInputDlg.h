#if !defined(AFX_ADDRINPUTDLG_H__6E43E5B9_85CC_4650_B939_DA0FF958585D__INCLUDED_)
#define AFX_ADDRINPUTDLG_H__6E43E5B9_85CC_4650_B939_DA0FF958585D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddrInputDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CAddrInputDlg ダイアログ

class CAddrInputDlg : public CDialog
{
// コンストラクション
public:
	CAddrInputDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CAddrInputDlg)
	enum { IDD = IDD_ADDRINPUTDLG };
	CEdit	m_edit1;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAddrInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAddrInputDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ADDRINPUTDLG_H__6E43E5B9_85CC_4650_B939_DA0FF958585D__INCLUDED_)
