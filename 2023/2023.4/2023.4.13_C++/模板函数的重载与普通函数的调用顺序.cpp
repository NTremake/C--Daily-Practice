void add1(int a, int b)
{
	cout << "普通函数的调用" << endl;
}
template<class T>
void add1(T a,int b)
{
	cout << "函数模板的调用" << endl;
}
template<class T>
void add1(T a, T b, T c)//函数模板可以重载
{
	cout << "重载函数模板的调用" << endl;
}
void test1()
{
	int a = 10;
	int b = 20;
	add1(a, b);//同名函数，优先调用普通函数
	add1<>(a, b);//用空参数，可以调用函数模板
	add1(a, b, 1);
	char c = 'c';
	char d = 'd';
	add1(c, d);//普通函数会先转换成int类型，所有模板函数匹配度更好
}
int main()
{
	test1();
	system("pause");
	return 0;
}