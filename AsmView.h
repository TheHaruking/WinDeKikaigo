#if !defined(AFX_ASMVIEW_H__781864A8_7031_4C0C_B06B_8A1FDD852E61__INCLUDED_)
#define AFX_ASMVIEW_H__781864A8_7031_4C0C_B06B_8A1FDD852E61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsmView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CAsmView �t�H�[�� �r���[

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "WinDeKikaigoDoc.h"

class CAsmView : public CFormView
{
protected:
	CAsmView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(CAsmView)

// �t�H�[�� �f�[�^
public:
	//{{AFX_DATA(CAsmView)
	enum { IDD = IDD_ASMVIEW };
	CComboBox	m_combo4;
	CComboBox	m_combo3;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	//}}AFX_DATA

// �A�g���r���[�g
public:
	CWinDeKikaigoDoc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAsmView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CAsmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAsmView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CWinDeKikaigoDoc* CLeftView::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ASMVIEW_H__781864A8_7031_4C0C_B06B_8A1FDD852E61__INCLUDED_)
