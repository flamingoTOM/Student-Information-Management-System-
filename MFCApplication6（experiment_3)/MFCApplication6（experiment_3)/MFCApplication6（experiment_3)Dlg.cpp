
// MFCApplication6（experiment_3)Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication6（experiment_3).h"
#include "MFCApplication6（experiment_3)Dlg.h"
#include "afxdialogex.h"
#include"Login_1.h"
#include"AddIn.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication6experiment3Dlg 对话框



CMFCApplication6experiment3Dlg::CMFCApplication6experiment3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION6EXPERIMENT_3_DIALOG, pParent)

	, Vmain_name(_T(""))
	, Vmain_ID(_T(""))
	, Vmain_major(_T(""))
	, Vmain_Elc(_T(""))
	, Vmain_Prob(_T(""))
	, Vmain_Cpp(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6experiment3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list1);
	/*
	DDX_Control(pDX, IDC_EDIT5, Vmain_name);
	DDX_Control(pDX, IDC_EDIT6, Vmain_ID);
	DDX_Control(pDX, IDC_EDIT4, Vmain_major);
	DDX_Control(pDX, IDC_EDIT8, Vmain_Elc);
	DDX_Control(pDX, IDC_EDIT9, Vmain_Prob);
	DDX_Control(pDX, IDC_EDIT10, Vmain_Cpp);
	*/

	DDX_Text(pDX, IDC_EDIT5, Vmain_name);
	DDX_Text(pDX, IDC_EDIT6, Vmain_ID);
	DDX_Text(pDX, IDC_EDIT4, Vmain_major);
	DDX_Text(pDX, IDC_EDIT8, Vmain_Elc);
	DDX_Text(pDX, IDC_EDIT9, Vmain_Prob);
	DDX_Text(pDX, IDC_EDIT10, Vmain_Cpp);
	DDX_Control(pDX, IDC_BUTTON3, m_check);

	DDX_Control(pDX, IDC_EDIT1, Fname);
	DDX_Control(pDX, IDC_EDIT2, Fnumber);
}

BEGIN_MESSAGE_MAP(CMFCApplication6experiment3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMFCApplication6experiment3Dlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication6experiment3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6experiment3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6experiment3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication6experiment3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication6experiment3Dlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT10, &CMFCApplication6experiment3Dlg::OnEnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication6experiment3Dlg::OnEnChangeEdit5)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFCApplication6experiment3Dlg::OnNMClickList1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication6experiment3Dlg::OnEnChangeEdit1)
	

END_MESSAGE_MAP()


// CMFCApplication6experiment3Dlg 消息处理程序

BOOL CMFCApplication6experiment3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	Login_1 Login;
	Login.DoModal();

	list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_FULLROWSELECT);
	//拓展list control的格式
	//绘制网格线，表头可以拖拽，可以选择整行或者整列
	CString col[8] = { _T("姓名"),_T("学号"),_T("专业"),_T("模电"),_T("概率论"),_T("C++"),_T("总分"),_T("平均分") };
	RECT r;	//rect对象用来存储一个矩形框的左上角坐标、宽度和高度。
	list1.GetClientRect(&r);	//显示矩形框调用函数要加取地址符号
	for (int i = 0; i < 8; i++)
	{
		list1.InsertColumn(i, col[i], LVCFMT_CENTER, (r.right - r.left) / 8);
	}
	list1.SetBkColor(RGB(199, 237, 233));	//设置列表框背景颜色
	list1.SetTextColor(RGB(18, 53, 85));	//字体颜色
	list1.SetTextBkColor(RGB(175, 215, 237));//文字背景色
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication6experiment3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication6experiment3Dlg::OnPaint()
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
HCURSOR CMFCApplication6experiment3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6experiment3Dlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



void CMFCApplication6experiment3Dlg::OnBnClickedButton3()         //查找
{
	CString fname, fnumber; int index = list1.GetItemCount();
	int q = 0;	//用来做flag

	for (int i = 0; i < index; i++)//初始化各行信息的选择状态，设置为未选择。
	{
		list1.SetItemState(i, 0, LVIS_SELECTED | LVIS_FOCUSED);
	}
	Fname.GetWindowTextW(fname); Fnumber.GetWindowTextW(fnumber);
	//获取需要搜索的姓名和学号，传入fname和fnumber。
	CString temp;
	//判断fname和fnumber是否为空，并做出对应操作。用int q的值判断是否找到符合信息的学生。
	if (fname != "" && fnumber != "")
	{
		for (int i = 0; i < index; i++)
		{
			temp = list1.GetItemText(i, 0);
			temp.TrimLeft();	//去掉左面空格//防止非定长函数对结果进行印象
			if (temp == fname && list1.GetItemText(i, 1) == fnumber)
			{
				list1.SetFocus();
				list1.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
				list1.EnsureVisible(i, true); q = 1;
				CString name, number, major, Elc, Prob, Cpp;
				name = list1.GetItemText(i, 0); number = list1.GetItemText(i, 1); major = list1.GetItemText(i, 2);
				Elc = list1.GetItemText(i, 3); Prob = list1.GetItemText(i, 4); Cpp = list1.GetItemText(i, 5);
				Vmain_name = name; Vmain_ID = number; Vmain_major = major;
				Vmain_Elc = Elc; Vmain_Prob = Prob; Vmain_Cpp = Cpp;
				UpdateData(false);
			}
		}
	}
	else if (fname != "" && fnumber == "")
	{
		for (int i = 0; i < index; i++)
		{
			temp = list1.GetItemText(i, 0);
			temp.TrimLeft();	//去掉左面空格
			if (temp == fname)
			{
				list1.SetFocus();//获得焦点
				list1.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
				//选中第一行，当鼠标点击列表光标悬浮在上面
				list1.EnsureVisible(i, true); q = 1;//确保可视化
				CString name, number, major, Elc, Prob, Cpp;
				name = list1.GetItemText(i, 0); number = list1.GetItemText(i, 1); major = list1.GetItemText(i, 2);
				Elc = list1.GetItemText(i, 3); Prob = list1.GetItemText(i, 4); Cpp = list1.GetItemText(i, 5);
				Vmain_name = name; Vmain_ID = number; Vmain_major = major;
				Vmain_Elc = Elc; Vmain_Prob = Prob; Vmain_Cpp = Cpp;
				UpdateData(false);
			}
		}
	}
	else if (fname == "" && fnumber != "")
	{
		for (int i = 0; i < index; i++)
		{
			if (list1.GetItemText(i, 1) == fnumber)
			{
				list1.SetFocus();
				list1.SetItemState(i, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
				list1.EnsureVisible(i, true); q = 1;
				CString name, number, major, Elc, Prob, Cpp;
				name = list1.GetItemText(i, 0); number = list1.GetItemText(i, 1); major = list1.GetItemText(i, 2);
				Elc = list1.GetItemText(i, 3); Prob = list1.GetItemText(i, 4); Cpp = list1.GetItemText(i, 5);
				Vmain_name = name; Vmain_ID = number; Vmain_major = major;
				Vmain_Elc = Elc; Vmain_Prob = Prob; Vmain_Cpp = Cpp;
				UpdateData(false);
			}
		}
	}
	else if (fname == "" && fnumber == "")
	{
		MessageBox(L"请输入查找信息！", L"输入错误");
		return;
	}
	if (q == 0)
		MessageBox(L"没有找到该学生！", L"输入错误或没有该学生!");
}


void CMFCApplication6experiment3Dlg::OnBnClickedButton1()
{
	AddIn a;
	a.DoModal();
}


void CMFCApplication6experiment3Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = list1.GetSelectedCount();
	POSITION pos = list1.GetFirstSelectedItemPosition();
	if (pos)
	{
		int p = 0;
		while (pos)
		{
			int k = list1.GetNextSelectedItem(pos);
			list1.DeleteItem(k - p); p++;
		}
		save = false;
	}
	else
		MessageBox(L"请选择需要删除的信息！", L"Error!");
}



void CMFCApplication6experiment3Dlg::OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult)	//显示
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int nIndex = list1.GetSelectionMark();	//选中行
	//获取索引指定内容
	CString name = list1.GetItemText(nIndex, 0);
	CString number = list1.GetItemText(nIndex, 1);
	CString major = list1.GetItemText(nIndex, 2);
	CString Elc = list1.GetItemText(nIndex, 3);
	CString Prob = list1.GetItemText(nIndex, 4);
	CString Cpp = list1.GetItemText(nIndex, 5);
	Vmain_name = name;	//把获得的内容传到编辑框
	Vmain_ID = number;
	Vmain_major = major;
	Vmain_Elc = Elc;
	Vmain_Prob = Prob;
	Vmain_Cpp = Cpp;
	UpdateData(FALSE);			//变量更新到编辑框
}





void CMFCApplication6experiment3Dlg::OnBnClickedButton4()//更改
{
	// TODO: 在此添加控件通知处理程序代码
	if (MessageBox(L"确定修改吗！", L"提示", MB_YESNO) == IDNO)	
		//消息弹出框，点击“否”则退出
		return;
	else//如果点击"是"则进行程序
	{
		UpdateData(TRUE);	//编辑框到变量
		int nIndex = list1.GetSelectionMark();//获取整行
		list1.SetItemText(nIndex, 0, Vmain_name);	//设置字符到编辑框
		list1.SetItemText(nIndex, 1, Vmain_ID);
		list1.SetItemText(nIndex, 2, Vmain_major);
		list1.SetItemText(nIndex, 3, Vmain_Elc);
		list1.SetItemText(nIndex, 4, Vmain_Prob);
		list1.SetItemText(nIndex, 5, Vmain_Cpp);
		float elc = _ttoi(Vmain_Elc);			//cstring转float
		float prob = _ttoi(Vmain_Prob);
		float cpp = _ttoi(Vmain_Cpp);
		float sum = elc + prob + cpp;			//用来计算
		Vmain_summ.Format(_T("%f"), sum);	//float转cstring
		list1.SetItemText(nIndex, 6, Vmain_summ);
		float aver = sum / 3.0;
		Vmain_average.Format(_T("%f"), aver);
		list1.SetItemText(nIndex, 7, Vmain_average);
	}
}






void CMFCApplication6experiment3Dlg::OnEnChangeEdit10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication6experiment3Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication6experiment3Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication6experiment3Dlg::OnBnClickedButton5()        //另存为
{

	// TODO: 在此添加控件通知处理程序代码



	CFile s(L"D://学生成绩记录.txt", CFile::modeCreate | CFile::modeReadWrite);
	//如果文件不存在，请创建一个新文件。 如果该文件已存在，它是被覆盖，并最初设置为长度为零。
	//以读写方式打开文件

	int index = list1.GetItemCount();
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CString a;
			if (j != 7)
				a = list1.GetItemText(i, j) + '\t';	//从控件获取信息
			if (j == 7 && i != index - 1)
			{
				a = list1.GetItemText(i, j) + '\t';	//回退一格
				a += "\r\n";	//回车+换行
			}
			if (j == 7 && i == index - 1)
				a = list1.GetItemText(i, j) + '\t';
			s.Write(a, a.GetLength());	//统计cstring类的长度
		}
	}
	save = true;
	MessageBox(L"已保存!",L"提示");

}

void CMFCApplication6experiment3Dlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!save)
	{
		if (MessageBox(L"信息还未保存！是否退出？", L"提示!", MB_YESNO) == IDNO)
		{
			return;
		}
	}
	CDialogEx::OnClose();
}




void CMFCApplication6experiment3Dlg::OnEnChangeEdit12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
