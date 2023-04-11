class animal
{
public:
	animal()
	{
		cout << "animal构造函数调用" << endl;
	}
	virtual ~animal() = 0;//利用虚析构，可以解决父类指针释放子类对象不干净的问题。
	/*{cout << "animal析构函数调用" << endl;}*/
	virtual void speak() = 0;
};
animal::~animal()
{
	cout << "animal析构函数调用" << endl;//纯虚析构，有了纯虚析构之后，这个类也属于抽象类，无法实例化
}
class cat :public animal
{
public:
	cat(string name)
	{
		cout << "cat构造函数调用" << endl;
		m_Name = new string(name);
	}
	void speak()
	{
		cout << *m_Name << "小猫说话" << endl;
	}
	~cat()
	{
		if (m_Name != NULL)
		{
			cout << "cat析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string *m_Name;
};
void test1()//如果子类没有堆区数据，就没必要写虚析构了
{
	animal* a = new cat("Tom");
	a->speak();
	delete a;
}
int main()
{
	test1();
	system("pause");
	return 0;
}