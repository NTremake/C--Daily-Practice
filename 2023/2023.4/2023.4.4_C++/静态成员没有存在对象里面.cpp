class Person
{
	int a;//只有非静态成员变量，存在类里

	static int A;//静态成员变量，没有存在类里
	void func1()//非静态成员函数，没有存在类里
	{
	}
	static void func()//静态成员函数，没有存在类里
	{
	}
};
int Person::A;
int main()
{
	Person p;//如果p是空对象，内存大小就是1
	cout << "Person的内存大小：" << sizeof(p) << endl;
	system("pause");
	return 0;
}