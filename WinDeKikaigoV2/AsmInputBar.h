#if !defined(AFX_ASMINPUTDLG_H__AEFAE611_F6CA_4A17_B1A3_34D5042F681E__INCLUDED_)
#define AFX_ASMINPUTDLG_H__AEFAE611_F6CA_4A17_B1A3_34D5042F681E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmInputDlg.h : �w�b�_�[ �t�@�C��
//

// �錾
#include "WinDeKikaigoV2Doc.h"

class CAsmViewV2; // ���ݎQ��

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBar �_�C�A���O

class CAsmInputBar : public CDialogBar
{
// �R���X�g���N�V����
public:
	CAsmInputBar();   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAsmInputBar)
	enum { IDD = IDD_DIALOGBAR_R };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAsmInputBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

public:
	CWinDeKikaigoV2Doc* m_pDoc; // AsmView ����擾.
	CAsmViewV2* m_pAsmView;

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAsmInputBar)
	afx_msg void OnInputLda();
	//}}AFX_MSG
	afx_msg LONG OnInitDialog(UINT, LONG);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ASMINPUTDLG_H__AEFAE611_F6CA_4A17_B1A3_34D5042F681E__INCLUDED_)
