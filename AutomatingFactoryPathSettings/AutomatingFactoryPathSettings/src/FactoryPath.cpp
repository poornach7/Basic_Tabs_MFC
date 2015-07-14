// FactoryPath.cpp : implementation file
//

#include "stdafx.h"
#include "AutomatingFactoryPathSettings.h"
#include "FactoryPath.h"
#include "afxdialogex.h"


// FactoryPath dialog

IMPLEMENT_DYNAMIC(FactoryPath, CDialogEx)

FactoryPath::FactoryPath(CWnd* pParent /*=NULL*/)
	: CDialogEx(FactoryPath::IDD, pParent)
{

}

FactoryPath::~FactoryPath()
{
}

void FactoryPath::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FactoryPath, CDialogEx)
END_MESSAGE_MAP()


// FactoryPath message handlers
