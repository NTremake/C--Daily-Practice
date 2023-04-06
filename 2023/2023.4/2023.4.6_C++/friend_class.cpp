class Building
{
	friend class Friend;//类作为友元
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};
class Friend
{
public:
	Friend();
	void visit();
	Building* b;
};
Friend::Friend()//将成员属性写在类外
{
	b = new Building;
}
Building::Building()//将成员函数写在类外
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
void Friend::visit()//将成员函数写在类外
{
	cout << "正在访问：" << b->m_SittingRoom << endl;
	cout << "正在访问：" << b->m_BedRoom << endl;
}
void test1()
{
	Friend f;
	f.visit();
}
int main()
{
	test1();
	system("pause");
	return 0;
}