template<class T>
class Base
{
public:
	T a;
};
class Son :public Base<int>//指定父类的通用数据类型为int
{
public:
};
template<class T1,class T2>
class Son1 :public Base<T2>//指定父类的通用数据类型为char
{
public:
	T1 obj;
};
void test1()//类模板的继承，子类必须指定通用数据的类型；可以看作函数参数，传入什么数据类型，就变成什么数据
{
	Son s1;
	Son1<int, char>s2;//指定模板的数据类型T1和T2分别为int、cahr
}
int main()
{
	test1();
	system("pause");
	return 0;
}