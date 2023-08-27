#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;// 互斥锁
void func1(const int num, const string& str) {
	for (int i = 0; i < 10; i++) {
		//mtx.lock();// 加锁，防止多个线程同时访问cout
		lock_guard<mutex> lock(mtx);// 在构造函数中加锁，在析构函数中解锁
		cout << num << "号第" << i << "次表白：" << str << endl;
		//mtx.unlock();// 解锁
		this_thread::sleep_for(chrono::milliseconds(300));
	}
}
int a = 0;
void add1() {
	for (int i = 0; i < 100000; i++) {
		//mtx.lock();
		lock_guard<mutex> lock(mtx);
		a++;
		//mtx.unlock();
	}
}
// 互斥锁mutex;lock_guard类，简化了加锁和解锁的操作
int main() {
	thread t1(func1, 1, "我爱你");
	thread t2(func1, 2, "我也爱你");
	thread t3(func1, 3, "我还爱你");
	thread t4(add1);
	thread t5(add1);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	cout << "a=" << a << endl;
}