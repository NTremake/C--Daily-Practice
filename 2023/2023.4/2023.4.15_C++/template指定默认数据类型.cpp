template<class NameType,class AgeType = int>//给成员属性声明不同的数据类型
class Person//类模板
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showInfo()
	{
		cout << "姓名：" << this->m_Name << "   年龄：" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
void test1()
{
	Person<string> p1("张三", 22);//类模板一般是需要指定数据类型的，在声明类模板时，可以有默认数据类型，传参时就能不用指定数据类型
	p1.showInfo();
}
int main()
{
	test1();
	system("pause");
	return 0;
}