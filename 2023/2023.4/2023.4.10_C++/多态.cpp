class animal
{
public:
	//动态多态的条件：1、有继承关系。2、子类重写父类函数(函数名、返回值和参数完全一样)
	virtual void speak()//变成了虚函数指针，占4个字节
	{
		cout << "动物叫" << endl;
	}
};
class cat :public animal
{
	virtual void speak()//子类的virtual可写可不写
	{
		cout << "小猫叫" << endl;
	}
};
void dospeak(animal& a1)//cat继承的虚函数，执行dospeak时，传入的是谁就执行谁；父类的指针或引用，指向子类对象
{
	a1.speak();
}
void test1()
{
	cat c1;
	dospeak(c1);
	/*animal a1;
	dospeak(a1);*/
}
int main()
{
	test1();
	system("pause");
	return 0;
}