// MyRecorder.h : main header file for the MYRECORDER application
//

#if !defined(AFX_MYRECORDER_H__C2D79525_8DF4_11D1_9316_00E04CA820F9__INCLUDED_)
#define AFX_MYRECORDER_H__C2D79525_8DF4_11D1_9316_00E04CA820F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyRecorderApp:
// See MyRecorder.cpp for the implementation of this class
//

class CMyRecorderApp : public CWinApp
{
public:
	CMyRecorderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyRecorderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyRecorderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYRECORDER_H__C2D79525_8DF4_11D1_9316_00E04CA820F9__INCLUDED_)
