#include "Teachers.h"

Teachers::Teachers()
{
}

Teachers::Teachers(int Id, string name, string password)
{
	this->_UserId = Id;
	this->_UserName = name;
	this->_UserPassword = password;

	this->InitComputerRoom();
}

//菜单界面
void Teachers::OpenSubmenu()
{
	cout << "欢迎教师：" << this->_UserName << "登录" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.查看所有预约        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.审核预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.退出登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作：";
}

//查看所有预约
void Teachers::ShowAllReservations()
{
	manageReservation manageRes;
	if (manageRes._ReservationsNum == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << endl;
	for (int i = 1; i <= manageRes._ReservationsNum; ++i)
	{
		cout << i << ". ";
		manageRes.showReservation(manageRes._ReservationsData[i]);

	}
	cout << endl;
	system("pause");
	system("cls");
}

//审核预约
void Teachers::CheckReservations()
{
	manageReservation manageRes;
	if (manageRes._ReservationsNum == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << endl << "待审核的预约记录如下：" << endl << endl;

	int count = 0;
	vector<int> vcheckKey;
	for (int i = 1; i <= manageRes._ReservationsNum; ++i) 
	{
		if (manageRes._ReservationsData[i]["预约状态"] == "1") 
		{
			vcheckKey.push_back(i);
			cout << ++count << ". ";
			manageRes.showReservation(manageRes._ReservationsData[i]);
		}
	}

	cout << endl << "输入0退出审核！" << endl;
	cout << "请输入您要审核的预约编号：" << endl;
	int select;
	int ret;
	while (true)
	{
		cin >> select;
		if(select > 0 && select <= count)
		{
			cout << endl << "请输入审核结果>>   1.通过   2.不通过   0.退出审核" << endl;
			cin >> ret;
			if (ret == 1)
			{
				manageRes._ReservationsData[vcheckKey[select - 1]]["预约状态"] = "2";
				manageRes.updateReservation();
				cout << "审核通过！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (ret == 2)
			{
				manageRes._ReservationsData[vcheckKey[select - 1]]["预约状态"] = "-1";
				manageRes.updateReservation();
				++this->_ComputerRoom[stoi(manageRes._ReservationsData[vcheckKey[select - 1]]["机房"]) - 1];
				this->SaveComputerRoom();
				cout << "审核不通过！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (ret == 0)
			{
				cout << "已退出审核！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "输入错误，请重新输入！" << endl;
			}
		}
		else if (select == 0)
		{
			cout << "已退出审核！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}
