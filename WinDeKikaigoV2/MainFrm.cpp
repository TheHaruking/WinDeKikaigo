// MainFrm.cpp : CMainFrame �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "WinDeKikaigoV2.h"

#include "BinViewV2.h"
#include "AsmViewV2.h"
#include "AsmInputBarDlg.h"

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

	// �E�y�C��
	if (!m_wndDialogBar_R.Create(this,
			IDD_DIALOGBAR_R, CBRS_RIGHT, 0))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// �N�����̃t�H�[�J�X���w��
	SetActiveView((CView*)m_wndSplitter.GetPane(0,0));

	// AsmView �� AsmInputBar ��A�g������
	((CAsmViewV2*)m_wndSplitter.GetPane(0,1))->RegisterAsmInputBar(&m_wndDialogBar_R);

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

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CBinViewV2), CSize(150, -1), pContext) ||
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
	CAsmInputBarDlg dlg;
	dlg.DoModal();
}
