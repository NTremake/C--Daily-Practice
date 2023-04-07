#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include "h1.h"
#define MAX 1000

void menu()
{
	cout << "***********************" << endl;
	cout << "**** 1、添加联系人 ****" << endl;
	cout << "**** 2、显示联系人 ****" << endl;
	cout << "**** 3、删除联系人 ****" << endl;
	cout << "**** 4、查找联系人 ****" << endl;
	cout << "**** 5、修改联系人 ****" << endl;
	cout << "**** 6、清空联系人 ****" << endl;
	cout << "**** 0、退出通讯录 ****" << endl;
	cout << "***********************" << endl;
}
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

int main()
{
	struct AddressBooks abs;
		abs.Size = 0;
	int select = 0;
	while(true)
	{
		menu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			delPerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			return 0;
			break;
		}
	}
	return 0;
}