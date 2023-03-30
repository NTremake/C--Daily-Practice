class Person
{
public://公共，类内和内外都可以访问
	string name="张三";
protected://保护，类内可以，类外不行；子级可以访问
	string car="奥迪";
private://私有，类内可以，类外不行；子级也不能访问
	string passWord = "123456";
private://函数也能设置权限
	void func()
	{
		name = "张三";
		car = "奥迪";
		passWord = "123456";
	}
};
int main()
{
	Person p1;
	p1.name = "李四";//只有姓名能在类外访问
	return 0;
}