// LeftView.h : CLeftView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__3F53A6A5_DF4B_4200_B00E_A30041FD0591__INCLUDED_)
#define AFX_LEFTVIEW_H__3F53A6A5_DF4B_4200_B00E_A30041FD0591__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSplitterPracticeDoc;

class CLeftView : public CTreeView
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// �A�g���r���[�g
public:
	CSplitterPracticeDoc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // �\�z��̍ŏ��̂P�x�����Ăяo����܂��B
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CLeftView)
		// ���� -  ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//         ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LeftView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CSplitterPracticeDoc* CLeftView::GetDocument()
   { return (CSplitterPracticeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_LEFTVIEW_H__3F53A6A5_DF4B_4200_B00E_A30041FD0591__INCLUDED_)
