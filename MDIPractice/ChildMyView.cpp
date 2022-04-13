// ChildMyView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MDIPractice.h"
#include "ChildMyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildMyView

IMPLEMENT_DYNCREATE(CChildMyView, CWnd)

BEGIN_MESSAGE_MAP(CChildMyView, CWnd)
	//{{AFX_MSG_MAP(CChildMyView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CChildMyView::CChildMyView()
{
}

CChildMyView::~CChildMyView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CChildMyView ���b�Z�[�W �n���h��

BOOL CChildMyView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	// CEdit��
/*	if (!CEdit::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
*/
	// CEditView �� (���s���G���[�I)
/*	if (!CEditView::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���[�h ���b�v���g�p�\�ɂ��܂�
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
*/
	return TRUE;
}



void CChildMyView::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	CFont* pFontOld;
	
	pFontOld = dc.SelectObject(&m_font);

	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	CString buf;

	dc.SetBkColor(RGB(255, 255, 0));
	buf.Format(L" ADDRESS   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F    0123456789ABCDEF");
	dc.TextOut(0, 0, buf);

	dc.SetBkColor(RGB(128, 128, 128));
	dc.SetTextColor(RGB(255, 255, 255));
	buf.Format(L" 00000000 ");
	dc.TextOut(0, 16, buf);

	// ���ɖ߂�
	dc.SelectObject(pFontOld);
	
}
// �`��p���b�Z�[�W�Ƃ��� CWnd::OnPaint() ���Ăяo���Ă͂����܂���


BOOL CChildMyView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{

	CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
/*
	m_static.Create(L"hello!!", WS_CHILD | WS_VISIBLE,
		CRect(10, 10, 150, 50), this);
	m_edit.Create(WS_CHILD | WS_VISIBLE, 
		CRect(30, 30, 150, 50), this, 0);
*/
	// �t�H���g�ҏW�I
	m_font.CreateFont(
		16, 0, 0, 0, FW_DONTCARE, // �����A���A�p�x�A�p�x�A����
		FALSE, FALSE, FALSE,	// �ΆA�����A�����
		SHIFTJIS_CHARSET,		// �����Z�b�g
		OUT_DEFAULT_PRECIS,		// �o�͐��x
		CLIP_DEFAULT_PRECIS,	// �N���b�s���O���x
		DRAFT_QUALITY,			// �o�͕i��
		DEFAULT_PITCH,			// �s�b�`
		_T("�l�r �S�V�b�N")		// �^�C�v�t�F�C�X��
		);

	return TRUE;
}
