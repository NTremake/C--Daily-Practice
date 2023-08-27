#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class AA {
public:
	recursive_mutex m_mtx;// 递归锁
	void func1() {
		m_mtx.lock();
		cout << "调用了func1()" << endl;
		m_mtx.unlock();
	}
	void func2() {
		m_mtx.lock();
		cout << "调用了func2()" << endl;
		func1();// 递归调用,如果不是递归锁，这里会死锁
		m_mtx.unlock();
	}
};// recursive_mutex递归锁
int main() {
	AA a;
	a.func1();
	a.func2();
}