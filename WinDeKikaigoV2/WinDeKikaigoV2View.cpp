// WinDeKikaigoV2View.cpp : CWinDeKikaigoV2View �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "WinDeKikaigoV2Doc.h"
#include "WinDeKikaigoV2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View

IMPLEMENT_DYNCREATE(CWinDeKikaigoV2View, CView)

BEGIN_MESSAGE_MAP(CWinDeKikaigoV2View, CView)
	//{{AFX_MSG_MAP(CWinDeKikaigoV2View)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View �N���X�̍\�z/����

CWinDeKikaigoV2View::CWinDeKikaigoV2View()
{
	// TODO: ���̏ꏊ�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B

}

CWinDeKikaigoV2View::~CWinDeKikaigoV2View()
{
}

BOOL CWinDeKikaigoV2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View �N���X�̕`��

void CWinDeKikaigoV2View::OnDraw(CDC* pDC)
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
	pDC->TextOut(0, 0, L"����ɂ��́�����");
}

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View �N���X�̐f�f

#ifdef _DEBUG
void CWinDeKikaigoV2View::AssertValid() const
{
	CView::AssertValid();
}

void CWinDeKikaigoV2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinDeKikaigoV2Doc* CWinDeKikaigoV2View::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoV2Doc)));
	return (CWinDeKikaigoV2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2View �N���X�̃��b�Z�[�W �n���h��

