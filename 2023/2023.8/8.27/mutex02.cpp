#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class AA {
public:
	recursive_mutex m_mtx;// �ݹ���
	void func1() {
		m_mtx.lock();
		cout << "������func1()" << endl;
		m_mtx.unlock();
	}
	void func2() {
		m_mtx.lock();
		cout << "������func2()" << endl;
		func1();// �ݹ����,������ǵݹ��������������
		m_mtx.unlock();
	}
};// recursive_mutex�ݹ���
int main() {
	AA a;
	a.func1();
	a.func2();
}