// SplitterPracticeDoc.cpp : CSplitterPracticeDoc �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "SplitterPractice.h"

#include "SplitterPracticeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc

IMPLEMENT_DYNCREATE(CSplitterPracticeDoc, CDocument)

BEGIN_MESSAGE_MAP(CSplitterPracticeDoc, CDocument)
	//{{AFX_MSG_MAP(CSplitterPracticeDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc �N���X�̍\�z/����

CSplitterPracticeDoc::CSplitterPracticeDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CSplitterPracticeDoc::~CSplitterPracticeDoc()
{
}

BOOL CSplitterPracticeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc �V���A���C�[�[�V����

void CSplitterPracticeDoc::Serialize(CArchive& ar)
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
// CSplitterPracticeDoc �N���X�̐f�f

#ifdef _DEBUG
void CSplitterPracticeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSplitterPracticeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterPracticeDoc �R�}���h
