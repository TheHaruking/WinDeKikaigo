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

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWinDeKikaigoV2Doc �V���A���C�[�[�V����

void CWinDeKikaigoV2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
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
