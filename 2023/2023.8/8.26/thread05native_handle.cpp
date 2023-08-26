#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void func1(const int num, const string& str) {
	for (int i = 0; i < 10; i++) {
		cout << num << "号第" << i << "次表白：" << str << endl;
		this_thread::sleep_for(chrono::milliseconds(700));
	}
}

int main() {
	thread t1(func1, 1, "我爱你");

	this_thread::sleep_for(chrono::seconds(4));
	thread::native_handle_type handle1= t1.native_handle();

	cout << "t1的handle:" << handle1 << endl;
	TerminateThread(handle1, 0);// 强制终止线程,不推荐使用;头文件是<Windows.h>

	t1.join();
}