// MyRichView.h: CMyRichView �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYRICHVIEW_H__A9D257A3_CB92_4572_B708_CBDEC7A750EF__INCLUDED_)
#define AFX_MYRICHVIEW_H__A9D257A3_CB92_4572_B708_CBDEC7A750EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyRichView : public CScrollView  
{
public:
	CMyRichView();
	DECLARE_DYNCREATE(CScrollView)
	virtual ~CMyRichView();

	//{{AFX_VIRTUAL(CMyRichView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	//}}AFX_VIRTUAL
};

#endif // !defined(AFX_MYRICHVIEW_H__A9D257A3_CB92_4572_B708_CBDEC7A750EF__INCLUDED_)
