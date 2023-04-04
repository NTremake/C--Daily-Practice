class Person//const修饰成员函数和对象
{
public:
	void showPerson() const//const修饰的函数，不能修改属性;const showPerson* const this
	{
		/*this->m_A = 10;*///m_A不能被常函数修改
		this->m_B = 20;//前面加上mutable就可以被常函数修改
		cout << this->m_B << endl;
cout << this->m_A << endl;//可以访问
	}
	void func(){}
	int m_A;
	mutable int m_B;
};
void test1()
{
	const Person p;//const也能修饰对象
	/*p.m_A = 10;*/
	p.m_B = 30;//常对象只有加了mutable的m_B才能被修改
cout << p.m_A << endl;
	p.showPerson();
	/*p.func();*///常对象只能调用常函数
}
int main()
{
	test1();
	system("pause");
	return 0;
}