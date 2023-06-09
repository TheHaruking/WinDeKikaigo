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

CEmu6502::CEmu6502()
{

}

CEmu6502::CEmu6502(BYTE* pData)
{
	Init(pData);
}

CEmu6502::~CEmu6502()
{
	
}

void CEmu6502::Init(BYTE* pData)
{
	m_pData = pData;  // メモリはクラス外の物を参照
	m_regA = m_regX = m_regY = 0x00;
	m_regS = /*0x00*/ 0xFF; // 本来はプログラム側で 0xFF に初期化するものだが便宜的にここで 0xFF にする。
	m_regPC = /* 0xFFFC*/ 0x0000; // 本来は RESET ベクタ (0xFFFC) だが便宜的に 0x0000 にする。
	// 電源 ON 時 I フラグはセットされる。(D, C は未定義だがクリアしておく)
	m_regP.byte = !BIT_N | !BIT_V | BIT_R | !BIT_B | !BIT_D | BIT_I | !BIT_Z | !BIT_C;

	// 確認用
#ifdef _DEBUG
	m_dbgstr.Format(L"                             NV_bdiZC\r\n");
	OutputDebugString(m_dbgstr);
#endif
}

void CEmu6502::Reset()
{
	Init(m_pData);
}

DWORD CEmu6502::Exec()
{
#ifdef _DEBUG
	WORD regPC_old = m_regPC; // 確認用
#endif
	// 処理 (後でテーブル化も検討)
	BYTE op = m_pData[m_regPC];
	m_regPC++;

	switch (op) {
	case 0xA9: lda(imm());  break;
	case 0xA5: lda(*zr());  break;
	case 0xAD: lda(*ad());  break;
	case 0xB5: lda(*zrx()); break;
	case 0xBD: lda(*adx()); break;
	case 0xB9: lda(*ady()); break;
	case 0xA1: lda(*idx()); break;
	case 0xB1: lda(*idy()); break;

	case 0xA2: ldx(imm());  break;
	case 0xA6: ldx(*zr());  break;
	case 0xAE: ldx(*ad());  break;
	case 0xB6: ldx(*zry()); break;
	case 0xBE: ldx(*ady()); break;

	case 0xA0: ldy(imm());  break;
	case 0xA4: ldy(*zr());  break;
	case 0xAC: ldy(*ad());  break;
	case 0xB4: ldy(*zrx()); break;
	case 0xBC: ldy(*adx()); break;

	case 0x85: sta(zr());   break;
	case 0x8D: sta(ad());   break;
	case 0x95: sta(zrx());  break;
	case 0x9D: sta(adx());  break;
	case 0x99: sta(ady());  break;
	case 0x81: sta(idx());  break;
	case 0x91: sta(idy());  break;

	case 0x86: stx(zr());   break;
	case 0x8E: stx(ad());   break;
	case 0x96: stx(zry());  break;

	case 0x84: sty(zr());   break;
	case 0x8C: sty(ad());   break;
	case 0x94: sty(zrx());  break;

	case 0x8A: txa(); break;
	case 0x98: tya(); break;
	case 0xAA: tax(); break;
	case 0xA8: tay(); break;
	case 0xBA: tsx(); break;
	case 0x9A: txs(); break;

	case 0x48: pha(); break;
	case 0x68: pla(); break;
	case 0x08: php(); break;
	case 0x28: plp(); break;

	case 0x29: and(imm());  break;
	case 0x25: and(*zr());  break;
	case 0x2D: and(*ad());  break;
	case 0x35: and(*zrx()); break;
	case 0x3D: and(*adx()); break;
	case 0x39: and(*ady()); break;
	case 0x21: and(*idx()); break;
	case 0x31: and(*idy()); break;

	case 0x09: ora(imm());  break;
	case 0x05: ora(*zr());  break;
	case 0x0D: ora(*ad());  break;
	case 0x15: ora(*zrx()); break;
	case 0x1D: ora(*adx()); break;
	case 0x19: ora(*ady()); break;
	case 0x01: ora(*idx()); break;
	case 0x11: ora(*idy()); break;

	case 0x49: eor(imm());  break;
	case 0x45: eor(*zr());  break;
	case 0x4D: eor(*ad());  break;
	case 0x55: eor(*zrx()); break;
	case 0x5D: eor(*adx()); break;
	case 0x59: eor(*ady()); break;
	case 0x41: eor(*idx()); break;
	case 0x51: eor(*idy()); break;

	case 0x69: adc(imm());  break;
	case 0x65: adc(*zr());  break;
	case 0x6D: adc(*ad());  break;
	case 0x75: adc(*zrx()); break;
	case 0x7D: adc(*adx()); break;
	case 0x79: adc(*ady()); break;
	case 0x61: adc(*idx()); break;
	case 0x71: adc(*idy()); break;

	case 0xE9: sbc(imm());  break;
	case 0xE5: sbc(*zr());  break;
	case 0xED: sbc(*ad());  break;
	case 0xF5: sbc(*zrx()); break;
	case 0xFD: sbc(*adx()); break;
	case 0xF9: sbc(*ady()); break;
	case 0xE1: sbc(*idx()); break;
	case 0xF1: sbc(*idy()); break;

	case 0x0A: asl();      break;
	case 0x06: asl(zr());  break;
	case 0x0E: asl(ad());  break;
	case 0x16: asl(zrx()); break;
	case 0x1E: asl(zry()); break;

	case 0x4A: lsr();      break;
	case 0x46: lsr(zr());  break;
	case 0x4E: lsr(ad());  break;
	case 0x56: lsr(zrx()); break;
	case 0x5E: lsr(zry()); break;

	case 0x2A: rol();      break;
	case 0x26: rol(zr());  break;
	case 0x2E: rol(ad());  break;
	case 0x36: rol(zrx()); break;
	case 0x3E: rol(zry()); break;

	case 0x6A: ror();      break;
	case 0x66: ror(zr());  break;
	case 0x6E: ror(ad());  break;
	case 0x76: ror(zrx()); break;
	case 0x7E: ror(zry()); break;

	case 0xE8: inx();       break;
	case 0xC8: iny();       break;
	case 0xE6: inc(zr());   break;
	case 0xEE: inc(ad());   break;
	case 0xF6: inc(zrx());  break;
	case 0xFE: inc(zry());  break;

	case 0xCA: dex();       break;
	case 0x88: dey();       break;
	case 0xC6: dec(zr());   break;
	case 0xCE: dec(ad());   break;
	case 0xD6: dec(zrx());  break;
	case 0xDE: dec(zry());  break;

	case 0xC9: cmp(imm());  break;
	case 0xC5: cmp(*zr());  break;
	case 0xCD: cmp(*ad());  break;
	case 0xD5: cmp(*zrx()); break;
	case 0xDD: cmp(*adx()); break;
	case 0xD9: cmp(*ady()); break;
	case 0xC1: cmp(*idx()); break;
	case 0xD1: cmp(*idy()); break;

	case 0xE0: cpx(imm());  break;
	case 0xE4: cpx(*zr());  break;
	case 0xEC: cpx(*ad());  break;
	case 0xC0: cpy(imm());  break;
	case 0xC4: cpy(*zr());  break;
	case 0xCC: cpy(*ad());  break;
	case 0x24: bit(*zr());  break;
	case 0x2C: bit(*ad());  break;

	case 0x4C: jmp(imm16()); break;
	case 0x6C: jmp(id16());  break;
	case 0x20: jsr(imm16()); break;
	case 0x60: ret();        break;

	case 0xD0: bne(rel()); break;
	case 0xF0: beq(rel()); break;
	case 0x10: bpl(rel()); break;
	case 0x30: bmi(rel()); break;
	case 0x90: bcc(rel()); break;
	case 0xB0: bcs(rel()); break;
	case 0x50: bvc(rel()); break;
	case 0x70: bvs(rel()); break;

	case 0x58: cli(); break;
	case 0x78: sei(); break;
	case 0xD8: cld(); break;
	case 0xF8: sed(); break;
	case 0x18: clc(); break;
	case 0x38: sec(); break;
	case 0xB8: clv(); break;

	case 0xEA: nop(); break;

	default:
		// エラー出力
		CString errmsg;
		errmsg.Format(L"未定義命令 (0x%02X) です。\r\n実行を中断します。", op);
		MessageBox(AfxGetMainWnd()->m_hWnd, errmsg, L"未定義命令実行エラー", 0);
		return 1;
	}

	// 確認用
#ifdef _DEBUG
	m_dbgstr.Format(L"PC:%04X, op:%02X, A:%02X, X:%02X, Y:%02X, P:%d%d_%d%d%d%d%d [NEXT:%04X]\r\n", regPC_old, op, m_regA, m_regX, m_regY, m_regP.bitN, m_regP.bitV, /*m_regP.bitR, */ m_regP.bitB, m_regP.bitD, m_regP.bitI, m_regP.bitZ, m_regP.bitC, m_regPC);
	OutputDebugString(m_dbgstr);
#endif
	return 0;
}
