#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include "h1.h"
#define MAX 1000

void menu()
{
	cout << "***********************" << endl;
	cout << "**** 1�������ϵ�� ****" << endl;
	cout << "**** 2����ʾ��ϵ�� ****" << endl;
	cout << "**** 3��ɾ����ϵ�� ****" << endl;
	cout << "**** 4��������ϵ�� ****" << endl;
	cout << "**** 5���޸���ϵ�� ****" << endl;
	cout << "**** 6�������ϵ�� ****" << endl;
	cout << "**** 0���˳�ͨѶ¼ ****" << endl;
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return 0;
			break;
		}
	}
	return 0;
}