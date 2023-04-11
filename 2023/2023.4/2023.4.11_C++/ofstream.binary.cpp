class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test1()
{
	ofstream ofs;//以二进制形式写文件
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = {"张三", 18};
	ofs.write((const char*)&p, sizeof(Person));//写文件，地址，大小
	ofs.close();
}
int main()
{
	test1();
	system("pause");
	return 0;
}