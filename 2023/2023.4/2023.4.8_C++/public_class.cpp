class Animal
{
public:
	void Domain()
	{
		cout << "动物界" << endl;
	}
};
class Cat :public Animal//类的继承，只需要写出权限和类名
{
public:
	void Tanuki()
	{
		cout << "狸猫" << endl;
	}
};
class Dog :public Animal
{
public:
	void Sheepdog()
	{
		cout << "牧羊犬" << endl;
	}
};
void test1()
{
	Cat c1;
	c1.Domain();//就可以在新的类里，直接调用继承的成员
	c1.Tanuki();
	cout << "-----------------------------" << endl;
	Dog d1;
	d1.Domain();
	d1.Sheepdog();
}
int main()
{
	test1();
	system("pause");
	return 0;
}