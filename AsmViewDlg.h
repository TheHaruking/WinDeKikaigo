#if !defined(AFX_ASMVIEWDLG_H__31322062_8822_44BE_AA05_37489738ADAC__INCLUDED_)
#define AFX_ASMVIEWDLG_H__31322062_8822_44BE_AA05_37489738ADAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmViewDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg �_�C�A���O

class CAsmViewDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CAsmViewDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAsmViewDlg)
	enum { IDD = IDD_ASMDLG };
	CButton	m_btnLda;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAsmViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	CImageList m_imageList;
	CToolBar m_toolBar;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAsmViewDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ASMVIEWDLG_H__31322062_8822_44BE_AA05_37489738ADAC__INCLUDED_)
