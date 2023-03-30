void func()
{
	cout << "空" << endl;
}
void func(int a)
{
	cout << "int" << endl;
}
void func(double b)
{
	cout << "double" << endl;
}
void func(double b,int a)
{
	cout << "d,i" << endl;
}
void func(int a,double b)
{
	cout << "i,d" << endl;
}
int main()//函数重载条件：同一作用域；同名；函数参数类型不同，或参数个数不同；或参数顺序不同
{
	func();
	func(10);
	func(3.14);
	func(3.14,10);
	func(10,3.14);
	return 0;
}