class base
{
public:
//只要有一个纯虚函数就是抽象类。抽象类特点：1、无法实例化。 2、抽象类的子类，必须重写父类的纯虚函数，否则也是抽象类
	virtual int getResult() = 0;//纯虚函数
};
class son :public base
{
public:
	int getResult(){}
};
void test1()
{
	/*base b;//抽象类不能实例化
	new base;*/
	son s;//子类必须重写父类的纯虚函数，否则不能实例化
}
int main()
{
	test1();
	system("pause");
	return 0;
}