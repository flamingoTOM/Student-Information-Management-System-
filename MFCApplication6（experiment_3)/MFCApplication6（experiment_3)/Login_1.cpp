// Login_1.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6（experiment_3).h"
#include "afxdialogex.h"
#include "Login_1.h"


// Login_1 对话框

IMPLEMENT_DYNAMIC(Login_1, CDialogEx)

Login_1::Login_1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
	, m_password(_T(""))
{

}

Login_1::~Login_1()
{
}

void Login_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}


BEGIN_MESSAGE_MAP(Login_1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Login_1::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Login_1::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &Login_1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Login_1 消息处理程序

void Login_1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	GetDlgItemText(IDC_EDIT1, m_strName);
	GetDlgItemText(IDC_EDIT2, m_password);
	CString username = L"0122204"; // 用户名
	CString password = L"liu041310"; // 的密码
	if (m_strName == L"" || m_password == L"")
	{
		MessageBox(L"用户名 或 密码 不能为空！", L"注意");
		GetDlgItem(IDC_EDIT1)->SetFocus();
	}
	else if (m_strName.Compare(username) != 0 || m_password.Compare(password) != 0)
	{
		MessageBox(L"用户名 或 密码 有误，请重新输入！", L"注意");
		SetDlgItemText(IDC_EDIT1, L"");
		SetDlgItemText(IDC_EDIT2, L"");
		GetDlgItem(IDC_EDIT1)->SetFocus();
	}
	else if (m_strName.Compare(username) == 0 || m_password.Compare(password) == 0)
	{
		CDialogEx::OnOK();
	}
}



void Login_1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void Login_1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
