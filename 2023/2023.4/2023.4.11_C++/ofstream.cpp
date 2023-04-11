void test1()//写文件
{
	//1、创建头文件<fstream>
	ofstream ofs;//2、创建流对象
	ofs.open("test.txt", ios::out);//3、路径或者文件名；指定打开方式
	ofs << "姓名：张三" << endl;//4、写内容
	ofs << "性别：男" << endl;
	ofs << "年龄：21" << endl;
	ofs.close();//5、关闭文件
}
int main()
{
	test1();
	system("pause");
	return 0;
}