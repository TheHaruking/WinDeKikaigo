// WinDeKikaigoDoc.h : CWinDeKikaigoDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDEKIKAIGODOC_H__64D758FE_FDCD_430C_849D_8AB8A8E2CC77__INCLUDED_)
#define AFX_WINDEKIKAIGODOC_H__64D758FE_FDCD_430C_849D_8AB8A8E2CC77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWinDeKikaigoDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CWinDeKikaigoDoc();
	DECLARE_DYNCREATE(CWinDeKikaigoDoc)

/*******************************************************************/
// アトリビュート
/*******************************************************************/
public:
	BYTE testBytes[0xFFFF];


// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CWinDeKikaigoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CWinDeKikaigoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CWinDeKikaigoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_WINDEKIKAIGODOC_H__64D758FE_FDCD_430C_849D_8AB8A8E2CC77__INCLUDED_)
