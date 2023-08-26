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
class ThreadFunc2 {
public:
	void operator()(int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
			Sleep(500);
		}
	}
};
class ThreadFunc3 {
public:
	static void func1(int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
			Sleep(500);
		}
	}
	void func2(int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
			Sleep(500);
		}
	}
};
// �߳�û�п������캯����ֻ���ƶ����죬ԭ�����̶߳����ʧЧ
// thread t1(thread&& other);
// ��ֵ����Ҳ����ת����ֵ��ֻ��ת����ֵ��thread& operator=(thread&& other);
int main() {
	//thread t1(thread_func1, 1, "�Ұ���");
	//thread t2(thread_func1, 2, "��Ҳ����");
	auto func1 = [](int num, const string& str) {
		for (int i = 0; i < 10; i++) {
			cout << num << "�ŵ�" << i << "�α�ף�" << str << endl;
			Sleep(500);
		}
	};
	//thread t3(func1, 3, "��ţ��");// ʹ��lambda���ʽ���̺߳���
	//thread t4(ThreadFunc2(), 4, "��ţ��");// ʹ�÷º������̺߳���
	thread t5(ThreadFunc3::func1, 5, "��ţ��");// ʹ�þ�̬��Ա�������̺߳���
	ThreadFunc3 tf6;
	thread t6(&ThreadFunc3::func2, &tf6, 6, "��ţ��");// ʹ����ͨ��Ա�������̺߳���

	for (int ii = 0; ii < 10; ii++) {
		cout << "main thread:" << ii << endl;
		Sleep(500);
	}

	//t1.join();// �ȴ����߳���ɣ�Ȼ������߳���Դ�������߳�
	//t2.join();
	//t3.join();
	//t4.join();
	t5.join();
	t6.join();
}