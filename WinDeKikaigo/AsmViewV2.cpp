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
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_LDA, OP_UND, OP_UND, OP_UND, OP_LDA, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_LDA, OP_UND, OP_UND, 
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
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_IMM,  ADR_NONE, ADR_NONE, ADR_NONE, ADR_AD,   ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX,  ADR_NONE, ADR_NONE, 
// C0
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, 
	ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE
};

const LPTSTR CAsmViewV2::OP2ASM[OP_MAX] = {
	L"UND",
	// �ǂݏ���
	L"LDA", L"LDX", L"LDY", L"STA", L"STX", L"STY",	// 1-6
	L"TXA", L"TYA", L"TXS", L"TAX", L"TAY", L"TSX",	// 7-12
	L"PHA", L"PHP", L"PLA", L"PLP",					// 13-16
	// �v�Z
	L"AND", L"ORA", L"EOR", L"ADC", L"SBC",			// 17-20
	L"ASL", L"LSR", L"ROL", L"ROR",					// 21-24
	L"INC", L"INX", L"INY", L"DEC", L"DEX", L"DEY",	// 25-30
	L"CMP", L"CPX", L"CPY", L"BIT",					// 31-34
	// �ړ�
	L"JMP", L"JSR", L"RTS", L"BRK", L"RTI",			// 35-39
	L"BEQ", L"BNE", L"BMI", L"BPL",					// 40-43
	L"BCS", L"BCC", L"BVS", L"BVC",					// 44-47
	L"CLI", L"CLD", L"CLC", L"CLV",					// 48-51
	L"SEI", L"SED", L"SEC", L"NOP",					// 52-55
};

const DWORD CAsmViewV2::ADR2OPR[ADR_MAX] = {
	0,			// ADR_NONE,
	1, 1, 2,	// ADR_IMM, ADR_ZR, ADR_AD,
	1, 1, 2, 2, // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	1, 1, 2		// ADR_INDX, ADR_INDY, ADR_IND,
};

const LPTSTR CAsmViewV2::ADR2STR[ADR_MAX] = {
	L"",									// ADR_NONE,
	L"%02X", L"%02X", L"%02X%02X",			// ADR_IMM, ADR_ZR, ADR_AD,
	L"%02X, x", L"%02X, y", L"%02X%02X, x", L"%02X%02X, y", // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	L"(%02X, x)", L"(%02X), y", L"(%02X%02X)"	// ADR_INDX, ADR_INDY, ADR_IND,
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
	DWORD dwOp = BIN2OP[pDoc->testBytes[0]];
	DWORD dwAdr = BIN2ADR[pDoc->testBytes[0]];
	DWORD dwOpr = ADR2OPR[dwAdr];

	CString buf;
	buf.Format(L"%s", OP2ASM[dwOp]);
	pDC->TextOut(0, 0, buf);

	// �I�y�����h.
	DWORD val1 = 0;
	DWORD val2 = 0;
	switch (dwOpr) {
	case 1: val1 = pDoc->testBytes[1]; break;
	case 2: val1 = pDoc->testBytes[2]; val2 = pDoc->testBytes[1]; break;
	}
	buf.Format(ADR2STR[dwAdr], val1, val2);
	pDC->TextOut(4*8, 0, buf);
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
