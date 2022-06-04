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
	ON_BN_CLICKED(IDC_ASMDLG_1, OnAsmdlg1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmInputBarDlg ���b�Z�[�W �n���h��

BOOL CAsmInputBarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	POINT pos;
	GetCursorPos(&pos);

	RECT rect;
	this->GetWindowRect(&rect);
	DWORD width = rect.right - rect.left;
	DWORD height = rect.bottom - rect.top;
	
//	this->SetWindowPos(this, pos.x, pos.y, pos.x, pos.y, SWP_SHOWWINDOW);
	this->MoveWindow(pos.x - width/2, pos.y - height/2, width, height);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CAsmInputBarDlg::OnAsmdlg1() 
{
	m_dwSelect = 1;
	this->OnOK();
}
