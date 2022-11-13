// WinDeKikaigoV2Doc.cpp : CWinDeKikaigoV2Doc �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "WinDeKikaigoV2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc

IMPLEMENT_DYNCREATE(CWinDeKikaigoV2Doc, CDocument)

BEGIN_MESSAGE_MAP(CWinDeKikaigoV2Doc, CDocument)
	//{{AFX_MSG_MAP(CWinDeKikaigoV2Doc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc �N���X�̍\�z/����

CWinDeKikaigoV2Doc::CWinDeKikaigoV2Doc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CWinDeKikaigoV2Doc::~CWinDeKikaigoV2Doc()
{
}

BOOL CWinDeKikaigoV2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)
	int i;
	// Free �G���A�AVRAM �� (�m�F���₷���̓s����) 0-255 �̘A�Ԃɂ��Ă���.
	for (i = 0; i <= 0xDFFF; i++) {
		m_data[i] = i&0xFF;
	}

	// SpriteMem, ���� IO ���� 0 �ɂ��Ă���.
	for (i = 0xE000; i <= 0xFFFF; i++) {
		m_data[i] = 0x00;
	}

	m_nSel = 0;
	m_nSelEnd = 0;
	SetPage(0);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc �V���A���C�[�[�V����

void CWinDeKikaigoV2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
		ar.Write(m_data, sizeof(m_data));
		SetModifiedFlag(FALSE); // �h�L�������g���ύX���ꂽ���ǂ����������t���O. (FALSE : �ύX�Ȃ�)
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
		memset(m_data, 0x00, sizeof(m_data));
		ar.Read(m_data, sizeof(m_data));
		UpdateAllViews(NULL);
		SetModifiedFlag(FALSE);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc �N���X�̐f�f

#ifdef _DEBUG
void CWinDeKikaigoV2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinDeKikaigoV2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc �R�}���h

void CWinDeKikaigoV2Doc::SetPage(LONG nPage)
{
	if ((nPage < 0) || (nPage >= PAGENUM)) {
		CString buf;
		buf.Format(
			L"ERROR:\n�w�肳�ꂽ�y�[�W�͋��e�͈͂𒴂��Ă��܂��B\n�E�w�肳�ꂽ�y�[�W: 0x%02X\n�E���e�͈�: 0x%02X �` 0x%0X",
			nPage, 0x00, PAGENUM-1);
		AfxMessageBox(buf);
		return;
	}

	m_nPage = nPage;
	m_pPageTop = &(m_data[nPage * PAGESIZE]);
}


BYTE* CWinDeKikaigoV2Doc::GetPageTopAddr()
{
	return m_pPageTop;
}


BYTE* CWinDeKikaigoV2Doc::GetDataAddr(LONG n)
{
	return &(m_data[n]);
}

LONG CWinDeKikaigoV2Doc::GetPage()
{
	return m_nPage;
}
