// AsmViewDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"
#include "AsmViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg �_�C�A���O


CAsmViewDlg::CAsmViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAsmViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAsmViewDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CAsmViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsmViewDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_btnLda);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAsmViewDlg, CDialog)
	//{{AFX_MSG_MAP(CAsmViewDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsmViewDlg ���b�Z�[�W �n���h��

BOOL CAsmViewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
/*	m_imageList.Create(IDB_BITMAP1, 32, 64, ILC_COLOR8);
	
	CString buf;
	buf.Format(L"m_imageList.GetImageCount() : %d", m_imageList.GetImageCount());
	OutputDebugString(buf);

	HICON hIcon;
	CBitmapButton* m_btn;
	DWORD button_tbl[] = {
		IDC_BUTTON1, IDC_BUTTON2, IDC_BUTTON3, 
		IDC_BUTTON4, IDC_BUTTON5, IDC_BUTTON6, 
	};
	for (int i = 0; i < 6; i++) {
		m_btn = (CBitmapButton*)GetDlgItem(button_tbl[i]);
		hIcon = m_imageList.ExtractIcon(1+i);
		m_btn->SetIcon(hIcon);
	}
*/			
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
