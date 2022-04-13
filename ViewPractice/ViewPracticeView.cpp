// ViewPracticeView.cpp : CViewPracticeView �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "ViewPractice.h"

#include "ViewPracticeDoc.h"
#include "ViewPracticeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView

IMPLEMENT_DYNCREATE(CViewPracticeView, CEditView)

BEGIN_MESSAGE_MAP(CViewPracticeView, CEditView)
	//{{AFX_MSG_MAP(CViewPracticeView)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView �N���X�̍\�z/����

CViewPracticeView::CViewPracticeView()
{
	// TODO: ���̏ꏊ�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B

}

CViewPracticeView::~CViewPracticeView()
{
}

BOOL CViewPracticeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���[�h ���b�v���g�p�\�ɂ��܂�

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView �N���X�̕`��

void CViewPracticeView::OnDraw(CDC* pDC)
{
	CViewPracticeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView �N���X�̐f�f

#ifdef _DEBUG
void CViewPracticeView::AssertValid() const
{
	CEditView::AssertValid();
}

void CViewPracticeView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CViewPracticeDoc* CViewPracticeView::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewPracticeDoc)));
	return (CViewPracticeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeView �N���X�̃��b�Z�[�W �n���h��

void CViewPracticeView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	// 
	CEdit& edit = GetEditCtrl();
	edit.SetWindowText(L"XX XX XX XX\r\nXX XX XX XX\r\n");
}

CPoint	g_ptChar;
INT	g_nChar;

void CViewPracticeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	CEdit& edit = GetEditCtrl();
	CString buf;
	buf.Format(L"nChar : %ld\r\n", nChar);
	OutputDebugString(buf);
	
	switch (nChar) {
	case VK_LEFT:
//		edit.SetCaretPos(CPoint(1,0));
		g_nChar--;
		edit.SetSel(g_nChar, g_nChar);
		break;

	case VK_RIGHT:
		g_nChar++;		
		edit.SetSel(g_nChar, g_nChar);
		break;
	
	case VK_UP:
		break;
	
	case VK_DOWN:
		break;
	
	case 'Q':
		g_nChar = 0;
		edit.SetSel(g_nChar, g_nChar);
		break;
	
	case 'W': {
		int nCharPos = edit.CharFromPos(CPoint(20, 10));
		CPoint pos = edit.PosFromChar('X');
		buf.Format(L"CharFromPos: %ld\r\nCPoint.x: %d\r\n", nCharPos, pos.x);
		OutputDebugString(buf);
		break;
	}
	
	default:
		CEditView::OnKeyDown(nChar, nRepCnt, nFlags);
		return;
	}
}

void CViewPracticeView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CString buf;
	buf.Format(L"OnChar: %ld\r\n", nChar);
	OutputDebugString(buf);

	switch (nChar) {
	case 'q':
	case 'w':
		return;
	default:
		CEditView::OnChar(nChar, nRepCnt, nFlags);
		break;
	}
}
