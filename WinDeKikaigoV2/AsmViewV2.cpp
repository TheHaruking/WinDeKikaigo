// AsmViewV2.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "WinDeKikaigoV2doc.h"
#include "AsmViewV2.h"
#include "MainFrm.h"

#include "AsmInputBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// �萔
const DWORD CAsmViewV2::BIN2OP[256] = {
// 00       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
	OP_BRK, OP_ORA, OP_UND, OP_UND, OP_UND, OP_ORA, OP_ASL, OP_UND, OP_PHP, OP_ORA, OP_ASL, OP_UND, OP_UND, OP_ORA, OP_ASL, OP_UND, 
	OP_BPL, OP_ORA, OP_UND, OP_UND, OP_UND, OP_ORA, OP_ASL, OP_UND, OP_CLC, OP_ORA, OP_UND, OP_UND, OP_UND, OP_ORA, OP_ASL, OP_UND, 
	OP_JSR, OP_AND, OP_UND, OP_UND, OP_BIT, OP_AND, OP_ROL, OP_UND, OP_PLP, OP_AND, OP_ROL, OP_UND, OP_BIT, OP_AND, OP_ROL, OP_UND, 
	OP_BMI, OP_AND, OP_UND, OP_UND, OP_UND, OP_AND, OP_ROL, OP_UND, OP_SEC, OP_AND, OP_UND, OP_UND, OP_UND, OP_AND, OP_ROL, OP_UND, 
// 40
	OP_RTI, OP_EOR, OP_UND, OP_UND, OP_UND, OP_EOR, OP_LSR, OP_UND, OP_PHA, OP_EOR, OP_LSR, OP_UND, OP_JMP, OP_EOR, OP_LSR, OP_UND, 
	OP_BVC, OP_EOR, OP_UND, OP_UND, OP_UND, OP_EOR, OP_LSR, OP_UND, OP_CLI, OP_EOR, OP_UND, OP_UND, OP_UND, OP_EOR, OP_LSR, OP_UND, 
	OP_RTS, OP_ADC, OP_UND, OP_UND, OP_UND, OP_ADC, OP_ROR, OP_UND, OP_PLA, OP_ADC, OP_ROR, OP_UND, OP_JMP, OP_ADC, OP_ROR, OP_UND, 
	OP_BVS, OP_ADC, OP_UND, OP_UND, OP_UND, OP_ADC, OP_ROR, OP_UND, OP_SEI, OP_ADC, OP_UND, OP_UND, OP_UND, OP_ADC, OP_ROR, OP_UND, 
// 80
	OP_UND, OP_STA, OP_UND, OP_UND, OP_STY, OP_STA, OP_STX, OP_UND, OP_DEY, OP_UND, OP_TXA, OP_UND, OP_STY, OP_STA, OP_STX, OP_UND, 
	OP_BCC, OP_STA, OP_UND, OP_UND, OP_STY, OP_STA, OP_STX, OP_UND, OP_TYA, OP_STA, OP_TXS, OP_UND, OP_UND, OP_STA, OP_UND, OP_UND, 
	OP_LDY, OP_LDA, OP_LDX, OP_UND, OP_LDY, OP_LDA, OP_LDX, OP_UND, OP_TAY, OP_LDA, OP_TAX, OP_UND, OP_LDY, OP_LDA, OP_LDX, OP_UND, 
	OP_BCS, OP_LDA, OP_UND, OP_UND, OP_LDY, OP_LDA, OP_LDX, OP_UND, OP_CLV, OP_LDA, OP_TSX, OP_UND, OP_LDY, OP_LDA, OP_LDX, OP_UND, 
// C0
	OP_CPY, OP_CMP, OP_UND, OP_UND, OP_CPY, OP_CMP, OP_DEC, OP_UND, OP_INY, OP_CMP, OP_DEX, OP_UND, OP_CPY, OP_CMP, OP_DEC, OP_UND, 
	OP_BNE, OP_CMP, OP_UND, OP_UND, OP_UND, OP_CMP, OP_DEC, OP_UND, OP_CLD, OP_CMP, OP_UND, OP_UND, OP_UND, OP_CMP, OP_DEC, OP_UND, 
	OP_CPY, OP_SBC, OP_UND, OP_UND, OP_CPX, OP_SBC, OP_INC, OP_UND, OP_INX, OP_SBC, OP_NOP, OP_UND, OP_CPX, OP_SBC, OP_INC, OP_UND, 
	OP_BEQ, OP_SBC, OP_UND, OP_UND, OP_UND, OP_SBC, OP_INC, OP_UND, OP_SED, OP_SBC, OP_UND, OP_UND, OP_UND, OP_SBC, OP_INC, OP_UND
};

const DWORD CAsmViewV2::BIN2ADR[256] = {
// 00         1         2         3         4         5         6         7         8         9         A         B         C         D         E         F
	ADR_NONE, ADR_INX , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM , ADR_A   , ADR_NONE, ADR_NONE, ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_NONE, 
	ADR_AD  , ADR_INX , ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM , ADR_A   , ADR_NONE, ADR_AD  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_NONE, 
// 40                                                                                                                                                             
	ADR_NONE, ADR_INX , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM , ADR_A   , ADR_NONE, ADR_AD  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_NONE, 
	ADR_NONE, ADR_INX , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM , ADR_A   , ADR_NONE, ADR_IN  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_NONE, 
// 80                                                                                                                                                             
	ADR_NONE, ADR_INX , ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_NONE, ADR_AD  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_ZRY , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_NONE, ADR_NONE, 
	ADR_IMM , ADR_INX , ADR_IMM , ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM,  ADR_NONE, ADR_NONE, ADR_AD  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_ZRY , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_ADY , ADR_NONE, 
// C0                                                                                                                                                             
	ADR_IMM , ADR_INX , ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM , ADR_NONE, ADR_NONE, ADR_AD  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_NONE, 
	ADR_IMM , ADR_INX , ADR_NONE, ADR_NONE, ADR_ZR  , ADR_ZR  , ADR_ZR  , ADR_NONE, ADR_NONE, ADR_IMM , ADR_NONE, ADR_NONE, ADR_AD  , ADR_AD  , ADR_AD  , ADR_NONE, 
	ADR_REL , ADR_INY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ZRX , ADR_ZRX , ADR_NONE, ADR_NONE, ADR_ADY , ADR_NONE, ADR_NONE, ADR_NONE, ADR_ADX , ADR_ADX , ADR_NONE
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
	0, 0, 1,	// ADR_NONE, ADR_A, ADR_REL
	1, 1, 2,	// ADR_IMM, ADR_ZR, ADR_AD,
	1, 1, 2, 2, // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	1, 1, 2		// ADR_INX, ADR_INY, ADR_IN,
};

const LPTSTR CAsmViewV2::ADR2STR[ADR_MAX] = {
	L"", L"", L"$  ",						// ADR_NONE, ADR_A, ADR_REL,
	L"#$  ", L"$  ", L"$    ",				// ADR_IMM, ADR_ZR, ADR_AD,
	L"$  ,x", L"$  ,y", L"$    ,x", L"$    ,y", // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	L"($  ,x)", L"($  ),y", L"($    )"		// ADR_INDX, ADR_INDY, ADR_IND,
};

const LONG CAsmViewV2::ADR2VALPOS[ADR_MAX] = {
	0, 0, 1,	// ADR_NONE, ADR_A, ADR_REL,
	2, 1, 1,	// ADR_IMM, ADR_ZR, ADR_AD,
	1, 1, 1, 1, // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	2, 2, 2		// ADR_INDX, ADR_INDY, ADR_IND,
};

const LPTSTR CAsmViewV2::ADR2VAL[ADR_MAX] = {
	L"", L"", L"%02X",						// ADR_NONE, ADR_A, ADR_REL
	L"%02X", L"%02X", L"%02X%02X",			// ADR_IMM, ADR_ZR, ADR_AD,
	L"%02X", L"%02X", L"%02X%02X", L"%02X%02X", // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	L"%02X", L"%02X", L"%02X%02X"			// ADR_INDX, ADR_INDY, ADR_IND,
};

const LONG CAsmViewV2::ASM2ADR[OP_MAX][10] = {
//    HEAD   #     0     $    0,x   0,y   $,x   $,y   (0x)  (0)y
//    HEAD: -1 �͕����̃A�h���b�V���O���[�h�����邱�Ƃ������B
	{   -1,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	// 1-6
	{   -1, 0xA9, 0xA5, 0xAD, 0xB5,    0, 0xBD, 0xB9, 0xA1, 0xB1 }, // L"LDA",
	{   -1, 0xA2, 0xA6, 0xAE,    0, 0xB6,    0, 0xBE,    0,    0 }, // L"LDX",
	{   -1, 0xA0, 0xA4, 0xAC, 0xB4,    0, 0xBC,    0,    0,    0 }, // L"LDY", 
	{   -1,    0, 0x85, 0x8D, 0x95,    0, 0x9D, 0x99, 0x81, 0x91 }, // L"STA", 
	{   -1,    0, 0x86, 0x8E,    0, 0x96,    0,    0,    0,    0 }, // L"STX", 
	{   -1,    0, 0x84, 0x8C, 0x94,    0,    0,    0,    0,    0 }, // L"STY",
	// 7-12
	{ 0x8A,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"TXA", 
	{ 0x98,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"TYA", 
	{ 0x9A,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"TXS", 
	{ 0xAA,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"TAX",
	{ 0xA8,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"TAY", 
	{ 0xBA,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"TSX",	
	// 13-16
	{ 0x48,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"PHA", 
	{ 0x08,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"PHP", 
	{ 0x68,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"PLA", 
	{ 0x28,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"PLP",					
	// �v�Z
	// 17-20
	{   -1, 0x29, 0x25, 0x2D, 0x35,    0, 0x3D, 0x39, 0x21, 0x31 }, // L"AND", 
	{   -1, 0x09, 0x05, 0x0D, 0x15,    0, 0x1D, 0x19, 0x01, 0x11 }, // L"ORA", 
	{   -1, 0x49, 0x45, 0x4D, 0x55,    0, 0x5D, 0x59, 0x41, 0x51 }, // L"EOR", 
	{   -1, 0x69, 0x65, 0x6D, 0x75,    0, 0x7D, 0x79, 0x61, 0x71 }, // L"ADC", 
	{   -1, 0xE9, 0xE5, 0xED, 0xF5,    0, 0xFD, 0xF9, 0xE1, 0xF1 }, // L"SBC",			
	// 21-24
	{   -1, 0x0A, 0x06, 0x0E, 0x16,    0, 0x1E,    0,    0,    0 }, // L"ASL", 
	{   -1, 0x4A, 0x46, 0x4E, 0x56,    0, 0x5E,    0,    0,    0 }, // L"LSR", 
	{   -1, 0x2A, 0x26, 0x2E, 0x36,    0, 0x3E,    0,    0,    0 }, // L"ROL", 
	{   -1, 0x6A, 0x66, 0x6E, 0x76,    0, 0x7E,    0,    0,    0 }, // L"ROR",					
	// 25-30
	{   -1,    0, 0xE6, 0xEE, 0xF6,    0, 0xFE,    0,    0,    0 }, // L"INC", 
	{ 0xE8,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"INX", 
	{ 0xC8,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"INY", 
	{   -1,    0, 0xC6, 0xCE, 0xD6,    0, 0xDE,    0,    0,    0 }, // L"DEC", 
	{ 0xCA,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"DEX", 
	{ 0x88,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"DEY",	
	// 31-34
	{   -1, 0xC9, 0xC5, 0xCD, 0xD5,    0, 0xDD, 0xD9, 0xC1, 0xD1 }, // L"CMP", 
	{   -1, 0xE0, 0xE4, 0xEC,    0,    0,    0,    0,    0,    0 }, // L"CPX", 
	{   -1, 0xC0, 0xC4, 0xCC,    0,    0,    0,    0,    0,    0 }, // L"CPY", 
	{   -1,    0, 0x24, 0x2C,    0,    0,    0,    0,    0,    0 }, // L"BIT",					
	// �ړ�
	// 35-39
	{   -1,    0,    0, 0x4C,    0,    0,    0,    0, 0x6C,    0 }, // L"JMP", 
	{ 0x20,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"JSR", 
	{ 0x60,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"RTS", 
	{ 0x00,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BRK", 
	{ 0x40,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"RTI",			
	// 40-43
	{ 0xF0,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BEQ", 
	{ 0xD0,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BNE", 
	{ 0x30,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BMI", 
	{ 0x10,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BPL",					
	// 44-47
	{ 0xB0,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BCS", 
	{ 0x90,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BCC", 
	{ 0x70,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BVS",
	{ 0x50,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"BVC",
	// 48-51
	{ 0x58,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"CLI", 
	{ 0xD8,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"CLD", 
	{ 0x18,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"CLC", 
	{ 0xB8,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"CLV",					
	// 52-55
	{ 0x78,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"SEI", 
	{ 0xF8,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"SED", 
	{ 0x38,    0,    0,    0,    0,    0,    0,    0,    0,    0 }, // L"SEC", 
	{ 0xEA,    0,    0,    0,    0,    0,    0,    0,    0,    0 }  // L"NOP",
};

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2

IMPLEMENT_DYNCREATE(CAsmViewV2, CScrollView)

CAsmViewV2::CAsmViewV2()
{
}

CAsmViewV2::~CAsmViewV2()
{
}

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 �f�f

#ifdef _DEBUG
void CAsmViewV2::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAsmViewV2::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

// �ǉ��I
CWinDeKikaigoV2Doc* CAsmViewV2::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoV2Doc)));
	return (CWinDeKikaigoV2Doc*)m_pDocument;
}
#endif //_DEBUG

BEGIN_MESSAGE_MAP(CAsmViewV2, CScrollView)
	//{{AFX_MSG_MAP(CAsmViewV2)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 �`��

void CAsmViewV2::OnDraw(CDC* pDC)
{
	LONG i = 0;
	CString buf;

	DWORD dwOp, dwAdr, dwOpr; // �I�y�R�[�h, �A�h���b�V���O, �I�y�����h�̃o�C�g��
	BYTE* bin;
	const DWORD HEIGHT = 21+2;
	DWORD xofs;
	LONG  count = 0;

	// �t�H���g�ύX
	CFont* pFontOld;
	pFontOld = pDC->SelectObject(&m_font);
	
	// �w�i�p�y��/�u���V
	CBrush brush(RGB(239, 239, 239));
	CBrush* pBrushOld = pDC->SelectObject(&brush);
	CPen pen(PS_NULL, 0, RGB(0, 0, 0));
	CPen* pPenOld = pDC->SelectObject(&pen);

	for (i = 0; (i < 64) && (m_AsmObj[i].type != ASMOBJ::END); i++) // i �͕\���c���W�Ɏg�p
	{
		bin = m_AsmObj[i].data;

		dwOp = BIN2OP[bin[0]];
		dwAdr = BIN2ADR[bin[0]];
		dwOpr = m_AsmObj[i].nSize;   // 1 or 2 or 3
		
		// UND �������ꍇ���f
		if (dwOp == OP_UND)
			break;
		
		// �I�y�����h.
		DWORD val1, val2;
		switch (dwOpr) {
		case 2: val1 = bin[1]; break;
		case 3: val1 = bin[2]; val2 = bin[1]; break;
		}

		// �\��:���s���J�[�\��
		xofs = 0;
		pDC->Rectangle(0, i*HEIGHT, 16+2, i*HEIGHT+HEIGHT+1); // �w�i�̓h��Ԃ�

		if (m_num2ip[i] == ((CMainFrame*)AfxGetMainWnd())->m_cpu.GetRegPC()) {
			::TransparentBlt(pDC->m_hDC, /*�R�s�[�� ���W  */ xofs, 1+i*HEIGHT, /*�T�C�Y*/ 16, 16+4, /*�R�s�[�� BMPDC */ m_bmpdcCur.m_hDC, /*���_  */ 0, 0, /*�T�C�Y*/ 16, 16, /*���ߐF*/ RGB(255, 255, 255));
		}
		xofs += 16+2;


		// �\��:�A�C�R����
		pDC->BitBlt(xofs, 1+i*HEIGHT, 24, 21, &(m_bmpdc[dwOp]), 1, 1, SRCCOPY); // ����1px �͏Ȃ�.
		xofs += 24+4; // �A�C�R���� + �]��.

		// �\��:"LDA " ��
		if (i == m_nCurSel) {
			pDC->SetBkColor(RGB(255,255,0));
		} else {
			pDC->SetBkColor(RGB(255,255,255));
		}

		buf.Format(L"%s ", OP2ASM[dwOp]);
		pDC->TextOut(xofs, i*HEIGHT, buf);
		xofs += 12*4;
		
		// �\��:"#$00" ��
		buf.Format(ADR2STR[dwAdr]);
		pDC->TextOut(xofs, i*HEIGHT, buf);
		pDC->SetBkColor(RGB(239,239,239));

		buf.Format(ADR2VAL[dwAdr], val1, val2);
		pDC->TextOut(xofs+ADR2VALPOS[dwAdr]*12, i*HEIGHT, buf);

		// �N���b�N���W���� AddrInputDlg �̂��߂̉���(�J�n,�I�[)���擾�ł���悤�ɂ��Ă���.
		m_num2width[i][0] = xofs + ADR2VALPOS[dwAdr]*12;						// �J�n.
		m_num2width[i][1] = xofs + ADR2VALPOS[dwAdr]*12 + ADR2OPR[dwAdr]*24;	// �I�[.

		count++;
	}

	// �c�� (DATA) ��\��
	pDC->SetBkColor(RGB(255,255,255));
	for (; (i < 64) && (m_AsmObj[i].type != ASMOBJ::END); i++) {
		bin = m_AsmObj[i].data;

		// �\��
		pDC->Rectangle(0, i*HEIGHT, 16+2, i*HEIGHT+HEIGHT+1); // �w�i�̓h��Ԃ�

		if (i == m_nCurSel) {
			pDC->SetBkColor(RGB(255,255,0));
		} else {
			pDC->SetBkColor(RGB(255,255,255));
		}

		buf.Format(L"DATA: $%02X ", bin[0]);
		pDC->TextOut(19, i*HEIGHT, buf);

		count++;
	}

	// �㏈��
	pDC->SelectObject(&m_font);

	// �X�N���[���͈͂̌���
	SetScrollSizes(MM_TEXT, CSize(1, HEIGHT*count));
}

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 ���b�Z�[�W �n���h��

void CAsmViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������		
	switch (nChar) {
	case VK_LEFT:  break;
	case VK_RIGHT: break;
	case VK_UP:    m_nCurSel--; break;
	case VK_DOWN:  m_nCurSel++; break;
	}

	// �͈̓`�F�b�N
	m_nCurSel = (m_nCurSel >= 0) ? m_nCurSel : 0; // �����l
	m_nCurSel = (m_nCurSel <= 63) ? m_nCurSel : 63; // ����l
	if (m_AsmObj[m_nCurSel].type == ASMOBJ::END)  // ����l
		m_nCurSel--;

	m_nCurIp = m_num2ip[m_nCurSel];
	
	this->RedrawWindow();

	// ���� (AsmView -> BinView)
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	pDoc->m_nSel = m_nCurIp;
	pDoc->UpdateAllViews(this);

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	const DWORD HEIGHT = 21+2;
	LONG y = CScrollView::GetScrollPosition().y + point.y;

	// �m�F�p
#ifdef _DEBUG
	CString buf;
	buf.Format(L"m_num2ip: %d\r\n", m_num2ip[y/HEIGHT]);
	OutputDebugString(buf);
#endif

	m_nCurSel = y/HEIGHT;
	m_nCurIp = m_num2ip[m_nCurSel];
	
	// �I�y�����h�����͔���.
	if ((point.x >= m_num2width[m_nCurSel][0]) && (point.x <= m_num2width[m_nCurSel][1]))
	{
		// Enter �������ꂽ�Ƃ��l�𔽉f����.
		if (m_AddrInputDlg.DoModal() == IDOK)
		{
			DWORD addr = m_AddrInputDlg.GetAddr();
			m_AsmObj[m_nCurSel].data[1] = addr & 0xFF;
			m_AsmObj[m_nCurSel].data[2] = (addr & 0xFF00) >> 8;

			AsmObjToBin();
		}
	}

	this->RedrawWindow();
	CScrollView::OnLButtonDown(nFlags, point);

	// ���� (AsmView -> BinView)
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	pDoc->m_nSel = m_nCurIp;
	pDoc->UpdateAllViews(this);
}

void CAsmViewV2::AsmObjToBin()
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();

	BYTE* BIN = pDoc->m_data; // �o�C�i��
	LONG ip = 0;

	// ASMOBJ ���� BIN �ɕϊ�
	for (int i=0; i<64; i++) {	
		if (m_AsmObj[i].type == ASMOBJ::END)
			break;

		memcpy(&(BIN[ip]), m_AsmObj[i].data, m_AsmObj[i].nSize);
		ip += m_AsmObj[i].nSize;
	}
}

void CAsmViewV2::SetAsmObj(LONG n, BYTE* data)
{
	DWORD dwOp, dwAdr, dwOpr;

	dwOp = BIN2OP[data[0]];
	dwAdr = BIN2ADR[data[0]];
	dwOpr = ADR2OPR[dwAdr];   // 0 or 1 or 2

	m_AsmObj[n].type = ASMOBJ::TEXT;
	m_AsmObj[n].nSize = 1 + dwOpr;
	memcpy(m_AsmObj[n].data, data, m_AsmObj[n].nSize);
}

LONG CAsmViewV2::GetAsmSel()
{
	return m_nCurSel;
}

void CAsmViewV2::BinToAsmObj()
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	
	// �t�A�Z���u�� (64 �o�C�g(+��)��) �\��
	// ������`���߈ȍ~�� DATA �\���ɐ؂�ւ���
	const BYTE* BIN = pDoc->m_data; // �o�C�i�� (�ǂݎ���p)
	LONG ip = 0; // �o�C�i���ǂݎ��ʒu

	DWORD dwOp, dwAdr, dwOpr; // �I�y�R�[�h, �A�h���b�V���O, �I�y�����h�̃o�C�g��
	INT i = 0;
	for (; ip < 64; i++) // i �͕\���c���W�Ɏg�p
	{
		dwOp = BIN2OP[BIN[ip]];
		dwAdr = BIN2ADR[BIN[ip]];
		dwOpr = ADR2OPR[dwAdr];   // 0 or 1 or 2

		// UND �������ꍇ���f
		if (dwOp == OP_UND)
			break;

		// ���W����ip�����ł���悤�ɕۑ����Ă���
		m_num2ip[i] = ip;
		// ip����m_nCurSel(=i)�����ł���悤�ɕۑ����Ă���
		for (DWORD j=0; j<=dwOpr; j++)
			m_ip2num[ip+j] = i;

		// ASMOBJ
		memcpy(m_AsmObj[i].data, &(BIN[ip]), 3);
		m_AsmObj[i].type = ASMOBJ::TEXT;
		m_AsmObj[i].nSize = 1 + dwOpr;

		// �ǂݐi�߂�
		ip += 1 + dwOpr;
	}

	// �c��� DATA �Ƃ���
	for (; ip < 64; ) {
		// ASMOBJ
		m_AsmObj[i].nSize   = 1;
		m_AsmObj[i].data[0] = BIN[ip];
		m_AsmObj[i].type = ASMOBJ::DATA;

		// ���W����ip�����ł���悤�ɕۑ����Ă���
		m_num2ip[i] = ip;
		// ip����m_nCurSel(=i)�����ł���悤�ɕۑ����Ă���
		for (LONG j=0; j<m_AsmObj[i].nSize; j++)
			m_ip2num[ip+j] = i;

		i++;
		ip++;
	}

	// ASMOBJ �I�[
	m_AsmObj[i].type = ASMOBJ::END;
}

void CAsmViewV2::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	int i;

	::ZeroMemory(m_num2ip, 256);
	m_nCurIp = 0;
	m_nCurSel = 0;

	const ASMOBJ ASMINITDATA = {
		ASMOBJ::DATA, //	ASMOBJTYPE type;
		4,			  //	LONG nSize;
		0x00		  //	BYTE data[4];
	};

	for (i = 0; i <= 64; i++)
		m_AsmObj[i] = ASMINITDATA;
	m_AsmObj[64].type = ASMOBJ::END;

	BinToAsmObj();
	SetScrollSizes(MM_TEXT, CSize(1,1)); // CScrollView ���쐬���邽�߂̃_�~�[�l

	// �A�C�R���֘A
	CClientDC dc(this);

	for (i = 0; i < OP_MAX; i++) {
		m_bmp[i].LoadBitmap(IDB_OP_UND+i);
		m_bmpdc[i].CreateCompatibleDC(&dc);
		m_bmpdc[i].SelectObject(&m_bmp[i]);
	}

	m_bmpCur.LoadBitmap(IDB_CURSOR);
	m_bmpdcCur.CreateCompatibleDC(&dc);
	m_bmpdcCur.SelectObject(&m_bmpCur);

	// �t�H���g
	m_font.CreateFont(
		22, 0,					// �����A��
		0, 0, FW_DONTCARE,		// �p�x�A�p�x�A����
		FALSE, FALSE, FALSE,	// �ΆA�����A�����
		ANSI_CHARSET,			// �����Z�b�g
		OUT_DEFAULT_PRECIS,		// �o�͐��x
		CLIP_DEFAULT_PRECIS,	// �N���b�s���O���x
		DEFAULT_QUALITY,		// �o�͕i��
		DEFAULT_PITCH,			// �s�b�`
		_T("Courier New")		// �^�C�v�t�F�C�X��
		);
}

void CAsmViewV2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	BinToAsmObj();

	// ���� (BinView -> AsmView)
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	m_nCurIp = pDoc->m_nSel;
	m_nCurSel = m_ip2num[m_nCurIp];

	CView::OnUpdate(pSender, lHint, pHint);	
}
