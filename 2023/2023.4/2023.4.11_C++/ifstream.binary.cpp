class Person{
public:
	char m_Name[64];
	int m_Age;
};
void test1(){
	ifstream ifs;
	ifs.open("person.txt", ios::out | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));//以二进制形式读文件
	cout << p.m_Name << "   " << p.m_Age << endl;
	ifs.close();
}
int main(){
	test1();
	system("pause");
	return 0;
}