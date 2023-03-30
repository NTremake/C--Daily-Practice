int* func()
{
	int* p = new int(10);//new关键词使变量开辟在堆区，不会自动释放；new返回的是指针地址
	return p;
}
int main()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	delete p;//程序员根据地址释放变量的内存
	cout << *p << endl;//打印无效
	return 0;
}