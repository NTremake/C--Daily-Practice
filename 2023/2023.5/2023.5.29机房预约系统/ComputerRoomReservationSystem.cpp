#include <iostream>
using namespace std;
#include <fstream>
#include "LogIn.h"
#include "globalFile.h"

int main()
{
	while (true) 
	{
		cout<<"==================== 欢迎使用机房预约系统 ====================" << endl;
		cout << endl << "请输入您的身份信息：" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学    生           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";

		cout << "请输入您的选择：" << endl;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			LogIn(STUDENTS_FILE, 1);
			break;
		case 2:
			LogIn(TEACHERS_FILE, 2);
			break;
		case 3:
			LogIn(MANAGER_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}