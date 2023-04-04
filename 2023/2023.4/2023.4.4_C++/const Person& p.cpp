class Person
{
public:
	Person(int age)
	{
		this->age = age;//this指针，是地址，能指向对象本身的属性，以避免参数重名的问题
	}
	Person& PersonAddAge(const Person& p)//Person&返回的是引用，如果只是Person的话，就会被识别成拷贝构造函数，而拷贝会创建新的对象，返回值就不是p2
	{
		this->age += p.age;
		return *this;
	}
	int age;
};
void test1()//this指针，指向的是对象本身
{
	Person p1(10);
	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//此函数返回值是p2对象本身，所有后面能一直重复调用addage函数（链式函数思想）
	cout << p2.age << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}