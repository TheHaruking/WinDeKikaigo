#if !defined(AFX_EMU6502OUTPUTV2_H__D4877751_1A66_4FC0_AA58_FDB893D26990__INCLUDED_)
#define AFX_EMU6502OUTPUTV2_H__D4877751_1A66_4FC0_AA58_FDB893D26990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Emu6502OutputV2.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CEmu6502OutputV2 �t�H�[�� �r���[

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "Emu6502.h"

class CEmu6502OutputV2 : public CDialogBar
{
public:
	CEmu6502OutputV2();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	virtual ~CEmu6502OutputV2();

	DECLARE_DYNCREATE(CEmu6502OutputV2)

// �t�H�[�� �f�[�^
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

// �A�g���r���[�g
public:
	CEmu6502* m_cpu;

// �I�y���[�V����
public:
	void Update();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CEmu6502OutputV2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CEmu6502OutputV2)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_EMU6502OUTPUTV2_H__D4877751_1A66_4FC0_AA58_FDB893D26990__INCLUDED_)
