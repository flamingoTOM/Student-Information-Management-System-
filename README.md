学生信息管理系统

If you want to know the whole process of the project or how to use the specific controls, please consult the pdf of the Github documentation
1.	建立基于对话框的图形界面
   
   （1）界面展示
   
 ![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/87d4dfc1-7f66-4ac5-bb3d-75921ba6a1e0)

（2）对“List Control”控件进行初始化

 ![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/be976af7-d923-49e5-954a-a25e8114e395)


2.	密码登录功能
   
（1）	在主程序中初始化弹出登陆界面


![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/12f6b70f-711d-4438-b0d0-41de90bf243b)


（2）	在Login_1.cpp中对“登录”（Button1）控件进行定义


![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/c6d56f35-d311-4f6d-ab8f-fc1f52779729)

 
（3）	实现效果截图

![GGG~(KH5{$8{HW2AVKVZEF3](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/dee89d26-34de-4a58-b994-3673ddb3d706)

 

3. 录入学生信息功能
   
3.1 录入界面展示

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/6b6824e5-26bf-4c85-bfd6-2695bc1d347d)

 
3.2 在主程序中对“录入”（Button1）控件进行定义，弹出录入窗口

 ![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/302d90f0-4992-415a-8a56-fa1dd036f70c)


3.3 建立AddIn.h文件

（1）在AddIn.h中定义student基类；

（2）定义CString n[8]用于保存学生各项信息；

（3）创建CMFCApplication6experiment3Dlg*Dlg1，保存父级对话框指针；

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/53bc4902-4b19-4c0a-bb83-26451072f555)

 

3.4 在AddIn.c文件中

（1）构造student()函数，将父级对话框指针传入；

（2）构造void set()成员函数，将n[8]插入到父级对话框的CListCtrl控件。


![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/a9743e37-957b-4287-bfd5-85380b8ece33)

 
3.5 在AddIn.c中对“确认录入”（Button1）控件进行定义

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/2781b39f-03eb-43b8-b69a-e4779ef9f0a7)

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/700e8617-0807-42b4-ad8b-8d0c000260a5)


 
 
3.6 实现效果截图

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/7961abe9-7098-4866-98b4-e96d8ac85e72)

 

4. 删除学生信息功能
   
（1）在主函数中对“删除”（Button2）控件进行定义

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/fc40562a-5597-427e-8423-20798cf494dd)

 
（2）实现效果截图

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/23a0de5d-7753-4422-b658-126f46ca8ff5)

 
5. 修改学生信息功能
   

（1）在主函数中对创建函数，将list1列表被选中的内容传递到右侧的“修改”编辑框的“Edit control”控件中

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/0c9c1056-e504-4ee3-b420-652ec79b95e0)

 

（2）在主函数中对“确认修改”（Button4）控件进行定义


![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/d0561d3d-c210-4bd2-b6de-59d5675491ad)

 
（3）实现效果截图

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/b76d2265-5b20-4b71-aa09-3f5816b310ed)

 


6. 查找学生信息功能
   
（1）在主函数中对“查找”（Button3）控件进行定义

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/d4377d64-e44a-47f1-a273-20cfc2e44489)
![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/54c1bd3a-4625-4932-b6af-a198b64d8bf4)


 
 
（2）实现效果截图

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/9c43d562-bc1e-4843-b7d1-d855b10bb471)

 
7. 保存文件功能
   
（1）在主函数中对“另存为”（Button5）控件进行定义，使文件保存在D盘，并命名为“学生成绩记录”

![image](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/cfb78bbb-92f5-4832-b630-e58c4b0a1b1c)

 
（2）实现效果截图

![~APCUZE$ISC7 3T3 GZH~OX](https://github.com/flamingoTOM/Student-Information-Management-System-/assets/152771730/f3bc07e1-40b8-4c0b-ba2c-7a72144fc1f5)

 
 


