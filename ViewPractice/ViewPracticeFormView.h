#if !defined(AFX_VIEWPRACTICEFORMVIEW_H__48BF85F8_1990_4028_BB3C_DF32C71494E0__INCLUDED_)
#define AFX_VIEWPRACTICEFORMVIEW_H__48BF85F8_1990_4028_BB3C_DF32C71494E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeFormView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView �t�H�[�� �r���[

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CViewPracticeFormView : public CFormView
{
protected:
	CViewPracticeFormView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(CViewPracticeFormView)

// �t�H�[�� �f�[�^
public:
	//{{AFX_DATA(CViewPracticeFormView)
	enum { IDD = IDD_FORMVIEW };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^�����o��ǉ����܂��B
	//}}AFX_DATA

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CViewPracticeFormView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CViewPracticeFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CViewPracticeFormView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICEFORMVIEW_H__48BF85F8_1990_4028_BB3C_DF32C71494E0__INCLUDED_)
