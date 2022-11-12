// MainFrm.cpp : CMainFrame �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "BinViewV2.h"
#include "AsmViewV2.h"
#include "AsmInputBarDlg.h"
#include "Emu6502.h"
#include "Emu6502OutputV2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_APP_LEFTPANE, OnAppLeftpane)
	ON_COMMAND(ID_APP_RIGHTPANE, OnAppRightpane)
	ON_COMMAND(ID_APP_DEBUG, OnAppDebug)
	ON_COMMAND(ID_APP_RESET, OnAppReset)
	ON_COMMAND(ID_APP_VM, OnAppVm)
	ON_UPDATE_COMMAND_UI(ID_APP_LEFTPANE, OnUpdateAppLeftpane)
	ON_UPDATE_COMMAND_UI(ID_APP_RIGHTPANE, OnUpdateAppRightpane)
	ON_UPDATE_COMMAND_UI(ID_APP_VM, OnUpdateAppVm)
	ON_COMMAND(ID_APP_TEST, OnAppTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̍\�z/����

CMainFrame::CMainFrame()
{
	// TODO: ���̈ʒu�Ƀ����o�̏����������R�[�h��ǉ����Ă��������B
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1) // OnCreateClient �͂���
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		/*| CBRS_GRIPPER*/ | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // �쐬�Ɏ��s
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�͈ȉ��̂R�s���폜
	//       ���Ă��������B
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	// ���y�C��
	if (!m_wndDialogBar_L.Create(this,
			IDD_DIALOGBAR_L, CBRS_LEFT, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// ��\���ɂ��Ă���.
	this->ShowControlBar(&m_wndDialogBar_L, FALSE, FALSE);

	// �E�y�C��
	if (!m_wndDialogBar_R.Create(this,
			IDD_DIALOGBAR_R, CBRS_RIGHT, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// ���y�C��
	if (!m_wndCpuOutput.Create(this,
			IDD_EMU6502OUTPUTV2_FORM, CBRS_BOTTOM, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// �N�����̃t�H�[�J�X���w��
	SetActiveView((CView*)m_wndSplitter.GetPane(0,0));

	// AsmInputBar <- AsmView
	m_wndDialogBar_R.m_pAsmView = (CAsmViewV2*)m_wndSplitter.GetPane(0,1);

	// CEmu6502Output <- CEmu6502
	m_wndCpuOutput.m_cpu = &m_cpu;

	// CPU ���W���[���̏�����
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_cpu.Init(pDoc->GetDataAddr(0x0000));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C�����āAWindow �N���X��X�^�C����
	//       �C�����Ă��������B

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̐f�f

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame ���b�Z�[�W �n���h��


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	// return CFrameWnd::OnCreateClient(lpcs, pContext);
	
	// �e�����E�B���h�E (m_wndSplitter) ���쐬���܂�
	if (!m_wndSplitter.CreateStatic(this, 1, 2)) // �cx��
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CBinViewV2), CSize(200, -1), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CAsmViewV2), CSize(-1, -1), pContext)	
		)
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}

	// ����.
	return TRUE;
}

void CMainFrame::OnAppLeftpane() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������
	BOOL bVisible = m_wndDialogBar_L.IsWindowVisible();
	this->ShowControlBar(&m_wndDialogBar_L, bVisible^1, FALSE);
}

void CMainFrame::OnAppRightpane() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������
	BOOL bVisible = m_wndDialogBar_R.IsWindowVisible();
	this->ShowControlBar(&m_wndDialogBar_R, bVisible^1, FALSE);
}

void CMainFrame::OnAppDebug() 
{
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_cpu.Exec();
	m_wndCpuOutput.Update();
	pDoc->UpdateAllViews(NULL);
	
	// ���z�}�V���E�B���h�E���J���Ă���ꍇ.
	if (m_wndVmWnd.m_hWnd != NULL) {
		m_wndVmWnd.Invalidate(FALSE); // �폜�͂��Ȃ�.
		m_wndVmWnd.UpdateWindow();
	}
}

void CMainFrame::OnAppReset() 
{
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	m_cpu.Reset();
	m_wndCpuOutput.Update();
	pDoc->UpdateAllViews(NULL);	
}

void CMainFrame::OnAppVm() 
{
	// �� Create ��Ԃł���� VmWnd ��\��������
	if (m_wndVmWnd.GetSafeHwnd() == NULL)
	{
		m_wndVmWnd.CreateEx(this);
		m_wndVmWnd.ShowWindow(SW_SHOW);

		// Document �N���X���Z�b�g
		CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
		m_wndVmWnd.SetDocument(pDoc);
	}
	else // ���ł� Create ����Ă���ꍇ�� Destroy ����.
	{
		m_wndVmWnd.DestroyWindow();
	}
}

void CMainFrame::OnUpdateAppLeftpane(CCmdUI* pCmdUI) 
{
	// TODO: ���̈ʒu�� command update UI �n���h���p�̃R�[�h��ǉ����Ă�������
	BOOL bVisible = m_wndDialogBar_L.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);
}

void CMainFrame::OnUpdateAppRightpane(CCmdUI* pCmdUI) 
{
	// TODO: ���̈ʒu�� command update UI �n���h���p�̃R�[�h��ǉ����Ă�������
	BOOL bVisible = m_wndDialogBar_R.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);	
}

void CMainFrame::OnUpdateAppVm(CCmdUI* pCmdUI) 
{
	// �� Create (Destroy ��) �ł���� FALSE.
	if (m_wndVmWnd.GetSafeHwnd() == NULL) {
		pCmdUI->SetCheck(FALSE);
		return;
	}

	// TODO: ���̈ʒu�� command update UI �n���h���p�̃R�[�h��ǉ����Ă�������
	BOOL bVisible = m_wndVmWnd.IsWindowVisible();
	pCmdUI->SetCheck(bVisible);		
}

// �@�\�m�F�p�֐�.
void CMainFrame::OnAppTest() 
{
	CWinDeKikaigoV2Doc* pDoc = (CWinDeKikaigoV2Doc*)(GetActiveView()->GetDocument());
	
	// ���l����͂ł��� CAddrInputDlg �𗬗p���ăy�[�W���w�肵�Ă��܂����Ƃɂ���.
	CAddrInputDlg dlg;

	dlg.DoModal();
	pDoc->SetPage(dlg.GetAddr());
	pDoc->UpdateAllViews(NULL);
}
