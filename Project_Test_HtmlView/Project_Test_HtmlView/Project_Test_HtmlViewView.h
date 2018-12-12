
// Project_Test_HtmlViewView.h : CProject_Test_HtmlViewView Ŭ������ �������̽�
//

#pragma once


class CProject_Test_HtmlViewView : public CHtmlView
{
protected: // serialization������ ��������ϴ�.
	CProject_Test_HtmlViewView();
	DECLARE_DYNCREATE(CProject_Test_HtmlViewView)

// Ư���Դϴ�.
public:
	CProject_Test_HtmlViewDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CProject_Test_HtmlViewView();
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
};

#ifndef _DEBUG  // Project_Test_HtmlViewView.cpp�� ����� ����
inline CProject_Test_HtmlViewDoc* CProject_Test_HtmlViewView::GetDocument() const
   { return reinterpret_cast<CProject_Test_HtmlViewDoc*>(m_pDocument); }
#endif

