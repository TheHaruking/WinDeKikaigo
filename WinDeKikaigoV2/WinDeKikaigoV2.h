// WinDeKikaigoV2.h : WINDEKIKAIGOV2 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_WINDEKIKAIGOV2_H__B21DA008_3D09_49AB_A83A_AC1F3995BD4C__INCLUDED_)
#define AFX_WINDEKIKAIGOV2_H__B21DA008_3D09_49AB_A83A_AC1F3995BD4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2App:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� WinDeKikaigoV2.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CWinDeKikaigoV2App : public CWinApp
{
public:
	CWinDeKikaigoV2App();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CWinDeKikaigoV2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CWinDeKikaigoV2App)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_WINDEKIKAIGOV2_H__B21DA008_3D09_49AB_A83A_AC1F3995BD4C__INCLUDED_)
