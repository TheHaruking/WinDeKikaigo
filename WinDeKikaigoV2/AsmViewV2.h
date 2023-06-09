#if !defined(AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_)
#define AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmViewV2.h : ヘッダー ファイル
//

#include "WinDeKikaigoV2Doc.h"
#include "AddrInputDlg.h"

class CAsmInputBar; // 相互参照

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 ビュー

class CAsmViewV2 : public CScrollView
{
protected:
	CAsmViewV2();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CAsmViewV2)

// アトリビュート
public:
	void BinToAsmObj();
	LONG GetAsmSel();
	void SetAsmObj(LONG n, BYTE* data);
	void AsmObjToBin();

	CWinDeKikaigoV2Doc* GetDocument();

protected:
	// ASMOBJ 構造体
	// 概要 : Asm -> Bin 変換のためのデータ配列
	typedef struct {
		typedef enum {
			TEXT, DATA, END
		} ASMOBJTYPE;
		/***********/
		ASMOBJTYPE type;
		LONG nSize;
		BYTE data[4];
	} ASMOBJ;

// オペレーション
public:
	enum {
		OP_UND, // 0
		// 読み書き
		OP_LDA, OP_LDX, OP_LDY, OP_STA, OP_STX, OP_STY,	// 1-6
		OP_TXA, OP_TYA, OP_TXS, OP_TAX, OP_TAY, OP_TSX,	// 7-12
		OP_PHA, OP_PHP, OP_PLA, OP_PLP,					// 13-16
		// 計算
		OP_AND, OP_ORA, OP_EOR, OP_ADC, OP_SBC,			// 17-20
		OP_ASL, OP_LSR, OP_ROL, OP_ROR,					// 21-24
		OP_INC, OP_INX, OP_INY, OP_DEC, OP_DEX, OP_DEY,	// 25-30
		OP_CMP, OP_CPX, OP_CPY, OP_BIT,					// 31-34
		// 移動
		OP_JMP, OP_JSR, OP_RTS, OP_BRK, OP_RTI,			// 35-39
		OP_BEQ, OP_BNE, OP_BMI, OP_BPL,					// 40-43
		OP_BCS, OP_BCC, OP_BVS, OP_BVC,					// 44-47
		OP_CLI, OP_CLD, OP_CLC, OP_CLV,					// 48-51
		OP_SEI, OP_SED, OP_SEC, OP_NOP,					// 52-55
		OP_MAX
	};
	// resource.h の IDC_PANE_LDA 等もこの順番に準ずる

	enum {
		ADR_NONE, ADR_A, ADR_REL,
		ADR_IMM, ADR_ZR, ADR_AD,
		ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
		ADR_INX, ADR_INY, ADR_IN,
		ADR_MAX
	};
	
	// 変換テーブル
	static const DWORD BIN2OP[256];
	static const DWORD BIN2ADR[256];
	static const LPTSTR OP2ASM[OP_MAX];
	static const DWORD ADR2OPR[ADR_MAX];
	static const LPTSTR ADR2STR[ADR_MAX];
	static const LONG ADR2VALPOS[ADR_MAX];
	static const LPTSTR ADR2VAL[ADR_MAX];
	static const LONG ASM2ADR[OP_MAX][11];

protected:
	// メンバ変数
	LONG m_num2ip[PAGESIZE];		// クリック座標からipを紐付ける
	LONG m_num2width[PAGESIZE][2];	// クリック座標から AddrInputDlg のための横幅(開始,終端)を取得.
	LONG m_ip2num[PAGESIZE];		// ip から ASM オブジェクトを紐付ける

	LONG m_nCurSel; // 現在選択中の ASM オブジェクト
	LONG m_nCurIp;  // 現在選択中の Instruction Pointer

	ASMOBJ m_AsmObj[PAGESIZE+1]; // 要終端
	BYTE   m_AsmObjToBinBuf[PAGESIZE+4]; // JMP (3バイト) 命令で 2 バイトはみ出る. 余裕を持たせた buf を用意.

	CBitmap m_bmp[OP_MAX];
	CDC m_bmpdc[OP_MAX];
	CFont m_font;

	CBitmap m_bmpCur;
	CDC m_bmpdcCur;

	CAddrInputDlg m_AddrInputDlg;

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CAsmViewV2)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CAsmViewV2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CAsmViewV2)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp ファイルがデバッグ環境の時使用されます。
inline CWinDeKikaigoV2Doc* CAsmViewV2::GetDocument()
   { return (CWinDeKikaigoV2Doc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_)
