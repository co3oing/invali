#pragma once

#ifdef _WIN32_WCE
#error "Windows CE������ CHtmlView�� �������� �ʽ��ϴ�."
#endif 

// test_Html HTML ���Դϴ�.

class test_Html : public CHtmlView
{
	DECLARE_DYNCREATE(test_Html)

protected:
	test_Html();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~test_Html();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};


