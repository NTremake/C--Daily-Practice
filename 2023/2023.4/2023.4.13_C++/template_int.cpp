template<class T>
T add1(T a,int b)
{
	return a + b;
}
void test1()
{
	int a = 10;
	char c = 'c';
	cout << add1<int>(a, c) << endl;//模板建议都指定转换的数据类型，不然一些编译器可能报错
}
int main()
{
	test1();
	system("pause");
	return 0;
}