// WinDeKikaigoV2View.h : CWinDeKikaigoV2View �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDEKIKAIGOV2VIEW_H__699D2E35_C571_4FA7_9194_42F47E612059__INCLUDED_)
#define AFX_WINDEKIKAIGOV2VIEW_H__699D2E35_C571_4FA7_9194_42F47E612059__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WinDeKikaigoV2Doc.h"

class CWinDeKikaigoV2View : public CView
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CWinDeKikaigoV2View();
	DECLARE_DYNCREATE(CWinDeKikaigoV2View)

// �A�g���r���[�g
public:
	CWinDeKikaigoV2Doc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CWinDeKikaigoV2View)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CWinDeKikaigoV2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CWinDeKikaigoV2View)
		// ���� -  ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//         ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WinDeKikaigoV2View.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CWinDeKikaigoV2Doc* CWinDeKikaigoV2View::GetDocument()
   { return (CWinDeKikaigoV2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_WINDEKIKAIGOV2VIEW_H__699D2E35_C571_4FA7_9194_42F47E612059__INCLUDED_)
