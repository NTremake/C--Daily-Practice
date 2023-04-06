class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	int m_A;
	int m_B;
};
ostream& operator<<(ostream& cout, Person& p)//cout全局唯一，所以必须是引用;cout是ostream输出流
{
	cout << p.m_A << "   " << p.m_B;
	return cout;//链式函数思想，返回cout，后面就可以继续接<<
}
void test1()//左移运算符<<的重载，只能写在全局函数里
{
	Person p(10,10);
	cout << p << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}