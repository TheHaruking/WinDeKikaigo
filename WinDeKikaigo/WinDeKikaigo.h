// WinDeKikaigo.h : WINDEKIKAIGO �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_WINDEKIKAIGO_H__654291BD_8A9B_424C_8374_E46633D6A3D2__INCLUDED_)
#define AFX_WINDEKIKAIGO_H__654291BD_8A9B_424C_8374_E46633D6A3D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� WinDeKikaigo.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CWinDeKikaigoApp : public CWinApp
{
public:
	CWinDeKikaigoApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CWinDeKikaigoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CWinDeKikaigoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_WINDEKIKAIGO_H__654291BD_8A9B_424C_8374_E46633D6A3D2__INCLUDED_)
