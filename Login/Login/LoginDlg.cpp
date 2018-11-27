
// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Login.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "CurlUtility.h"
#include "DlgLibManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLoginDlg 对话框



CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
    , m_AutoLogin(FALSE)
    , m_RememberPass(FALSE)
    , m_UserName(_T(""))
    , m_Pass(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Check(pDX, IDC_CHECK_AUTOLOGIN, m_AutoLogin);
    DDX_Check(pDX, IDC_CHECK_PASS, m_RememberPass);
    DDX_Text(pDX, IDC_EDIT_USERNAME, m_UserName);
    DDX_Text(pDX, IDC_EDIT_PASS, m_Pass);
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
    bool islogin = CurlUtility::Get().LoginWithCookie();
    if (islogin)
    {
        CLoginDlg::OnOK();
        CDlgLibManager dlg;
        dlg.DoModal();
    }
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLoginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CLoginDlg::OnBnClickedButtonLogin()
{
    UpdateData(TRUE);
    if (m_UserName.Trim().IsEmpty())
    {
        AfxMessageBox(L"用户名不能为空");
        return;
    }
    if (m_Pass.IsEmpty())
    {
        AfxMessageBox(L"密码不能为空");
        return;
    }
    bool islogin = CurlUtility::Get().Login(m_UserName,m_Pass);
    if (islogin)
    {
        this->ShowWindow(SW_HIDE);
        CDlgLibManager dlg;
        dlg.SetParent(this);
        dlg.DoModal();
    }
}
