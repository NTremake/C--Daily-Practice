#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// lambda函数
int main() {
	int a = 3;
	double b = 4.2;
	/*auto func1 = [a, b](const int& num) {
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "参数为：" << num << endl;
		};*/
	// []里可以填引用,就是引用捕获；=号就是值捕获；
	auto func1 = [&](const int& num) {
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "参数为：" << num << endl;
		};
	func1(1);
	// 也可以分类捕获
	auto func2 = [=, &b](const int& num) {
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "参数为：" << num << endl;
		};
	func2(2);
	auto show = [](const int& num) {
		cout << "数字：" << num << endl;
		};
	vector<int> v1 = { 1,2,3,4,5 };
	for_each(v1.begin(), v1.end(), show);
}