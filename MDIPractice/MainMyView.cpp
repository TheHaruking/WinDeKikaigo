// MainMyView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MDIPractice.h"
#include "MainMyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainMyView

IMPLEMENT_DYNCREATE(CMainMyView, CFormView)

CMainMyView::CMainMyView()
	: CFormView(CMainMyView::IDD)
{
	//{{AFX_DATA_INIT(CMainMyView)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//}}AFX_DATA_INIT
}

CMainMyView::~CMainMyView()
{
}

void CMainMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainMyView)
		// ����: ClassWizard �͂��̈ʒu�� DDX ����� DDV �̌Ăяo����ǉ����܂�
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainMyView, CFormView)
	//{{AFX_MSG_MAP(CMainMyView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainMyView �f�f

#ifdef _DEBUG
void CMainMyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMainMyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainMyView ���b�Z�[�W �n���h��
