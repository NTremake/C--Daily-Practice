class base
{
public:
	base()
	{
		cout << "base的构造函数" << endl;//1
	}
	~base()
	{
		cout << "base的析构函数" << endl;//4
	}
};
class son :public base
{
public:
	son()
	{
		cout << "son的构造函数" << endl;//2
	}
	~son()
	{
		cout << "son的析构函数" << endl;//3
	}
};
void test1()
{
	son s1;//类继承时，子类和父类构造函数和析构函数的顺序
}
int main()
{
	test1();
	system("pause");
	return 0;
}