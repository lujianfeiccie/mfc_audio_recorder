; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyAudioCls
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyRecorder.h"

ClassCount=4
Class1=CMyRecorderApp
Class2=CMyRecorderDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyAudioCls
Resource3=IDD_MYRECORDER_DIALOG

[CLS:CMyRecorderApp]
Type=0
HeaderFile=MyRecorder.h
ImplementationFile=MyRecorder.cpp
Filter=N

[CLS:CMyRecorderDlg]
Type=0
HeaderFile=MyRecorderDlg.h
ImplementationFile=MyRecorderDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_REC

[CLS:CAboutDlg]
Type=0
HeaderFile=MyRecorderDlg.h
ImplementationFile=MyRecorderDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYRECORDER_DIALOG]
Type=1
Class=CMyRecorderDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_REC,button,1342242816
Control4=IDC_BUTTON_PLAY,button,1342242816
Control5=IDC_BUTTON_StopRec,button,1342242816
Control6=IDC_BUTTON_PAUSE,button,1342242816
Control7=IDC_BUTTON_StopPly,button,1342242816
Control8=IDC_BUTTON_SAVE,button,1342242816

[CLS:CMyAudioCls]
Type=0
HeaderFile=MyAudioCls.h
ImplementationFile=MyAudioCls.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CMyAudioCls

