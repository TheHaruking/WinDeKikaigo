// ViewPractice.h : VIEWPRACTICE �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_VIEWPRACTICE_H__0D481A1B_E082_4610_A3F2_A9FCDA7BBB74__INCLUDED_)
#define AFX_VIEWPRACTICE_H__0D481A1B_E082_4610_A3F2_A9FCDA7BBB74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� ViewPractice.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CViewPracticeApp : public CWinApp
{
public:
	CViewPracticeApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CViewPracticeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CViewPracticeApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICE_H__0D481A1B_E082_4610_A3F2_A9FCDA7BBB74__INCLUDED_)
