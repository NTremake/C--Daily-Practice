#define _CRT_SECURE_NO_WARINGS
#include "WorkerManager.h"

//初始化
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())//文件不存在的情况
	{
		cout << "文件打开失败！" << endl;
		this->m_EmpNum = 0;//初始化数据
		this->m_EmpArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;//让ifs先读一个字符，在判断这个字符是否为文件结束符
	if (ifs.eof())//文件存在，但数据为空的情况
	{
		cout << "文件数据为空！" << endl;
		this->m_EmpNum = 0;//初始化数据
		this->m_EmpArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->m_EmpNum = this->get_empNum();//文件中有数据的情况
	cout << "文件中的职工人数为：" << this->m_EmpNum << endl;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)//测试代码
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_id
	//		<< "   职工姓名：" << this->m_EmpArray[i]->m_name
	//		<< "   职工岗位：" << this->m_EmpArray[i]->m_deptId << endl;
	//	/*this->m_EmpArray[a]->showInfo();*/
	//}
}

//菜单
void workerManager::showMenu()
{
	cout << "****************************************" << endl;
	cout << "******** 欢迎使用职工管理系统！ ********" << endl;
	cout << "************ 0.退出管理程序 ************" << endl;
	cout << "************ 1.增加职工信息 ************" << endl;
	cout << "************ 2.显示职工信息 ************" << endl;
	cout << "************ 3.删除离职职工 ************" << endl;
	cout << "************ 4.修改职工信息 ************" << endl;
	cout << "************ 5.查找职工信息 ************" << endl;
	cout << "************ 6.按照编号排序 ************" << endl;
	cout << "************ 7.清空所有文档 ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//退出功能
void workerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//添加新职工
void workerManager::add_Emp()
{
	cout << "请输入需要添加的职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		
		Worker* worker = NULL;//worker是newspace数组中的单个职工
		int newSize = this->m_EmpNum + addNum;//新职工总数=原职工数+新添加的职工数
		Worker** newSpace = new Worker* [newSize * sizeof(worker)];//new arr[10]创建数组指针。[newSize*sizeof(worker)]

		if (this->m_EmpArray != NULL)//如果不为空，就需要先把旧数组暂存到新数组
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];//把旧数组暂存在新数组
			}
		}
		for (int i = 0; i < addNum; i++)//给新添加的员工赋值
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、基层员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;


			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入错误，请重新输入！" << endl;
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;//最后把员工添加到数组中
		}
		delete[] m_EmpArray;//清空旧数组
		this->m_EmpArray = newSpace;//更新旧数组空间
		this->m_EmpNum = newSize;//更新旧的员工人数
		this->m_fileIsEmpty = false;//更新文件不为空的标志
		this->save();
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "   "
			<< this->m_EmpArray[i]->m_name << "   "
			<< this->m_EmpArray[i]->m_deptId << endl;
	}
	ofs.close();
}

//获取文件中的人数
int workerManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化职工信息
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示员工信息功能
void workerManager::show_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//删除职工
void workerManager::del_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入要删除的职工编号：" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			if (this->m_EmpNum == 0)
			{
				this->m_fileIsEmpty = true;
			}
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "未找到该职工！" << endl;
		}
		system("pause");
		system("cls");
	}
}

//判断职工是否存在，并返回数组中的位置
int workerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改职工信息
void workerManager::mod_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到：" << id << "号职工的信息，请输入该职工的新编号：" << endl;
			cin >> newId;
			cout << "请输入该职工的姓名：" << endl;
			cin >> newName;
			cout << "请输入该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				cout << "输入错误，请重新输入！" << endl;
				break;
			}
			this->m_EmpArray[ret] = worker;
			this->save();
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "未找到该职工信息！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void workerManager::find_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件为空或者不存在！" << endl;
	}
	else
	{
		cout << "请选择查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入职工编号：" << endl;
			int id = 0;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1)
			{
				cout << "该员工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入职工姓名：" << endl;
			string name = "";
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，第" << this->m_EmpArray[i]->m_id << "号职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//职工排序
void workerManager::sort_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按编号升序排列" << endl;
		cout << "2、按编号降序排列" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "查无此人！" << endl;
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		this->save();
		cout << "排序成功！排序结果为：" << endl;
		this->show_Emp();
	}
}

//清空文件
void workerManager::clean_File()
{
	cout << "确认清空职工信息吗？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		while (select == 1)
		{
			cout << "请输入“确认清空”四个字再次确认：" << endl;
			string ret = "";
			cin >> ret;
			string str = "确认清空";
			if (ret == str)
			{
				ofstream ofs(FILENAME, ios::trunc);//删除文件并新建
				ofs.close();
				if (this->m_EmpArray != NULL)
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						delete this->m_EmpArray[i];
						this->m_EmpArray[i] = NULL;
					}
					delete[] this->m_EmpArray;
					this->m_EmpArray = NULL;
					this->m_EmpNum = 0;
					this->m_fileIsEmpty = true;
					cout << "清空成功！" << endl;
					break;
				}
				break;
			}
			else
				break;
		}
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_fileIsEmpty = true;
	}
}