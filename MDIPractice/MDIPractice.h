// MDIPractice.h : MDIPRACTICE �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_MDIPRACTICE_H__CA563FB8_1E2A_47EF_88FF_BD0C491AD9E8__INCLUDED_)
#define AFX_MDIPRACTICE_H__CA563FB8_1E2A_47EF_88FF_BD0C491AD9E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CMDIPracticeApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� MDIPractice.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CMDIPracticeApp : public CWinApp
{
public:
	CMDIPracticeApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CMDIPracticeApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	//{{AFX_MSG(CMDIPracticeApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MDIPRACTICE_H__CA563FB8_1E2A_47EF_88FF_BD0C491AD9E8__INCLUDED_)
