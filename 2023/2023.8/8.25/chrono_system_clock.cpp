#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
	chrono::hours t1(1);
	chrono::minutes t2(60);
	chrono::seconds t3(60 * 60);
	chrono::milliseconds t4(60 * 60 * 1000);// ����
	//chrono::microseconds t5(60 * 60 * 1000 * 1000);// ΢��
	//chrono::nanoseconds t6(60 * 60 * 1000 * 1000 * 1000);// ����

	if (t1 == t2) {
		cout << "t1 == t2" << endl;
	}
	if (t1 == t3) {
		cout << "t1 == t3" << endl;
	}
	if (t1 == t4) {
		cout << "t1 == t4" << endl;
	}
	cout << "t1=" << t1.count() << endl;
	cout << "t2=" << t2.count() << endl;
	cout << "t3=" << t3.count() << endl;
	cout << "t4=" << t4.count() << endl;
	cout << "--------------------------" << endl;
	// 1)��̬��Ա����chrono::system_clock::now()���ص�ǰϵͳʱ�䡣(C++ʱ��)
	chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
	//auto now = chrono::system_clock::now();
	// 2)��̬��Ա����chrono::system_clock::to_time_t()��ʱ���ת��Ϊtime_t���͡�(utcʱ��)
	time_t t_now = chrono::system_clock::to_time_t(now);
	//auto t_now = chrono::system_clock::to_time_t(now);
	
	// ʱ��ƫ��
	//t_now += 60 * 60 * 24;// ����һ��
	//t_now -= 60 * 60 * 1;// ����һСʱ
	t_now += 180;// ����3����

	// 3)��̬��Ա����localtime()��time_t����ת��Ϊtm���͡�(����ʱ��)>VS����localtime_s����ȫ
	tm* tm_now = localtime(&t_now);
	// 4)��ʽ���������ʱ�䡣
	cout << put_time(tm_now, "%Y-%m-%d %H:%M:%S") << endl;
	cout << put_time(tm_now, "%Y-%m-%d") << endl;
	cout << put_time(tm_now, "%H:%M:%S") << endl;
	cout << put_time(tm_now, "%Y%m%d%H%M%S") << endl;
	cout << "---------------------------" << endl;
	// ���Խ�ʱ��ת��Ϊstring���ͣ�����������
	stringstream ss;// ����stringstream����,��Ҫͷ�ļ�<sstream>
	ss << put_time(tm_now, "%Y-%m-%d %H:%M:%S");// ��tm����ת��Ϊstring����
	string timestr = ss.str();// ��stringstream����ת��Ϊstring����
	cout << timestr << endl;
}