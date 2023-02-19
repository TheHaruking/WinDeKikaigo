// Emu6502OutputV2.cpp : インプリメンテーション ファイル
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
		// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//}}AFX_DATA_INIT
}

CEmu6502OutputV2::~CEmu6502OutputV2()
{
}

void CEmu6502OutputV2::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmu6502OutputV2)
	DDX_Control(pDX, IDC_CHECK_FLAG_Z, m_chkFlagZ);
	DDX_Control(pDX, IDC_CHECK_FLAG_V, m_chkFlagV);
	DDX_Control(pDX, IDC_CHECK_FLAG_R, m_chkFlagR);
	DDX_Control(pDX, IDC_CHECK_FLAG_N, m_chkFlagN);
	DDX_Control(pDX, IDC_CHECK_FLAG_I, m_chkFlagI);
	DDX_Control(pDX, IDC_CHECK_FLAG_D, m_chkFlagD);
	DDX_Control(pDX, IDC_CHECK_FLAG_C, m_chkFlagC);
	DDX_Control(pDX, IDC_CHECK_FLAG_B, m_chkFlagB);
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
	ON_EN_CHANGE(IDC_EDIT_REGA, OnChangeEditRegA)
	ON_EN_CHANGE(IDC_EDIT_REGX, OnChangeEditRegX)
	ON_EN_CHANGE(IDC_EDIT_REGY, OnChangeEditRegY)
	ON_EN_CHANGE(IDC_EDIT_REGS, OnChangeEditRegS)
	ON_EN_CHANGE(IDC_EDIT_PC, OnChangeEditPC)
	ON_BN_CLICKED(IDC_CHECK_FLAG_N, OnCheckFlagN)
	ON_BN_CLICKED(IDC_CHECK_FLAG_V, OnCheckFlagV)
	ON_BN_CLICKED(IDC_CHECK_FLAG_R, OnCheckFlagR)
	ON_BN_CLICKED(IDC_CHECK_FLAG_B, OnCheckFlagB)
	ON_BN_CLICKED(IDC_CHECK_FLAG_D, OnCheckFlagD)
	ON_BN_CLICKED(IDC_CHECK_FLAG_I, OnCheckFlagI)
	ON_BN_CLICKED(IDC_CHECK_FLAG_Z, OnCheckFlagZ)
	ON_BN_CLICKED(IDC_CHECK_FLAG_C, OnCheckFlagC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmu6502OutputV2 診断

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
// CEmu6502OutputV2 メッセージ ハンドラ

void CEmu6502OutputV2::Update()
{
	UpdateData(FALSE);

	// レジスタ PC, A, X, Y, S
	m_buf.Format(L"0x%04X", m_cpu->m_regPC); m_editRegPC.SetWindowText(m_buf);
	m_buf.Format(L"0x%02X", m_cpu->m_regA); m_editRegA.SetWindowText(m_buf);
	m_buf.Format(L"0x%02X", m_cpu->m_regX); m_editRegX.SetWindowText(m_buf);
	m_buf.Format(L"0x%02X", m_cpu->m_regY); m_editRegY.SetWindowText(m_buf);
	m_buf.Format(L"0x%02X", m_cpu->m_regS); m_editRegS.SetWindowText(m_buf);

	// スタック (積まれた分を表示)
	{
		CString bufStack;
		for (int i = 0; i < (0xFF - m_cpu->m_regS); i++) {
			WORD adrStack = 0x01FF - i;
			m_buf.Format(L" %04X: 0x%02X\r\n", adrStack, m_cpu->m_pData[adrStack]);
			bufStack += m_buf;
		}

		m_editStack.SetWindowText(bufStack);
		m_editStack.LineScroll(m_editStack.GetLineCount());
	}

	// ステータスレジスタ
	m_chkFlagN.SetCheck(m_cpu->m_regP.bitN);
	m_chkFlagV.SetCheck(m_cpu->m_regP.bitV);
	m_chkFlagR.SetCheck(m_cpu->m_regP.bitR);
	m_chkFlagB.SetCheck(m_cpu->m_regP.bitB);
	m_chkFlagD.SetCheck(m_cpu->m_regP.bitD);
	m_chkFlagI.SetCheck(m_cpu->m_regP.bitI);
	m_chkFlagZ.SetCheck(m_cpu->m_regP.bitZ);
	m_chkFlagC.SetCheck(m_cpu->m_regP.bitC);
}

void CEmu6502OutputV2::EditToCpu(void* dst, CEdit& edit, DWORD byte)
{
	edit.GetWindowText(m_buf);

	DWORD val = wcstol(m_buf, NULL, 16);
	
	switch (byte)
	{
	case 1: *(BYTE*)dst  = (BYTE)val; break;
	case 2: *(WORD*)dst  = (WORD)val; break;
	case 4: *(DWORD*)dst = val; break;
	default: ASSERT(0); break;
	}
}

void CEmu6502OutputV2::OnChangeEditRegA()
{
	// 対象の editbox にフォーカスがある場合のみ実行.
	CWnd* wndFocus = this->GetFocus();
	if (wndFocus != (CWnd*)&m_editRegA)
		return;

	EditToCpu(&m_cpu->m_regA, m_editRegA, 1);
}

void CEmu6502OutputV2::OnChangeEditRegX()
{
	// 対象の editbox にフォーカスがある場合のみ実行.
	CWnd* wndFocus = this->GetFocus();
	if (wndFocus != (CWnd*)&m_editRegX)
		return;

	EditToCpu(&m_cpu->m_regX, m_editRegX, 1);
}

void CEmu6502OutputV2::OnChangeEditRegY()
{
	// 対象の editbox にフォーカスがある場合のみ実行.
	CWnd* wndFocus = this->GetFocus();
	if (wndFocus != (CWnd*)&m_editRegY)
		return;

	EditToCpu(&m_cpu->m_regY, m_editRegY, 1);
}

void CEmu6502OutputV2::OnChangeEditRegS()
{
	// 対象の editbox にフォーカスがある場合のみ実行.
	CWnd* wndFocus = this->GetFocus();
	if (wndFocus != (CWnd*)&m_editRegS)
		return;

	EditToCpu(&m_cpu->m_regS, m_editRegS, 1);
}

void CEmu6502OutputV2::OnChangeEditPC()
{
	// 対象の editbox にフォーカスがある場合のみ実行.
	CWnd* wndFocus = this->GetFocus();
	if (wndFocus != (CWnd*)&m_editRegPC)
		return;

	EditToCpu(&m_cpu->m_regPC,m_editRegPC, 2);
}

void CEmu6502OutputV2::OnCheckFlagN() 
{
	m_cpu->m_regP.bitN = m_chkFlagN.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagV() 
{
	m_cpu->m_regP.bitV = m_chkFlagV.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagR() 
{
	m_cpu->m_regP.bitR = m_chkFlagR.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagB() 
{
	m_cpu->m_regP.bitB = m_chkFlagB.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagD() 
{
	m_cpu->m_regP.bitD = m_chkFlagD.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagI() 
{
	m_cpu->m_regP.bitI = m_chkFlagI.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagZ() 
{
	m_cpu->m_regP.bitZ = m_chkFlagZ.GetCheck();
	::SetFocus(m_editRegPC);
}

void CEmu6502OutputV2::OnCheckFlagC() 
{
	m_cpu->m_regP.bitC = m_chkFlagC.GetCheck();
	::SetFocus(m_editRegPC);
}
