class Person
{
public:
	static void func()//静态成员函数，只能访问静态变量;不用在类外声明
	{
		A = 20 ;
		cout << "静态函数" << endl;
	}
	static int A;
};
int Person::A = 10;
void test1()
{
	Person::func();//所有对象共享的函数，所以不用创建对象也能访问
	cout << Person::A << endl;
}
int main()//静态成员函数
{
	test1();
	system("pause");
	return 0;
}