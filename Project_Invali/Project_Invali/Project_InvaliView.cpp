
// Project_InvaliView.cpp : CProject_InvaliView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Project_Invali.h"
#endif

#include "Project_InvaliDoc.h"
#include "Project_InvaliView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProject_InvaliView

IMPLEMENT_DYNCREATE(CProject_InvaliView, CFormView)

BEGIN_MESSAGE_MAP(CProject_InvaliView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY(NM_CLICK, IDC_TREE_CONTROL, &CProject_InvaliView::OnClickTreeControl)
END_MESSAGE_MAP()

// CProject_InvaliView 생성/소멸

CProject_InvaliView::CProject_InvaliView()
	: CFormView(IDD_PROJECT_INVALI_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CProject_InvaliView::~CProject_InvaliView()
{
}

void CProject_InvaliView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_treeControl);
}

BOOL CProject_InvaliView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CProject_InvaliView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CProject_InvaliView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProject_InvaliView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProject_InvaliView 진단

#ifdef _DEBUG
void CProject_InvaliView::AssertValid() const
{
	CFormView::AssertValid();
}

void CProject_InvaliView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CProject_InvaliDoc* CProject_InvaliView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject_InvaliDoc)));
	return (CProject_InvaliDoc*)m_pDocument;
}
#endif //_DEBUG


void CProject_InvaliView::OnClickTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPoint p;
	GetCursorPos(&p);
	UINT flag;
	m_treeControl.ScreenToClient(&p);// 마우스좌표를 트리좌표로 변환하고, 
	HTREEITEM hItem_dc = m_treeControl.HitTest(p, &flag); // HitTest 함수로 트리아이템 받아. 

														  // 시험용 문자 출력.
	AfxMessageBox(m_treeControl.GetItemText(hItem_dc));

	*pResult = 0;
}
