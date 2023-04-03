class Phone
{
public:
	Phone(string pName):myPname(pName)
	{
		cout << "Phone的构造函数" << endl;
	}
	~Phone()
	{
		cout << "Phone的析构函数" << endl;
	}
	string myPname;
};
class Person
{
public:
	Person(string name,string pName) :myname(name),myphone(pName)//等价于Phone(pName)
	{
		cout << "Person的构造函数" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数" << endl;
	}
	string myname;
	Phone myphone;
};
void test1()
{
	Person p1("张三", "手机");
	cout << p1.myname << "   " << p1.myphone.myPname << endl;
}
int main()//类嵌套时，先调用子类的构造函数；释放内存时，先释放父类(栈，先入后出)
{
	test1();
	system("pause");
	return 0;
}