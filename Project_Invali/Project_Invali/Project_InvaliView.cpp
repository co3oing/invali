
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

#define STR_SWITCH(x)  {CString switchval(x); if (false) {;} // Semicolon is necessary
#define CASE(y)  else if (switchval == y) {;
#define DEFAULT else if (true) {;
#define BREAK  }
#define END_SWITCH }

// CProject_InvaliView

IMPLEMENT_DYNCREATE(CProject_InvaliView, CFormView)

BEGIN_MESSAGE_MAP(CProject_InvaliView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY(NM_CLICK, IDC_TREE_CONTROL, &CProject_InvaliView::OnClickTreeControl)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CProject_InvaliView::OnSelchangedTreeControl)
END_MESSAGE_MAP()

// CProject_InvaliView ����/�Ҹ�

CProject_InvaliView::CProject_InvaliView()
	: CFormView(IDD_PROJECT_INVALI_FORM)
	, m_ClickedRootNode(false)
	, m_strSelectedNode(_T(""))
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
	DDX_Control(pDX, IDC_EXPLORER, m_webControl);
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
	UpdateData(TRUE);
	m_hRoot = m_treeControl.InsertItem(_T("U-Saint SSU Notice"), 0, TVI_ROOT);
	m_treeControl.InsertItem(_T("��ü"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("�л�"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("����"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("���� ����"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("�ܱ��� ���л�"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("����,ä��"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("���� ���"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("���� ���"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("����"), m_hRoot, TVI_LAST);
	m_treeControl.Expand(m_hRoot, TVE_EXPAND);


	m_hRoot1 = m_treeControl.InsertItem(_T("SSU Fun-System"), 0, TVI_ROOT);
	m_treeControl.InsertItem(_T("â��"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("����"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("����ü"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("�ǻ����"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("������"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("�۷ι�"), m_hRoot1, TVI_LAST);
	m_treeControl.Expand(m_hRoot1, TVE_EXPAND);

	m_hRoot2 = m_treeControl.InsertItem(_T("SoftWare Notice"), 0, TVI_ROOT);
	m_treeControl.InsertItem(_T("�к� ��������"), m_hRoot2, TVI_LAST);
	m_treeControl.InsertItem(_T("��� ����"), m_hRoot2, TVI_LAST);
	m_treeControl.Expand(m_hRoot2, TVE_EXPAND);

	m_treeControl.InsertItem(_T("�ѱ� �������"), 0, TVI_ROOT);

	UpdateData(FALSE);

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
	m_treeControl.ScreenToClient(&p);// ���콺��ǥ�� Ʈ����ǥ�� ��ȯ�ϰ�,  // HitTest �Լ��� Ʈ�������� �޾�. 

	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	m_strSelectedNode = m_treeControl.GetItemText(m_hSelectedNode);
	if (m_strSelectedNode == "U-Saint SSU Notice")
	{
		m_ClickedRootNode = TRUE;
		m_hSelectedNode = m_hRoot;
		if (m_strSelectedNode == "SoftWare Notice")
		{
			m_ClickedRootNode = TRUE;
			m_hSelectedNode = m_hRoot1;

			if (m_strSelectedNode == "SSU Fun-System")
			{
				m_ClickedRootNode = TRUE;
				m_hSelectedNode = m_hRoot2;
			}
		}
	}

	if (m_ClickedRootNode == TRUE)
	{
		m_treeControl.Expand(m_hSelectedNode, TVE_TOGGLE);
	}
	UpdateData(FALSE);

	*pResult = 0;
}





void CProject_InvaliView::OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strItem = m_treeControl.GetItemText(pNMTreeView->itemNew.hItem);
	STR_SWITCH(strItem)
		CASE(_T("��ü"))
		// code 
		CComVariant var(_T("http://ssu.ac.kr/web/kor/plaza_d_01"));
		m_webControl.Navigate2(&var, NULL, NULL, NULL, NULL);
		BREAK
		CASE(_T("����"))
		// code
		BREAK
		CASE(_T("���� ����"))
		// code
		BREAK
		CASE(_T("�ܱ��� ���л�"))
		// code
		BREAK
		CASE(_T("����,ä��"))
		// code
		BREAK
		CASE(_T("���� ���"))
		// code
		BREAK
		CASE(_T("���� ���"))
		// code
		BREAK
		CASE(_T("����"))
		// code
		BREAK
		CASE(_T("â��"))
		// code
		BREAK
		CASE(_T("����"))
		// code
		BREAK
		CASE(_T("����ü"))
		// code
		BREAK
		CASE(_T("�ǻ����"))
		// code
		BREAK
		CASE(_T("������"))
		// code
		BREAK
		CASE(_T("�۷ι�"))
		// code
		BREAK
		CASE(_T("�к� ��������"))
		// code
		CComVariant var(_T("https://sw.ssu.ac.kr/"));
		m_webControl.Navigate2(&var, NULL, NULL, NULL, NULL);
		BREAK
		CASE(_T("��� ����"))
		// code
		BREAK
		CASE(_T("�ѱ� �������"))
		// code
		BREAK
		END_SWITCH;

	*pResult = 0;
}
