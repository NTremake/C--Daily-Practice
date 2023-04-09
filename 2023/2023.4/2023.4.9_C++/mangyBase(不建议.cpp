class base1
{
public:
	base1()
	{
		a = 1;
	}
	int a;
};
class base2
{
public:
	base2()
	{
		a = 2;
	}
	int a;
};
class son :public base1,public base2//继承多个类，一般不建议这样继承
{
public:
	son()
	{
		c = 3;
		d = 4;
	}
	int c;
	int d;
};
void test1()
{
	son s1;
	cout << s1.base1::a << endl;//多个父类里的成员重名时，也用作用域区分
	cout << s1.base2::a << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}