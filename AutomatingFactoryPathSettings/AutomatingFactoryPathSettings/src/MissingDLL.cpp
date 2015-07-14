// MissingDLL.cpp : implementation file
//

#include "stdafx.h"
#include "AutomatingFactoryPathSettings.h"
#include "MissingDLL.h"
#include "afxdialogex.h"


// MissingDLL dialog

IMPLEMENT_DYNAMIC(MissingDLL, CDialogEx)

MissingDLL::MissingDLL(CWnd* pParent /*=NULL*/)
	: CDialogEx(MissingDLL::IDD, pParent)
{

}

MissingDLL::~MissingDLL()
{
}

void MissingDLL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MissingDLL, CDialogEx)
END_MESSAGE_MAP()


// MissingDLL message handlers
