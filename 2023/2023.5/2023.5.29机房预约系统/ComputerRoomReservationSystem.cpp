#include <iostream>
using namespace std;
#include <fstream>
#include "LogIn.h"
#include "globalFile.h"

int main()
{
	while (true) 
	{
		cout<<"==================== ��ӭʹ�û���ԤԼϵͳ ====================" << endl;
		cout << endl << "���������������Ϣ��" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";

		cout << "����������ѡ��" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}