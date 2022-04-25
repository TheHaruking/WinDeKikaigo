// BinViewV2.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "WinDeKikaigoDoc.h"
#include "BinViewV2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// �萔
const BYTE CBinViewV2::DATA_KEY2HEX[] = {
	// 0123456789:;<=>?
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0, 0, 0, 0, 0, 0,
	// @ABCDEF
	0, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
const BYTE CBinViewV2::DATA_KEY2HEX10[] = {
	0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0, 0, 0, 0, 0, 0,
	0, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0
};
const LPTSTR CBinViewV2::DATA_HEX2FMT[] = {
	L"", L"%02X ", L"%04X ", L"%06X ", L"%08X ",
	L"%010X ", L"%012X ", L"%014X ", L"%016X "
};

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2

IMPLEMENT_DYNCREATE(CBinViewV2, CView)

CBinViewV2::CBinViewV2()
{
}

CBinViewV2::~CBinViewV2()
{
}


BEGIN_MESSAGE_MAP(CBinViewV2, CView)
	//{{AFX_MSG_MAP(CBinViewV2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �`��

void CBinViewV2::OnDraw(CDC* pDC)
{
	CWinDeKikaigoDoc* pDoc = GetDocument();

	// �t�H���g�ύX
	CFont* pFontOld;
	pFontOld = pDC->SelectObject(&m_font);

	// 
	DWORD NEXT = m_dwFontHeight + m_dwRowMargin;
	DWORD ofs = 0;
	DWORD height = 0;

	CString buf, bufLine;
	BYTE* b = pDoc->testBytes;
	DWORD dw;

	for (int i = 0; i < 8; i++) {
		ofs = i*m_dwMaxColumn;
		
		bufLine.Format(L"");
		for (DWORD j = 0; j < m_dwMaxColumn; j++) {
			switch (m_eDigit) {
			case DIGIT_BYTE: dw = b[ofs+j]; break;
			case DIGIT_WORD: dw = ((WORD*)b)[ofs+j]; break;
			case DIGIT_DWORD: dw = ((DWORD*)b)[ofs+j]; break;
			}
			buf.Format(DATA_HEX2FMT[m_eDigit], dw);
			bufLine += buf;
		}
		pDC->TextOut(0, height, bufLine);
		height += NEXT;
	}

	// �㏈��
	pDC->SelectObject(&m_font);
}

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �f�f

#ifdef _DEBUG
void CBinViewV2::AssertValid() const
{
	CView::AssertValid();
}

void CBinViewV2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// �ǉ��I
CWinDeKikaigoDoc* CBinViewV2::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �����֐�

void CBinViewV2::DigitUp()
{
	switch (m_eDigit) {
	case DIGIT_BYTE:
		m_eDigit = DIGIT_WORD;
		m_dwMaxColumn /= 2;
		break;
	case DIGIT_WORD:
		m_eDigit = DIGIT_DWORD;
		m_dwMaxColumn /= 2;
		break;
	}
}

void CBinViewV2::DigitDown()
{
	switch (m_eDigit) {
	case DIGIT_WORD:
		m_eDigit = DIGIT_BYTE;
		m_dwMaxColumn *= 2;
		break;
	case DIGIT_DWORD:
		m_eDigit = DIGIT_WORD;
		m_dwMaxColumn *= 2;
		break;
	}
}

void CBinViewV2::CaretPosUpdate()
{
	CPoint fixPoint;
	const DWORD GROUPNUM = m_eDigit*2+1; // "XX " ��1�P�ʂƂ���

	DWORD sel = m_dwSel/m_eDigit;
	fixPoint.x = (sel%m_dwMaxColumn) * (m_dwFontWidth*GROUPNUM);
	fixPoint.y = (sel/m_dwMaxColumn) * (m_dwFontHeight+m_dwRowMargin);

	DWORD selmod = m_dwSel % m_eDigit;
	fixPoint.x += selmod * m_dwFontWidth*2;
	SetFocus();
	SetCaretPos(fixPoint);
}

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 ���b�Z�[�W �n���h��

BOOL CBinViewV2::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// �����o������
	m_dwFontHeight = 16;	// �t�H���g�̍���
//	m_dwFontWidth = 8;		// �t�H���g�̕� (m_font.CreateFont �֐���Ɏ擾����)
	m_dwRowMargin = 1;		// �t�H���g�̍s�]��
	m_dwMaxColumn = 4;		// ��
	m_dwSel = 0;			// �I�𒆂̔ԍ�
	m_bIsSecond = FALSE;	// ����4�r�b�g�ҏW�����H
	m_eDigit = DIGIT_BYTE; // �ҏW���[�h(��)

	m_font.CreateFont(
		m_dwFontHeight, 0,		// �����A��
		0, 0, FW_DONTCARE,		// �p�x�A�p�x�A����
		FALSE, FALSE, FALSE,	// �ΆA�����A�����
		ANSI_CHARSET,			// �����Z�b�g
		OUT_DEFAULT_PRECIS,		// �o�͐��x
		CLIP_DEFAULT_PRECIS,	// �N���b�s���O���x
		DEFAULT_QUALITY,		// �o�͕i��
		DEFAULT_PITCH,			// �s�b�`
		_T("�l�r �S�V�b�N")		// �^�C�v�t�F�C�X��
		);

	// �t�H���g�����擾
	CDC* pDC = GetDC();
	CFont* oldFont = pDC->SelectObject(&m_font);
	SIZE size;

	::GetTextExtentPointW(pDC->m_hDC, L"0", 1 , &size);
	m_dwFontWidth = size.cx; // �����ݒ�I
	pDC->SelectObject(&oldFont);
	ReleaseDC(pDC);

	// �L�����b�g
	CreateSolidCaret(0, 16);
	ShowCaret();

	return bResult;
}

void CBinViewV2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
//	CWinDeKikaigoDoc* pDoc = GetDocument();
}

void CBinViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���W�v�Z
	DWORD x, row, xmod;
	const DWORD GROUPNUM = m_eDigit*2+1; // "XX " ��1�P�ʂƂ���

	x = point.x / m_dwFontWidth;
	xmod = (x % GROUPNUM)/2; // �󔒃N���b�N���Ɏ�����I�����邪���e����B
	x /= GROUPNUM;
	row = point.y / (m_dwFontHeight + m_dwRowMargin);
	m_dwSel = row * m_dwMaxColumn + x;
	m_dwSel *= m_eDigit;
	m_dwSel += xmod;
	
	// �o��
	CString buf;
	buf.Format(L"Down! x:%d, y:%d, m_dwSel:%d, max:%d\r\n", point.x, point.y, m_dwSel, m_dwMaxColumn);
	OutputDebugString(buf);

	// �L�����b�g�ݒ�
	CaretPosUpdate();

	CView::OnLButtonDown(nFlags, point);
}

void CBinViewV2::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	CView::OnLButtonUp(nFlags, point);
}

void CBinViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();
	BYTE* b = pDoc->testBytes;

	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	switch (nChar) {
	case 'I': m_dwMaxColumn--; break;
	case 'O': m_dwMaxColumn++; break;
	case 'U': DigitDown(); break;
	case 'P': DigitUp(); break;

	case VK_LEFT:  m_dwSel--; break;
	case VK_RIGHT: m_dwSel++; break;
	case VK_UP:    m_dwSel -= m_dwMaxColumn*m_eDigit; break;
	case VK_DOWN:  m_dwSel += m_dwMaxColumn*m_eDigit; break;

	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
	case '8': case '9': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
		{
			// (��)DWORD�̐���: 3210 7654 BA98...
			DWORD sel = m_dwSel^(m_eDigit-1);	// xor���Z�Ŋ��Ғl�ɂȂ�.
			// �J�n
			if (!m_bIsSecond) {
				b[sel] = DATA_KEY2HEX[nChar-0x30] << 4;
				m_bIsSecond = TRUE;
			}
			// �I��
			else {
				b[sel] |= DATA_KEY2HEX[nChar-0x30];
				m_bIsSecond = FALSE;
				m_dwSel++;
			}
			break;
		}
	}

	// ��ʂɔ��f
	CaretPosUpdate();
	RedrawWindow();
	pDoc->UpdateAllViews(this);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
