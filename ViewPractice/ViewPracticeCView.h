#if !defined(AFX_VIEWPRACTICECVIEW_H__7F76A666_8F1D_4FF0_973D_6E15F157D7E7__INCLUDED_)
#define AFX_VIEWPRACTICECVIEW_H__7F76A666_8F1D_4FF0_973D_6E15F157D7E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeCView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView �r���[

class CViewPracticeCView : public CView
{
protected:
	CViewPracticeCView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^
	DECLARE_DYNCREATE(CViewPracticeCView)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CViewPracticeCView)
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CViewPracticeCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CViewPracticeCView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICECVIEW_H__7F76A666_8F1D_4FF0_973D_6E15F157D7E7__INCLUDED_)
