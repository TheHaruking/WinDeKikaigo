// ViewPracticeDoc.cpp : CViewPracticeDoc �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "ViewPractice.h"

#include "ViewPracticeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc

IMPLEMENT_DYNCREATE(CViewPracticeDoc, CDocument)

BEGIN_MESSAGE_MAP(CViewPracticeDoc, CDocument)
	//{{AFX_MSG_MAP(CViewPracticeDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc �N���X�̍\�z/����

CViewPracticeDoc::CViewPracticeDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CViewPracticeDoc::~CViewPracticeDoc()
{
}

BOOL CViewPracticeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc �V���A���C�[�[�V����

void CViewPracticeDoc::Serialize(CArchive& ar)
{
	// CEditView �͂��ׂẴV���A���C�[�[�V���� �n���h���̂ǂꂩ�̃G�f�B�b�g�R���g���[�����܂�ł��܂��B
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc �N���X�̐f�f

#ifdef _DEBUG
void CViewPracticeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CViewPracticeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewPracticeDoc �R�}���h
