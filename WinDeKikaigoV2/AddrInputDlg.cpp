// AddrInputDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "windekikaigov2.h"
#include "AddrInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddrInputDlg �_�C�A���O


CAddrInputDlg::CAddrInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddrInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddrInputDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CAddrInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddrInputDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddrInputDlg, CDialog)
	//{{AFX_MSG_MAP(CAddrInputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddrInputDlg ���b�Z�[�W �n���h��

BOOL CAddrInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �_�C�A���O�̈ʒu����
	POINT pos;
	GetCursorPos(&pos);

	RECT rect;
	this->GetWindowRect(&rect);
	DWORD width = rect.right - rect.left;
	DWORD height = rect.bottom - rect.top;
	
	this->MoveWindow(pos.x, pos.y - height/2, width, height);

	
//	return FALSE;
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CAddrInputDlg::OnOK()
{
	CString buf;
	m_edit1.GetWindowText(buf);
	m_dwAddr = wcstol(buf, NULL, 16);
	CDialog::OnOK();
}


DWORD CAddrInputDlg::GetAddr()
{
	return m_dwAddr;
}
