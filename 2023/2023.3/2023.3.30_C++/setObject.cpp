class Student
{
public:
	string name;
	int ID;
	void showStu()
	{
		cout << "姓名：" << name << "   学号：" << ID << endl;
	}
	void setName(string sname)
	{
		name = sname;
	}
	void setID(int sid)
	{
		ID = sid;
	}
};
int main()//类的函数也可以修改自己属性
{
	Student s1;
	s1.setName("张三");
	s1.setID(1);
	s1.showStu();
	Student s2;
	s2.setName("李四");
	s2.setID(2);
	s2.showStu();
	return 0;
}