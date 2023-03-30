struct Student
{
	string name;
	int score;
};
struct Teacher
{
	string name;
	struct Student s1[5];
};
void allocatespace(struct Teacher t1[3], int len )
{
	string nameSeed = "ABCDEF";
	for (int i = 0; i < 3; i++)
	{
		t1[i].name = "teacher_";
		t1[i].name += nameSeed[i];//teacher_后面加上nameSeed的字符
		for (int j = 0; j < 5; j++)
		{
			t1[i].s1[j].name = "student_";
			t1[i].s1[j].name += nameSeed[j];
			int random = rand() % 41 + 60;
			t1[i].s1[j].score = random;
		}
	}
}
void printfInfo(struct Teacher t1[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "老师姓名：" << t1[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << t1[i].s1[j].name 
				<< "  学生成绩：" << t1[i].s1[j].score << endl;
		}
	}
}
int main()//结构体数组的嵌套和生成
{
	srand((unsigned int)time(NULL));
	struct Teacher t1[3] = {};
	int len = sizeof(t1) / sizeof(t1[0]);
	allocatespace(t1, len);
	printfInfo(t1);
	return 0;
}