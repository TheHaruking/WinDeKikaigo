// ViewPracticeTreeView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView

IMPLEMENT_DYNCREATE(CViewPracticeTreeView, CTreeView)

CViewPracticeTreeView::CViewPracticeTreeView()
{
}

CViewPracticeTreeView::~CViewPracticeTreeView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeTreeView, CTreeView)
	//{{AFX_MSG_MAP(CViewPracticeTreeView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView �`��

void CViewPracticeTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView �f�f

#ifdef _DEBUG
void CViewPracticeTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CViewPracticeTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeTreeView ���b�Z�[�W �n���h��
