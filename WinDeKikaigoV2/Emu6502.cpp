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
	CString buf;
	buf.Format(L"m_regPC:%04X, m_pData:%02X", m_regPC, m_pData[m_regPC]);
	OutputDebugString(buf);
}
