class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int a)
	{
		age = new int(a);//在堆区开辟一个空间
		cout << "有参构造函数" << endl;
	}
	Person(const Person& p)
	{
		/*age = p.age;*///编译器默认的浅拷贝，释放堆区内存时容易出现问题
		cout << "拷贝构造函数" << endl;
		age = new int(*p.age);//使用拷贝函数时，再在堆区开辟一个内存，以免释放内存时，delete误删原对象地址
	}
	~Person()
	{
		if (age != NULL)
		{
			delete age;//age在堆区，需要手动释放内存，还有指针置空
			age = NULL;
		}
		cout << "析构函数" << endl;
	}
	int* age;
};
int main()//浅拷贝与深拷贝
{
	Person p1(10);
	Person p2(p1);
	cout << *p2.age << endl;
	system("pause");
	return 0;
}