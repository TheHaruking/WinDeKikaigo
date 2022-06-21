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
