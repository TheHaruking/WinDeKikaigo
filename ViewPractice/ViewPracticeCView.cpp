// ViewPracticeCView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView

IMPLEMENT_DYNCREATE(CViewPracticeCView, CView)

CViewPracticeCView::CViewPracticeCView()
{
}

CViewPracticeCView::~CViewPracticeCView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeCView, CView)
	//{{AFX_MSG_MAP(CViewPracticeCView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView �`��

void CViewPracticeCView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView �f�f

#ifdef _DEBUG
void CViewPracticeCView::AssertValid() const
{
	CView::AssertValid();
}

void CViewPracticeCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeCView ���b�Z�[�W �n���h��
