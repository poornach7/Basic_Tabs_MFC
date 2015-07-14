#pragma once


// FactoryPath dialog

class FactoryPath : public CDialogEx
{
	DECLARE_DYNAMIC(FactoryPath)

public:
	FactoryPath(CWnd* pParent = NULL);   // standard constructor
	virtual ~FactoryPath();

// Dialog Data
	enum { IDD = IDD_TAB_FACTORY_PATH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
