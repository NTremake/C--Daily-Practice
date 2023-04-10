class AbstractDrinking
{
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void putinCup() = 0;
	virtual void putSomething() = 0;
	void makeDrink()
	{
		Boil();
		Brew();
		putinCup();
		putSomething();
	}
};
class Coffee :public AbstractDrinking
{
public:
	void Boil(){
		cout << "烧水" << endl;
	}
	void Brew(){
		cout << "冲泡咖啡" << endl;
	}
	void putinCup(){
		cout << "倒入杯中" << endl;
	}
	void putSomething(){
		cout << "加入糖和牛奶" << endl;
	}
};
class Tea :public AbstractDrinking
{
public:
	void Boil(){
		cout << "烧水" << endl;
	}
	void Brew(){
		cout << "沏茶" << endl;
	}
	void putinCup(){
		cout << "倒入杯中" << endl;
	}
	void putSomething(){
		cout << "加入枸杞" << endl;
	}
};
void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}
void test1()//利用多态，创建制作各种饮品的行为
{
	doWork(new Coffee);
	cout << "----------------------" << endl;
	doWork(new Tea);
}
int main()
{
	test1();
	system("pause");
	return 0;
}