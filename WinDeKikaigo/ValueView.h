#if !defined(AFX_VALUEVIEW_H__62E19D42_D0EF_457E_83B4_A9E2FDC23C59__INCLUDED_)
#define AFX_VALUEVIEW_H__62E19D42_D0EF_457E_83B4_A9E2FDC23C59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ValueView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CValueView �t�H�[�� �r���[

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CWinDeKikaigoDoc;

class CValueView : public CFormView
{
protected:
	CValueView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(CValueView)

// �t�H�[�� �f�[�^
public:
	//{{AFX_DATA(CValueView)
	enum { IDD = IDD_VALUEVIEW };
	CEdit	m_edit4;
	CEdit	m_edit3;
	CEdit	m_edit2;
	CEdit	m_edit1;
	CComboBox	m_combo1;
	//}}AFX_DATA

// �A�g���r���[�g
public:
	CWinDeKikaigoDoc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CValueView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CValueView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CValueView)
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

inline CWinDeKikaigoDoc* CValueView::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VALUEVIEW_H__62E19D42_D0EF_457E_83B4_A9E2FDC23C59__INCLUDED_)
