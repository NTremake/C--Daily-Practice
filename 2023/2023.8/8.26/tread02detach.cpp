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
int main() {
	thread t1(thread_func1, 1, "我爱你");
	//thread t2(thread_func1, 2, "我也爱你");

	t1.detach();// 分离子线程,之后就不能再join()子线程了
	//t2.detach();

	//如果子线程已经连接(join)或者分离(detach)，返回真
	if (t1.joinable()) {
		t1.join();
	}

	//t1.join();// 回收线程资源
	//t2.join();
	Sleep(8000);
}