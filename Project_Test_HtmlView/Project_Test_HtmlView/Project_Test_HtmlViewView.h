
// Project_Test_HtmlViewView.h : CProject_Test_HtmlViewView 클래스의 인터페이스
//

#pragma once


class CProject_Test_HtmlViewView : public CHtmlView
{
protected: // serialization에서만 만들어집니다.
	CProject_Test_HtmlViewView();
	DECLARE_DYNCREATE(CProject_Test_HtmlViewView)

// 특성입니다.
public:
	CProject_Test_HtmlViewDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CProject_Test_HtmlViewView();
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
};

#ifndef _DEBUG  // Project_Test_HtmlViewView.cpp의 디버그 버전
inline CProject_Test_HtmlViewDoc* CProject_Test_HtmlViewView::GetDocument() const
   { return reinterpret_cast<CProject_Test_HtmlViewDoc*>(m_pDocument); }
#endif

