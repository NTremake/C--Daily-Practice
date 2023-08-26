#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void thread_func1(int num, const string& str) {
	cout << "子线程：" << this_thread::get_id() << endl;
	for (int i = 0; i < 10; i++) {
		cout << num << "号第" << i << "次表白：" << str << endl;
		Sleep(500);
	}
}
// get_id()获取线程在内存中的id;swap()交换线程;sleep_for()线程休眠
int main() {
	thread t1(thread_func1, 1, "我爱你");
	thread t2(thread_func1, 2, "我也爱你");

	cout << "主线程：" << this_thread::get_id() << endl;// get_id()获取线程在内存中的id
	cout << "t1的id:" << t1.get_id() << endl;
	cout << "t2的id:" << t2.get_id() << endl;
	t1.swap(t2);// 交换线程
	cout << "交换后t1的id:" << t1.get_id() << endl;
	cout << "交换后t2的id:" << t2.get_id() << endl;

	this_thread::sleep_for(chrono::seconds(6));// 线程休眠
	//Sleep(6000);
	t1.join();
	t2.join();
}