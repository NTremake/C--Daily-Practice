void test()
{
	int* arr = new int[10];//new数组时用中括号
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		cout << arr[i] << "   ";
	}
	delete[] arr;//释放数组内存时，需要加上中括号，释放数组首地址即可
}
int main()
{
	test();
	return 0;
}