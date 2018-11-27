// DlgLibManager.cpp : implementation file
//

#include "stdafx.h"
#include "Login.h"
#include "DlgLibManager.h"
#include "afxdialogex.h"
#include "CurlUtility.h"


// CDlgLibManager dialog

IMPLEMENT_DYNAMIC(CDlgLibManager, CDialogEx)

CDlgLibManager::CDlgLibManager(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgLibManager::~CDlgLibManager()
{
}

void CDlgLibManager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLibManager, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_IN, &CDlgLibManager::OnBnClickedButtonIn)
    ON_BN_CLICKED(IDC_BUTTON_OUT, &CDlgLibManager::OnBnClickedButtonOut)
    ON_BN_CLICKED(IDC_BUTTON1, &CDlgLibManager::OnBnClickedButton1)
    ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDlgLibManager message handlers


void CDlgLibManager::OnBnClickedButtonIn()
{
    // TODO: Add your control notification handler code here
}


void CDlgLibManager::OnBnClickedButtonOut()
{
    // TODO: Add your control notification handler code here
}


void CDlgLibManager::OnBnClickedButton1()
{
    CurrentDirectoryAutoChange tmp;
    CurlUtility::Get().RemoveCookies();
    this->OnOK();
    //this->GetParent()->ShowWindow(SW_SHOW);
}


void CDlgLibManager::OnClose()
{
    // TODO: Add your message handler code here and/or call default
    CDialogEx::OnClose();
    this->GetParent()->DestroyWindow();
}


void CDlgLibManager::OnOK()
{
    // TODO: Add your specialized code here and/or call the base class
    this->GetParent()->DestroyWindow();

    CDialogEx::OnOK();
}
