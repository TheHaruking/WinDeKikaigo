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
    for (int i = 0; i < 256; i++)
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
	m_hBitmap = (HBITMAP)::LoadImage(NULL, L"�摜\\spr_000.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	DWORD dwError = GetLastError();
	if (m_hBitmap == NULL) {
		CString buf;
		buf.Format(L"�摜���ǂݍ��߂܂���ł����B\nErrorCode : %d", dwError);
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
// CVmWindow ���b�Z�[�W �n���h��

void CVmWindow::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	::StretchDIBits(dc.m_hDC, 0, 0, WIDTH*m_dwScale, HEIGHT*m_dwScale,
		0, 0, WIDTH, HEIGHT,
		m_pBytes, m_pBmi, DIB_RGB_COLORS, SRCCOPY);

	::TransparentBlt(dc.m_hDC, /*�R�s�[��*/ 120, 80, 32, 32, /*�R�s�[��*/ m_hBitmapDC, 0, 0, m_hBitmapWidth, m_hBitmapHeight, RGB(255, 255, 255));
	// �`��p���b�Z�[�W�Ƃ��� CWnd::OnPaint() ���Ăяo���Ă͂����܂���
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
	
	// TODO: ���̈ʒu�ɌŗL�̍쐬�p�R�[�h��ǉ����Ă�������
	
	// �X�v���C�g�摜
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
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	if (m_hBitmapDC)
		::DeleteDC(m_hBitmapDC);
}
