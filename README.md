# Student-Information-Management-System-

If you want to know the whole process of the project or how to use the specific controls, please consult the pdf of the Github documentation
1.	建立基于对话框的图形界面
（1）界面展示
 ![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/87d4dfc1-7f66-4ac5-bb3d-75921ba6a1e0)

（2）对“List Control”控件进行初始化
 

2.	密码登录功能
（1）	在主程序中初始化弹出登陆界面
 

（2）	在Login_1.cpp中对“登录”（Button1）控件进行定义
 
（3）	实现效果截图
 

3. 录入学生信息功能
3.1 录入界面展示
 
3.2 在主程序中对“录入”（Button1）控件进行定义，弹出录入窗口
 

3.3 建立AddIn.h文件
（1）在AddIn.h中定义student基类；
（2）定义CString n[8]用于保存学生各项信息；
（3）创建CMFCApplication6experiment3Dlg*Dlg1，保存父级对话框指针；
 

3.4 在AddIn.c文件中
（1）构造student()函数，将父级对话框指针传入；
（2）构造void set()成员函数，将n[8]插入到父级对话框的CListCtrl控件。
 
3.5 在AddIn.c中对“确认录入”（Button1）控件进行定义
 
 
3.6 实现效果截图
 

4. 删除学生信息功能
（1）在主函数中对“删除”（Button2）控件进行定义
 
（2）实现效果截图
 
5. 修改学生信息功能

（1）在主函数中对创建函数，将list1列表被选中的内容传递到右侧的“修改”编辑框的“Edit control”控件中
 

（2）在主函数中对“确认修改”（Button4）控件进行定义
 
（3）实现效果截图
 


6. 查找学生信息功能
（1）在主函数中对“查找”（Button3）控件进行定义
 
 
（2）实现效果截图
 
7. 保存文件功能
（1）在主函数中对“另存为”（Button5）控件进行定义，使文件保存在D盘，并命名为“学生成绩记录”
 
（2）实现效果截图
 
 


