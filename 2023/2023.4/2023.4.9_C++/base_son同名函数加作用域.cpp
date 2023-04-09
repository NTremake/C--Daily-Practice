class base
{
public:
	base()
	{
		a = 100;
	}
	void func()
	{
		cout << "base func()调用" << endl;
	}
	void func(int a)
	{
		cout << "base func(int a)调用" << endl;
	}
	int a;
};
class son :public base
{
public:
	son()
	{
		a = 200;
	}
	void func()
	{
		cout << "son func()调用" << endl;
	}
static void func1()
	{
		cout << "base static func1()调用" << endl;
	}
	int a;
};
void test1()
{
	son s1;
	cout << "son  a=" << s1.a << endl;
	cout << "base  a=" << s1.base::a << endl;
	s1.func();//子类和父类成员重名时，默认调用子类成员，调用父类需要加作用域
	s1.base::func();
	s1.base::func(10);//子类和父类函数重名时，父类函数必须加作用域，即使子类没有重载函数
son::base::func1();//静态成员函数，可以直接通过类名加作用域调用
}
int main()
{
	test1();
	system("pause");
	return 0;
}