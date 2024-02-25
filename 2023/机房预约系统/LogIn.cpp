#include "LogIn.h"

//登录功能
void LogIn(string FileName, int type)
{
	Identity* person = nullptr;

	ifstream ifs;
	ifs.open(FileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	int userId = 0;
	string userName;
	string userPassword;
	if (type == 1)
	{
		cout << "请输入您的学号：" << endl;
		cin >> userId;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> userId;
	}
	else if (type == 3)
	{
		cout << "请输入您的管理员用账号：" << endl;
		cin >> userId;
	}

	cout << "请输入您的用户名：" << endl;
	cin >> userName;
	cout << "请输入您的密码：" << endl;
	cin >> userPassword;

	//学生登录验证
	if (type == 1)
	{
		int FileId;
		string fileName2;
		string FilePassword;
		while (ifs >> FileId && ifs >> fileName2 && ifs >> FilePassword)
		{
			if (FileId == userId && fileName2 == userName && FilePassword == userPassword)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");

				//创建学生对象
				person = new Students(userId, userName, userPassword);
				//打开学生子菜单
				studentMenu(person);

				return;
			}
		}
	}

	//教师登录验证
	else if (type == 2)
	{
		int FileId;
		string fileName2;
		string FilePassword;
		while (ifs >> FileId && ifs >> fileName2 && ifs >> FilePassword)
		{
			if (FileId == userId && fileName2 == userName && FilePassword == userPassword)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");

				//创建教师对象
				person = new Teachers(userId, userName, userPassword);
				//打开教师子菜单
				teacherMenu(person);

				return;
			}
		}
	}

	//管理员登录验证
	else if (type == 3)
	{
		int fileId;
		string fileName2;
		string FilePassword;
		while (ifs >> fileId && ifs >> fileName2 && ifs >> FilePassword)
		{
			if (fileId == userId && fileName2 == userName && FilePassword == userPassword)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				
				//创建管理员对象
				person = new Manager(userId, userName, userPassword);
				//打开管理员子菜单
				managerMenu(person);

				return;
			}
		}
	}
	ifs.close();
	cout << "登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

//管理员子菜单界面
void managerMenu(Identity*& manager)
{
	Manager* admini = (Manager*)manager;//将父类指针强制转换成，管理员指针，调用管理员的成员函数
	int select = 0;
	while (true)
	{
		manager->OpenSubmenu();//打开子菜单
		cin >> select;

		//添加账号
		if (select == 1)
		{
			cout << "添加账号" << endl;
			admini->AddAccount();
		}
		//查看账号
		else if (select == 2)
		{
			cout << "查看账号信息" << endl;
			admini->ShowAccounts();
		}
		//查看机房
		else if (select == 3)
		{
			cout << "查看机房信息" << endl;
			admini->ShowComputerRooms();
		}
		//清空预约
		else if (select == 4)
		{
			//cout << "清空预约信息" << endl;
			admini->ClearReservations();
		}
		//注销登录
		else if (select == 0)
		{
			delete manager;
			manager = nullptr;
			cout << endl << "退出登录成功" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生子菜单界面
void studentMenu(Identity*& student)
{
	int select = 0;
	Students* thisStudent = (Students*)student;
	while (true)
	{
		thisStudent->OpenSubmenu();//打开子菜单
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "申请预约" << endl;
			thisStudent->ApplyReservation();
			break;
		case 2:
			cout << "查看自身预约" << endl;
			thisStudent->CheckSelfReservation();
			break;
		case 3:
			cout << "查看所有预约" << endl;
			thisStudent->ShowAllReservations();
			break;
		case 4:
			cout << "取消预约" << endl;
			thisStudent->CancelReservation();
			break;
		case 0:
		{
			delete student;
			student = nullptr;
			cout << endl << "退出登录成功" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//老师子菜单界面
void teacherMenu(Identity*& teacher)
{
	Teachers* thisTeacher = (Teachers*)teacher;

	int select = 0;
	while (true)
	{
		thisTeacher->OpenSubmenu();//打开子菜单

		cin >> select;
		switch (select)
		{
		case 1:
			cout << "查看所有预约" << endl;
			thisTeacher->ShowAllReservations();
			break;
		case 2:
			cout << "审核预约" << endl;
			thisTeacher->CheckReservations();
			break;
		case 0:
		{
			delete teacher;
			teacher = nullptr;
			cout << endl << "退出登录成功" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
