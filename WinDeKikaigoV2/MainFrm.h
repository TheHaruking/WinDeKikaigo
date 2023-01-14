// MainFrm.h : CMainFrame �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__C505CD39_5989_46DC_8B56_86DED598BDA6__INCLUDED_)
#define AFX_MAINFRM_H__C505CD39_5989_46DC_8B56_86DED598BDA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AsmInputBar.h"
#include "Emu6502.h"
#include "Emu6502OutputV2.h"
#include "VmWindow.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	void OnInputLda();
	virtual ~CMainFrame();
//	UINT MyThreadProc(LPVOID pParam);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // �R���g���[�� �o�[�p�����o
	CStatusBar   m_wndStatusBar;
	CToolBar     m_wndToolBar;
	// �ǉ�
	CDialogBar   m_wndDialogBar_L;
	CAsmInputBar m_wndDialogBar_R;
	CSplitterWnd m_wndSplitter;
	CVmWindow    m_wndVmWnd;

	CEmu6502 m_cpu;
	CEmu6502OutputV2 m_wndCpuOutput;

	CWinThread*	m_clock;
	BOOL		m_bRunning;
	DWORD		m_tick;

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAppLeftpane();
	afx_msg void OnAppRightpane();
	afx_msg void OnAppDebug();
	afx_msg void OnAppReset();
	afx_msg void OnAppVm();
	afx_msg void OnUpdateAppLeftpane(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAppRightpane(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAppVm(CCmdUI* pCmdUI);
	afx_msg void OnAppTest();
	afx_msg void OnAppRun();
	afx_msg void OnAppStop();
	afx_msg void OnUpdateAppRun(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MAINFRM_H__C505CD39_5989_46DC_8B56_86DED598BDA6__INCLUDED_)
