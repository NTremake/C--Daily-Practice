class Person1
{
public:
	void showPerson1(){ cout << "Person1的调用" << endl; }
};
class Person2
{
public:
	void showPerson2(){ cout << "Person2的调用" << endl; }
};

template<class T>
class Person
{
public:
	T obj;
	void func1(){ obj.showPerson1(); }//类模板成员函数不是在一开始就创建，调用时才创建
	void func2(){ obj.showPerson2(); }
};
void test1()
{
	Person<Person1> p;
	p.func1();
	Person<Person2> p1;
	p1.func2();
}
int main()
{
	test1();
	system("pause");
	return 0;
}