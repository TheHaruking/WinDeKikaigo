// SplitterPracticeView.cpp : CSplitterPracticeView �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "SplitterPractice.h"

#include "SplitterPracticeDoc.h"
#include "SplitterPracticeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView

IMPLEMENT_DYNCREATE(CSplitterPracticeView, CListView)

BEGIN_MESSAGE_MAP(CSplitterPracticeView, CListView)
	//{{AFX_MSG_MAP(CSplitterPracticeView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView �N���X�̍\�z/����

CSplitterPracticeView::CSplitterPracticeView()
{
	// TODO: ���̏ꏊ�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B

}

CSplitterPracticeView::~CSplitterPracticeView()
{
}

BOOL CSplitterPracticeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView �N���X�̕`��

void CSplitterPracticeView::OnDraw(CDC* pDC)
{
	CSplitterPracticeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, L"Item!");
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

void CSplitterPracticeView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl() �����o�֐��̌Ăяo����ʂ��Ē��ڂ��̃��X�g �R���g���[����
	//  �A�N�Z�X���邱�Ƃɂ���� ListView ���A�C�e���ŌŒ�ł��܂��B
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView �N���X�̐f�f

#ifdef _DEBUG
void CSplitterPracticeView::AssertValid() const
{
	CListView::AssertValid();
}

void CSplitterPracticeView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CSplitterPracticeDoc* CSplitterPracticeView::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitterPracticeDoc)));
	return (CSplitterPracticeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeView �N���X�̃��b�Z�[�W �n���h��
void CSplitterPracticeView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	// TODO: ���[�U�[�ɂ��E�C���h�E�̃r���[ �X�^�C���ύX�ɑΉ�����R�[�h��ǉ����Ă�������
}
