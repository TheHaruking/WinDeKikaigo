// Emu6502OutputV2.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "windekikaigov2.h"
#include "Emu6502OutputV2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmu6502OutputV2

IMPLEMENT_DYNCREATE(CEmu6502OutputV2, CDialogBar)

CEmu6502OutputV2::CEmu6502OutputV2()
{
	//{{AFX_DATA_INIT(CEmu6502OutputV2)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//}}AFX_DATA_INIT
}

CEmu6502OutputV2::~CEmu6502OutputV2()
{
}

void CEmu6502OutputV2::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmu6502OutputV2)
	DDX_Control(pDX, IDC_EDIT_STACK, m_editStack);
	DDX_Control(pDX, IDC_EDIT_REGY, m_editRegY);
	DDX_Control(pDX, IDC_EDIT_REGX, m_editRegX);
	DDX_Control(pDX, IDC_EDIT_REGS, m_editRegS);
	DDX_Control(pDX, IDC_EDIT_REGA, m_editRegA);
	DDX_Control(pDX, IDC_EDIT_PC, m_editRegPC);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmu6502OutputV2, CDialogBar)
	//{{AFX_MSG_MAP(CEmu6502OutputV2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmu6502OutputV2 �f�f

#ifdef _DEBUG
void CEmu6502OutputV2::AssertValid() const
{
	CDialogBar::AssertValid();
}

void CEmu6502OutputV2::Dump(CDumpContext& dc) const
{
	CDialogBar::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEmu6502OutputV2 ���b�Z�[�W �n���h��

void CEmu6502OutputV2::Update()
{
	UpdateData(FALSE);
	CString buf;
	
	buf.Format(L"0x%04X", m_cpu->m_regPC); m_editRegPC.SetWindowText(buf);
	buf.Format(L"0x%02X", m_cpu->m_regA); m_editRegA.SetWindowText(buf);
	buf.Format(L"0x%02X", m_cpu->m_regX); m_editRegX.SetWindowText(buf);
	buf.Format(L"0x%02X", m_cpu->m_regY); m_editRegY.SetWindowText(buf);
	buf.Format(L"0x%02X", m_cpu->m_regS); m_editRegS.SetWindowText(buf);

	// �X�^�b�N (�ς܂ꂽ����\��)
	{
		CString bufStack;
		for (int i = 0; i < m_cpu->m_regS; i++) {
			WORD adrStack = 0x01FF - i;
			buf.Format(L" %04X: 0x%02X\r\n", adrStack, m_cpu->m_pData[adrStack]);
			bufStack += buf;
		}

		m_editStack.SetWindowText(bufStack);
		m_editStack.LineScroll(m_editStack.GetLineCount());
	}
}
