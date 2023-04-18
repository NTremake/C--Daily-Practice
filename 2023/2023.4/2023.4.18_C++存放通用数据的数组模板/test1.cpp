#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include <string>
#include "myarray.hpp"

class Person
{
public:
	Person() {};
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void PrintfInt(myArray<int>& arr)
{
	cout << "����Ԫ�صĴ�ӡ" << endl;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void printfArray(myArray<Person>& arr)
{
	cout << "����Ԫ�صĴ�ӡ" << endl;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������" << arr[i].m_Name << "   ���䣺" << arr[i].m_Age << endl;
	}
}
void test1()
{
	//���Դ���
	myArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);//β�巨��ֵ
	}
	PrintfInt(arr1);
	cout << "arr1��������" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�С��" << arr1.getSize() << endl;
	myArray<int>arr2(arr1);
	arr2.Pop_Back();
	PrintfInt(arr2);
	cout << "arr2��������" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�С��" << arr2.getSize() << endl;
}
void test02()
{
	myArray<Person>arr(10);
	Person p1("����", 18);
	Person p2("����", 21);
	Person p3("����", 22);
	Person p4("����", 20);
	Person p5("����", 19);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	printfArray(arr);
	cout << "arr�����������" << arr.getCapacity() << endl;
	cout << "arr����Ĵ�С��" << arr.getSize() << endl;
}
int main()
{
	/*test1();*/
	test02();
	system("pause");
	return 0;
}