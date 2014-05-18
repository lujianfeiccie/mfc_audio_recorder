// MyRecorderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyRecorder.h"
#include "MyRecorderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyRecorderDlg dialog

CMyRecorderDlg::CMyRecorderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyRecorderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyRecorderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	bRecording=FALSE;
	bPlaying=FALSE;
	bPaused=FALSE;
	bEnding=FALSE;
	m_pAudio = new CMyAudioCls;
}

void CMyRecorderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyRecorderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyRecorderDlg, CDialog)
	//{{AFX_MSG_MAP(CMyRecorderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(MM_WIM_OPEN,OnMM_WIM_OPEN)
	ON_MESSAGE(MM_WIM_DATA,OnMM_WIM_DATA)
	ON_MESSAGE(MM_WIM_CLOSE,OnMM_WIM_CLOSE)
	ON_MESSAGE(MM_WOM_OPEN,OnMM_WOM_OPEN)
	ON_MESSAGE(MM_WOM_DONE,OnMM_WOM_DONE)
	ON_MESSAGE(MM_WOM_CLOSE,OnMM_WOM_CLOSE)
	ON_BN_CLICKED(IDC_BUTTON_REC, OnStartRecord)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnSave)
	ON_BN_CLICKED(IDC_BUTTON_StopPly, OnStopPlay)
	ON_BN_CLICKED(IDC_BUTTON_StopRec, OnStopRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyRecorderDlg message handlers

BOOL CMyRecorderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CMyRecorderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyRecorderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyRecorderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyRecorderDlg::OnStartRecord() 
{
	// TODO: Add your control notification handler code here
	m_pAudio->StartRecording(this->m_hWnd);
	bRecording = TRUE;
	bEnding = FALSE;
}

void CMyRecorderDlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	if(!bPlaying)
	{
		return;
	}
	if(!bPaused)
	{
		m_pAudio->Pause();
		bPaused = TRUE;
	}
	else
	{
		m_pAudio->Restart();
		bPaused = FALSE;
	}

	return;
}

void CMyRecorderDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	if(bRecording)
	{
		m_pAudio->StopRecording();
	}

	m_pAudio->StartPlaying(this->m_hWnd, bPlaying);
	
	return;
}

void CMyRecorderDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	m_pAudio->SaveAudioToFile("test.wav");
}

void CMyRecorderDlg::OnStopPlay() 
{
	// TODO: Add your control notification handler code here
	if(!bPlaying)
	{
		return;
	}

	bEnding = TRUE;
	m_pAudio->StopPlaying();

	return;
}

void CMyRecorderDlg::OnStopRecord() 
{
	// TODO: Add your control notification handler code here
	if(!bRecording)
	{
		return;
	}
	m_pAudio->StopRecording();
	bRecording = FALSE;
	bEnding = TRUE;
}

LRESULT CMyRecorderDlg::OnMM_WIM_OPEN(UINT wParam, LONG lParam)
{
	bRecording = TRUE;
	m_pAudio->OnMM_WIM_OPEN();
	return 0;
}

LRESULT CMyRecorderDlg::OnMM_WIM_DATA(UINT wParam, LONG lParam)
{
	m_pAudio->OnMM_WIM_DATA((PWAVEHDR)lParam, bEnding);
	return 0;
}

LRESULT CMyRecorderDlg::OnMM_WIM_CLOSE(UINT wParam, LONG lParam)
{
	if(m_pAudio->GetDataLength()==0)
	{
		return 0;
	}

	m_pAudio->OnMM_WIM_CLOSE();

	bRecording = FALSE;
	return 0;
}

LRESULT CMyRecorderDlg::OnMM_WOM_OPEN(UINT wParam, LONG lParam)
{
	m_pAudio->OnMM_WOM_OPEN();
	bPlaying = TRUE;
	bEnding = FALSE;
	return 0;
}

LRESULT CMyRecorderDlg::OnMM_WOM_DONE(UINT wParam, LONG lParam)
{
	m_pAudio->OnMM_WOM_DONE();

	bPaused = FALSE;
	bPlaying = FALSE;
	return 0;
}

LRESULT CMyRecorderDlg::OnMM_WOM_CLOSE(UINT wParam, LONG lParam)
{
	m_pAudio->OnMM_WOM_CLOSE();

	bPaused = FALSE;
	bPlaying = FALSE;
	return 0;
}