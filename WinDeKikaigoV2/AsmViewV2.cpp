// AsmViewV2.cpp : インプリメンテーション ファイル
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
// 定数
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
	// 読み書き
	L"LDA", L"LDX", L"LDY", L"STA", L"STX", L"STY",	// 1-6
	L"TXA", L"TYA", L"TXS", L"TAX", L"TAY", L"TSX",	// 7-12
	L"PHA", L"PHP", L"PLA", L"PLP",					// 13-16
	// 計算
	L"AND", L"ORA", L"EOR", L"ADC", L"SBC",			// 17-20
	L"ASL", L"LSR", L"ROL", L"ROR",					// 21-24
	L"INC", L"INX", L"INY", L"DEC", L"DEX", L"DEY",	// 25-30
	L"CMP", L"CPX", L"CPY", L"BIT",					// 31-34
	// 移動
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
	L"", L"", L"%02X",									// ADR_NONE, ADR_A, ADR_REL
	L"#%02X", L"%02X", L"%02X%02X",			// ADR_IMM, ADR_ZR, ADR_AD,
	L"%02X, x", L"%02X, y", L"%02X%02X, x", L"%02X%02X, y", // ADR_ZRX, ADR_ZRY, ADR_ADX, ADR_ADY, 
	L"(%02X, x)", L"(%02X), y", L"(%02X%02X)"	// ADR_INDX, ADR_INDY, ADR_IND,
};

const LONG CAsmViewV2::ASM2ADR[OP_MAX][10] = {
//    HEAD   #     0     $    0,x   0,y   $,x   $,y   (0x)  (0)y
//    HEAD: -1 は複数のアドレッシングモードがあることを示す。
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	// 1-6
	{   -1, 0xA9, 0xA5, 0xAD, 0xB5,    0, 0xBD, 0xB9, 0xA1, 0xB1 }, // L"LDA",
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"LDX",
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"LDY", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"STA", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"STX", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"STY",
	// 7-12
	{ 0x8A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"TXA", 
	{ 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"TYA", 
	{ 0x9A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"TXS", 
	{ 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"TAX",
	{ 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"TAY", 
	{ 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"TSX",	
	// 13-16
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"PHA", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"PHP", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"PLA", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"PLP",					
	// 計算
	// 17-20
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"AND", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"ORA", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"EOR", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"ADC", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"SBC",			
	// 21-24
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"ASL", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"LSR", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"ROL", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"ROR",					
	// 25-30
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"INC", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"INX", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"INY", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"DEC", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"DEX", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"DEY",	
	// 31-34
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CMP", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CPX", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CPY", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BIT",					
	// 移動
	// 35-39
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"JMP", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"JSR", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"RTS", 
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BRK", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"RTI",			
	// 40-43
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BEQ", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BNE", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BMI", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BPL",					
	// 44-47
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BCS", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BCC", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BVS", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"BVC",					
	// 48-51
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CLI", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CLD", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CLC", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"CLV",					
	// 52-55
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"SEI", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"SED", 
	{   -1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // L"SEC", 
	{ 0xEA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }  // L"NOP",
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
// CAsmViewV2 診断

#ifdef _DEBUG
void CAsmViewV2::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAsmViewV2::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

// 追加！
CWinDeKikaigoV2Doc* CAsmViewV2::GetDocument() // 非デバッグ バージョンはインラインです。
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
// CAsmViewV2 描画

void CAsmViewV2::OnDraw(CDC* pDC)
{
/*	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	
	// 逆アセンブル (64 バイト(+α)分) 表示
	// ※未定義命令以降は DATA 表示に切り替える
	const BYTE* BIN = pDoc->m_data; // バイナリ (読み取り専用)
	LONG ip = 0; // バイナリ読み取り位置

	DWORD dwOp, dwAdr, dwOpr; // オペコード, アドレッシング, オペランドのバイト数
	CString buf; // 表示用
	INT i = 0;
	for (; ip < 64; i++) // i は表示縦座標に使用
	{
		dwOp = BIN2OP[BIN[ip]];
		dwAdr = BIN2ADR[BIN[ip]];
		dwOpr = ADR2OPR[dwAdr];   // 0 or 1 or 2

		// UND だった場合中断
		if (dwOp == OP_UND)
			break;

		// オペランド.
		DWORD val1 = 0;
		DWORD val2 = 0;
		switch (dwOpr) {
		case 1: val1 = BIN[ip+1]; break;
		case 2: val1 = BIN[ip+2]; val2 = BIN[ip+1]; break;
		}

		// 表示
		if (ip == m_nCurIp) {
			pDC->SetBkColor(RGB(255,255,0));
		} else {
			pDC->SetBkColor(RGB(255,255,255));
		}
		buf.Format(L"%s", OP2ASM[dwOp]);
		pDC->TextOut(0, i*16, buf);
		buf.Format(ADR2STR[dwAdr], val1, val2);
		pDC->TextOut(4*8, i*16, buf);

		// 座標からipを特定できるように保存しておく
		m_pos2ip[i] = ip;

		// ASMOBJ
		memcpy(m_AsmObj[i].data, &(BIN[ip]), 3);
		m_AsmObj[i].type = ASMOBJ::TEXT;
		m_AsmObj[i].nSize = 1 + dwOpr;

		// 読み進める
		ip += 1 + dwOpr;
	}

	// 残りは DATA として表示
	pDC->SetBkColor(RGB(255,255,255));
	for (; ip < 64; i++) {
		buf.Format(L"%02X ", BIN[ip]);
		pDC->TextOut(0, i*16, buf);

		// ASMOBJ
		m_AsmObj[i].nSize   = 1;
		m_AsmObj[i].data[0] = BIN[ip];
		m_AsmObj[i].type = ASMOBJ::DATA;
		ip ++;
	}

	// ASMOBJ 終端
	m_AsmObj[i].type = ASMOBJ::END;
*/
	LONG i = 0;
	CString buf;

	DWORD dwOp, dwAdr, dwOpr; // オペコード, アドレッシング, オペランドのバイト数
	BYTE* bin;
	
	for (i = 0; i < 64; i++) // i は表示縦座標に使用
	{
		bin = m_AsmObj[i].data;

		dwOp = BIN2OP[bin[0]];
		dwAdr = BIN2ADR[bin[0]];
		dwOpr = m_AsmObj[i].nSize;   // 1 or 2 or 3
		
		// UND だった場合中断
		if (dwOp == OP_UND)
			break;
		
		// オペランド.
		DWORD val1, val2;
		switch (dwOpr) {
		case 2: val1 = bin[1]; break;
		case 3: val1 = bin[2]; val2 = bin[1]; break;
		}

		// 表示
		if (i == m_nCurSel) {
			pDC->SetBkColor(RGB(255,255,0));
		} else {
			pDC->SetBkColor(RGB(255,255,255));
		}
		buf.Format(L"%s", OP2ASM[dwOp]);
		pDC->TextOut(0, i*16, buf);
		buf.Format(ADR2STR[dwAdr], val1, val2);
		pDC->TextOut(4*8, i*16, buf);
	}

	// 残り (DATA) を表示
	pDC->SetBkColor(RGB(255,255,255));
	for (; i < 64; i++) {
		bin = m_AsmObj[i].data;

		// 表示
		if (i == m_nCurSel) {
			pDC->SetBkColor(RGB(255,255,0));
		} else {
			pDC->SetBkColor(RGB(255,255,255));
		}

		buf.Format(L"DATA: %02X ", bin[0]);
		pDC->TextOut(0, i*16, buf);
	}
	
	//
	SetScrollSizes(MM_TEXT, CSize(1, i*16));
}

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 メッセージ ハンドラ

void CAsmViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください		
	switch (nChar) {
	case VK_LEFT:  break;
	case VK_RIGHT: break;
	case VK_UP:    m_nCurSel--; break;
	case VK_DOWN:  m_nCurSel++; break;
	}

	m_nCurIp = m_pos2ip[m_nCurSel];
	
	this->RedrawWindow();
	
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CString buf;
	buf.Format(L"m_pos2ip: %d\r\n", m_pos2ip[point.y/16]);
	OutputDebugString(buf);

	m_nCurSel = point.y/16;
	m_nCurIp = m_pos2ip[m_nCurSel];
	
	this->RedrawWindow();

	CScrollView::OnLButtonDown(nFlags, point);
}

void CAsmViewV2::RegisterAsmInputBar(CAsmInputBar* wndAsmInputBar)
{
	// AsmInputBar のアドレスを保存
	m_pAsmInputBar = wndAsmInputBar;
	m_pAsmInputBar->m_pAsmView = this;
}

void CAsmViewV2::AsmObjToBin()
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();

	BYTE* BIN = pDoc->m_data; // バイナリ
	LONG ip = 0;

	// ASMOBJ から BIN に変換
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
	
	// 逆アセンブル (64 バイト(+α)分) 表示
	// ※未定義命令以降は DATA 表示に切り替える
	const BYTE* BIN = pDoc->m_data; // バイナリ (読み取り専用)
	LONG ip = 0; // バイナリ読み取り位置

	DWORD dwOp, dwAdr, dwOpr; // オペコード, アドレッシング, オペランドのバイト数
	INT i = 0;
	for (; ip < 64; i++) // i は表示縦座標に使用
	{
		dwOp = BIN2OP[BIN[ip]];
		dwAdr = BIN2ADR[BIN[ip]];
		dwOpr = ADR2OPR[dwAdr];   // 0 or 1 or 2

		// UND だった場合中断
		if (dwOp == OP_UND)
			break;

		// 座標からipを特定できるように保存しておく
		m_pos2ip[i] = ip;

		// ASMOBJ
		memcpy(m_AsmObj[i].data, &(BIN[ip]), 3);
		m_AsmObj[i].type = ASMOBJ::TEXT;
		m_AsmObj[i].nSize = 1 + dwOpr;

		// 読み進める
		ip += 1 + dwOpr;
	}

	// 残りは DATA とする
	for (; ip < 64; ) {
		// ASMOBJ
		m_AsmObj[i].nSize   = 1;
		m_AsmObj[i].data[0] = BIN[ip];
		m_AsmObj[i].type = ASMOBJ::DATA;

		// 座標からipを特定できるように保存しておく
		m_pos2ip[i] = ip;

		i++;
		ip++;
	}

	// ASMOBJ 終端
	m_AsmObj[i].type = ASMOBJ::END;
}

void CAsmViewV2::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	::ZeroMemory(m_pos2ip, 256);
	m_nCurIp = 0;
	m_nCurSel = 0;

	const ASMOBJ ASMINITDATA = {
		ASMOBJ::DATA, //	ASMOBJTYPE type;
		4,			  //	LONG nSize;
		0x00		  //	BYTE data[4];
	};

	for (int i = 0; i <= 64; i++)
		m_AsmObj[i] = ASMINITDATA;
	m_AsmObj[64].type = ASMOBJ::END;

	BinToAsmObj();
	SetScrollSizes(MM_TEXT, CSize(1,1)); // CScrollView を作成するためのダミー値
}
