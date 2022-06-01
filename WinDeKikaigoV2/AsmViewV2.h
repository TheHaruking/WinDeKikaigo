#if !defined(AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_)
#define AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmViewV2.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 �r���[

class CAsmViewV2 : public CView
{
protected:
	CAsmViewV2();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^
	DECLARE_DYNCREATE(CAsmViewV2)

// �A�g���r���[�g
public:
	CWinDeKikaigoV2Doc* GetDocument();

// �I�y���[�V����
protected:
	enum {
		OP_UND, // 0
		// �ǂݏ���
		OP_LDA, OP_LDX, OP_LDY, OP_STA, OP_STX, OP_STY,	// 1-6
		OP_TXA, OP_TYA, OP_TXS, OP_TAX, OP_TAY, OP_TSX,	// 7-12
		OP_PHA, OP_PHP, OP_PLA, OP_PLP,					// 13-16
		// �v�Z
		OP_AND, OP_ORA, OP_EOR, OP_ADC, OP_SBC,			// 17-20
		OP_ASL, OP_LSR, OP_ROL, OP_ROR,					// 21-24
		OP_INC, OP_INX, OP_INY, OP_DEC, OP_DEX, OP_DEY,	// 25-30
		OP_CMP, OP_CPX, OP_CPY, OP_BIT,					// 31-34
		// �ړ�
		OP_JMP, OP_JSR, OP_RTS, OP_BRK, OP_RTI,			// 35-39
		OP_BEQ, OP_BNE, OP_BMI, OP_BPL,					// 40-43
		OP_BCS, OP_BCC, OP_BVS, OP_BVC,					// 44-47
		OP_CLI, OP_CLD, OP_CLC, OP_CLV,					// 48-51
		OP_SEI, OP_SED, OP_SEC, OP_NOP,					// 52-55
		OP_MAX
	};

	enum {
		ADR_NONE,
		ADR_IMM, ADR_ZR, ADR_AD,
		ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
		ADR_INDX, ADR_INDY, ADR_IND,
		ADR_MAX
	};

	static const DWORD BIN2OP[256];
	static const DWORD BIN2ADR[256];
	static const LPTSTR OP2ASM[OP_MAX];
	static const DWORD ADR2OPR[ADR_MAX];
	static const LPTSTR ADR2STR[ADR_MAX];

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CAsmViewV2)
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CAsmViewV2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CAsmViewV2)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CWinDeKikaigoV2Doc* CAsmViewV2::GetDocument()
   { return (CWinDeKikaigoV2Doc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ASMVIEWV2_H__492B3A1C_7588_43B2_823F_36E7D6C50E1E__INCLUDED_)
