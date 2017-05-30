
// CServerMFCMain.cpp : implementation file
//

#include "stdafx.h"
#include "ServerMFC.h"
#include "CServerMFCMain.h"
#include "afxdialogex.h"
#include <controllers/AllController.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CServerMFCMain dialog


CServerMFCMain::CServerMFCMain(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SERVERMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerMFCMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CServerMFCMain, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SERVER_START, &CServerMFCMain::OnBnClickedServerStart)
END_MESSAGE_MAP()


// CServerMFCMain message handlers

BOOL CServerMFCMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerMFCMain::OnPaint()
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
HCURSOR CServerMFCMain::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServerMFCMain::OnBnClickedServerStart()
{
	
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle


	// TODO Check port

}
