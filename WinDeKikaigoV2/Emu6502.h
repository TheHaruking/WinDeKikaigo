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
	inline BYTE imm()  { m_regPC++; return m_pData[m_regPC]; };
	inline BYTE* zd()  { m_regPC++; WORD adr = m_pData[m_regPC]; return &(m_pData[adr]); };
	inline BYTE* zdx() { m_regPC++; WORD adr = m_pData[m_regPC]; return &(m_pData[adr + m_regX]); };
	inline BYTE* zdy() { m_regPC++; WORD adr = m_pData[m_regPC]; return &(m_pData[adr + m_regY]); };
	inline BYTE* ad()  { m_regPC++; WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); return &(m_pData[adr]); };
	inline BYTE* adx() { m_regPC++; WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); return &(m_pData[adr + m_regX]); };
	inline BYTE* ady() { m_regPC++; WORD adr = m_pData[m_regPC]; m_regPC++; adr |= (m_pData[m_regPC] << 8); return &(m_pData[adr + m_regY]); };
	inline BYTE* inx() { m_regPC++; WORD adr = m_pData[m_regPC]; WORD adr2 = m_pData[adr + m_regX]; adr2 |= (m_pData[adr + m_regX +1] << 8); return &(m_pData[adr2]); };
	inline BYTE* iny() { m_regPC++; WORD adr = m_pData[m_regPC]; WORD adr2 = m_pData[adr]; adr2 |= (m_pData[adr+1] << 8); return &(m_pData[adr2 + m_regY]); };

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

public:
	void Exec();
	CEmu6502(BYTE* pData);
	virtual ~CEmu6502();
};

#endif // !defined(AFX_EMU6502_H__A50E5E02_C522_4A1E_B638_B5FE2CD1822C__INCLUDED_)
