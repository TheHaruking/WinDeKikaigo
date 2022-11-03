// WinDeKikaigoV2Doc.h : CWinDeKikaigoV2Doc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDEKIKAIGOV2DOC_H__FDCC2254_1604_4272_9C52_649F2816781B__INCLUDED_)
#define AFX_WINDEKIKAIGOV2DOC_H__FDCC2254_1604_4272_9C52_649F2816781B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWinDeKikaigoV2Doc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CWinDeKikaigoV2Doc();
	DECLARE_DYNCREATE(CWinDeKikaigoV2Doc)

// アトリビュート
public:
	BYTE m_data[0x10000]; // テスト用仮データ
	LONG m_nSel;

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CWinDeKikaigoV2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CWinDeKikaigoV2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CWinDeKikaigoV2Doc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_WINDEKIKAIGOV2DOC_H__FDCC2254_1604_4272_9C52_649F2816781B__INCLUDED_)
