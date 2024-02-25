#include "Students.h"

Students::Students()
{

}

Students::Students(int Id, string name, string password)
{
	this->_UserId=Id;
	this->_UserName=name;
	this->_UserPassword=password;

	this->InitComputerRoom();
}

//打开学生菜单
void Students::OpenSubmenu()
{
	cout << "欢迎同学：" << this->_UserName << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.申请预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看我的预约        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看所有预约        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.取消预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.退出登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作：";
}

//申请预约
void Students::ApplyReservation()
{
	manageReservation manageRes;
	if (this->IsEmpty())
	{
		cout << "机房为空，暂时不能预约！" << endl;
		return;
	}
	cout << "机房开放时间为周一至周六！" << endl;
	cout << "请输入预约时间：" << endl;
	cout << "1、周一" << "   ";
	cout << "2、周二" << "   ";
	cout << "3、周三" << "   ";
	cout << "4、周四" << "   ";
	cout << "5、周五" << "   ";
	cout << "6、周六" << endl;
	int date = 0;
	int time = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 6)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "请输入预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> time;
		if (time == 1 || time == 2)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	//判断预约时间是否重复
	for (map<int, map<string, string>>::iterator it = manageRes._ReservationsData.begin(); it != manageRes._ReservationsData.end(); ++it)
	{
		if (it->second["日期"] == to_string(date) && it->second["时间段"] == to_string(time) && it->second["学号"] == to_string(this->_UserId) && (it->second["预约状态"] == to_string(1) || it->second["预约状态"] == to_string(2)))
		{
			cout << "您已经预约过该时间段的机房，请重新选择！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "请选择机房：" << endl;
	for (unsigned int i = 0; i < this->_ComputerRoom.size(); ++i)
	{
		cout << i + 1 << "号机房容量为：" << this->_ComputerRoom[i] << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			--this->_ComputerRoom[room - 1];
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	this->SaveComputerRoom();
	cout << "预约成功，已经提交审核！" << endl;

	ofstream ofs;
	ofs.open(RESERVATIONS_FILE, ios::app);
	ofs << "日期:" << date << "   ";
	ofs << "时间段:" << time << "   ";
	ofs << "机房:" << room << "   ";
	ofs << "学号:" << this->_UserId << "   ";
	ofs << "学生姓名:" << this->_UserName << "   ";
	ofs << "预约状态:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}

//查看自身预约
void Students::CheckSelfReservation()
{
	manageReservation managereservation;
	if (managereservation._ReservationsNum == 0)
	{
		cout << endl << "无预约记录！" << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	int count = 0;
	cout << endl;
	for (int i = 1; i <= managereservation._ReservationsNum; ++i)
	{
		if (stoi(managereservation._ReservationsData[i]["学号"]) == this->_UserId)
		{
			managereservation.showReservation(managereservation._ReservationsData[i]);
			++count;
		}
	}
	cout << endl;
	if (count == 0)
	{
		cout << endl << "无预约记录！" << endl << endl;
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Students::ShowAllReservations()
{
	manageReservation managereservation;
	if (managereservation._ReservationsNum == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << endl;
	for (int i = 1; i <= managereservation._ReservationsNum; ++i)
	{
		cout << i << ". ";
		managereservation.showReservation(managereservation._ReservationsData[i]);
	}
	cout << endl;
	system("pause");
	system("cls");
}

//取消预约
void Students::CancelReservation()
{
	manageReservation managereservation;
	if (managereservation._ReservationsNum == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << endl << "输入0，返回上一级！" << endl;
	cout << "审核中或预约成功的记录可以取消，请输入需要取消的记录：" << endl;
	int count = 0;
	vector<int> vkey;

	//将符合条件的预约记录的key存储到vkey中
	for (int i = 1; i <= managereservation._ReservationsNum; ++i)
	{
		if (stoi(managereservation._ReservationsData[i]["学号"]) == this->_UserId && (stoi(managereservation._ReservationsData[i]["预约状态"]) == 1 || stoi(managereservation._ReservationsData[i]["预约状态"]) == 2))
		{
			vkey.push_back(i);
			cout <<++count << ". ";
			managereservation.showReservation(managereservation._ReservationsData[i]);
		}
	}
	if (count == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//改变预约状态，并更新文件
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= count)
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				managereservation._ReservationsData[vkey[select - 1]]["预约状态"] = "0";
				managereservation.updateReservation();
				++this->_ComputerRoom[stoi(managereservation._ReservationsData[vkey[select - 1]]["机房"]) - 1];
				this->SaveComputerRoom();
				cout << "取消成功！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}

//机房为空时，禁止预约,true为空
bool Students::IsEmpty()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	int ret;
	int computer;
	while (ifs >> ret && ifs >> computer)
	{
		if (computer != 0)
		{
			return false;
		}
	}
	ifs.close();
	return true;
}
