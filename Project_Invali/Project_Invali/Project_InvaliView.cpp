
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

// CProject_InvaliView 생성/소멸

CProject_InvaliView::CProject_InvaliView()
	: CFormView(IDD_PROJECT_INVALI_FORM)
	, m_ClickedRootNode(false)
	, m_strSelectedNode(_T(""))
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
	DDX_Control(pDX, IDC_EXPLORER, m_webControl);
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
	UpdateData(TRUE);
	m_hRoot = m_treeControl.InsertItem(_T("U-Saint SSU Notice"), 0, TVI_ROOT);
	m_treeControl.InsertItem(_T("전체"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("학사"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("장학"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("국제 교류"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("외국인 유학생"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("모집,채용"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("교내 행사"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("교외 행사"), m_hRoot, TVI_LAST);
	m_treeControl.InsertItem(_T("봉사"), m_hRoot, TVI_LAST);
	m_treeControl.Expand(m_hRoot, TVE_EXPAND);


	m_hRoot1 = m_treeControl.InsertItem(_T("SSU Fun-System"), 0, TVI_ROOT);
	m_treeControl.InsertItem(_T("창의"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("융합"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("공동체"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("의사소통"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("리더십"), m_hRoot1, TVI_LAST);
	m_treeControl.InsertItem(_T("글로벌"), m_hRoot1, TVI_LAST);
	m_treeControl.Expand(m_hRoot1, TVE_EXPAND);

	m_hRoot2 = m_treeControl.InsertItem(_T("SoftWare Notice"), 0, TVI_ROOT);
	m_treeControl.InsertItem(_T("학부 공지사항"), m_hRoot2, TVI_LAST);
	m_treeControl.InsertItem(_T("취업 정보"), m_hRoot2, TVI_LAST);
	m_treeControl.Expand(m_hRoot2, TVE_EXPAND);

	m_treeControl.InsertItem(_T("한국 장학재단"), 0, TVI_ROOT);

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
	m_treeControl.ScreenToClient(&p);// 마우스좌표를 트리좌표로 변환하고,  // HitTest 함수로 트리아이템 받아. 

	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strItem = m_treeControl.GetItemText(pNMTreeView->itemNew.hItem);
	STR_SWITCH(strItem)
		CASE(_T("전체"))
		// code 
		CComVariant var(_T("http://ssu.ac.kr/web/kor/plaza_d_01"));
		m_webControl.Navigate2(&var, NULL, NULL, NULL, NULL);
		BREAK
		CASE(_T("장학"))
		// code
		BREAK
		CASE(_T("국제 교류"))
		// code
		BREAK
		CASE(_T("외국인 유학생"))
		// code
		BREAK
		CASE(_T("모집,채용"))
		// code
		BREAK
		CASE(_T("교내 행사"))
		// code
		BREAK
		CASE(_T("교외 행사"))
		// code
		BREAK
		CASE(_T("봉사"))
		// code
		BREAK
		CASE(_T("창의"))
		// code
		BREAK
		CASE(_T("융합"))
		// code
		BREAK
		CASE(_T("공동체"))
		// code
		BREAK
		CASE(_T("의사소통"))
		// code
		BREAK
		CASE(_T("리더십"))
		// code
		BREAK
		CASE(_T("글로벌"))
		// code
		BREAK
		CASE(_T("학부 공지사항"))
		// code
		CComVariant var(_T("https://sw.ssu.ac.kr/"));
		m_webControl.Navigate2(&var, NULL, NULL, NULL, NULL);
		BREAK
		CASE(_T("취업 정보"))
		// code
		BREAK
		CASE(_T("한국 장학재단"))
		// code
		BREAK
		END_SWITCH;

	*pResult = 0;
}
