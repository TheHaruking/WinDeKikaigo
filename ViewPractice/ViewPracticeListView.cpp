// ViewPracticeListView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView

IMPLEMENT_DYNCREATE(CViewPracticeListView, CListView)

CViewPracticeListView::CViewPracticeListView()
{
}

CViewPracticeListView::~CViewPracticeListView()
{
}


BEGIN_MESSAGE_MAP(CViewPracticeListView, CListView)
	//{{AFX_MSG_MAP(CViewPracticeListView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView �`��

void CViewPracticeListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView �f�f

#ifdef _DEBUG
void CViewPracticeListView::AssertValid() const
{
	CListView::AssertValid();
}

void CViewPracticeListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeListView ���b�Z�[�W �n���h��
