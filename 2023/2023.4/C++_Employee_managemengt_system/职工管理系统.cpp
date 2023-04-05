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
	w = new Manager(1, "张三", 2);
	w->showInfo();
	delete w;
	w = new Boss(2, "李四", 3);
	w->showInfo();
	delete w;*/

	workerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.mod_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://编号排序
			wm.sort_Emp();
			break;
		case 7://清空职工
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