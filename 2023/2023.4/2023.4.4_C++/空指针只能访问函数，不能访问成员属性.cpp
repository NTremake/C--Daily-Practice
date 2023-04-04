class Person
{
public:
	void showclassName()
	{
		cout << "class name is Person" << endl;
	}
	void showPersonAge()
	{
		if (this == NULL)//空指针成员属性也为空，所以不能访问属性
		{
			return;
		}
		cout << "Person age is" << m_age << endl;
	}
	int m_age;
};
void test1()//空指针也能访问成员函数
{
	Person* p = NULL;
	p->showclassName();
	p->showPersonAge();
}
int main()
{
	test1();
	system("pause");
	return 0;
}