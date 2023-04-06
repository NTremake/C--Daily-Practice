class Building;
class Friend
{
public:
	Friend();
	void visit1();
	void visit2();
	Building* b;
};
class Building
{
	friend void Friend::visit1();//成员函数做友元
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Friend::Friend()
{
	b = new Building;
}
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
void Friend::visit1()
{
	cout << "正在访问：" << b->m_SittingRoom << endl;
	cout << "正在访问：" << b->m_BedRoom << endl;
}
void Friend::visit2()
{
	cout << "正在访问：" << b->m_SittingRoom << endl;//没有声明friend的成员函数就不能访问private成员
}
void test1()
{
	Friend f;
	f.visit1();
	f.visit2();
}
int main()
{
	test1();
	system("pause");
	return 0;
}