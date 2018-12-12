
// Project_Test_HtmlViewView.cpp : CProject_Test_HtmlViewView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CProject_Test_HtmlViewView 생성/소멸

CProject_Test_HtmlViewView::CProject_Test_HtmlViewView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CProject_Test_HtmlViewView::~CProject_Test_HtmlViewView()
{
}

BOOL CProject_Test_HtmlViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CHtmlView::PreCreateWindow(cs);
}

void CProject_Test_HtmlViewView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://sw.ssu.ac.kr"),NULL,NULL);
	SetSilent(1);
}


// CProject_Test_HtmlViewView 인쇄


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


// CProject_Test_HtmlViewView 진단

#ifdef _DEBUG
void CProject_Test_HtmlViewView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CProject_Test_HtmlViewView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CProject_Test_HtmlViewDoc* CProject_Test_HtmlViewView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject_Test_HtmlViewDoc)));
	return (CProject_Test_HtmlViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CProject_Test_HtmlViewView 메시지 처리기
