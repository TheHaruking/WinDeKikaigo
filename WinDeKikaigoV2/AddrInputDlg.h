#if !defined(AFX_ADDRINPUTDLG_H__6E43E5B9_85CC_4650_B939_DA0FF958585D__INCLUDED_)
#define AFX_ADDRINPUTDLG_H__6E43E5B9_85CC_4650_B939_DA0FF958585D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddrInputDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CAddrInputDlg �_�C�A���O

class CAddrInputDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CAddrInputDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAddrInputDlg)
	enum { IDD = IDD_ADDRINPUTDLG };
	CEdit	m_edit1;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAddrInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAddrInputDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ADDRINPUTDLG_H__6E43E5B9_85CC_4650_B939_DA0FF958585D__INCLUDED_)
