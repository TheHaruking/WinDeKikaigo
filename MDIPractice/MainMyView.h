#if !defined(AFX_MAINMYVIEW_H__612DD5AB_4111_4FA8_94F4_5033EDCC1719__INCLUDED_)
#define AFX_MAINMYVIEW_H__612DD5AB_4111_4FA8_94F4_5033EDCC1719__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainMyView.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CMainMyView �t�H�[�� �r���[

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMainMyView : public CFormView
{
protected:
	DECLARE_DYNCREATE(CMainMyView)

// �t�H�[�� �f�[�^
public:
	CMainMyView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B

	//{{AFX_DATA(CMainMyView)
	enum { IDD = IDD_FORMVIEW };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^�����o��ǉ����܂��B
	//}}AFX_DATA

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CMainMyView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CMainMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CMainMyView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MAINMYVIEW_H__612DD5AB_4111_4FA8_94F4_5033EDCC1719__INCLUDED_)
