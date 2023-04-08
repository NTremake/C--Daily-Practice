class Person
{
public:
	Person()
	{
		m_Age = new int(0);
	}
	Person(int age)
	{
		m_Age = new int(age);
	}
	Person& operator=(Person& p)
	{
		if (m_Age != NULL)//先把新对象的自身属性清空
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);//深拷贝，为新对象再开辟一个内存
		return *this;//链式函数思想
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	int* m_Age;
};
void test1()//等号的重载
{
	Person p1(20);
	Person p2;
	Person p3;
	p3 = p2 = p1;
	cout << "p1=" << *p1.m_Age << endl;
	cout << "p2=" << *p2.m_Age << endl;
	cout << "p3=" << *p3.m_Age << endl;

}
int main()
{
	test1();
	system("pause");
	return 0;
}