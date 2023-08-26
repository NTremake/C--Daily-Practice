#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void once_func(const int num, const string& str) {
	cout << "once_func():" << num << str << endl;
}
once_flag flag;// 用于标记某个函数只能被子线程调用一次，本质是取值为0或1的锁
void thread_func1(int num, const string& str) {
	call_once(flag, once_func, 0, "纯牛马");
	for (int i = 0; i < 10; i++) {
		cout << num << "号第" << i << "次表白：" << str << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}
// call_once()保证某个函数只能被子线程调用一次
int main() {
	thread t1(thread_func1, 1, "我爱你");
	thread t2(thread_func1, 2, "我也爱你");

	t1.join();
	t2.join();
}