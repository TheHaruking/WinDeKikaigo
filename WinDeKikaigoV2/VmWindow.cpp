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

/////////////////////////////////////////////////////////////////////////////
// CVmWindow

CVmWindow::CVmWindow()
{
}

CVmWindow::~CVmWindow()
{
}


BEGIN_MESSAGE_MAP(CVmWindow, CWnd)
	//{{AFX_MSG_MAP(CVmWindow)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVmWindow ���b�Z�[�W �n���h��

void CVmWindow::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
    RECT rc;
    GetClientRect(&rc);
#if 0
	// 32 bit Color �T���v��
    static const UINT32 pixeldata[] = {
		RGB(255,255,0),
		RGB(255,255,0),
		RGB(255,255,255),
		RGB(255,0,0)
	};

    BYTE bitmapinfo[FIELD_OFFSET(BITMAPINFO,bmiColors) + (3 * sizeof(DWORD))];
    BITMAPINFOHEADER &bih = *(BITMAPINFOHEADER*) bitmapinfo;

    bih.biSize = sizeof(BITMAPINFOHEADER);
    bih.biWidth = 2; bih.biHeight = 2;
    bih.biPlanes = 1; bih.biBitCount = 32;
    bih.biCompression = BI_BITFIELDS; bih.biSizeImage = 0;
    bih.biClrUsed = bih.biClrImportant = 0;

    DWORD *pMasks = (DWORD*) (&bitmapinfo[bih.biSize]);

    pMasks[0] = 0xff0000; // Red
    pMasks[1] = 0x00ff00; // Green
    pMasks[2] = 0x0000ff; // Blue

    StretchDIBits(dc.m_hDC, 0, 0, rc.right, rc.bottom, 
		0, 0, 2, 2, pixeldata, (BITMAPINFO*) &bih, DIB_RGB_COLORS, SRCCOPY);
#else
	// 
	BITMAPINFO* pBmi = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + sizeof(RGBQUAD) * 255);
    memset(pBmi, 0, sizeof(BITMAPINFO));

    BITMAPINFOHEADER &bmh = pBmi->bmiHeader;
    bmh.biSize = sizeof(BITMAPINFOHEADER);
    bmh.biBitCount = 8;
    bmh.biCompression = BI_RGB;
    bmh.biPlanes = 1;
    bmh.biWidth = 256;
    bmh.biHeight = -192; // TOPDOWN �`���ɂ���.

    RGBQUAD* palette = &pBmi->bmiColors[0];
    for (int i = 0; i < 256; ++i) 
    {
        RGBQUAD rgb = { 0 };
        rgb.rgbRed = i;
        rgb.rgbGreen = i;
        rgb.rgbBlue = i;
        palette[i] = rgb;
    }

	// 0x4000 : VRAM.
   	BYTE* pBytes = &(m_pDoc->m_data[0x4000]);

	StretchDIBits(dc.m_hDC, 0, 0, rc.right, rc.bottom,
		0, 0, rc.right, rc.bottom,
		pBytes, pBmi, DIB_PAL_COLORS, SRCCOPY);

    if (pBmi)
        free(pBmi);

#endif
	// �`��p���b�Z�[�W�Ƃ��� CWnd::OnPaint() ���Ăяo���Ă͂����܂���
}

void CVmWindow::SetDocument(CWinDeKikaigoV2Doc* pDoc)
{
	m_pDoc = pDoc;
}
