// HtmlView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Project_Invali.h"
#include "HtmlView.h"


// HtmlView

IMPLEMENT_DYNCREATE(HtmlView, CHtmlView)

HtmlView::HtmlView()
{

}

HtmlView::~HtmlView()
{
}

void HtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(HtmlView, CHtmlView)
END_MESSAGE_MAP()


// HtmlView 진단입니다.

#ifdef _DEBUG
void HtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void HtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// HtmlView 메시지 처리기입니다.
