#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> a = 0;// ԭ�����ͣ����Խ�����̵߳����⣬����Ҫ������
//atomic_int a = 0;// ԭ������
//int a = 0;
//atomic<int*> ptr = &a;// ָ����ԭ�����ͣ�������ָ��Ķ�����ԭ������
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