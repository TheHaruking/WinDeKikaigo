#if !defined(AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_)
#define AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VmWindow.h : �w�b�_�[ �t�@�C��
//

#include "WinDeKikaigoV2Doc.h"

/////////////////////////////////////////////////////////////////////////////
// CVmWindow �E�B���h�E

class CVmWindow : public CWnd
{
// �R���X�g���N�V����
public:
	CVmWindow();

// �A�g���r���[�g
public:

// �I�y���[�V����
private:
	static const LONG WIDTH;
	static const LONG HEIGHT;

	CWinDeKikaigoV2Doc* m_pDoc;
	BYTE* m_pBytes;
	BITMAPINFO* m_pBmi;
	DWORD m_dwScale;

	struct VMBITMAP {
		HBITMAP hBitmap;
		HDC hBitmapDC;
		LONG hBitmapWidth;
		LONG hBitmapHeight;
		LONG x;
		LONG y;
	} m_vbmpList[16];

	struct SPRITEMEM {
		BYTE id;
		BYTE reserved;
		BYTE x;
		BYTE y;
	} *m_pSprList;

private:

	void LoadBitmapFileToArrayObj(VMBITMAP* vmBitmap, LONG n);

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CVmWindow)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	BOOL CreateEx(CWnd* pParentWnd);
	void SetDocument(CWinDeKikaigoV2Doc* pDoc);
	virtual ~CVmWindow();
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CVmWindow)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_VMWINDOW_H__F54058E7_DDEA_4290_A032_C2F42C76548F__INCLUDED_)
