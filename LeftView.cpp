// LeftView.cpp : CLeftView �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "WinDeKikaigo.h"

#include "WinDeKikaigoDoc.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	//}}AFX_MSG_MAP
	// �W������R�}���h
	//ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	//ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	//ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView �N���X�̍\�z/����

CLeftView::CLeftView()
{
}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView �N���X�̕`��

void CLeftView::OnDraw(CDC* pDC)
{
	CWinDeKikaigoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView �N���X�̐f�f

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CWinDeKikaigoDoc* CLeftView::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView �N���X�̃��b�Z�[�W �n���h��
