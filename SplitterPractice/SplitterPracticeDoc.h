// SplitterPracticeDoc.h : CSplitterPracticeDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLITTERPRACTICEDOC_H__97B9C9FE_40DD_43A9_968D_3F841E7CF1BD__INCLUDED_)
#define AFX_SPLITTERPRACTICEDOC_H__97B9C9FE_40DD_43A9_968D_3F841E7CF1BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSplitterPracticeDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CSplitterPracticeDoc();
	DECLARE_DYNCREATE(CSplitterPracticeDoc)

// アトリビュート
public:

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSplitterPracticeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CSplitterPracticeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CSplitterPracticeDoc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SPLITTERPRACTICEDOC_H__97B9C9FE_40DD_43A9_968D_3F841E7CF1BD__INCLUDED_)
