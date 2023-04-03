class Person//构造函数的意义就是为了初始化对象
{
public:
	Person()//普通构造函数、无参构造函数
	{
		cout << "无参构造函数" << endl;
	}
	Person(int a)//有参构造函数，普通构造函数
	{
		age = a;
		cout << "有参构造函数" << endl;
	}
	Person(const Person& p)//拷贝构造函数，将传过来的对象的属性拷贝到新对象上
	{
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}
	~Person()//析构函数
	{
		cout << "析构函数" << endl;
	}
	int age;
};
void copy(Person p)
{
}
void test1()
{
	Person p;
	copy(p);//对象传参是构造函数时会调用拷贝构造函数
}
Person doWork()
{
	Person p1;
	return p1;//函数返回值是构造函数时，也会调用拷贝构造函数
}
void test2()
{
	Person p2 = doWork();
}
int main()
{
test1();
test2();
	Person p1;//无参构造
	p1 = Person(10);//有参构造，Person(10)是匿名函数，用了就销毁
	Person p2=Person(p1);//构造函数在初始化一个新的构造函数时，会调用拷贝构造函数
	cout << "p2的年龄：" << p2.age << endl;
	system("pause");
	return 0;
}