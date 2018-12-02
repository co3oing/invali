
// Project_InvaliView.cpp : CProject_InvaliView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CProject_InvaliView ����/�Ҹ�

CProject_InvaliView::CProject_InvaliView()
	: CFormView(IDD_PROJECT_INVALI_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

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


// CProject_InvaliView ����

#ifdef _DEBUG
void CProject_InvaliView::AssertValid() const
{
	CFormView::AssertValid();
}

void CProject_InvaliView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CProject_InvaliDoc* CProject_InvaliView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject_InvaliDoc)));
	return (CProject_InvaliDoc*)m_pDocument;
}
#endif //_DEBUG


void CProject_InvaliView::OnClickTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CPoint p;
	GetCursorPos(&p);
	UINT flag;
	m_treeControl.ScreenToClient(&p);// ���콺��ǥ�� Ʈ����ǥ�� ��ȯ�ϰ�, 
	HTREEITEM hItem_dc = m_treeControl.HitTest(p, &flag); // HitTest �Լ��� Ʈ�������� �޾�. 

														  // ����� ���� ���.
	AfxMessageBox(m_treeControl.GetItemText(hItem_dc));

	*pResult = 0;
}
