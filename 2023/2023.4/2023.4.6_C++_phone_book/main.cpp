#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include <string>
#include "h1.h"
#define MAX 1000

struct Person
{
	string name;
	int Sex;
	int Age;
	string Phone;
	string Addr;
};
struct AddressBooks
{
	struct Person personArray[MAX];
	int Size;
};
void addPerson(struct AddressBooks* abs)//添加联系人
{
	if (abs->Size == (MAX - 1))
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->personArray[abs->Size].name = name;
		int Sex;
		cout << "请输入联系人性别：" << endl;
		cout << "1---男" << endl << "2---女" << endl;
		while (true)
		{
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs->personArray[abs->Size].Sex = Sex;
				break;
			}
			else
				cout << "输入错误！" << endl;
		}
		int Age;
		cout << "请输入联系人年龄：" << endl;
		cin >> Age;
		abs->personArray[abs->Size].Age = Age;
		string Phone;
		cout << "请输入联系人电话：" << endl;
		cin >> Phone;
		abs->personArray[abs->Size].Phone = Phone;
		string Addr;
		cout << "请输入联系人住址：" << endl;
		cin >> Addr;
		abs->personArray[abs->Size].Addr = Addr;
		abs->Size++;
		cout << "添加完成！" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(struct AddressBooks* abs)//显示所有联系人
{
	if (abs->Size == 0)
	{
		cout << "当前联系人信息为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name << "      ";
			cout << "性别：" << (abs->personArray[i].Sex == 1 ? "男" : "女") << "      ";
			cout << "年龄：" << abs->personArray[i].Age << "      ";
			cout << "电话：" << abs->personArray[i].Phone << "      ";
			cout << "住址：" << abs->personArray[i].Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(AddressBooks* abs, string name)//通过姓名判断联系人是否存在
{
	for (int i = 0; i < abs->Size; i++)
	{
		if (abs->personArray[i].name == name)
			return i;
	}
	return -1;
}
void delPerson(AddressBooks* abs)//删除联系人
{
	string delname;
	cout << "请输入需要删除的联系人的姓名：" << endl;
	cin >> delname;
	int ret=isExist(abs, delname);
	if (ret != -1)
	{
		for (int i = ret; i < abs->Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			abs->Size--;
			cout << "删除成功" << endl;
		}
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(AddressBooks* abs)//查找联系人
{
	string name;
	cout << "请输入您要查找的联系人姓名：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].name << "      ";
		cout << "性别：" << (abs->personArray[ret].Sex == 1 ? "男" : "女") << "      ";
		cout << "年龄：" << abs->personArray[ret].Age << "      ";
		cout << "电话：" << abs->personArray[ret].Phone << "      ";
		cout << "住址：" << abs->personArray[ret].Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(AddressBooks* abs)
{
	string name;
	cout << "请输入您要修改的联系人姓名：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->personArray[ret].name = name;
		int Sex;
		cout << "请输入联系人性别：" << endl;
		cout << "1---男" << endl << "2---女" << endl;
		while (true)
		{
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs->personArray[ret].Sex = Sex;
				break;
			}
			else
				cout << "输入错误！" << endl;
		}
		int Age;
		cout << "请输入联系人年龄：" << endl;
		cin >> Age;
		abs->personArray[ret].Age = Age;
		string Phone;
		cout << "请输入联系人电话：" << endl;
		cin >> Phone;
		abs->personArray[ret].Phone = Phone;
		string Addr;
		cout << "请输入联系人住址：" << endl;
		cin >> Addr;
		abs->personArray[ret].Addr = Addr;
		cout << "修改完成！" << endl;
	}
	else
	{
		cout<< "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(AddressBooks* abs)
{
	cout << "是否确认清空？" << endl;
	cout << "1---清空" <<endl << "2---不清空" << endl;
	int flag;
	while (true)
	{
		cin >> flag;
		if (flag == 1)
		{
			abs->Size = 0;
			cout << "联系人已清空！" << endl;
			break;
		}
		else
			break;
	}
	system("pause");
	system("cls");
}