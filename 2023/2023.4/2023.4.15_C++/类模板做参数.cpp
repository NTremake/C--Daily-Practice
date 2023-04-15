template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this->m_Name << "   年龄：" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
void func(Person<string, int>& p)//类模板作为参数，自己指定数据类型：最常用
{
	p.showPerson();
}
template<class T1,class T2>
void func1(Person<T1, T2>&p)//函数参数模板化
{
	p.showPerson();//typeid(T).name()可以显示参数的类型
	cout << "T1的数据类型：" << typeid(T1).name() << endl;
	cout << "T2的数据类型：" << typeid(T2).name() << endl;
}
template<class T>
void func2(T& p)//整个类模板化
{
	p.showPerson();
}
void test1()
{
	Person<string, int>p("张三", 22);
	func(p);
	Person<string, int>p1("李四", 22);
	func1(p1);
	Person<string, int>p2("王五", 22);
	func2(p2);
}
int main()
{
	test1();
	system("pause");
	return 0;
}