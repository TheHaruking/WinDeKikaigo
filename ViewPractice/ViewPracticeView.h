// ViewPracticeView.h : CViewPracticeView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWPRACTICEVIEW_H__866D9FCA_E348_4638_9217_9CB59E2FDE33__INCLUDED_)
#define AFX_VIEWPRACTICEVIEW_H__866D9FCA_E348_4638_9217_9CB59E2FDE33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewPracticeView : public CEditView
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CViewPracticeView();
	DECLARE_DYNCREATE(CViewPracticeView)

// �A�g���r���[�g
public:
	CViewPracticeDoc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CViewPracticeView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CViewPracticeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CViewPracticeView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ViewPracticeView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CViewPracticeDoc* CViewPracticeView::GetDocument()
   { return (CViewPracticeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VIEWPRACTICEVIEW_H__866D9FCA_E348_4638_9217_9CB59E2FDE33__INCLUDED_)
