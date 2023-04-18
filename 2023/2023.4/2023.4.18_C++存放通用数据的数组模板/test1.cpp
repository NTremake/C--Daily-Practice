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
	cout << "数组元素的打印" << endl;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void printfArray(myArray<Person>& arr)
{
	cout << "数组元素的打印" << endl;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << "   年龄：" << arr[i].m_Age << endl;
	}
}
void test1()
{
	//测试代码
	myArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);//尾插法赋值
	}
	PrintfInt(arr1);
	cout << "arr1的容量：" << arr1.getCapacity() << endl;
	cout << "arr1的大小：" << arr1.getSize() << endl;
	myArray<int>arr2(arr1);
	arr2.Pop_Back();
	PrintfInt(arr2);
	cout << "arr2的容量：" << arr2.getCapacity() << endl;
	cout << "arr2的大小：" << arr2.getSize() << endl;
}
void test02()
{
	myArray<Person>arr(10);
	Person p1("张三", 18);
	Person p2("李四", 21);
	Person p3("王五", 22);
	Person p4("赵六", 20);
	Person p5("刘七", 19);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	printfArray(arr);
	cout << "arr数组的容量：" << arr.getCapacity() << endl;
	cout << "arr数组的大小：" << arr.getSize() << endl;
}
int main()
{
	/*test1();*/
	test02();
	system("pause");
	return 0;
}