#pragma once

#ifdef _WIN32_WCE
#error "Windows CE������ CHtmlView�� �������� �ʽ��ϴ�."
#endif 

// HtmlView HTML ���Դϴ�.

class HtmlView : public CHtmlView
{
	DECLARE_DYNCREATE(HtmlView)

protected:
	HtmlView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~HtmlView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};


