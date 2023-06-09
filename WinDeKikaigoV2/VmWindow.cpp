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

/////////////////////////////////////////////////////////////////////////////
// CVmWindow

CVmWindow::CVmWindow()
{
	int i;

	// BITMAPINFO + パレット(256色) のメモリを確保.
	m_pBmi = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + sizeof(RGBQUAD) * 255); // BITMAPINFO 自体が 1 つのカラーパレットを持っている.
    memset(m_pBmi, 0, sizeof(BITMAPINFO));

	// BITMAPINFO
    BITMAPINFOHEADER &bmh = m_pBmi->bmiHeader;
    bmh.biSize = sizeof(BITMAPINFOHEADER);
    bmh.biBitCount = 8; // 256 色.
    bmh.biCompression = BI_RGB;
    bmh.biPlanes = 1;
    bmh.biWidth = VM_WIDTH;
    bmh.biHeight = -VM_HEIGHT; // TOPDOWN 形式にする.
	bmh.biClrUsed = 0;

	// 拡大率
	m_dwScale = 2;

	// Bitmap Object
	memset(m_vbmpList, 0, sizeof(m_vbmpList));
	for (i = 0; i < VM_BMPNUM; i++) {
		LoadBitmapFileToArrayObj(m_vbmpList, i);
	}
}

CVmWindow::~CVmWindow()
{
	int i;

	// Bitmap オブジェクト破棄
	for (i = 0; i < VM_BMPNUM; i++) {
		if (m_vbmpList[i].hBitmap)
			::DeleteObject(m_vbmpList[i].hBitmap);
	}

	// VRAM 用メモリ破棄
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
	const DWORD S = m_dwScale; // 拡大率
	int i;
	
	// Palette 更新
	memcpy(&(m_pBmi->bmiColors[0]), m_pPalette, 4*256); // BGR 版.
	// RGB 版. (Blue と Red を入れ替える)
/*	for (i = 0; i < 256; i++) {
		RGBQUAD buf = ((RGBQUAD*)m_pPalette)[i];
		BYTE byte1  = buf.rgbBlue;
		buf.rgbBlue = buf.rgbRed;
		buf.rgbRed  = byte1;
		m_pBmi->bmiColors[i] = buf;
	}
*/
	// VRAM 描画
	::StretchDIBits(dc.m_hDC, 0, 0, VM_WIDTH*S, VM_HEIGHT*S,
		0, 0, VM_WIDTH, VM_HEIGHT,
		m_pBytes, m_pBmi, DIB_RGB_COLORS, SRCCOPY);

	// スプライト画像 描画
	LONG id;
	VMBITMAP vbmp;
	for (i = 0; i < VM_SPRNUM; i++) {
		id = m_pSprList[i].id;
		vbmp = m_vbmpList[id];
		::TransparentBlt(dc.m_hDC,
			/*コピー先 座標  */ m_pSprList[i].x*S, m_pSprList[i].y*S,
			/*コピー先 サイズ*/ vbmp.hBitmapWidth*S, vbmp.hBitmapHeight*S,
			/*コピー元 BMPDC */ vbmp.hBitmapDC,
			/*コピー元 原点  */ 0, 0,
			/*コピー元 サイズ*/ vbmp.hBitmapWidth, vbmp.hBitmapHeight,
			/*コピー元 透過色*/ RGB(255, 255, 255));
	}

	// 描画用メッセージとして CWnd::OnPaint() を呼び出してはいけません
}

void CVmWindow::SetDocument(CWinDeKikaigoV2Doc* pDoc)
{
	m_pDoc = pDoc;

	// 0x2000 : VRAM.
   	m_pBytes	= m_pDoc->GetDataAddr(0x2000);
	m_pSprList	= (SPRITEMEM*)m_pDoc->GetDataAddr(0xE000);
	m_pPalette  = (PALETTEMEM*)m_pDoc->GetDataAddr(0xE400);
}

BOOL CVmWindow::CreateEx(CWnd* pParentWnd)
{
	DWORD dwStyle = WS_SYSMENU | WS_CAPTION | WS_POPUP | WS_VISIBLE;
	CRect rect(60, 60, 60 + VM_WIDTH*m_dwScale, 60 + VM_HEIGHT*m_dwScale); // 画面サイズは 256 x 192

	// m_VmWnd を作成 (Popup Window は Create"Ex" でないといけない。)
	AdjustWindowRectEx(&rect, dwStyle, FALSE, 0);
	return CWnd::CreateEx(0, 
	AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, ::LoadCursor(AfxGetResourceHandle(), NULL)),
		L"仮想マシン", dwStyle, 
		rect, NULL, NULL, NULL );
}

int CVmWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// スプライト画像 DC 初期化
	CDC* pDC = this->GetDC();
	VMBITMAP* pvbmp;

	for (int i = 0; i < VM_BMPNUM; i++) {
		pvbmp = &(m_vbmpList[i]);
		if (pvbmp->hBitmap != NULL) {
			pvbmp->hBitmapDC = ::CreateCompatibleDC(pDC->m_hDC);
			::SelectObject(pvbmp->hBitmapDC, pvbmp->hBitmap);
		}
	}

	this->ReleaseDC(pDC);

	return 0;
}

void CVmWindow::OnDestroy() 
{
	CWnd::OnDestroy();
	
	// スプライト画像 DC 削除
	VMBITMAP* pvbmp;
	for (int i = 0; i < VM_BMPNUM; i++) {
		pvbmp = &(m_vbmpList[i]);
		if (pvbmp->hBitmapDC)
			::DeleteDC(pvbmp->hBitmapDC);
	}
}

void CVmWindow::LoadBitmapFileToArrayObj(VMBITMAP* pvbmpArray, LONG n)
{
	VMBITMAP* pvbmp = &(pvbmpArray[n]);

	// ファイルから画像読み込み
	CString buf;
	buf.Format(L"画像\\spr_%03d.bmp", n);
	pvbmp->hBitmap = (HBITMAP)::LoadImage(NULL, buf, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	// エラー判定
	DWORD dwError = GetLastError();

	// dwError のみで判定しないこと (例: 32bit BMP を LoadImage した場合 ... dwError:0, m_hBitmap:NULL に。)
	if (dwError != 0 || pvbmp->hBitmap == NULL) {
		switch (dwError) {
		case 0: // dwError:0, m_hBitmap:NULL のケース
			buf.Format(L"画像が読み込めませんでした。\n画像 : %d 番\n理由 : 対応していないフォーマット (32bit ビットマップ等) です。", n);
			break;
		case 2: // ファイルがないケース
			// 何もせずリターン。
			return;
		default: // その他のエラー
			buf.Format(L"画像が読み込めませんでした。^n画像 : %d 番", n);
			break;
		}

		MessageBox(buf);
		return;
	}

	// 幅/高さ だけ保存する
	BITMAP bitmap;
	::GetObject(pvbmp->hBitmap, sizeof(bitmap), (LPVOID)&bitmap);
	pvbmp->hBitmapWidth = bitmap.bmWidth;
	pvbmp->hBitmapHeight = bitmap.bmHeight;
}
