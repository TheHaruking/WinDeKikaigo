// ViewPracticeDoc.h : CViewPracticeDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWPRACTICEDOC_H__CF4EF643_34B5_4F93_B30B_04B76760902B__INCLUDED_)
#define AFX_VIEWPRACTICEDOC_H__CF4EF643_34B5_4F93_B30B_04B76760902B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewPracticeDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CViewPracticeDoc();
	DECLARE_DYNCREATE(CViewPracticeDoc)

// アトリビュート
public:

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CViewPracticeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CViewPracticeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CViewPracticeDoc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_VIEWPRACTICEDOC_H__CF4EF643_34B5_4F93_B30B_04B76760902B__INCLUDED_)
