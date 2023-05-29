#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(int id, string name, string password)
{
	this->_UserId = id;
	this->_UserName = name;
	this->_UserPassword = password;
}

//机房信息初始化
void Manager::InitComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	int ret;
	int computerNum;
	while (ifs >> ret && ifs >> computerNum)
	{
		this->_ComputerRoom.push_back(computerNum);
	}
	ifs.close();
}

//菜单界面
void Manager::OpenSubmenu()
{
	//打开管理员菜单
	cout << "欢迎管理员：" << this->_UserName << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.退出登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作：";
}

//添加账号
void Manager::AddAccount()
{
	string fileName;
	int select = 0;
	while (true)
	{
		cout << "请输入添加账号的类型：" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			fileName = STUDENTS_FILE;
			break;
		case 2:
			fileName = TEACHERS_FILE;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}

		if (select == 1 || select == 2)
		{
			break;
		}
	}

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	while (true)
	{
		int id = 0;
		string name = "";
		string password = "";
		switch (select)
		{
		case 1:
		{
			cout << "请输入学号：" << endl;
			cin >> id;
			if (this->CheckUserId(id, fileName))
			{
				cout << "该账号已存在，请重新输入！" << endl;
				break;
			}
			cout << "请输入学生姓名：" << endl;
			cin >> name;
			cout << "请输入密码：" << endl;
			cin >> password;
			ofs << id << "  " << name << "  " << password << "  " << endl;
			cout << "添加成功！" << endl;
			ofs.close();
			system("pause");
			system("cls");
			return;
		}
		case 2:
		{
			cout << "请输入职工编号：" << endl;
			cin >> id;
			if (this->CheckUserId(id, fileName))
			{
				cout << "该账号已存在，请重新输入！" << endl;
				break;
			}
			cout << "请输入老师姓名：" << endl;
			cin >> name;
			cout << "请输入密码：" << endl;
			cin >> password;
			ofs << id << "  " << name << "  " << password << "  " << endl;
			cout << "添加成功！" << endl;
			ofs.close();
			system("pause");
			system("cls");
			return;
		}
		}
	}
}

//查看账号
void Manager::ShowAccounts()
{
	int select = 0;
	int fileUserId;
	string fileUserName;
	string fileUserPassword;
	char ch;
	ifstream ifs;
	while (true)
	{
		cout << "请选择查看内容：" << endl;
		cout << "1、查看所有学生" << endl;
		cout << "2、查看所有老师" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			//文件不存在
			ifs.open(STUDENTS_FILE, ios::in);
			if (!ifs.is_open())
			{
				cout << "学生文件不存在！" << endl;
				system("pause");
				system("cls");
				return;
			}
			//文件为空
			ifs >> ch;
			if (ifs.eof())
			{
				cout << "学生文件为空！" << endl;
				ifs.close();
				system("pause");
				system("cls");
				return;
			}
			//文件存在且不为空
			ifs.putback(ch);
			while (ifs >> fileUserId && ifs >> fileUserName && ifs >> fileUserPassword)
			{
				cout << "学号：" << fileUserId << "\t\t姓名：" << fileUserName << "\t\t密码：" << fileUserPassword << endl;
			}
			ifs.close();
			system("pause");
			system("cls");
			return;
		case 2:
			ifs.open(TEACHERS_FILE, ios::in);
			if (!ifs.is_open())
			{
				cout << "教师文件不存在！" << endl;
				system("pause");
				system("cls");
				return;
			}
			ifs >> ch;
			if (ifs.eof())
			{
				cout << "教师文件为空！" << endl;
				ifs.close();
				system("pause");
				system("cls");
				return;
			}
			ifs.putback(ch);
			while (ifs >> fileUserId && ifs >> fileUserName && ifs >> fileUserPassword)
			{
				cout << "职工编号：" << fileUserId << "\t\t姓名：" << fileUserName << "\t\t密码：" << fileUserPassword << endl;
			}
			ifs.close();
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	}
}

//查看机房信息
void Manager::ShowComputerRooms()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房文件不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "机房文件为空！" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(ch);
	int roomId;
	int computerNum;
	while (ifs >> roomId && ifs >> computerNum)
	{
		cout << "机房编号：" << roomId << "\t机房容量：" << computerNum << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::ClearReservations()
{
	ofstream ofs;
	ofs.open(RESERVATIONS_FILE, ios::trunc);
	ofs.close();
	cout << endl << "清空预约成功！" << endl << endl;
	system("pause");
	system("cls");
}

//账号id查重,返回true表示重复
bool Manager::CheckUserId(int id, string filename)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件打开失败！" << endl;
		return false;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		ifs.close();
		return false;
	}

	ifs.putback(ch);
	int fileId;
	string fileUserName;
	string fileUserPassword;
	while (ifs >> fileId && ifs >> fileUserName && ifs >> fileUserPassword)
	{
		if (id == fileId)
		{
			//cout << "该账号已存在，请重新输入！" << endl;
			ifs.close();
			return true;
		}
	}
	return false;
}