class Person
{
public:
	string showName()//姓名有可读可写接口
	{
		return pName;
	}
	void setName(string name)
	{
		pName = name;
	}
	void setAge(int age)//写
	{
		if (age < 0 || age>150)
		{
			pAge = 0;
			cout << "年龄有误！" << "   ";
			return;
		}
		pAge = age;
	}
	int showAge()//读
	{
		return pAge;
	}
	int showSex()//只读接口
	{
		return pSex = 1;
	}
private://所有属性先设置为私有，再写公共的接口
	string pName;//可读可写
	int pAge;//可读可写
	int pSex;//只读
};
int main()//类的权限接口
{
	Person p1;
	p1.setName("张三");
	cout << p1.showName()<<"   ";
	p1.setAge(21);
	cout << p1.showAge()<<"   ";
	cout << p1.showSex() << endl;
	return 0;
}