// AsmViewV2.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "windekikaigodoc.h"
#include "AsmViewV2.h"

#include "AsmViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// �萔
const DWORD CAsmViewV2::BIN2OP[256] = {
//	0       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
// 40
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
// 80
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_LDA, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
// C0
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND
};

const DWORD CAsmViewV2::BIN2ADR[256] = {
//  0         1         2         3         4         5         6         7         8         9         A         B         C         D         E         F
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
// 40
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
// 80
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_IMM,  ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
// C0
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE
};


/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2

IMPLEMENT_DYNCREATE(CAsmViewV2, CView)

CAsmViewV2::CAsmViewV2()
{
}

CAsmViewV2::~CAsmViewV2()
{
}


BEGIN_MESSAGE_MAP(CAsmViewV2, CView)
	//{{AFX_MSG_MAP(CAsmViewV2)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 �`��

void CAsmViewV2::OnDraw(CDC* pDC)
{
	CWinDeKikaigoDoc* pDoc = GetDocument();
	
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
	// �����̃R�[�h�͌�Ƀf�[�u��������.
	DWORD dwOutput = 0;
	switch (pDoc->testBytes[0]) {
	case 0xA9:
		pDC->TextOut(0, 0, L"LDA ");
		dwOutput = 1;
		break;
	case 0xAD:
		pDC->TextOut(0, 0, L"LDA ");
		dwOutput = 2;
		break;
	case 0xB5:
		pDC->TextOut(0, 0, L"LDA     ,x");
		dwOutput = 1;
		break;
	}
	// �I�y�����h.
	CString buf;
	switch (dwOutput) {
	case 1:
		buf.Format(L"%02X", pDoc->testBytes[1]);
		pDC->TextOut(4*8, 0, buf);
		break;
	case 2:
		buf.Format(L"%02X%02X", pDoc->testBytes[2], pDoc->testBytes[1]);
		pDC->TextOut(4*8, 0, buf);
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 �f�f

#ifdef _DEBUG
void CAsmViewV2::AssertValid() const
{
	CView::AssertValid();
}

void CAsmViewV2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// �ǉ��I
CWinDeKikaigoDoc* CAsmViewV2::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 ���b�Z�[�W �n���h��

void CAsmViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	CAsmViewDlg dlg;
	dlg.DoModal();

	CView::OnLButtonDown(nFlags, point);
}
