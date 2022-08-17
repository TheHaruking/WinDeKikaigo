#if !defined(AFX_EMU6502OUTPUTV2_H__D4877751_1A66_4FC0_AA58_FDB893D26990__INCLUDED_)
#define AFX_EMU6502OUTPUTV2_H__D4877751_1A66_4FC0_AA58_FDB893D26990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Emu6502OutputV2.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CEmu6502OutputV2 フォーム ビュー

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "Emu6502.h"

class CEmu6502OutputV2 : public CDialogBar
{
public:
	CEmu6502OutputV2();           // 動的生成に使用されるプロテクト コンストラクタ。
	virtual ~CEmu6502OutputV2();

	DECLARE_DYNCREATE(CEmu6502OutputV2)

// フォーム データ
public:
	//{{AFX_DATA(CEmu6502OutputV2)
	enum { IDD = IDD_EMU6502OUTPUTV2_FORM };
	CButton	m_chkFlagZ;
	CButton	m_chkFlagV;
	CButton	m_chkFlagR;
	CButton	m_chkFlagN;
	CButton	m_chkFlagI;
	CButton	m_chkFlagD;
	CButton	m_chkFlagC;
	CButton	m_chkFlagB;
	CEdit	m_editStack;
	CEdit	m_editRegY;
	CEdit	m_editRegX;
	CEdit	m_editRegS;
	CEdit	m_editRegA;
	CEdit	m_editRegPC;
	//}}AFX_DATA

// アトリビュート
public:
	CEmu6502* m_cpu;

// オペレーション
public:
	void Update();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CEmu6502OutputV2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CEmu6502OutputV2)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_EMU6502OUTPUTV2_H__D4877751_1A66_4FC0_AA58_FDB893D26990__INCLUDED_)
