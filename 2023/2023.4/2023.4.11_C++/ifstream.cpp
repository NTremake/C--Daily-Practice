void test1()//读文件
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())//判断文件是否能正确打开
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//char buf1[1024] = { 0 };//方式一
	//while (ifs >> buf1)//把文件内容放进数组
	//{
	//	cout << buf1 << endl;
	//}
	//char buf2[1024] = { 0 };//方式二
	//while (ifs.getline(buf2, sizeof(buf2)))
	//{
	//	cout << buf2 << endl;
	//}
	string buf3;//方式三
	while (getline(ifs, buf3))
	{
		cout << buf3 << endl;
	}
	//char c;//方式四，不推荐
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}
	ifs.close();
}
int main()
{
	test1();
	system("pause");
	return 0;
}