#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> a = 0;// 原子类型，可以解决多线程的问题，不需要互斥锁
//atomic_int a = 0;// 原子整数
//int a = 0;
//atomic<int*> ptr = &a;// 指针是原子类型，不代表指针的对象是原子类型
void func1() 
{
	for (int i = 0; i < 100000; ++i)
	{
		++a;
	}
}
int main()
{
	thread t1(func1);
	thread t2(func1);

	t1.join();
	t2.join();
	cout << "a=" << a << endl;
}