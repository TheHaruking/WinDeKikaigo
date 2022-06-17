#include <afxwin.h>
#include <math.h>

struct CMainFrame : public CFrameWnd {
	CMainFrame() {
		Create(NULL, L"実験作");
	}

	void OnPaint() {
		CPaintDC dc(this);
		dc.TextOut(10, 10, L"こんにちは！！");
	}

	void OnTimer() {
		RedrawWindow();
	}

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

struct CMyApp : public CWinApp {
	virtual BOOL InitInstance() {
		m_pMainWnd = new CMainFrame;
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}
};

CMyApp theApp;