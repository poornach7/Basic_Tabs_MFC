
// AutomatingFactoryPathSettingsDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "FactoryPath.h"
#include "MissingDLL.h"



// CAutomatingFactoryPathSettingsDlg dialog
class CAutomatingFactoryPathSettingsDlg : public CDialogEx
{
// Construction
public:
	CAutomatingFactoryPathSettingsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_AUTOMATINGFACTORYPATHSETTINGS_DIALOG };

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
	CTabCtrl tabFactoryPath;
	FactoryPath loadFactoryPath;
	MissingDLL loadMissingDLL;
	void ShowWindowNumber(int number);

private:
	CRect m_rSettingsRect;
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
