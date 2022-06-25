// Emu6502.h: CEmu6502 クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_)
#define AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEmu6502  
{
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

protected:
	inline BYTE imm()  { m_regPC++; return m_pData[m_regPC]; };
	inline BYTE* zr()  { m_regPC++; WORD adr = m_pData[m_regPC]; return &(m_pData[adr]); };
	inline BYTE* zrx() { m_regPC++; WORD adr = m_pData[m_regPC]; return &(m_pData[adr + m_regX]); };
	inline BYTE* zry() { m_regPC++; WORD adr = m_pData[m_regPC]; return &(m_pData[adr + m_regY]); };
	inline BYTE* ad()  { m_regPC++; WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); return &(m_pData[adr]); };
	inline BYTE* adx() { m_regPC++; WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); return &(m_pData[adr + m_regX]); };
	inline BYTE* ady() { m_regPC++; WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); return &(m_pData[adr + m_regY]); };
	inline BYTE* idx() { m_regPC++; WORD adr = m_pData[m_regPC]; WORD adr2 = m_pData[adr + m_regX]; adr2 |= (m_pData[adr + m_regX +1] << 8); return &(m_pData[adr2]); };
	inline BYTE* idy() { m_regPC++; WORD adr = m_pData[m_regPC]; WORD adr2 = m_pData[adr]; adr2 |= (m_pData[adr+1] << 8); return &(m_pData[adr2 + m_regY]); };

	/* for test!! */ inline void setN(BYTE byte) { m_regP.bitN = (byte >> 7); }
	inline void setNZ(BYTE byte)                 { m_regP.bitN = (byte >> 7); m_regP.bitZ = (byte == 0); }
	inline void setNZC(BYTE byte, BYTE before)   { m_regP.bitN = (byte >> 7); m_regP.bitZ = (byte == 0); m_regP.bitC = (before > byte);}
	inline void setNZCV(BYTE byte, BYTE before)  { m_regP.bitN = (byte >> 7); m_regP.bitZ = (byte == 0); m_regP.bitC = (before > byte); m_regP.bitV = ((char)before > (char)byte); }
	inline void setNZCVn(BYTE byte, BYTE before) { m_regP.bitN = (byte >> 7); m_regP.bitZ = (byte == 0); m_regP.bitC = (before > byte); m_regP.bitV = ((char)before < (char)byte); }

	inline void lda(BYTE byte) { m_regA = byte; setNZ(byte); }
	inline void sta(BYTE* byte) { *byte = m_regA; }
	inline void adc(BYTE byte) { BYTE regA_old = m_regA; setNZCV((m_regA += byte), regA_old); }
	inline void sbc(BYTE byte) { BYTE regA_old = m_regA; setNZCVn((m_regA -= byte), regA_old); }
	inline void bit(BYTE byte) { m_regP.bitZ = ((byte & m_regA) == 0); m_regP.bitN = (byte >> 7); m_regP.bitV = (byte >> 6); }
	inline void inx() { m_regX++; setNZ(m_regX); }
	inline void cmp() { }

public:
	void Exec();
	CEmu6502(BYTE* pData);
	virtual ~CEmu6502();
};

#endif // !defined(AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_)
