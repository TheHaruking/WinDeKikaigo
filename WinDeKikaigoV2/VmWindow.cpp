// VmWindow.cpp : �C���v�������e�[�V���� �t�@�C��
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
	int i;

	// BITMAPINFO + �p���b�g(256�F) �̃��������m��.
	m_pBmi = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + sizeof(RGBQUAD) * 255); // BITMAPINFO ���̂� 1 �̃J���[�p���b�g�������Ă���.
    memset(m_pBmi, 0, sizeof(BITMAPINFO));

	// BITMAPINFO
    BITMAPINFOHEADER &bmh = m_pBmi->bmiHeader;
    bmh.biSize = sizeof(BITMAPINFOHEADER);
    bmh.biBitCount = 8; // 256 �F.
    bmh.biCompression = BI_RGB;
    bmh.biPlanes = 1;
    bmh.biWidth = WIDTH;
    bmh.biHeight = -HEIGHT; // TOPDOWN �`���ɂ���.
	bmh.biClrUsed = 0;

	// �p���b�g���̐ݒ� (��).
	RGBQUAD* palette = &(m_pBmi->bmiColors[0]);
    for (i = 0; i < 256; i++)
    {
        RGBQUAD rgb = { 0 };
        rgb.rgbRed = i;
        rgb.rgbGreen = 0;
        rgb.rgbBlue = 0;
        palette[i] = rgb;
    }

	// �g�嗦
	m_dwScale = 2;

	// Bitmap Object
	memset(m_vbmpList, 0, sizeof(m_vbmpList));
	for (i = 0; i < 16; i++) {
		LoadBitmapFileToArrayObj(m_vbmpList, i);
	}
}

CVmWindow::~CVmWindow()
{
	int i;

	// Bitmap �I�u�W�F�N�g�j��
	for (i = 0; i < 16; i++) {
		if (m_vbmpList[i].hBitmap)
			::DeleteObject(m_vbmpList[i].hBitmap);
	}

	// VRAM �p�������j��
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
// CVmWindow ���b�Z�[�W �n���h��

void CVmWindow::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	const DWORD S = m_dwScale; // �g�嗦
	
	// VRAM �`��
	::StretchDIBits(dc.m_hDC, 0, 0, WIDTH*S, HEIGHT*S,
		0, 0, WIDTH, HEIGHT,
		m_pBytes, m_pBmi, DIB_RGB_COLORS, SRCCOPY);

	// �X�v���C�g�摜 �`��
	for (int i = 0; i < 16; i++) {
		::TransparentBlt(dc.m_hDC,
			/*�R�s�[�� ���W  */ m_pSprList[i].x*S, m_pSprList[i].y*S,
			/*�R�s�[�� �T�C�Y*/ m_vbmpList[i].hBitmapWidth*S, m_vbmpList[i].hBitmapHeight*S,
			/*�R�s�[�� BMPDC */ m_vbmpList[m_pSprList[i].id].hBitmapDC,
			/*�R�s�[�� ���_  */ 0, 0,
			/*�R�s�[�� �T�C�Y*/ m_vbmpList[i].hBitmapWidth, m_vbmpList[i].hBitmapHeight,
			/*�R�s�[�� ���ߐF*/ RGB(255, 255, 255));
	}

	// �`��p���b�Z�[�W�Ƃ��� CWnd::OnPaint() ���Ăяo���Ă͂����܂���
}

void CVmWindow::SetDocument(CWinDeKikaigoV2Doc* pDoc)
{
	m_pDoc = pDoc;

	// 0x2000 : VRAM.
   	m_pBytes	= m_pDoc->GetDataAddr(0x2000);
	m_pSprList	= (SPRITEMEM*)m_pDoc->GetDataAddr(0xE000);
}

BOOL CVmWindow::CreateEx(CWnd* pParentWnd)
{
	DWORD dwStyle = WS_SYSMENU | WS_CAPTION | WS_POPUP | WS_VISIBLE;
	CRect rect(60, 60, 60 + WIDTH*m_dwScale, 60 + HEIGHT*m_dwScale); // ��ʃT�C�Y�� 256 x 192

	// m_VmWnd ���쐬 (Popup Window �� Create"Ex" �łȂ��Ƃ����Ȃ��B)
	AdjustWindowRectEx(&rect, dwStyle, FALSE, 0);
	return CWnd::CreateEx(0, 
	AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, ::LoadCursor(AfxGetResourceHandle(), NULL)),
		L"���z�}�V��", dwStyle, 
		rect, pParentWnd, NULL, NULL );
}

int CVmWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// �X�v���C�g�摜 DC ������
	CDC* pDC = this->GetDC();
	VMBITMAP* pvbmp;

	for (int i = 0; i < 16; i++) {
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
	
	// �X�v���C�g�摜 DC �폜
	VMBITMAP* pvbmp;
	for (int i = 0; i < 16; i++) {
		pvbmp = &(m_vbmpList[i]);
		if (pvbmp->hBitmapDC)
			::DeleteDC(pvbmp->hBitmapDC);
	}
}

void CVmWindow::LoadBitmapFileToArrayObj(VMBITMAP* pvbmpArray, LONG n)
{
	VMBITMAP* pvbmp = &(pvbmpArray[n]);

	// �t�@�C������摜�ǂݍ���
	CString buf;
	buf.Format(L"�摜\\spr_%03d.bmp", n);
	pvbmp->hBitmap = (HBITMAP)::LoadImage(NULL, buf, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	// �G���[����
	DWORD dwError = GetLastError();

	// dwError �݂̂Ŕ��肵�Ȃ����� (��: 32bit BMP �� LoadImage �����ꍇ ... dwError:0, m_hBitmap:NULL �ɁB)
	if (dwError != 0 || pvbmp->hBitmap == NULL) {
		switch (dwError) {
		case 0: // dwError:0, m_hBitmap:NULL �̃P�[�X
			buf.Format(L"�摜���ǂݍ��߂܂���ł����B\n�摜 : %d ��\n���R : �Ή����Ă��Ȃ��t�H�[�}�b�g (32bit �r�b�g�}�b�v��) �ł��B", n);
			break;
		case 2: // �t�@�C�����Ȃ��P�[�X
			// �����������^�[���B
			return;
		default: // ���̑��̃G���[
			buf.Format(L"�摜���ǂݍ��߂܂���ł����B^n�摜 : %d ��", n);
			break;
		}

		MessageBox(buf);
		return;
	}

	// ��/���� �����ۑ�����
	BITMAP bitmap;
	::GetObject(pvbmp->hBitmap, sizeof(bitmap), (LPVOID)&bitmap);
	pvbmp->hBitmapWidth = bitmap.bmWidth;
	pvbmp->hBitmapHeight = bitmap.bmHeight;
}
