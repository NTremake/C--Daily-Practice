struct Student
{
	string name;
	int age;
	int score;
};
struct teacher
{
	int id;
	string name;
	int age;
	struct Student s1;//直接写出结构体变量名称
};
int main()//结构体嵌套
{
	struct teacher t1;
		t1.name = "张三";
		t1.id = 666;
		t1.age = 36;
		t1.s1.name = "李四";
		t1.s1.age = 18;
		t1.s1.score = 98;

	cout << t1.name << "  " << t1.s1.name;
struct Student* p = &t1.s1;//利用指针打印嵌套下的结构体
	cout << p->age;
	return 0;
}