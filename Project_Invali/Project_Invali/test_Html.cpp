// test_Html.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Project_Invali.h"
#include "test_Html.h"


// test_Html

IMPLEMENT_DYNCREATE(test_Html, CHtmlView)

test_Html::test_Html()
{

}

test_Html::~test_Html()
{
}

void test_Html::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(test_Html, CHtmlView)
END_MESSAGE_MAP()


// test_Html 진단입니다.

#ifdef _DEBUG
void test_Html::AssertValid() const
{
	CHtmlView::AssertValid();
}

void test_Html::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// test_Html 메시지 처리기입니다.
