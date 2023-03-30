struct Student
{
	string name;
	int age;
	int score;
};
int main()//结构体数组
{
	struct Student stu[3] =
	{
		{"张三",19,99},
		{"李四",25,90},
		{"王五",32,92}
	};
	cout << stu[1].name << endl;
	stu[1].name = "赵六";
	cout << stu[1].name << endl;
	return 0;
}