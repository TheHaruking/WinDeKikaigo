#if !defined(AFX_VIEWPRACTICESCROLLVIEW_H__D0CF38C6_7303_4E7B_BEAC_F148F07A4BB5__INCLUDED_)
#define AFX_VIEWPRACTICESCROLLVIEW_H__D0CF38C6_7303_4E7B_BEAC_F148F07A4BB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewPracticeScrollView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView �r���[

class ViewPracticeScrollView : public CScrollView
{
protected:
	ViewPracticeScrollView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(ViewPracticeScrollView)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(ViewPracticeScrollView)
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	virtual void OnInitialUpdate();     // �\�z��A�ŏ��̏����B
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~ViewPracticeScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ViewPracticeScrollView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICESCROLLVIEW_H__D0CF38C6_7303_4E7B_BEAC_F148F07A4BB5__INCLUDED_)
