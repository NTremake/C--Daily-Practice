#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void thread_func1(int num, const string& str) {
	for (int i = 0; i < 10; i++) {
		cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
		Sleep(500);
	}
}
int main() {
	thread t1(thread_func1, 1, "�Ұ���");
	//thread t2(thread_func1, 2, "��Ҳ����");

	t1.detach();// �������߳�,֮��Ͳ�����join()���߳���
	//t2.detach();

	//������߳��Ѿ�����(join)���߷���(detach)��������
	if (t1.joinable()) {
		t1.join();
	}

	//t1.join();// �����߳���Դ
	//t2.join();
	Sleep(8000);
}