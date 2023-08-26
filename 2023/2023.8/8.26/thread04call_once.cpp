#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void once_func(const int num, const string& str) {
	cout << "once_func():" << num << str << endl;
}
once_flag flag;// ���ڱ��ĳ������ֻ�ܱ����̵߳���һ�Σ�������ȡֵΪ0��1����
void thread_func1(int num, const string& str) {
	call_once(flag, once_func, 0, "��ţ��");
	for (int i = 0; i < 10; i++) {
		cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}
// call_once()��֤ĳ������ֻ�ܱ����̵߳���һ��
int main() {
	thread t1(thread_func1, 1, "�Ұ���");
	thread t2(thread_func1, 2, "��Ҳ����");

	t1.join();
	t2.join();
}