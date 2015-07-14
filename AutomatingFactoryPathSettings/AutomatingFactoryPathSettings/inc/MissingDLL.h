#pragma once


// MissingDLL dialog

class MissingDLL : public CDialogEx
{
	DECLARE_DYNAMIC(MissingDLL)

public:
	MissingDLL(CWnd* pParent = NULL);   // standard constructor
	virtual ~MissingDLL();

// Dialog Data
	enum { IDD = IDD_TAB_MISSING_DLL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
