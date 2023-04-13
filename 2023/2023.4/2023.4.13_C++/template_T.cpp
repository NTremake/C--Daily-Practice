template<typename T>//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是通用数据类型
void Swap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 1;
	int b = 2;
	Swap(a,b);//方式一，自动类型推导，让编译器自动识别数据类型
	Swap<int>(a, b);//方式二，显示指定类型，直接告诉编译器实参的数据类型
	cout << a << endl;
	cout << b << endl;
	system("pause");
	return 0;
}