class A
{
public:
	int age;
};
class B1 :virtual public A//继承时添加virtual，虚基指针，父类A变为虚基类
{
public:};
class B2 :virtual public A
{
public:};
class C :public B1,public B2//这种虚继承是为父类A创建一个虚基指针，就之继承同一份，避免同时继承B1和B2，造成资源浪费
{
public:};
void test1()//菱形继承
{
	C a1;
	a1.B1::age = 20;
	a1.B2::age = 18;
	cout << a1.B1::age << endl;
	cout << a1.B2::age << endl;
	cout << a1.age << endl;//继承后的元素都指向同一个地址
}
int main(){
	test1();
	system("pause");
	return 0;
}