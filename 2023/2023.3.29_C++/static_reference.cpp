int& test()
{
	static int a = 10;//静态变量在全局区开辟，程序结束时才会由系统释放
	return a;
}
int main()
{
	int& b = test();
	cout << "b=" << b << endl;
	cout << "b=" << b << endl;
	test() = 20;//引用类型的函数，可以直接作为左值
	cout << "b=" << b << endl;
	return 0;
}
---------------------------------------
int main()
{
	const int& b = 10;//常量引用，b不能被修改。int& b=10是错误的
	return 0;
}