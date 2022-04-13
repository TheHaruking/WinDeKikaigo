#if !defined(AFX_BINVIEWV2_H__1AF60E83_BD99_48B6_A10F_FE56B093AF1F__INCLUDED_)
#define AFX_BINVIEWV2_H__1AF60E83_BD99_48B6_A10F_FE56B093AF1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BinViewV2.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �r���[

class CBinViewV2 : public CView
{
protected:
	CBinViewV2();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^
	DECLARE_DYNCREATE(CBinViewV2)

// �A�g���r���[�g
public:
	CWinDeKikaigoDoc* GetDocument();

// �I�y���[�V����
public:
	CFont m_font;
	DWORD m_fontWidth;	// test!
	DWORD m_fontHeight;	// test!
	DWORD m_fontRowMargin;
	DWORD m_dwMaxColumn;
	DWORD m_dwSel;

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CBinViewV2)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CBinViewV2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CBinViewV2)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // .cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CWinDeKikaigoDoc* CBinViewV2::GetDocument()
   { return (CWinDeKikaigoDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_BINVIEWV2_H__1AF60E83_BD99_48B6_A10F_FE56B093AF1F__INCLUDED_)
