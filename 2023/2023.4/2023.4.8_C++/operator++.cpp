class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger m);
public:
	MyInteger()
	{
		m_A = 0;
	}
	MyInteger& operator++()//返回对象使<<重载能够识别，引用能够使++一直操作原对象，避免形参拷贝
	{
		m_A++;
		return *this;
	}
	MyInteger operator++(int)//这里不返回引用，不然就是返回temp局部变量的引用，局部变量会释放；后置++需要int作为占位符
	{
		MyInteger temp = *this;
		m_A++;
		return temp;
	}
private:
	int m_A;
};
ostream& operator<<(ostream& cout, MyInteger m)
{
	cout << m.m_A;
	return cout;
}
void test1()//
{
	MyInteger m1;
	cout << ++(++m1) << endl;//总结一句话就是：前置运算返回引用，后置运算返回值
	cout << m1++ << endl;//后置递增就不能实现链式操作了
	cout << m1 << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}