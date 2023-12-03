
// MFCApplication6（experiment_3)Dlg.h: 头文件
//

#pragma once


// CMFCApplication6experiment3Dlg 对话框
class CMFCApplication6experiment3Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication6experiment3Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION6EXPERIMENT_3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl list1;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	bool save = false;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	CString Vmain_name;
	CString Vmain_ID;
	CString Vmain_major;
	CString Vmain_Elc;
	CString Vmain_Prob;
	CString Vmain_Cpp;
	afx_msg void OnEnChangeEdit10();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	CString Vmain_average;
	CString Vmain_summ;
	CButton m_check;
	CEdit Fname;
	CEdit Fnumber;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeEdit12();
	CEdit m_savepath;
	afx_msg void Onnewhold();
	afx_msg void OnClose();
};



