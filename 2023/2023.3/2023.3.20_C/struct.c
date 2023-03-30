int main()
{
	int a = 10;
	int* p = &a;//把a的地址存在变量p里面，p就是指针变量；指针的类型（int）要和指向变量的类型相同
	*p = 20;//*是解引用操作符，可以修改地址p里面的值；*p就是变量a，p是a的地址
	printf("%d\n", a);
	return 0;
  }
---------------------------------
struct Book//创建结构体类型
{
	char name[20];//定义书名类型，括号里是数组长度
	short price;//定义价格类型
 };

int main()
{
	struct Book B1 = { "C语言程序设计",55 };//利用结构体类型创建变量
	printf("书名：%s\n", B1.name);//.（点）是获取结构体变量中，某个数据的运算符
	printf("价格：%d元\n", B1.price);//指针地址->price，也可以打印
	strcpy(B1.name, "C++ Primer Plus");//strcpy--string copy--字符串拷贝--库函数--需要string.h。因为name类型是数组，所有需要strcpy函数来修改。先是拷贝的目的地，再是拷贝的内容
	B1.price = 39;//可以直接修改结构体变量
	printf("新书名：%s\n", B1.name);
	printf("甩卖价格：%d元\n", B1.price);
	return 0;
  }
--------------------------------
struct Book
{
	char name[20];
	short price;
 };

int main()
{
	struct Book B1 = { "C语言程序设计",55 };
	struct Book* pb = &B1;//结构体变量也可以用指针获取
	printf("%s\n", (*pb).name);
	printf("%d\n", (*pb).price);
	return 0;
  }
-------------------------------
int main()//结构体的创建
{
	struct Book B1 = { "C语言程序设计",55 };
	struct Book* pb = &B1;
	printf("%s\n", pb->name);//->直接指向结构体变量中的数据，不需要解引用操作符*
	printf("%d\n", pb->price);
	return 0;
  }
--------------------------------------
typedef struct Student//typedef重命名结构体声明
{
	char name[20];
	char sex[5];
	short age;
	char tele[12];
}Stu;//"struct Student"改成"Stu"

struct t
{
	Stu s;//结构体可以嵌套结构体
	char a[10];
	char* p;
};
void printf1(Stu* ps)
{
	printf("%s\n", ps->name);
	printf("%s\n", ps->sex);
	printf("%d\n", ps->age);
	printf("%s\n", ps->tele);
}
int main()
{
	Stu s1= { "阿伟","男",21,"666"};
	struct t t1 = { {"张三","保密",30,"1234"},"hehe",NULL };

	printf1(&s1);//传参给函数的情况下，通过指针打印时空效益都更优
	Stu* ps = &s1;
	printf("%s\n", ps->name);//不能用*ps.name打印

	printf("%s\n", t1.a);
	printf("%d\n", t1.s.age);
	return 0;
}