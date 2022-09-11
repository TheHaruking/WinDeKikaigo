// VmWindow.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "windekikaigov2.h"
#include "VmWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const LONG CVmWindow::WIDTH = 256;
const LONG CVmWindow::HEIGHT = 192;
/////////////////////////////////////////////////////////////////////////////
// CVmWindow

CVmWindow::CVmWindow()
{
	// BITMAPINFO + パレット(256色) のメモリを確保.
	m_pBmi = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + sizeof(RGBQUAD) * 255); // BITMAPINFO 自体が 1 つのカラーパレットを持っている.
    memset(m_pBmi, 0, sizeof(BITMAPINFO));

	// BITMAPINFO
    BITMAPINFOHEADER &bmh = m_pBmi->bmiHeader;
    bmh.biSize = sizeof(BITMAPINFOHEADER);
    bmh.biBitCount = 8; // 256 色.
    bmh.biCompression = BI_RGB;
    bmh.biPlanes = 1;
    bmh.biWidth = WIDTH;
    bmh.biHeight = -HEIGHT; // TOPDOWN 形式にする.
	bmh.biClrUsed = 0;

	// パレット部の設定 (仮).
	RGBQUAD* palette = &(m_pBmi->bmiColors[0]);
    for (int i = 0; i < 256; i++)
    {
        RGBQUAD rgb = { 0 };
        rgb.rgbRed = i;
        rgb.rgbGreen = 0;
        rgb.rgbBlue = 0;
        palette[i] = rgb;
    }

	// 拡大率
	m_dwScale = 2;

	// Bitmap Object
	m_hBitmap = (HBITMAP)::LoadImage(NULL, L"画像\\spr_000.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	DWORD dwError = GetLastError();
	if (m_hBitmap == NULL) {
		CString buf;
		buf.Format(L"画像が読み込めませんでした。\nErrorCode : %d", dwError);
		MessageBox(buf);
	}

	BITMAP bitmap;
	::GetObject(m_hBitmap, sizeof(bitmap), (LPVOID)&bitmap);
	m_hBitmapWidth = bitmap.bmWidth;
	m_hBitmapHeight = bitmap.bmHeight;
}

CVmWindow::~CVmWindow()
{
	if (m_hBitmap)
		::DeleteObject(m_hBitmap);
	if (m_pBmi)
		free(m_pBmi);
}

BEGIN_MESSAGE_MAP(CVmWindow, CWnd)
	//{{AFX_MSG_MAP(CVmWindow)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVmWindow メッセージ ハンドラ

void CVmWindow::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	::StretchDIBits(dc.m_hDC, 0, 0, WIDTH*m_dwScale, HEIGHT*m_dwScale,
		0, 0, WIDTH, HEIGHT,
		m_pBytes, m_pBmi, DIB_RGB_COLORS, SRCCOPY);

	::TransparentBlt(dc.m_hDC, /*コピー先*/ 120, 80, 32, 32, /*コピー元*/ m_hBitmapDC, 0, 0, m_hBitmapWidth, m_hBitmapHeight, RGB(255, 255, 255));
	// 描画用メッセージとして CWnd::OnPaint() を呼び出してはいけません
}

void CVmWindow::SetDocument(CWinDeKikaigoV2Doc* pDoc)
{
	m_pDoc = pDoc;

	// 0x3000 : VRAM.
   	m_pBytes = &(m_pDoc->m_data[0x3000]);
}

BOOL CVmWindow::CreateEx(CWnd* pParentWnd)
{
	DWORD dwStyle = WS_SYSMENU | WS_CAPTION | WS_POPUP | WS_VISIBLE;
	CRect rect(60, 60, 60 + WIDTH*m_dwScale, 60 + HEIGHT*m_dwScale); // 画面サイズは 256 x 192

	// m_VmWnd を作成 (Popup Window は Create"Ex" でないといけない。)
	AdjustWindowRectEx(&rect, dwStyle, FALSE, 0);
	return CWnd::CreateEx(0, 
	AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, ::LoadCursor(AfxGetResourceHandle(), NULL)),
		L"仮想マシン", dwStyle, 
		rect, pParentWnd, NULL, NULL );
}

int CVmWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	
	// スプライト画像
	if (m_hBitmap != NULL) {
		CDC* pDC = this->GetDC();
		m_hBitmapDC = ::CreateCompatibleDC(pDC->m_hDC);
		::SelectObject(m_hBitmapDC, m_hBitmap);
		this->ReleaseDC(pDC);
	}

	return 0;
}


void CVmWindow::OnDestroy() 
{
	CWnd::OnDestroy();
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	if (m_hBitmapDC)
		::DeleteDC(m_hBitmapDC);
}
