#include "CColors.h"

// LetterDlg.h : header file
//

#pragma once


// CLetterDlg dialog
class CLetterDlg : public CDialogEx
{
// Construction
public:
	CLetterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LETTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedRadio1();
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnClickedCheck1();
	CColors m_edit;
};
