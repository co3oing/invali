
// Project_InvaliView.h : CProject_InvaliView Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "CWebBrowser2.h"


class CProject_InvaliView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CProject_InvaliView();
	DECLARE_DYNCREATE(CProject_InvaliView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PROJECT_INVALI_FORM };
#endif

// Ư���Դϴ�.
public:
	CProject_InvaliDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CProject_InvaliView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // Project_InvaliView.cpp�� ����� ����
inline CProject_InvaliDoc* CProject_InvaliView::GetDocument() const
   { return reinterpret_cast<CProject_InvaliDoc*>(m_pDocument); }
#endif

