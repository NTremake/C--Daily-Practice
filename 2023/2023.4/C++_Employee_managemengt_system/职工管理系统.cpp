#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	/*Worker* w = NULL;
	w = new Manager(1, "����", 2);
	w->showInfo();
	delete w;
	w = new Boss(2, "����", 3);
	w->showInfo();
	delete w;*/

	workerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://����ְ��
			wm.add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.del_Emp();
			break;
		case 4://�޸�ְ��
			wm.mod_Emp();
			break;
		case 5://����ְ��
			wm.find_Emp();
			break;
		case 6://�������
			wm.sort_Emp();
			break;
		case 7://���ְ��
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}