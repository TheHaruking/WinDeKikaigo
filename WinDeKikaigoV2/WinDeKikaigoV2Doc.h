// WinDeKikaigoV2Doc.h : CWinDeKikaigoV2Doc �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDEKIKAIGOV2DOC_H__FDCC2254_1604_4272_9C52_649F2816781B__INCLUDED_)
#define AFX_WINDEKIKAIGOV2DOC_H__FDCC2254_1604_4272_9C52_649F2816781B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWinDeKikaigoV2Doc : public CDocument
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CWinDeKikaigoV2Doc();
	DECLARE_DYNCREATE(CWinDeKikaigoV2Doc)

// �A�g���r���[�g
public:
	BYTE m_data[0x10000]; // �e�X�g�p���f�[�^
	LONG m_nSel;

// �I�y���[�V����
public:

//�I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CWinDeKikaigoV2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CWinDeKikaigoV2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CWinDeKikaigoV2Doc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_WINDEKIKAIGOV2DOC_H__FDCC2254_1604_4272_9C52_649F2816781B__INCLUDED_)
