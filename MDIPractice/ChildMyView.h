#if !defined(AFX_CHILDMYVIEW_H__4CC009EF_3F40_4FF0_80DE_47C82D27C6C9__INCLUDED_)
#define AFX_CHILDMYVIEW_H__4CC009EF_3F40_4FF0_80DE_47C82D27C6C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildMyView �E�B���h�E

class CChildMyView : public CWnd
{
// �R���X�g���N�V����
public:
	CChildMyView();
	DECLARE_DYNCREATE(CChildMyView)

// �A�g���r���[�g
public:
	CStatic m_static;
	CEdit m_edit;
	CFont m_font;

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CChildMyView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CChildMyView();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CChildMyView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CHILDMYVIEW_H__4CC009EF_3F40_4FF0_80DE_47C82D27C6C9__INCLUDED_)
