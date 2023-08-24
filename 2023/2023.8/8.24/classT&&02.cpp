#include <iostream>
using namespace std;

void func1(int& a) {
	cout << "左值引用：" << a << endl;
}
void func1(int&& a) {
	cout << "右值引用：" << a << endl;
}
template <typename TT>
void func(TT&& a) {
	func1(forward<TT>(a));
}// 完美转发，能保持左值和右值再传递过程中保持不变
int main() {
	int a = 3;
	func1(a);
	func1(3);
	func(a);
	func(3);
}