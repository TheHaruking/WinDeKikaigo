// Emu6502.h: CEmu6502 クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_)
#define AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEmu6502OutputV2;

class CEmu6502 
{
	friend class CEmu6502OutputV2;

protected:
	BYTE* m_pData;
	BYTE m_regA;
	BYTE m_regX;
	BYTE m_regY;
	typedef struct {
		union {
			struct { BYTE l, h; };
			WORD word;
		};
	} WORDADR;
	WORD m_regPC;
	enum {
		BIT_N = 0x80, BIT_V = 0x40, BIT_R = 0x20, BIT_B = 0x10,
		BIT_D = 0x08, BIT_I = 0x04, BIT_Z = 0x02, BIT_C = 0x01,
	};
	typedef struct {
		union {
			struct {
				BYTE bitC:1, bitZ:1, bitI:1, bitD:1, bitB:1, bitR:1, bitV:1, bitN:1;
			};
			BYTE byte;
		};
	} STATUSREG;
	STATUSREG m_regP;
	BYTE m_regS;
#ifdef _DEBUG
	CString m_dbgstr;
#endif

protected:
	inline BYTE imm()  { BYTE ret = m_pData[m_regPC]; m_regPC++; return ret; }
	inline char rel()  { BYTE ret = (char)(m_pData[m_regPC]); m_regPC++; return ret; }
	inline WORD imm16(){ WORD adr = *(WORD*)(&(m_pData[m_regPC])); m_regPC+=2; return adr; }
	inline BYTE* zr()  { BYTE adr = m_pData[m_regPC]; m_regPC++; return &(m_pData[adr]); }
	inline BYTE* zrx() { BYTE adr = m_pData[m_regPC]; m_regPC++; return &(m_pData[adr += m_regX]); }
	inline BYTE* zry() { BYTE adr = m_pData[m_regPC]; m_regPC++; return &(m_pData[adr += m_regY]); }
	inline BYTE* ad()  { WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); m_regPC++; return &(m_pData[adr]); }
	inline BYTE* adx() { WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); m_regPC++; return &(m_pData[adr += m_regX]); }
	inline BYTE* ady() { WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); m_regPC++; return &(m_pData[adr += m_regY]); }
	inline BYTE* idx() { WORD adr = m_pData[m_regPC]; m_regPC++;  WORD adr2 = m_pData[adr + m_regX]; adr2 |= (m_pData[adr + m_regX +1] << 8); return &(m_pData[adr2]); }
	inline BYTE* idy() { WORD adr = m_pData[m_regPC]; m_regPC++;  WORD adr2 = m_pData[adr]; adr2 |= (m_pData[adr+1] << 8); return &(m_pData[adr2 += m_regY]); }
	inline WORD id16() { WORD adr = m_pData[m_regPC]; m_regPC+=2; WORD adr2 = m_pData[adr]; adr2 |= (m_pData[adr+1] << 8); return adr2; }

	inline void setNZ(BYTE byte) { m_regP.bitN = (byte >> 7); m_regP.bitZ = (byte == 0); }
	inline void push16(WORD word) { WORD p = (0x0100 + m_regS - 1); *(WORD*)(&(m_pData[p])) = word; m_regS -= 2; }
	inline WORD* pop16() { m_regS += 2; WORD p = (0x0100 + m_regS - 1); return (WORD*)(&(m_pData[p])); }

	inline void lda(BYTE byte) { setNZ(m_regA = byte); }
	inline void ldx(BYTE byte) { setNZ(m_regX = byte); }
	inline void ldy(BYTE byte) { setNZ(m_regY = byte); }
	inline void sta(BYTE* byte) { *byte = m_regA; }
	inline void stx(BYTE* byte) { *byte = m_regX; }
	inline void sty(BYTE* byte) { *byte = m_regY; }

	inline void tax() { setNZ(m_regX = m_regA); }
	inline void tay() { setNZ(m_regY = m_regA); }
	inline void txa() { setNZ(m_regA = m_regX); }
	inline void tya() { setNZ(m_regA = m_regY); }
	inline void tsx() { setNZ(m_regX = m_regS); }
	inline void txs() { setNZ(m_regS = m_regX); }

	inline void pha() { m_pData[0x0100 + m_regS] = m_regA; m_regS--; }
	inline void pla() { m_regS++; setNZ(m_regA = m_pData[0x0100 + m_regS]); }
	inline void php() { m_pData[0x0100 + m_regS] = m_regP.byte; m_regS--; }
	inline void plp() { m_regS++; m_regP.byte = m_pData[0x0100 + m_regS]; }

	inline void and(BYTE byte) { setNZ(m_regA &= byte); }
	inline void ora(BYTE byte) { setNZ(m_regA |= byte); }
	inline void eor(BYTE byte) { setNZ(m_regA ^= byte); }

	inline void adc(BYTE byte) { SHORT val = m_regA; BYTE regA_old = m_regA; setNZ((BYTE)(val += byte +  m_regP.bitC)); m_regA = (BYTE)val; m_regP.bitV = (byte&0x80) ? ((char)m_regA > (char)regA_old) : ((char)m_regA < (char)regA_old); m_regP.bitC =  (val>>8); }
	inline void sbc(BYTE byte) { SHORT val = m_regA; BYTE regA_old = m_regA; setNZ((BYTE)(val -= byte + !m_regP.bitC)); m_regA = (BYTE)val; m_regP.bitV = (byte&0x80) ? ((char)m_regA < (char)regA_old) : ((char)m_regA > (char)regA_old); m_regP.bitC = !(val>>8); }

	inline void asl() { BYTE regA_old = m_regA; setNZ(m_regA <<= 1); m_regP.bitC = (regA_old >> 7); }
	inline void lsr() { BYTE regA_old = m_regA; setNZ(m_regA >>= 1); m_regP.bitC = (regA_old &  1); }
	inline void rol() { BYTE regA_old = m_regA; setNZ((m_regA <<= 1) |= (m_regP.bitC     )); m_regP.bitC = (regA_old >> 7); }
	inline void ror() { BYTE regA_old = m_regA; setNZ((m_regA >>= 1) |= (m_regP.bitC << 7)); m_regP.bitC = (regA_old &  1); }
	inline void asl(BYTE* byte) { BYTE byte_old = *byte; setNZ(*byte <<= 1); m_regP.bitC = (byte_old >> 7); }
	inline void lsr(BYTE* byte) { BYTE byte_old = *byte; setNZ(*byte >>= 1); m_regP.bitC = (byte_old &  1); }
	inline void rol(BYTE* byte) { BYTE byte_old = *byte; setNZ((*byte <<= 1) |= (m_regP.bitC     )); m_regP.bitC = (byte_old >> 7); }
	inline void ror(BYTE* byte) { BYTE byte_old = *byte; setNZ((*byte >>= 1) |= (m_regP.bitC << 7)); m_regP.bitC = (byte_old &  1); }

	inline void inc(BYTE* byte) { setNZ(++*byte); }
	inline void inx() { setNZ(++m_regX); }
	inline void iny() { setNZ(++m_regY); }
	inline void dec(BYTE* byte) { setNZ(--*byte); }
	inline void dex() { setNZ(--m_regX); }
	inline void dey() { setNZ(--m_regY); }

	inline void cmp(BYTE byte) { setNZ(m_regA - byte); m_regP.bitC = (m_regA >= byte); }
	inline void cpx(BYTE byte) { setNZ(m_regX - byte); m_regP.bitC = (m_regX >= byte); }
	inline void cpy(BYTE byte) { setNZ(m_regY - byte); m_regP.bitC = (m_regY >= byte); }
	inline void bit(BYTE byte) { m_regP.bitN = (byte >> 7); m_regP.bitZ = ((byte & m_regA) == 0); m_regP.bitV = (byte >> 6); }

	inline void jmp(WORD word) { m_regPC = word; }
	inline void jsr(WORD word) { push16(m_regPC); m_regPC = word; }
	inline void ret() { m_regPC = *pop16(); }
//	inline void brk() {}
//	inline void rti() {}

	inline void bne(char sbyte) { m_regPC += !(m_regP.bitZ) ? sbyte : 0; }
	inline void beq(char sbyte) { m_regPC +=  (m_regP.bitZ) ? sbyte : 0; }
	inline void bpl(char sbyte) { m_regPC += !(m_regP.bitN) ? sbyte : 0; }
	inline void bmi(char sbyte) { m_regPC +=  (m_regP.bitN) ? sbyte : 0; }
	inline void bcc(char sbyte) { m_regPC += !(m_regP.bitC) ? sbyte : 0; }
	inline void bcs(char sbyte) { m_regPC +=  (m_regP.bitC) ? sbyte : 0; }
	inline void bvc(char sbyte) { m_regPC += !(m_regP.bitV) ? sbyte : 0; }
	inline void bvs(char sbyte) { m_regPC +=  (m_regP.bitV) ? sbyte : 0; }

	inline void clc() { m_regP.bitC = 0; }
	inline void sec() { m_regP.bitC = 1; }
	inline void cld() { m_regP.bitD = 0; }
	inline void sed() { m_regP.bitD = 1; }
	inline void cli() { m_regP.bitI = 0; }
	inline void sei() { m_regP.bitI = 1; }
	inline void clv() { m_regP.bitV = 0; }

	inline void nop() {}

public:
	CEmu6502();
	CEmu6502(BYTE* pData);
	virtual ~CEmu6502();

	void Init(BYTE* pData);
	void Reset();
	DWORD Exec();
	inline WORD GetRegPC() { return m_regPC; };
};

#endif // !defined(AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_)
