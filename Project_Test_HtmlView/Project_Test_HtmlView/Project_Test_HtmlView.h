
// Project_Test_HtmlView.h : Project_Test_HtmlView ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CProject_Test_HtmlViewApp:
// �� Ŭ������ ������ ���ؼ��� Project_Test_HtmlView.cpp�� �����Ͻʽÿ�.
//

class CProject_Test_HtmlViewApp : public CWinAppEx
{
public:
	CProject_Test_HtmlViewApp();


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

extern CProject_Test_HtmlViewApp theApp;
