class Building//全局函数做友元
{
	friend void PrivateVisit(Building* b);//函数前面加friend在类里声明
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};
void PrivateVisit(Building* b)
{
	cout << "正在访问：" << b->m_SittingRoom << endl;
	cout << "正在访问：" << b->m_BedRoom << endl;//友元函数能够访问私有成员
}
void test1()
{
	Building b;
	PrivateVisit(&b);
}
int main()
{
	test1();
	system("pause");
	return 0;
}