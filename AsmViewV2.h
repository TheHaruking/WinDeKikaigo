#if !defined(AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_)
#define AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmViewV2.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 ビュー

class CAsmViewV2 : public CView
{
protected:
	CAsmViewV2();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CAsmViewV2)

// アトリビュート
public:
	CWinDeKikaigoDoc* GetDocument();

// オペレーション
protected:
	enum {
		OP_UND,
		OP_LDA, OP_LDX, OP_LDY, OP_STA, OP_STX, OP_STY, 
		OP_TXA, OP_TYA, OP_TXS, OP_TAX, OP_TAY, OP_TSX, 
		OP_PHA, OP_PHP, OP_PLA, OP_PLP, 
		OP_AND, OP_ORA, OP_EOR, OP_ADC, OP_SBC,
		OP_ASL, OP_LSR, OP_ROL, OP_ROR, 
		OP_INC, OP_INX, OP_INY, OP_DEC, OP_DEX, OP_DEY, 
		OP_CMP, OP_CPX, OP_CPY, OP_BIT, 
		OP_JMP, OP_JSR, OP_RTS, OP_BRK, OP_RTI, 
		OP_BEQ, OP_BNE, OP_BMI, OP_BPL, 
		OP_BCS, OP_BCC, OP_BVS, OP_BVC, 
		OP_SEI, OP_SED, OP_SEC, 
		OP_CLI, OP_CLD, OP_CLC, OP_CLV,  
		OP_NOP
	};

	enum {
		ADR_NONE, ADR_IMM, ADR_ZR, ADR_AD,
		ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
		ADR_INDX, ADR_INDY, ADR_IND,
	};

	static const DWORD BIN2OP[256];
	static const DWORD BIN2ADR[256];

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CAsmViewV2)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp ファイルがデバッグ環境の時使用されます。
inline CWinDeKikaigoDoc* CAsmViewV2::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_)
