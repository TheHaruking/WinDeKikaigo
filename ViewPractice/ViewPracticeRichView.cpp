// ViewPracticeRichView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "ViewPractice.h"
#include "ViewPracticeRichView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView

IMPLEMENT_DYNCREATE(CViewPracticeRichView, CRichEditView)

CViewPracticeRichView::CViewPracticeRichView()
{
}

CViewPracticeRichView::~CViewPracticeRichView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeRichView, CRichEditView)
	//{{AFX_MSG_MAP(CViewPracticeRichView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView �`��

void CViewPracticeRichView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView �f�f

#ifdef _DEBUG
void CViewPracticeRichView::AssertValid() const
{
	CView::AssertValid();
}

void CViewPracticeRichView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeRichView ���b�Z�[�W �n���h��
