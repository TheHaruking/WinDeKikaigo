// ViewPracticeHtmlView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "viewpractice.h"
#include "ViewPracticeHtmlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView

IMPLEMENT_DYNCREATE(CViewPracticeHtmlView, CHtmlView)

CViewPracticeHtmlView::CViewPracticeHtmlView()
{
	//{{AFX_DATA_INIT(CViewPracticeHtmlView)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

CViewPracticeHtmlView::~CViewPracticeHtmlView()
{
}

void CViewPracticeHtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewPracticeHtmlView)
		// ����: ClassWizard �͂��̈ʒu�� DDX �� DDV �̌Ăяo���R�[�h��ǉ����܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewPracticeHtmlView, CHtmlView)
	//{{AFX_MSG_MAP(CViewPracticeHtmlView)
		// ����: ClassWizard �͂��̈ʒu�Ƀ��b�Z�[�W �}�b�v �}�N����ǉ����܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView diagnostics

#ifdef _DEBUG
void CViewPracticeHtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CViewPracticeHtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeHtmlView message handlers
