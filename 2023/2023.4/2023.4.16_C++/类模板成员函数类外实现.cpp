template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showInfo();
	T1 m_Name;
	T2 m_Age;
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name,T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person<T1, T2>::showInfo()//成员函数在类外的实现
{
	cout << "姓名：" << this->m_Name << "   年龄：" << this->m_Age << endl;
}
void test1()
{
	Person<string, int> p1("张三", 22);
	p1.showInfo();
}
int main()
{
	test1();
	system("pause");
	return 0;
}