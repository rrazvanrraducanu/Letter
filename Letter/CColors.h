#pragma once


// CColors

class CColors : public CEdit
{
	DECLARE_DYNAMIC(CColors)

public:
	CColors();
	virtual ~CColors();

protected:
	DECLARE_MESSAGE_MAP()
public:
	COLORREF m_clrText;
	COLORREF m_clrBkgnd;
	CBrush m_brBkgnd;
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


