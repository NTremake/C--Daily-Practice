#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void func1(const int num, const string& str) {
	for (int i = 0; i < 10; i++) {
		cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
		this_thread::sleep_for(chrono::milliseconds(700));
	}
}

int main() {
	thread t1(func1, 1, "�Ұ���");

	this_thread::sleep_for(chrono::seconds(4));
	thread::native_handle_type handle1= t1.native_handle();

	cout << "t1��handle:" << handle1 << endl;
	TerminateThread(handle1, 0);// ǿ����ֹ�߳�,���Ƽ�ʹ��;ͷ�ļ���<Windows.h>

	t1.join();
}