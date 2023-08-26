#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void thread_func1(int num, const string& str) {
	for (int i = 0; i < 10; i++) {
		cout << num << "号第" << i << "次表白：" << str << endl;
		Sleep(500);
	}
}
class ThreadFunc2 {
public:
	void operator()(int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "号第" << i << "次表白：" << str << endl;
			Sleep(500);
		}
	}
};
class ThreadFunc3 {
public:
	static void func1(int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "号第" << i << "次表白：" << str << endl;
			Sleep(500);
		}
	}
	void func2(int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "号第" << i << "次表白：" << str << endl;
			Sleep(500);
		}
	}
};
// 线程没有拷贝构造函数，只有移动构造，原来的线程对象会失效
// thread t1(thread&& other);
// 赋值函数也不能转移左值，只能转移右值：thread& operator=(thread&& other);
int main() {
	//thread t1(thread_func1, 1, "我爱你");
	//thread t2(thread_func1, 2, "我也爱你");
	auto func1 = [](int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "号第" << i << "次表白：" << str << endl;
			Sleep(500);
		}
	};
	//thread t3(func1, 3, "纯牛马");// 使用lambda表达式做线程函数
	//thread t4(ThreadFunc2(), 4, "纯牛马");// 使用仿函数做线程函数
	thread t5(ThreadFunc3::func1, 5, "纯牛马");// 使用静态成员函数做线程函数
	ThreadFunc3 tf6;
	thread t6(&ThreadFunc3::func2, &tf6, 6, "纯牛马");// 使用普通成员函数做线程函数

	for (int ii = 0; ii < 10; ii++) {
		cout << "main thread:" << ii << endl;
		Sleep(500);
	}

	//t1.join();// 等待子线程完成，然后回收线程资源；连接线程
	//t2.join();
	//t3.join();
	//t4.join();
	t5.join();
	t6.join();
}