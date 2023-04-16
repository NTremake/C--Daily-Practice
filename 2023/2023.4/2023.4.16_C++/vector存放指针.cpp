class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test1()
{
	vector<Person* > v1;//可以存放各种数据，包括指针
	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	Person p5("刘七", 50);
	v1.push_back(&p1);//存放指针需要引用
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);
	v1.push_back(&p5);
	/*for (vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "   年龄：" << it->m_Age << endl;
	}*/
	for (vector<Person* >::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name << "   年龄：" << (*it)->m_Age << endl;
	}//指针的效率更高
}
int main()
{
	test1();
	system("pause");
	return 0;
}