#include <iostream>
#include <initializer_list>
using namespace std;

// 1. initializer_list是一个类模板，定义在<initializer_list>中。
// 2. initializer_list中的元素永远是常量，不可修改。
// 作用是把所有参数统一为一个参数，然后传参
float Sum(initializer_list<float> il) {
	float total = 0;
	/*for (auto i : il) {
		total += i;
	}*/
	for (auto i = il.begin(); i != il.end(); ++i) {
		total += *i;
	}
	return total;
}// 统一初始化列表
int main() {
	//float a = Sum(1.1, 2.2, 3.3);// 错误
	float b = Sum({ 1.1, 2.2, 3.3 });
	cout << b << endl;
}