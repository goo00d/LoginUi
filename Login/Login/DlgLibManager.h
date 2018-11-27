#pragma once


// CDlgLibManager dialog

class CDlgLibManager : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLibManager)

public:
	CDlgLibManager(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgLibManager();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonIn();
    afx_msg void OnBnClickedButtonOut();
    afx_msg void OnBnClickedButton1();
    afx_msg void OnClose();
    virtual void OnOK();
};
