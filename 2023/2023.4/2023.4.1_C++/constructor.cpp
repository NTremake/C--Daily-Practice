class Person
{
public:
	Person()//构造函数
	{
		cout << "构造函数" << endl;
	}
	~Person()//析构函数
	{
		cout << "析构函数" << endl;
	}
};
void test1()
{
	/*Person p;*///创建在栈区，能直接调用析构函数，不要带括号
}
int main()
{
	test1();
	Person p;//创建在主函数里面，这里不会直接调用析构，这里没有销毁对象p；不要带括号，就会默认调用对象的所有函数
	system("pause");
	return 0;
}