class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(Person& p)//返回bool类型
	{
		if (m_Name == p.m_Name && m_Age == p.m_Age)
			return true;
		return false;
	}
	string m_Name;
	int m_Age;
};
void test1()//关系运算符的重载
{
	Person p1("张三", 20);
	Person p2("张三", 21);
	if (p1 == p2)
		cout << "p1和p2相等" << endl;
	else
		cout << "p1和p2不相等" << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}