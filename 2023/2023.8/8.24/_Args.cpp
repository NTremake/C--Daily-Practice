#include <iostream>
using namespace std;

void print() {
	cout << "递归结束" << endl;
}
template <typename T, typename ...Args>
void print(T arg, Args... args) {
	cout << "参数：" << arg << endl;
	//cout << "还有" << sizeof...(args) << "个参数未展开" << endl;// sizeof...()计算剩余参数
	print(args...);
}// 可变参数模板，可以传递多个不同参数，递归
template <typename ...Args>
void func(const string& str, Args... args) {
	cout << str << endl;
	print(args...);
	cout << "表白结束" << endl;
}// 可变参数模板也可以调用其他函数模板
int main() {
	//print("张三", 20, "李四", 21);
	func("我是帅哥", 6, "我喜欢你", 6, "真的");
}