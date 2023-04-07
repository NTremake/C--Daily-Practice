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
void addPerson(struct AddressBooks* abs)//�����ϵ��
{
	if (abs->Size == (MAX - 1))
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->personArray[abs->Size].name = name;
		int Sex;
		cout << "��������ϵ���Ա�" << endl;
		cout << "1---��" << endl << "2---Ů" << endl;
		while (true)
		{
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs->personArray[abs->Size].Sex = Sex;
				break;
			}
			else
				cout << "�������" << endl;
		}
		int Age;
		cout << "��������ϵ�����䣺" << endl;
		cin >> Age;
		abs->personArray[abs->Size].Age = Age;
		string Phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> Phone;
		abs->personArray[abs->Size].Phone = Phone;
		string Addr;
		cout << "��������ϵ��סַ��" << endl;
		cin >> Addr;
		abs->personArray[abs->Size].Addr = Addr;
		abs->Size++;
		cout << "�����ɣ�" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(struct AddressBooks* abs)//��ʾ������ϵ��
{
	if (abs->Size == 0)
	{
		cout << "��ǰ��ϵ����ϢΪ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "������" << abs->personArray[i].name << "      ";
			cout << "�Ա�" << (abs->personArray[i].Sex == 1 ? "��" : "Ů") << "      ";
			cout << "���䣺" << abs->personArray[i].Age << "      ";
			cout << "�绰��" << abs->personArray[i].Phone << "      ";
			cout << "סַ��" << abs->personArray[i].Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(AddressBooks* abs, string name)//ͨ�������ж���ϵ���Ƿ����
{
	for (int i = 0; i < abs->Size; i++)
	{
		if (abs->personArray[i].name == name)
			return i;
	}
	return -1;
}
void delPerson(AddressBooks* abs)//ɾ����ϵ��
{
	string delname;
	cout << "��������Ҫɾ������ϵ�˵�������" << endl;
	cin >> delname;
	int ret=isExist(abs, delname);
	if (ret != -1)
	{
		for (int i = ret; i < abs->Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			abs->Size--;
			cout << "ɾ���ɹ�" << endl;
		}
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(AddressBooks* abs)//������ϵ��
{
	string name;
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].name << "      ";
		cout << "�Ա�" << (abs->personArray[ret].Sex == 1 ? "��" : "Ů") << "      ";
		cout << "���䣺" << abs->personArray[ret].Age << "      ";
		cout << "�绰��" << abs->personArray[ret].Phone << "      ";
		cout << "סַ��" << abs->personArray[ret].Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(AddressBooks* abs)
{
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->personArray[ret].name = name;
		int Sex;
		cout << "��������ϵ���Ա�" << endl;
		cout << "1---��" << endl << "2---Ů" << endl;
		while (true)
		{
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs->personArray[ret].Sex = Sex;
				break;
			}
			else
				cout << "�������" << endl;
		}
		int Age;
		cout << "��������ϵ�����䣺" << endl;
		cin >> Age;
		abs->personArray[ret].Age = Age;
		string Phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> Phone;
		abs->personArray[ret].Phone = Phone;
		string Addr;
		cout << "��������ϵ��סַ��" << endl;
		cin >> Addr;
		abs->personArray[ret].Addr = Addr;
		cout << "�޸���ɣ�" << endl;
	}
	else
	{
		cout<< "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(AddressBooks* abs)
{
	cout << "�Ƿ�ȷ����գ�" << endl;
	cout << "1---���" <<endl << "2---�����" << endl;
	int flag;
	while (true)
	{
		cin >> flag;
		if (flag == 1)
		{
			abs->Size = 0;
			cout << "��ϵ������գ�" << endl;
			break;
		}
		else
			break;
	}
	system("pause");
	system("cls");
}