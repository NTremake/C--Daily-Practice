#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class workerManager
{
public:
	workerManager();

	void showMenu();//菜单

	void exitSystem();//退出功能

	void add_Emp();//添加职工

	void save();//保存文件

	bool m_fileIsEmpty;//判断文件是否为空

	int get_empNum();//获取文件中的人数

	void init_Emp();//初始化职工信息

	void show_Emp();//显示员工信息

	void del_Emp();//删除职工

	int isExist(int id);//判断职工是否存在，并返回数组中的位置

	void mod_Emp();//修改职工信息

	void find_Emp();//查找职工

	void sort_Emp();//职工排序

	void clean_File();//清空文件

	int m_EmpNum;//职工数量

	Worker** m_EmpArray;//指向职工数组，数组中又包含各种职工

	~workerManager();
};