// test_Html.cpp : ���� �����Դϴ�.
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


// test_Html �����Դϴ�.

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


// test_Html �޽��� ó�����Դϴ�.
