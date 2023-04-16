#pragma once
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();
	T1 m_Name;
	T2 m_Age;
};
//类模板的分文件编写，将声明和函数都写在头文件，后缀是.hpp，这是约定俗成的主流的写法，一看就知道是类模板。解决类模板函数在调用时才创建的问题。（也可以将声明和函数分开写，再引入cpp文件，不推荐）
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << this->m_Name << "   年龄：" << this->m_Age << endl;
}

-----------------------------------------------------------
#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include <string>
#include "person.hpp"

void test1()
{
	Person<string, int>p("张三", 22);
	p.showPerson();
}
int main()
{
	test1();
	system("pause");
	return 0;
}