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
const DWORD CBinViewV2::DATA_KEY2HEX[] = {
	// 0123456789:;<=>?
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0, 0, 0, 0, 0, 0,
	// @ABCDEF
	0, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
const DWORD CBinViewV2::DATA_KEY2HEX10[] = {
	0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0, 0, 0, 0, 0, 0,
	0, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0
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

	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
	CFont* pFontOld;
	pFontOld = pDC->SelectObject(&m_font);

	// �������e�X�g�I
	DWORD NEXT = m_dwFontHeight + m_dwRowMargin;
	DWORD ofs = 0;
	DWORD height = 0;

	CString buf;
	BYTE* b = pDoc->testBytes;

	for (int i = 0; i < 8; i++) {
		ofs = i*m_dwMaxColumn;
		switch (m_dwMaxColumn) {
		case  1: buf.Format(L"%02X", b[ofs+0]); break;
		case  2: buf.Format(L"%02X %02X", b[ofs+0], b[ofs+1]); break;
		case  3: buf.Format(L"%02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2]); break;
		case  4: buf.Format(L"%02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3]); break;
		case  5: buf.Format(L"%02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4]); break;
		case  6: buf.Format(L"%02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5]); break;
		case  7: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6]); break;
		case  8: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7]); break;
		case  9: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8]); break;
		case 10: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9]); break;
		case 11: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10]); break;
		case 12: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11]); break;
		case 13: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12]); break;
		case 14: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12], b[ofs+13]); break;
		case 15: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12], b[ofs+13], b[ofs+14]); break;
		case 16: buf.Format(L"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", b[ofs+0], b[ofs+1], b[ofs+2], b[ofs+3], b[ofs+4], b[ofs+5], b[ofs+6], b[ofs+7], b[ofs+8], b[ofs+9], b[ofs+10], b[ofs+11], b[ofs+12], b[ofs+13], b[ofs+14], b[ofs+15]); break;
		}
		pDC->TextOut(0, height, buf);
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
// CBinViewV2 ���b�Z�[�W �n���h��

BOOL CBinViewV2::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// �����o������
	m_dwFontHeight = 16;
//	m_dwFontWidth = 8; // m_font.CreateFont �֐���Ɏ擾����.
	m_dwRowMargin = 1;
	m_dwMaxColumn = 16;
	m_dwSel = 0;
	m_bIsSecond = FALSE;

	m_font.CreateFont(
		m_dwFontHeight, 0,	// �����A��
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
	m_dwFontWidth = size.cx;
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
	DWORD x, row;
	x = (point.x + m_dwFontWidth/2) / m_dwFontWidth;
	x /= 3;	// "XX " ��1�P�ʂƂ���
	row = point.y / (m_dwFontHeight + m_dwRowMargin);
	m_dwSel = row * m_dwMaxColumn + x;
	
	// �o��
	CString buf;
	buf.Format(L"Down! x:%d, y:%d, m_dwSel:%d, max:%d\r\n", point.x, point.y, m_dwSel, m_dwMaxColumn);
	OutputDebugString(buf);

	// �L�����b�g�ݒ�
	CPoint fixPoint;
	fixPoint.x = (m_dwSel%m_dwMaxColumn) * (m_dwFontWidth*3);
	fixPoint.y = (m_dwSel/m_dwMaxColumn) * (m_dwFontHeight+m_dwRowMargin);
	SetFocus();
	SetCaretPos(fixPoint);

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
	case VK_LEFT: m_dwMaxColumn--; break;
	case VK_RIGHT: m_dwMaxColumn++; break;
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
	case '8': case '9': case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
		if (!m_bIsSecond) {
			b[m_dwSel] = DATA_KEY2HEX10[nChar-0x30];
			m_bIsSecond = TRUE;
		} else {
			b[m_dwSel] |= DATA_KEY2HEX[nChar-0x30];
			m_bIsSecond = FALSE;
			m_dwSel++;
		}
		break;
	}
	RedrawWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
