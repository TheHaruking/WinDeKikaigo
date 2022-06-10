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
	ON_BN_CLICKED(IDC_INPUT_LDA, OnInputLda)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)   // �ǉ��I
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

void CAsmInputBar::OnInputLda()
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	CAsmInputBarDlg dlg;

	dlg.DoModal();
	
	CString buf;
	buf.Format(L"GetAsmSel() : %d, dwSelect: %d", m_pAsmView->GetAsmSel(), dlg.m_dwSelect);

	// ��������
	// m_pDoc->m_data[m_nCurIp] = 0xEA;
	BYTE data[] = { 0xEA };
	m_pAsmView->SetAsmObj(m_pAsmView->GetAsmSel(), data, sizeof(data));
	m_pAsmView->AsmObjToBin();

	OutputDebugString(buf);

	m_pDoc->UpdateAllViews(NULL);
}
