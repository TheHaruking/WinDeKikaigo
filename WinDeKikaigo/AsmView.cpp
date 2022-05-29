// AsmView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "AsmView.h"

#include "WinDeKikaigoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmView

IMPLEMENT_DYNCREATE(CAsmView, CFormView)

CAsmView::CAsmView()
	: CFormView(CAsmView::IDD)
{
	//{{AFX_DATA_INIT(CAsmView)
	//}}AFX_DATA_INIT
}

CAsmView::~CAsmView()
{
}

void CAsmView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmView)
	DDX_Control(pDX, IDC_COMBO4, m_combo4);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAsmView, CFormView)
	//{{AFX_MSG_MAP(CAsmView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmView �f�f

#ifdef _DEBUG
void CAsmView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAsmView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

// �ǉ��I
CWinDeKikaigoDoc* CAsmView::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDeKikaigoDoc)));
	return (CWinDeKikaigoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAsmView ���b�Z�[�W �n���h��

void CAsmView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	m_combo1.InsertString(-1, L"LDA #$XX");
	m_combo1.InsertString(-1, L"LDA $XXXX");
	m_combo1.InsertString(-1, L"LDA $XX, x");
	m_combo1.InsertString(-1, L"LDA $XX, y");

}

void CAsmView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();

	// �������e�X�g�I
	BYTE* testBytes = pDoc->testBytes;

	// �����񏈗�
	if (testBytes[0] == 0x34) {
		m_combo4.EnableWindow(TRUE);

	} else {
		m_combo4.EnableWindow(FALSE);
	}
}
