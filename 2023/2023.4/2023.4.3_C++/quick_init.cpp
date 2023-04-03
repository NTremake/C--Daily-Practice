class Person
{
public:
	Person()
	{
	}
	Person(int a, int b, int c) :A(a), B(b), C(c)//初始化列表，这样给属性赋值节省内存
	{
	}
int A;
int B;
int C;
};
void test1()
{
	Person p(10, 20, 30);
	cout << p.A << "   " << p.B << "   " << p.C << "   " << endl;
}
int main()
{
	system("pause");
	return 0;
}