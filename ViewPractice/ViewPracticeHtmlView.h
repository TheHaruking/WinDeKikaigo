#if !defined(AFX_VIEWPRACTICEHTMLVIEW_H__14EC81D2_3199_407F_BC6C_E20EF1F42082__INCLUDED_)
#define AFX_VIEWPRACTICEHTMLVIEW_H__14EC81D2_3199_407F_BC6C_E20EF1F42082__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeHtmlView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView HTML �r���[

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>

class CViewPracticeHtmlView : public CHtmlView
{
protected:
	CViewPracticeHtmlView();           // ���I�����Ŏg�p����� protected �R���X�g���N�^
	DECLARE_DYNCREATE(CViewPracticeHtmlView)

// html Data
public:
	//{{AFX_DATA(CViewPracticeHtmlView)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CViewPracticeHtmlView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CViewPracticeHtmlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CViewPracticeHtmlView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICEHTMLVIEW_H__14EC81D2_3199_407F_BC6C_E20EF1F42082__INCLUDED_)
