// AsmInputBarDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "AsmInputBarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg �_�C�A���O


CAsmInputBarDlg::CAsmInputBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAsmInputBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAsmInputBarDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CAsmInputBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmInputBarDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAsmInputBarDlg, CDialog)
	//{{AFX_MSG_MAP(CAsmInputBarDlg)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDC_ASMDLG_0, IDC_ASMDLG_9, OnClickedPanel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg ���b�Z�[�W �n���h��

BOOL CAsmInputBarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �_�C�A���O�̈ʒu����
	POINT pos;
	GetCursorPos(&pos);

	RECT rect;
	this->GetWindowRect(&rect);
	DWORD width = rect.right - rect.left;
	DWORD height = rect.bottom - rect.top;
	
	this->MoveWindow(pos.x - width/2, pos.y - height/2, width, height);

	// �{�^���̖���������
	for (int i = 0; i < 10; i++) {
		if (m_ADRTABLE[1+i /* HEAD �͏���*/] == 0) {
			GetDlgItem(IDC_ASMDLG_0+i)->ShowWindow(SW_HIDE);
		}
	}
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CAsmInputBarDlg::OnClickedPanel(UINT nID) 
{
	// #define IDC_ASMDLG_0                    5100
	UINT id = nID - IDC_ASMDLG_0;
	m_dwSelect = id;

	this->OnOK();
}

void CAsmInputBarDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAsmInputBarDlg::SetAdressingModeDataTable(const LONG* ADRTABLE)
{
	m_ADRTABLE = ADRTABLE;
}

DWORD CAsmInputBarDlg::GetSelected()
{
	return m_dwSelect;
}
