
// Project_Invali.h : Project_Invali ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CProject_InvaliApp:
// �� Ŭ������ ������ ���ؼ��� Project_Invali.cpp�� �����Ͻʽÿ�.
//

class CProject_InvaliApp : public CWinAppEx
{
public:
	CProject_InvaliApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProject_InvaliApp theApp;
