#include <iostream>
#include <chrono>
using namespace std;

int main() {
	//��̬��Ա����chrono::steady_clock::now()��ȡ��ʼʱ��
	chrono::steady_clock::time_point starttime = chrono::steady_clock::now();
	//auto starttime = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; i++) {
		//cout << "hello world" << endl;
	}
	//��̬��Ա����chrono::steady_clock::now()��ȡ����ʱ��
	chrono::steady_clock::time_point endtime = chrono::steady_clock::now();
	//auto endtime = chrono::steady_clock::now();
	//�������ĵ�ʱ�䣬��λ������
	auto duration1 = endtime - starttime;
	//chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endtime - starttime);
	cout << "��ʱ��" << duration1.count() << "����(" << (double)duration1.count() / (1000 * 1000 * 1000) << "��)" << endl;
}