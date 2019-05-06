// CColors.cpp : implementation file
//

#include "pch.h"
#include "Letter.h"
#include "CColors.h"


// CColors

IMPLEMENT_DYNAMIC(CColors, CEdit)

CColors::CColors()
{
	m_clrText = RGB(0, 0, 0);
	m_clrBkgnd = RGB(255, 255, 255);
	m_brBkgnd.CreateSolidBrush(m_clrBkgnd);

}

CColors::~CColors()
{
}


BEGIN_MESSAGE_MAP(CColors, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CColors message handlers




HBRUSH CColors::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  Change any attributes of the DC here
	pDC->SetTextColor(m_clrText);
	pDC->SetBkColor(m_clrBkgnd);
	// TODO:  Return a non-NULL brush if the parent's handler should not be called
	return m_brBkgnd;
	//return NULL;
}
