#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void thread_func1(int num, const string& str) {
	cout << "���̣߳�" << this_thread::get_id() << endl;
	for (int i = 0; i < 10; i++) {
		cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
		Sleep(500);
	}
}
// get_id()��ȡ�߳����ڴ��е�id;swap()�����߳�;sleep_for()�߳�����
int main() {
	thread t1(thread_func1, 1, "�Ұ���");
	thread t2(thread_func1, 2, "��Ҳ����");

	cout << "���̣߳�" << this_thread::get_id() << endl;// get_id()��ȡ�߳����ڴ��е�id
	cout << "t1��id:" << t1.get_id() << endl;
	cout << "t2��id:" << t2.get_id() << endl;
	t1.swap(t2);// �����߳�
	cout << "������t1��id:" << t1.get_id() << endl;
	cout << "������t2��id:" << t2.get_id() << endl;

	this_thread::sleep_for(chrono::seconds(6));// �߳�����
	//Sleep(6000);
	t1.join();
	t2.join();
}