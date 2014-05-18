// MyRecorderDlg.h : header file
//

#if !defined(AFX_MYRECORDERDLG_H__C2D79527_8DF4_11D1_9316_00E04CA820F9__INCLUDED_)
#define AFX_MYRECORDERDLG_H__C2D79527_8DF4_11D1_9316_00E04CA820F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyAudioCls.h"
/////////////////////////////////////////////////////////////////////////////
// CMyRecorderDlg dialog

class CMyRecorderDlg : public CDialog
{
// Construction
public:
	BOOL bPlaying;
	BOOL bRecording;
	BOOL bEnding;
	BOOL bPaused;
	CMyRecorderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyRecorderDlg)
	enum { IDD = IDD_MYRECORDER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyRecorderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMyAudioCls*	m_pAudio;
	// Generated message map functions
	//{{AFX_MSG(CMyRecorderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartRecord();
	afx_msg void OnPause();
	afx_msg void OnPlay();
	afx_msg void OnSave();
	afx_msg void OnStopPlay();
	afx_msg void OnStopRecord();
	afx_msg LRESULT OnMM_WIM_OPEN(UINT wParam, LONG lParam);
	afx_msg LRESULT OnMM_WIM_DATA(UINT wParam, LONG lParam);
	afx_msg LRESULT OnMM_WIM_CLOSE(UINT wParam, LONG lParam);
	afx_msg LRESULT OnMM_WOM_OPEN(UINT wParam, LONG lParam);
	afx_msg LRESULT OnMM_WOM_DONE(UINT wParam, LONG lParam);
	afx_msg LRESULT OnMM_WOM_CLOSE(UINT wParam, LONG lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYRECORDERDLG_H__C2D79527_8DF4_11D1_9316_00E04CA820F9__INCLUDED_)
