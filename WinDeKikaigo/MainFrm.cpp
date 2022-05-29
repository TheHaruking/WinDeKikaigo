// MainFrm.cpp : CMainFrame �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "WinDeKikaigo.h"

#include "MainFrm.h"
#include "LeftView.h" // ForTest
#include "RightView.h" // ForTest

#include "BinView.h"
#include "BinViewV2.h"
#include "ValueView.h"
#include "AsmView.h"
#include "AsmViewV2.h"

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
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, OnUpdateViewStyles)
	ON_COMMAND_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, OnViewStyle)

	// �e�X�g
	ON_COMMAND(ID_SPLIT_LEFT, OnSplitLeft)

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
}

CMainFrame::~CMainFrame()
{
}

// ������ Window �͂��̉��� OnCreateClient �ōs��.
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
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

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

// �������E�C���h�E�̍쐬 (splitter) �͂����ōs�� ��
BOOL CMainFrame::OnCreateClient(
	LPCREATESTRUCT /*lpcs*/, // ���g�p
	CCreateContext* pContext)
{
#if 1
	// �e�����E�B���h�E (m_wndSplitter) ���쐬���܂�
	if (!m_wndSplitter.CreateStatic(this, 1, 2)) // �cx��
		return FALSE;

	if (!m_wndSplitter.CreateView(
			0, 0, RUNTIME_CLASS(CLeftView),
			CSize(100, 100),
			pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}

	// �q�����E�B���h�E (m_wndSplitter1) ���쐬���܂�
	if (!m_wndSplitter1.CreateStatic(
//			&m_wndSplitter, 3, 1, // X �� 1�s
			&m_wndSplitter, 2, 1, // X �� 1�s
			WS_CHILD | WS_VISIBLE | WS_BORDER,  // �X�^�C�� WS_BORDER ���K�v�ł��B
			m_wndSplitter.IdFromRowCol(0, 1)
			)) // �cx��
		return FALSE;

	if (!m_wndSplitter1.CreateView(
			0, 0, RUNTIME_CLASS(CBinViewV2),
			CSize(100, 100),
			pContext) ||
/*		!m_wndSplitter1.CreateView(
			1, 0, RUNTIME_CLASS(CValueView), 
			CSize(100, 100), 
			pContext) ||
*/		!m_wndSplitter1.CreateView(
			1, 0, RUNTIME_CLASS(CAsmViewV2), 
			CSize(100, 100), 
			pContext)
			)
	{
		m_wndSplitter1.DestroyWindow();
		return FALSE;
	}

	// �N�����t�H�[�J�X��ݒ�
	SetActiveView((CView*)m_wndSplitter1.GetPane(0,0));

	// ����.
	return TRUE;
#else
	// �e�����E�B���h�E (m_wndSplitter) ���쐬���܂�
	m_wndSplitter.Create(this, 1, 2, CSize(10, 10), pContext); // �cx��
	return TRUE;
#endif
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
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

CRightView* CMainFrame::GetRightPane()
{
	CWnd* pWnd = m_wndSplitter.GetPane(0, 1);
	CRightView* pView = DYNAMIC_DOWNCAST(CRightView, pWnd);
	return pView;
}

void CMainFrame::OnUpdateViewStyles(CCmdUI* pCmdUI)
{

	CRightView* pView = GetRightPane(); 


	if (pView == NULL)
		pCmdUI->Enable(FALSE);
	else
	{
		DWORD dwStyle = pView->GetStyle() & LVS_TYPEMASK;

		if (pCmdUI->m_nID == ID_VIEW_LINEUP)
		{
			if (dwStyle == LVS_ICON || dwStyle == LVS_SMALLICON)
				pCmdUI->Enable();
			else
				pCmdUI->Enable(FALSE);
		}
		else
		{
			pCmdUI->Enable();
			BOOL bChecked = FALSE;

			switch (pCmdUI->m_nID)
			{
			case ID_VIEW_DETAILS:
				bChecked = (dwStyle == LVS_REPORT);
				break;

			case ID_VIEW_SMALLICON:
				bChecked = (dwStyle == LVS_SMALLICON);
				break;

			case ID_VIEW_LARGEICON:
				bChecked = (dwStyle == LVS_ICON);
				break;

			case ID_VIEW_LIST:
				bChecked = (dwStyle == LVS_LIST);
				break;

			default:
				bChecked = FALSE;
				break;
			}

			pCmdUI->SetRadio(bChecked ? 1 : 0);
		}
	}
}


void CMainFrame::OnViewStyle(UINT nCommandID)
{
	CRightView* pView = GetRightPane();

	if (pView != NULL)
	{
		DWORD dwStyle = -1;

		switch (nCommandID)
		{
		case ID_VIEW_LINEUP:
			{
				CListCtrl& refListCtrl = pView->GetListCtrl();
				refListCtrl.Arrange(LVA_SNAPTOGRID);
			}
			break;

		case ID_VIEW_DETAILS:
			dwStyle = LVS_REPORT;
			break;

		case ID_VIEW_SMALLICON:
			dwStyle = LVS_SMALLICON;
			break;

		case ID_VIEW_LARGEICON:
			dwStyle = LVS_ICON;
			break;

		case ID_VIEW_LIST:
			dwStyle = LVS_LIST;
			break;
		}

		if (dwStyle != -1)
			pView->ModifyStyle(LVS_TYPEMASK, dwStyle);
	}
}

/*******************************************************************/
// ���y�C�����g�O������
void CMainFrame::OnSplitLeft()
{
//	MessageBox(L"Hello!");

	m_wndSplitter.SetColumnInfo(0, 100, 90);
	m_wndSplitter.RecalcLayout();

//	CWnd * pCurView = m_wndSplitter.GetPane(0, 0);
	
	//m_wndSplitter.DeleteView(0, 0);
/*
	if( !pCurView == NULL )
	{
		if(0)
		{
			pCurView->ShowWindow(SW_SHOW);
			m_wndSplitter.RecalcLayout();
		}
		else
		{
			pCurView->ShowWindow(SW_HIDE);
			m_wndSplitter.RecalcLayout();
		}
	}
	*/
}
