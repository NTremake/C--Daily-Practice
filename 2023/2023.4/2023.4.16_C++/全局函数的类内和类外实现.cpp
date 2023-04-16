template<class T1, class T2>
class Person;
//让编译器提前知道函数和类的存在
template<class T1, class T2>
void showPerson2(Person<T1, T2>& p)
{
	cout << "姓名：" << p.m_Name << "   年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	
	friend void showPerson(Person<T1,T2>& p)//全局函数类内实现(推荐
	{
		cout << "姓名：" << p.m_Name << "   年龄：" << p.m_Age << endl;
	}
	friend void showPerson2<>(Person<T1, T2>& p);//全局函数，类外实现,加空模板
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

void test1()
{
	Person<string, int>p("张三", 22);
	showPerson(p);
	Person<string, int>p2("李四", 22);
	showPerson2(p2);
}
int main()
{
	test1();
	system("pause");
	return 0;
}