#pragma once
#include "afxdialogex.h"


// Login_1 对话框

class Login_1 : public CDialogEx
{
	DECLARE_DYNAMIC(Login_1)

public:
	Login_1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Login_1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_strName;
	CString m_password;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
