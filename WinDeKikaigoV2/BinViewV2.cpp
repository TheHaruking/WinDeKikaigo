// BinViewV2.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "WinDeKikaigoV2Doc.h"
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

IMPLEMENT_DYNCREATE(CBinViewV2, CScrollView)

CBinViewV2::CBinViewV2()
{
}

CBinViewV2::~CBinViewV2()
{
}


BEGIN_MESSAGE_MAP(CBinViewV2, CScrollView)
	//{{AFX_MSG_MAP(CBinViewV2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �`��

void CBinViewV2::OnDraw(CDC* pDC)
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();

	// �t�H���g�ύX
	CFont* pFontOld;
	pFontOld = pDC->SelectObject(&m_font);

	// 
	DWORD NEXT = m_nFontHeight + m_nRowMargin;
	DWORD ofs = 0;
	DWORD height = 0;

	CString buf;
	BYTE* data = pDoc->GetPageTopAddr();
	const DWORD BASEADDR = pDoc->GetPage() * PAGESIZE;
	DWORD dw;
	LONG count = 0;

	CBrush brush(RGB(160,160,160));
	CBrush* pBrushOld = pDC->SelectObject(&brush);
	CPen pen(PS_NULL, 0, RGB(160, 160, 160));
	CPen* pPenOld = pDC->SelectObject(&pen);

	// DIGIT_BYTE:1 ... DIGIT_QWORD:8
	const LONG MAXCOUNTTBL[9] = {
		0, PAGESIZE/1, PAGESIZE/2, 0, PAGESIZE/4, 0, 0, 0, PAGESIZE/8
	};

	// PAGESIZE �o�C�g(DIGIT_BYTE�̏ꍇ) ���o�͂���
	for (int i = 0; count < MAXCOUNTTBL[m_eDigit]; i++) {
		ofs = i*m_nMaxColumn;

		// �A�h���X��.
		pDC->Rectangle(0, height, m_nAddrWidth, height + m_nFontHeight + 2);

		buf.Format(L" %04X", BASEADDR + ofs);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		pDC->TextOut(0, height, buf);

		// �f�[�^��.
		pDC->SetBkMode(OPAQUE);

		for (INT j = 0; j < m_nMaxColumn; j++) {
			// �y�[�W�ő�𒴂��Ȃ��悤�ɂ���
			if (count >= MAXCOUNTTBL[m_eDigit])
				break;

			switch (m_eDigit) {
			case DIGIT_BYTE:  dw = ((BYTE*) data)[ofs+j]; break;
			case DIGIT_WORD:  dw = ((WORD*) data)[ofs+j]; break;
			case DIGIT_DWORD: dw = ((DWORD*)data)[ofs+j]; break;
			}
			buf.Format(DATA_HEX2FMT[m_eDigit], dw);

			// �I�����
			if ((count >= m_nSel) && (count < m_nSelEnd)) {
				pDC->SetTextColor(RGB(255,255,255));
				pDC->SetBkColor(RGB(0,0,0));
			} else {
				pDC->SetTextColor(RGB(0,0,0));
				pDC->SetBkColor(RGB(255,255,255));
			}
			pDC->TextOut(m_nDataXOfs + ((m_eDigit*2+1)*j)*m_nFontWidth, height, buf);
			count++;
		}

		height += NEXT;
	}

	// �X�N���[���͈͂̌���
	SetScrollSizes(MM_TEXT, CSize(1, height));

	// �㏈��
	pDC->SelectObject(&m_font);
}

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �f�f

#ifdef _DEBUG
void CBinViewV2::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBinViewV2::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

// �ǉ��I
CWinDeKikaigoV2Doc* CBinViewV2::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoV2Doc)));
	return (CWinDeKikaigoV2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 �����֐�

void CBinViewV2::DigitUp()
{
	switch (m_eDigit) {
	case DIGIT_BYTE:
		m_eDigit = DIGIT_WORD;
		m_nMaxColumn /= 2;
		break;
	case DIGIT_WORD:
		m_eDigit = DIGIT_DWORD;
		m_nMaxColumn /= 2;
		break;
	}
}

void CBinViewV2::DigitDown()
{
	switch (m_eDigit) {
	case DIGIT_WORD:
		m_eDigit = DIGIT_BYTE;
		m_nMaxColumn *= 2;
		break;
	case DIGIT_DWORD:
		m_eDigit = DIGIT_WORD;
		m_nMaxColumn *= 2;
		break;
	}
}

void CBinViewV2::CaretPosUpdate()
{
	CPoint fixPoint;
	const DWORD GROUPNUM = m_eDigit*2+1; // "XX " ��1�P�ʂƂ���

	DWORD sel = m_nSel/m_eDigit;
	fixPoint.x = (sel%m_nMaxColumn) * (m_nFontWidth*GROUPNUM) + ((m_bIsSecond)?m_nFontWidth:0) + m_nDataXOfs;
	fixPoint.y = (sel/m_nMaxColumn) * (m_nFontHeight+m_nRowMargin) - CScrollView::GetScrollPosition().y;

	DWORD selmod = m_nSel % m_eDigit;
	fixPoint.x += selmod * m_nFontWidth*2;

	SetCaretPos(fixPoint);
}

/////////////////////////////////////////////////////////////////////////////
// CBinViewV2 ���b�Z�[�W �n���h��

BOOL CBinViewV2::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// �����o������
	m_nFontHeight = 16;		// �t�H���g�̍���
//	m_nFontWidth = 8;		// �t�H���g�̕� (m_font.CreateFont �֐���Ɏ擾����)
	m_nRowMargin = 1;		// �t�H���g�̍s�]��
	m_nMaxColumn = 4;		// ��
	m_nSel = 0;				// �I�𒆂̔ԍ�
	m_nSelEnd = 0;			// �I��͈͏I�_�̔ԍ�
	m_bIsSecond = FALSE;	// ����4�r�b�g�ҏW�����H
	m_eDigit = DIGIT_BYTE;	// �ҏW���[�h(��)

	m_font.CreateFont(
		m_nFontHeight, 0,		// �����A��
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
	m_nFontWidth = size.cx; // �t�H���g�̕��͂����Őݒ�I
	pDC->SelectObject(&oldFont);
	ReleaseDC(pDC);

	// �A�h���X�\�����̉������v�Z.
	m_nAddrWidth = m_nFontWidth * 6;
	m_nDataXOfs  = m_nAddrWidth + m_nFontWidth*1;

	// �L�����b�g
//	CreateSolidCaret(0, 16);
//	ShowCaret();

	// CScrollView ���쐬���邽�߂̃_�~�[�l
	SetScrollSizes(MM_TEXT, CSize(1,1));

	return bResult;
}

void CBinViewV2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���W�v�Z
	LONG x, y, row;
	const LONG GROUPNUM = m_eDigit*2+1; // "XX " ��1�P�ʂƂ���
	y = CScrollView::GetScrollPosition().y + point.y;

	// �A�h���X�\�����N���b�N���͉��������I��.
	if (point.x < m_nDataXOfs) {
		CScrollView::OnLButtonDown(nFlags, point);
		return;
	}

	// �f�[�^�\�����𒴂����ꍇ�����������I��.
	if (point.x > (m_nDataXOfs + (GROUPNUM*m_nMaxColumn) * m_nFontWidth)) {
		CScrollView::OnLButtonDown(nFlags, point);
		return;
	}

	x = point.x - m_nDataXOfs; // �A�h���X�\�����������Ă���.
	x /= m_nFontWidth; 
	x /= GROUPNUM;
	row = y / (m_nFontHeight + m_nRowMargin);
	m_nSel = row * m_nMaxColumn + x;
	m_nSel *= m_eDigit;

	m_nSel = (m_nSel >= 0) ? m_nSel : 0; // �����`�F�b�N
	m_nSel = (m_nSel <  PAGESIZE) ? m_nSel : PAGESIZE-1; // ����`�F�b�N
	m_nSelEnd = m_nSel;

	m_bIsSecond = FALSE; // 2���ڃt���O���Z�b�g
	
	// �m�F�p
#ifdef _DEBUG
//	CString buf;
//	buf.Format(L"Down! x:%d, y:%d, m_nSel:%d, max:%d\r\n", point.x, point.y, m_nSel, m_nMaxColumn);
//	OutputDebugString(buf);
#endif

	// �L�����b�g�ݒ�
	CaretPosUpdate();
	RedrawWindow();

	// ���� (BinView -> AsmView)
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	pDoc->m_nSel = m_nSel;
	pDoc->UpdateAllViews(this);

	CScrollView::OnLButtonDown(nFlags, point);
}

void CBinViewV2::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	CScrollView::OnLButtonUp(nFlags, point);
}

void CBinViewV2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	BYTE* b = pDoc->GetPageTopAddr();
	BOOL bNeedReset_IsSecond = TRUE;

	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	switch (nChar) {
	case 'I': m_nMaxColumn--; break;
	case 'O': m_nMaxColumn++; break;
	case 'U': DigitDown(); break;
	case 'P': DigitUp(); break;

	case VK_LEFT:  m_nSel--; break;
	case VK_RIGHT: m_nSel++; break;
	case VK_UP:    m_nSel -= m_nMaxColumn*m_eDigit; break;
	case VK_DOWN:  m_nSel += m_nMaxColumn*m_eDigit; break;

	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
	case '8': case '9': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
		{
			// (��)DWORD�̐���: 3210 7654 BA98...
			DWORD sel = m_nSel^(m_eDigit-1);	// xor���Z�Ŋ��Ғl�ɂȂ�.
			// �J�n
			if (!m_bIsSecond) {
				b[sel] = DATA_KEY2HEX[nChar-0x30] << 4;
				m_bIsSecond = TRUE;
			}
			// �I��
			else {
				b[sel] |= DATA_KEY2HEX[nChar-0x30];
				m_bIsSecond = FALSE;
				m_nSel++;
			}
			bNeedReset_IsSecond = FALSE;
			break;
		}
	}

	// �͈̓`�F�b�N
	m_nSel = (m_nSel >= 0) ? m_nSel : 0;					// �����l
	m_nSel = (m_nSel <  PAGESIZE) ? m_nSel : PAGESIZE-1;	// ����l
	m_nSelEnd = m_nSel;

	m_nMaxColumn = (m_nMaxColumn >= 1)  ? m_nMaxColumn : 1;		// �����l
	m_nMaxColumn = (m_nMaxColumn <= 16) ? m_nMaxColumn : 16;	// ����l

	// �ړ������� bIsSecond �����Z�b�g����
	if (bNeedReset_IsSecond)
		m_bIsSecond = FALSE;

	// ��ʂɔ��f
	CaretPosUpdate();
	RedrawWindow();

	// ���� (BinView -> AsmView)
	pDoc->m_nSel = m_nSel;
	pDoc->UpdateAllViews(this);

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CBinViewV2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// ���� (AsmView -> BinView)
	CWinDeKikaigoV2Doc* pDoc = GetDocument();
	m_nSel = pDoc->m_nSel;
	m_nSelEnd = pDoc->m_nSelEnd;
	CaretPosUpdate();

	CScrollView::OnUpdate(pSender, lHint, pHint);	
}

void CBinViewV2::OnSetFocus(CWnd* pOldWnd) 
{
	CScrollView::OnSetFocus(pOldWnd);

	CreateSolidCaret(0, 16);
	ShowCaret();
}

void CBinViewV2::OnKillFocus(CWnd* pNewWnd) 
{
	CScrollView::OnKillFocus(pNewWnd);
	
//	HideCaret();	
}

BOOL CBinViewV2::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
//	return CScrollView::OnMouseWheel(nFlags, zDelta, pt);

	// CSplitterWnd ���p������ OnMouseWheel ���I�[�o�[���C�h����̂��ʓ|�Ȃ��߁ACScrollView �̓����I�Ȋ֐� DoMouseWheel �𒼐ڌĂ�ł��܂����Ƃɂ���.
	if (nFlags & (MK_SHIFT | MK_CONTROL))
		return FALSE;
	return CScrollView::DoMouseWheel(nFlags, zDelta, pt);
}
