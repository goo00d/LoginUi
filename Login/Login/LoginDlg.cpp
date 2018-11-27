
// LoginDlg.cpp : ʵ���ļ�
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


// CLoginDlg �Ի���



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


// CLoginDlg ��Ϣ�������

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
    bool islogin = CurlUtility::Get().LoginWithCookie();
    if (islogin)
    {
        CLoginDlg::OnOK();
        CDlgLibManager dlg;
        dlg.DoModal();
    }
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLoginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CLoginDlg::OnBnClickedButtonLogin()
{
    UpdateData(TRUE);
    if (m_UserName.Trim().IsEmpty())
    {
        AfxMessageBox(L"�û�������Ϊ��");
        return;
    }
    if (m_Pass.IsEmpty())
    {
        AfxMessageBox(L"���벻��Ϊ��");
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
