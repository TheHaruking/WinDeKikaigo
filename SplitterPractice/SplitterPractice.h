// SplitterPractice.h : SPLITTERPRACTICE �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_SPLITTERPRACTICE_H__82DC7C3A_88C8_4DDB_9B97_56F9391E7A58__INCLUDED_)
#define AFX_SPLITTERPRACTICE_H__82DC7C3A_88C8_4DDB_9B97_56F9391E7A58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� SplitterPractice.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CSplitterPracticeApp : public CWinApp
{
public:
	CSplitterPracticeApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSplitterPracticeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CSplitterPracticeApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SPLITTERPRACTICE_H__82DC7C3A_88C8_4DDB_9B97_56F9391E7A58__INCLUDED_)
