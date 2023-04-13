template<class T>
void Swap(T& a,T& b){
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void func(){
	cout << "func函数的调用" << endl;
}
void test1(){
	func<int>();//对面没有使用数据类型的函数模板，手动声明一个数据类型，才能调用函数
}
int main(){
	int a = 1;
	int b = 2;
	char c = 'a';
	/*Swap(a, c);*///数据不一致时，不能自动推导
	test1();
	cout << a << endl;
	cout << b << endl;
	system("pause");
	return 0;
}