// SplitterPracticeView.h : CSplitterPracticeView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLITTERPRACTICEVIEW_H__199E4CA4_01FE_402A_94C7_F58D1178CE18__INCLUDED_)
#define AFX_SPLITTERPRACTICEVIEW_H__199E4CA4_01FE_402A_94C7_F58D1178CE18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSplitterPracticeView : public CListView
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CSplitterPracticeView();
	DECLARE_DYNCREATE(CSplitterPracticeView)

// �A�g���r���[�g
public:
	CSplitterPracticeDoc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSplitterPracticeView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // �\�z��̍ŏ��̂P�x�����Ăяo����܂��B
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CSplitterPracticeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CSplitterPracticeView)
		// ���� -  ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//         ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SplitterPracticeView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CSplitterPracticeDoc* CSplitterPracticeView::GetDocument()
   { return (CSplitterPracticeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SPLITTERPRACTICEVIEW_H__199E4CA4_01FE_402A_94C7_F58D1178CE18__INCLUDED_)
