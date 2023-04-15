class Person
{
public:
	Person(int age,string name)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	int m_Age;
	string m_Name;
};
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}
//具体化函数模板，需要加上template<>空模板，优先于常规模板;对于Person这种非内置的数据类型，不能使用普通模板比较
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age && p1.m_Name == p2.m_Name)
		return true;
	else
		return false;
}
void test1()
{
	Person p1(20, "张三");
	Person p2(20, "张三");
	bool ret = myCompare(p1, p2);
	if (ret)
		cout << "相等" << endl;
	else
		cout << "不相等" << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}