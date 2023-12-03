
#pragma once
#include "afxdialogex.h"



// AddIn 对话框



class CMFCApplication6experiment3Dlg; // 前置声明，告知编译器有这个类





//定义student类。
//CString n[8]用于保存学生各项信息。
//CMFCApplication6Dlg*Dlg1，保存父级对话框指针。
//student(CMFCApplication6Dlg*dlg)构造函数，将父级对话框指针传入。
//void set();成员函数。将n[8]分别插入到父级对话框的CListCtrl控件。
class student
{
public:
	CString n[8];
	CMFCApplication6experiment3Dlg* Dlg1 = NULL;	//创建父级对话框指针
	student(CMFCApplication6experiment3Dlg* dlg);
	void set();
};

class AddIn : public CDialogEx
{
	DECLARE_DYNAMIC(AddIn)

public:
	AddIn(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddIn();
	//AddIn(CMFCApplication6experiment3Dlg*dlg);
	CMFCApplication6experiment3Dlg* Dlg = NULL;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit a_Name;
	CEdit a_ID;
	CEdit a_Major;
	CEdit a_Elc;
	CEdit a_Prob;
	CEdit a_Cpp;
	afx_msg void OnEnChangeEdit4();
	BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

};


