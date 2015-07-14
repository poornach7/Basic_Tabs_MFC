
// AutomatingFactoryPathSettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AutomatingFactoryPathSettings.h"
#include "AutomatingFactoryPathSettingsDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAutomatingFactoryPathSettingsDlg dialog



CAutomatingFactoryPathSettingsDlg::CAutomatingFactoryPathSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAutomatingFactoryPathSettingsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutomatingFactoryPathSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, tabFactoryPath);
}

BEGIN_MESSAGE_MAP(CAutomatingFactoryPathSettingsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CAutomatingFactoryPathSettingsDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CAutomatingFactoryPathSettingsDlg message handlers

BOOL CAutomatingFactoryPathSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	CRect tabRect;

	tabFactoryPath.GetWindowRect(tabRect);

	// Set the size and location of the child windows based on the tab control
	m_rSettingsRect.left = 10;
	m_rSettingsRect.top = 30;
	m_rSettingsRect.right = tabRect.Width() - 6;
	m_rSettingsRect.bottom = tabRect.Height() - 25;

	// Create the child windows for the main window class

	loadFactoryPath.Create(IDD_TAB_FACTORY_PATH, this);
	loadMissingDLL.Create(IDD_TAB_MISSING_DLL, this);

	// This is redundant with the default value, considering what OnShowWindow does
	ShowWindowNumber(0);

	// Set the titles for each tab
	TCITEM tabItem;
	tabItem.mask = TCIF_TEXT;

	tabItem.pszText = _T("  FactoryPath   ");
	tabFactoryPath.InsertItem(0, &tabItem);

	tabItem.pszText = _T("  MissingDLL   ");
	tabFactoryPath.InsertItem(1, &tabItem);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAutomatingFactoryPathSettingsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutomatingFactoryPathSettingsDlg::OnPaint()
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
HCURSOR CAutomatingFactoryPathSettingsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAutomatingFactoryPathSettingsDlg::ShowWindowNumber(int number)
{
	// This example uses two windows
	int windowCount = 2;

	// Validate the parameter
	if ((number >= 0) && (number < windowCount))
	{
		// Create and assign pointers to each window
		CDialog *m_dPointer[2];

		m_dPointer[0] = &loadFactoryPath;
		m_dPointer[1] = &loadMissingDLL;


		// Hide every window except for the chosen one
		for (int count = 0; count < windowCount; count++)
		{
			if (count != number)
			{
				m_dPointer[count]->ShowWindow(SW_HIDE);
			}
			else if (count == number)
			{
				// Show the chosen window and set it's location
				m_dPointer[count]->SetWindowPos(&wndTop, m_rSettingsRect.left,
					m_rSettingsRect.top, m_rSettingsRect.right,
					m_rSettingsRect.bottom, SWP_SHOWWINDOW);

				tabFactoryPath.SetCurSel(count);
			}
		}
	}
}





void CAutomatingFactoryPathSettingsDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowWindowNumber(tabFactoryPath.GetCurFocus());

	pNMHDR = NULL;
	pResult = NULL;
}
