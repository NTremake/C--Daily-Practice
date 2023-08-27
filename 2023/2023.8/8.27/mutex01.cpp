#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;// ������
void func1(const int num, const string& str) {
	for (int i = 0; i < 10; i++) {
		//mtx.lock();// ��������ֹ����߳�ͬʱ����cout
		lock_guard<mutex> lock(mtx);// �ڹ��캯���м����������������н���
		cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
		//mtx.unlock();// ����
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
// ������mutex;lock_guard�࣬���˼����ͽ����Ĳ���
int main() {
	thread t1(func1, 1, "�Ұ���");
	thread t2(func1, 2, "��Ҳ����");
	thread t3(func1, 3, "�һ�����");
	thread t4(add1);
	thread t5(add1);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	cout << "a=" << a << endl;
}