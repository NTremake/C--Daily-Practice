int main()
{
	int a = 10;
	int& b = a;//&引用符，使a增加一个名字，不能再次修改别名
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b = 100;//修改b时，a也会被修改
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}
--------------------------------------
void Swap(int& a, int& b)//引用操作符，也可以用形参修改实参
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);//&引用本质上是指针常量
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}