// Emu6502.cpp: CEmu6502 クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "windekikaigov2.h"
#include "Emu6502.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

CEmu6502::CEmu6502(BYTE* pData)
{
	m_pData = pData;
	m_regA = m_regX = m_regY = 0x00;
	m_regS = 0x00;
	m_regPC = 0x0000;
	// 電源 ON 時 I フラグはセットされる。(D, C は未定義だがクリアしておく)
	m_regP.byte = !BIT_N | !BIT_V | BIT_R | !BIT_B | !BIT_D | BIT_I | !BIT_Z | !BIT_C;
}

CEmu6502::~CEmu6502()
{
	
}

void CEmu6502::Exec()
{
	// RET (0x60) が無かったら実行しない : RET の有無を走査。
	BOOL bNoRET = TRUE;
	for (int i = 0; i < 64; i++) {
		if (m_pData[i] == 0x60) {
			bNoRET = FALSE;
			break;
		}
	}

	// RET (0x60) が無かったら実行しない
	if (bNoRET) {
		MessageBox(AfxGetMainWnd()->m_hWnd, L"RET (0x60) が見つかりません。\r\n実行を中断します。", L"", 0);
		return;
	}

	// 処理 (後でテーブル化も検討)
	BYTE op;
	CString buf;
	for (m_regPC = 0; m_regPC < 64; m_regPC++) {
		op = m_pData[m_regPC];

		switch (op) {
		case 0x60: goto end;
		case 0xA9: m_regA = imm(); break;
		case 0xAD: m_regA = *ad(); break;
		case 0xB1: m_regA = *iny(); break;
		case 0xA1: m_regA = *inx(); break;
		case 0x8D: *ad() = m_regA; break;
		case 0xE8: m_regX++; break;
		}

		// 確認用
		buf.Format(L"PC:%04X, A:%02X, X:%02X, Y:%02X\r\n", m_regPC, m_regA, m_regX, m_regY);
		OutputDebugString(buf);
	}
end:
	;
}
