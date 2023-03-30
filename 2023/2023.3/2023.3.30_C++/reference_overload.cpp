void func(int& a)//int& a=10错误,所以被func(a)调用
{
	cout << "空" << endl;
}
void func(const int& a)//const int& a=10正确
{
	cout << "const" << endl;
}
int main()
{
	int a = 10;
	func(a);
	func(10);
	return 0;
}