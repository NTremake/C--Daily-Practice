class Person
{
public:
	void operator()(string name)//函数调用符的重载，也叫仿函数
	{
		cout << name << endl;
	}
	int operator()(int a, int b)//函数调用运算符只能写在类里
	{
		return a + b;
	}
	string m_Name;
};
void test1()
{
	Person p1;
	p1.m_Name = "张三";
	p1("张三");//仿函数调用
	cout << p1(10, 20) << endl;
	cout << Person()(1, 2) << endl;//匿名对象也能调用仿函数
}
int main()
{
	test1();
	system("pause");
	return 0;
}