
// LetterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Letter.h"
#include "LetterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLetterDlg dialog



CLetterDlg::CLetterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LETTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLetterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_edit);
}

BEGIN_MESSAGE_MAP(CLetterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_RADIO1, &CLetterDlg::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_BUTTON1, &CLetterDlg::OnClickedButton1)
ON_BN_CLICKED(IDC_RADIO1, &CLetterDlg::OnClickedRadio1)
ON_BN_CLICKED(IDC_RADIO3, &CLetterDlg::OnBnClickedRadio3)
ON_BN_CLICKED(IDC_RADIO2, &CLetterDlg::OnBnClickedRadio2)
ON_BN_CLICKED(IDC_CHECK1, &CLetterDlg::OnClickedCheck1)
END_MESSAGE_MAP()


// CLetterDlg message handlers

BOOL CLetterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLetterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLetterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLetterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLetterDlg::OnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CEdit* pe1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pe2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CString str;
	pe1->GetWindowText(str);
	pe2->SetWindowText(str);
}


void CLetterDlg::OnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	CEdit* pe2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pe2->ModifyStyle(ES_UPPERCASE, ES_LOWERCASE);
}


void CLetterDlg::OnRadio2()
{
	// TODO: Add your command handler code here
	
}


void CLetterDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	CEdit* pe2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pe2->ModifyStyle(ES_UPPERCASE|ES_LOWERCASE, NULL);
	pe2->SetRedraw();
}


void CLetterDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	CEdit* pe2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pe2->ModifyStyle(ES_LOWERCASE, ES_UPPERCASE);
}


void CLetterDlg::OnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	if (IsDlgButtonChecked(IDC_CHECK1))
		m_edit.m_clrText = RGB(255, 0, 0);
	else
		m_edit.m_clrText = RGB(0, 0, 0);
	RedrawWindow();
}
