// ViewPracticeFormView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView

IMPLEMENT_DYNCREATE(CViewPracticeFormView, CFormView)

CViewPracticeFormView::CViewPracticeFormView()
	: CFormView(CViewPracticeFormView::IDD)
{
	//{{AFX_DATA_INIT(CViewPracticeFormView)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//}}AFX_DATA_INIT
}

CViewPracticeFormView::~CViewPracticeFormView()
{
}

void CViewPracticeFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewPracticeFormView)
		// ����: ClassWizard �͂��̈ʒu�� DDX ����� DDV �̌Ăяo����ǉ����܂�
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewPracticeFormView, CFormView)
	//{{AFX_MSG_MAP(CViewPracticeFormView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView �f�f

#ifdef _DEBUG
void CViewPracticeFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CViewPracticeFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeFormView ���b�Z�[�W �n���h��
