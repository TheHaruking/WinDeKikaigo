// AsmViewV2.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "WinDeKikaigoV2doc.h"
#include "AsmViewV2.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// 定数
const DWORD CAsmViewV2::BIN2OP[256] = {
// 00       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
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
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_NOP, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, 
	OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND, OP_UND
};

const DWORD CAsmViewV2::BIN2ADR[256] = {
// 00         1         2         3         4         5         6         7         8         9         A         B         C         D         E         F
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
	::ZeroMemory(m_pos2ip, 256);
	m_nCurIp = 0;
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
// CAsmViewV2 描画

void CAsmViewV2::OnDraw(CDC* pDC)
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	
	// 逆アセンブル (64 バイト(+α)分) 表示
	// ※未定義命令以降は DATA 表示に切り替える
	const BYTE* BIN = pDoc->m_data; // バイナリ
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
		// 読み進める
		ip += 1 + dwOpr;
	}

	// 残りは DATA として表示
	pDC->SetBkColor(RGB(255,255,255));
	for (; ip < 64; i++) {
		buf.Format(L"%02X %02X %02X %02X", BIN[ip+0], BIN[ip+1], BIN[ip+2], BIN[ip+3]);
		pDC->TextOut(0, i*16, buf);
		ip += 4;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAsmViewV2 診断

#ifdef _DEBUG
void CAsmViewV2::AssertValid() const
{
	CView::AssertValid();
}

void CAsmViewV2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// 追加！
CWinDeKikaigoV2Doc* CAsmViewV2::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoV2Doc)));
	return (CWinDeKikaigoV2Doc*)m_pDocument;
}
#endif //_DEBUG

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
	
	// ((CMainFrame*)GetParent())->m_wndDialogBar_R.m_nCurIp = m_nCurIp; // これはできない
	// ((CMainFrame*)AfxGetMainWnd())->m_wndDialogBar_R.m_nCurIp = m_nCurIp;
	m_pAsmInputBar->m_nCurIp = m_nCurIp; // 直接 AsmInputBar に書き込む

	this->RedrawWindow();
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CString buf;
	buf.Format(L"m_pos2ip: %d\r\n", m_pos2ip[point.y/16]);
	OutputDebugString(buf);

	m_nCurSel = point.y/16;
	m_nCurIp = m_pos2ip[m_nCurSel];
	m_pAsmInputBar->m_nCurIp = m_nCurIp; // 直接 AsmInputBar に書き込む
	
	this->RedrawWindow();

	CView::OnLButtonDown(nFlags, point);
}

void CAsmViewV2::RegisterAsmInputBar(CAsmInputBar* wndAsmInputBar)
{
	m_pAsmInputBar = wndAsmInputBar;
	m_pAsmInputBar->m_pDoc = GetDocument();
}
