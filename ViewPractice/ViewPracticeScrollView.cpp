// ViewPracticeScrollView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "ViewPractice.h"
#include "ViewPracticeScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView

IMPLEMENT_DYNCREATE(ViewPracticeScrollView, CScrollView)

ViewPracticeScrollView::ViewPracticeScrollView()
{
}

ViewPracticeScrollView::~ViewPracticeScrollView()
{
}

BEGIN_MESSAGE_MAP(ViewPracticeScrollView, CScrollView)
	//{{AFX_MSG_MAP(ViewPracticeScrollView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView �`��

void ViewPracticeScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: ���̃r���[�S�̂̃T�C�Y���v�Z���Ă��������B
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void ViewPracticeScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView �f�f

#ifdef _DEBUG
void ViewPracticeScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void ViewPracticeScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ViewPracticeScrollView ���b�Z�[�W �n���h��
