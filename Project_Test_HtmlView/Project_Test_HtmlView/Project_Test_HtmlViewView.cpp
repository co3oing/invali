
// Project_Test_HtmlViewView.cpp : CProject_Test_HtmlViewView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Project_Test_HtmlView.h"
#endif

#include "Project_Test_HtmlViewDoc.h"
#include "Project_Test_HtmlViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProject_Test_HtmlViewView

IMPLEMENT_DYNCREATE(CProject_Test_HtmlViewView, CHtmlView)

BEGIN_MESSAGE_MAP(CProject_Test_HtmlViewView, CHtmlView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CProject_Test_HtmlViewView ����/�Ҹ�

CProject_Test_HtmlViewView::CProject_Test_HtmlViewView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CProject_Test_HtmlViewView::~CProject_Test_HtmlViewView()
{
}

BOOL CProject_Test_HtmlViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CHtmlView::PreCreateWindow(cs);
}

void CProject_Test_HtmlViewView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://sw.ssu.ac.kr"),NULL,NULL);
	SetSilent(1);
}


// CProject_Test_HtmlViewView �μ�


void CProject_Test_HtmlViewView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}


void CProject_Test_HtmlViewView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProject_Test_HtmlViewView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProject_Test_HtmlViewView ����

#ifdef _DEBUG
void CProject_Test_HtmlViewView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CProject_Test_HtmlViewView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CProject_Test_HtmlViewDoc* CProject_Test_HtmlViewView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject_Test_HtmlViewDoc)));
	return (CProject_Test_HtmlViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CProject_Test_HtmlViewView �޽��� ó����
