#if !defined(AFX_VIEWPRACTICERICHVIEW_H__751A5613_D5BB_40FB_9493_D6A5D4B34625__INCLUDED_)
#define AFX_VIEWPRACTICERICHVIEW_H__751A5613_D5BB_40FB_9493_D6A5D4B34625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeRichView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView �r���[

class CViewPracticeRichView : public CRichEditView
{
protected:
	CViewPracticeRichView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^
	DECLARE_DYNCREATE(CViewPracticeRichView)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CViewPracticeRichView)
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CViewPracticeRichView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CViewPracticeRichView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICERICHVIEW_H__751A5613_D5BB_40FB_9493_D6A5D4B34625__INCLUDED_)
