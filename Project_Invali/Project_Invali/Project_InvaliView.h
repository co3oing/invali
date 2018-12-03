
// Project_InvaliView.h : CProject_InvaliView 클래스의 인터페이스
//

#pragma once
#include "afxcmn.h"
#include "CWebBrowser2.h"


class CProject_InvaliView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CProject_InvaliView();
	DECLARE_DYNCREATE(CProject_InvaliView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PROJECT_INVALI_FORM };
#endif

// 특성입니다.
public:
	CProject_InvaliDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CProject_InvaliView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
//	HTREEITEM m_treeControl;
	CTreeCtrl m_treeControl;
	HTREEITEM m_hSelectedNode;
	HTREEITEM m_hRoot;
	HTREEITEM m_hRoot1;
	HTREEITEM m_hRoot2;
	bool m_ClickedRootNode;
	CString m_strSelectedNode;
	afx_msg void OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	CWebBrowser2 m_webControl;
	DECLARE_EVENTSINK_MAP()
//	void DocumentCompleteExplorer(LPDISPATCH pDisp, VARIANT* URL);
};

#ifndef _DEBUG  // Project_InvaliView.cpp의 디버그 버전
inline CProject_InvaliDoc* CProject_InvaliView::GetDocument() const
   { return reinterpret_cast<CProject_InvaliDoc*>(m_pDocument); }
#endif

