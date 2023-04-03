class Person
{
public:
	static int A;//静态成员变量
};
int Person::A;//需要在类外声明
void test1()
{
	Person p1;
	p1.A = 10;
	cout << p1.A << endl;
	Person p2;
	p2.A = 20;
	cout << Person::A << endl;//静态成员变量共用一份数据，所以p1.A也被改成20,也可以用类名的方式访问
}
int main()
{
	test1();
	system("pause");
	return 0;
}