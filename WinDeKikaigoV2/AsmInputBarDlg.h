#if !defined(AFX_ASMINPUTBARDLG_H__57558B06_D8C8_474E_8667_ACB6070937C5__INCLUDED_)
#define AFX_ASMINPUTBARDLG_H__57558B06_D8C8_474E_8667_ACB6070937C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmInputBarDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg �_�C�A���O

class CAsmInputBarDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CAsmInputBarDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAsmInputBarDlg)
	enum { IDD = IDD_ASMINPUTBARDLG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAsmInputBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

public:
	DWORD m_dwSelect;

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAsmInputBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAsmdlg1();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ASMINPUTBARDLG_H__57558B06_D8C8_474E_8667_ACB6070937C5__INCLUDED_)
