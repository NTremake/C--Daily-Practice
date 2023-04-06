class Person
{
public:
	/*Person operator+(Person &p)//运算符函数重载的成员函数
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/
	int m_A;
	int m_B;
};
Person operator+(Person& p1, Person& p2)//运算符函数重载的全局函数
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
Person operator+(Person& p, int a)//运算符重载的函数也能重载
{
	Person temp;
	temp.m_A = p.m_A + a;
	temp.m_B = p.m_B + a;
	return temp;
}
void test1()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 20;
	p2.m_B = 20;
	Person p3 = p1 + p2;//成员函数运算符重载也是p1+p2
	Person p4 = p1 + 10;
	cout << p3.m_A << "   " << p3.m_B << endl;
	cout << p4.m_A << "   " << p4.m_B << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}