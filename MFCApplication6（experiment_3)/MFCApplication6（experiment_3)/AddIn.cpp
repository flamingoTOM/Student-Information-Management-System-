// AddIn.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication6（experiment_3).h"
#include "afxdialogex.h"
#include "AddIn.h"
#include "MFCApplication6（experiment_3)Dlg.h"


// AddIn 对话框

student::student(CMFCApplication6experiment3Dlg* dlg)
{
	Dlg1 = dlg;
}

void student::set()
{
	for (int b = 0; b < 8; b++)
	{
		Dlg1->list1.SetItemText(Dlg1->list1.GetItemCount() - 1, b, n[b]);	
		//添加每行中的每个元素
		//从子窗口读出的东西，传到父窗口控件上
	}
}


IMPLEMENT_DYNAMIC(AddIn, CDialogEx)

AddIn::AddIn(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

AddIn::~AddIn()
{
}

void AddIn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, a_Name);
	DDX_Control(pDX, IDC_EDIT3, a_ID);
	DDX_Control(pDX, IDC_EDIT4, a_Major);
	DDX_Control(pDX, IDC_EDIT5, a_Elc);
	DDX_Control(pDX, IDC_EDIT6, a_Prob);
	DDX_Control(pDX, IDC_EDIT7, a_Cpp);
}


BEGIN_MESSAGE_MAP(AddIn, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AddIn::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &AddIn::OnEnChangeEdit4)
END_MESSAGE_MAP()


// AddIn 消息处理程序


void AddIn::OnBnClickedButton1() {
	student stu(Dlg);
	a_Name.GetWindowTextW(stu.n[0]);
	a_ID.GetWindowTextW(stu.n[1]);
	a_Major.GetWindowTextW(stu.n[2]);
	a_Elc.GetWindowTextW(stu.n[3]);
	a_Prob.GetWindowTextW(stu.n[4]);
	a_Cpp.GetWindowTextW(stu.n[5]);

	for (int g = 0; g < 6; g++) {
		if (stu.n[g].IsEmpty()) {
			MessageBox(L"请输入完整信息！", L"Error!");
			return;
		}
	}

	for (int i = 0; i < Dlg->list1.GetItemCount(); i++)
	{
		if (Dlg->list1.GetItemText(i, 1) == stu.n[1])
		{
			CString str("学号为");
			str += stu.n[1]; str += "的学生信息已录入！";
			MessageBox(str, L"提示!");
			AddIn::OnOK();
			return;
		}
	}
	Dlg->list1.InsertItem(Dlg->list1.GetItemCount(), L"");
	// 从子窗口获取内容传到父类控件上
	double x = _ttof(stu.n[3]) + _ttof(stu.n[4]) + _ttof(stu.n[5]);
	double y = x / 3;
	stu.n[6].Format(L"%f", x); stu.n[7].Format(L"%f", y);
	stu.set();
	MessageBox(L"录入成功", L"提示!");
	Dlg->save = false;
	AddIn::OnOK();
}

BOOL AddIn::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Dlg = (CMFCApplication6experiment3Dlg*)AfxGetMainWnd();	
	//换取主窗口指针,不加会冲突
	return TRUE;
}
BOOL AddIn::PreTranslateMessage(MSG* pMsg)

{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:     // 按回车表示确定
			OnBnClickedButton1();
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}













void AddIn::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
