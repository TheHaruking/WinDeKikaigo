// WinDeKikaigoDoc.h : CWinDeKikaigoDoc �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDEKIKAIGODOC_H__64D758FE_FDCD_430C_849D_8AB8A8E2CC77__INCLUDED_)
#define AFX_WINDEKIKAIGODOC_H__64D758FE_FDCD_430C_849D_8AB8A8E2CC77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWinDeKikaigoDoc : public CDocument
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CWinDeKikaigoDoc();
	DECLARE_DYNCREATE(CWinDeKikaigoDoc)

/*******************************************************************/
// �A�g���r���[�g
/*******************************************************************/
public:
	BYTE testBytes[0xFFFF];


// �I�y���[�V����
public:

//�I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CWinDeKikaigoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CWinDeKikaigoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CWinDeKikaigoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_WINDEKIKAIGODOC_H__64D758FE_FDCD_430C_849D_8AB8A8E2CC77__INCLUDED_)
