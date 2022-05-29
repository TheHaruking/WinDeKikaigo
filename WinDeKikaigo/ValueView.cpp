// ValueView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "windekikaigo.h"
#include "ValueView.h"

#include "WinDeKikaigoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CValueView

IMPLEMENT_DYNCREATE(CValueView, CFormView)

CValueView::CValueView()
	: CFormView(CValueView::IDD)
{
	//{{AFX_DATA_INIT(CValueView)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//}}AFX_DATA_INIT
}

CValueView::~CValueView()
{
}

void CValueView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CValueView)
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_VALUE_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CValueView, CFormView)
	//{{AFX_MSG_MAP(CValueView)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValueView �f�f

#ifdef _DEBUG
void CValueView::AssertValid() const
{
	CFormView::AssertValid();
}

void CValueView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CValueView ���b�Z�[�W �n���h��

void CValueView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	m_combo1.InsertString(-1, L"u�@�@�@�@ (uint8_t)"); // "-1" : �Ō���ɒǉ�
	m_combo1.InsertString(-1, L"u�A�A (uint16_t)");
	m_combo1.InsertString(-1, L"u�C (uint32_t)");
	m_combo1.InsertString(-1, L"s�@�@�@�@ (int8_t)");
	m_combo1.InsertString(-1, L"s�A�A (int16_t)");
	m_combo1.InsertString(-1, L"s�C (int32_t)");
	m_combo1.InsertString(-1, L"f�C (float)");
	m_combo1.InsertString(-1, L"------------------------");
	m_combo1.InsertString(-1, L"u�@�̃A�h���X (uint8_t*)");
	m_combo1.InsertString(-1, L"u�A�̃A�h���X (uint16_t*)");
	m_combo1.InsertString(-1, L"u�C�̃A�h���X (uint32_t*)");
	m_combo1.InsertString(-1, L"s�@�̃A�h���X (int8_t*)");
	m_combo1.InsertString(-1, L"s�A�̃A�h���X (int16_t*)");
	m_combo1.InsertString(-1, L"s�C�̃A�h���X (int32_t*)");
	m_combo1.InsertString(-1, L"f�C�̃A�h���X (float*)");
}

void CValueView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
}

void CValueView::OnChangeEdit1() 
{
	CWinDeKikaigoDoc* pDoc = GetDocument();	
	
	UpdateData(TRUE);  // �R���g���[������f�[�^���擾

	// ����
	CString strBuf; // ���͕�����
	BYTE byteBuf;	// ���͕�����𐔒l��
	wchar_t* retp;	// wcstol �̌���

	m_edit1.GetWindowText(strBuf);
	byteBuf = (BYTE)wcstol(strBuf, &retp, 10);

	// �f�[�^�K�p
	pDoc->testBytes[0] = byteBuf;
	pDoc->UpdateAllViews(NULL);
}
