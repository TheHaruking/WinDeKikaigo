// AsmInputDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "AsmInputBar.h"
#include "AsmInputBarDlg.h"

#include "AsmViewV2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBar �_�C�A���O

CAsmInputBar::CAsmInputBar()
{
	//{{AFX_DATA_INIT(CAsmInputBar)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}

void CAsmInputBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmInputBar)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAsmInputBar, CDialogBar)
	//{{AFX_MSG_MAP(CAsmInputBar)
//	ON_BN_CLICKED(IDC_INPUT_LDA, OnInputLda)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)   // �ǉ��I
	ON_COMMAND_RANGE(IDC_PANE_LDA, IDC_PANE_NOP, OnInputLda)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBar ���b�Z�[�W �n���h��

LONG CAsmInputBar::OnInitDialog(UINT wParam, LONG lParam)
{
	BOOL bRet = HandleInitDialog(wParam, lParam);

	if (!UpdateData(FALSE))
	{
		TRACE0("Warning: UpdateDate failed.");
	}

	return bRet;
}

void CAsmInputBar::OnInputLda(UINT nID)
{
	/*
		#define IDC_PANE_LDA                    5000
		#define IDC_PANE_LDX                    5001
		...
		#define IDC_PANE_NOP                    5055
		�� nID �̏��� ASMVIEW �� enum OP_LDA ��ɏ�����悤�Ɏ��ƂŐݒ肵�Ă���B
	*/
	DWORD id = nID - IDC_PANE_LDA + 1;
	const LONG* OPADRTABLE = m_pAsmView->ASM2ADR[id];
	BYTE data[3] = { 0x00, 0x00, 0x00 };

	// �P��̃A�h���b�V���O���[�h�݂̂̃I�y�R�[�h�������ꍇ
	if (OPADRTABLE[0] >= 0x00) {
		data[0] = (BYTE)OPADRTABLE[0];
	}
	// �����̃A�h���b�V���O���[�h��L����I�y�R�[�h�������ꍇ
	else /*(OPADRTABLE[0] == -1)*/ {
		CAsmInputBarDlg dlg;

		dlg.SetAdressingModeDataTable(OPADRTABLE);
		if (dlg.DoModal() == IDCANCEL)
			return;

		data[0] = (BYTE)OPADRTABLE[dlg.GetSelected() + 1];
	}

	// ���f
	m_pAsmView->SetAsmObj(m_pAsmView->GetAsmSel(), data);
	m_pAsmView->AsmObjToBin();
	m_pAsmView->GetDocument()->UpdateAllViews(NULL);
}
