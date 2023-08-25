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
	chrono::milliseconds t4(60 * 60 * 1000);// 毫秒
	//chrono::microseconds t5(60 * 60 * 1000 * 1000);// 微秒
	//chrono::nanoseconds t6(60 * 60 * 1000 * 1000 * 1000);// 纳秒

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
	// 1)静态成员函数chrono::system_clock::now()返回当前系统时间。(C++时间)
	chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
	//auto now = chrono::system_clock::now();
	// 2)静态成员函数chrono::system_clock::to_time_t()将时间点转换为time_t类型。(utc时间)
	time_t t_now = chrono::system_clock::to_time_t(now);
	//auto t_now = chrono::system_clock::to_time_t(now);
	
	// 时间偏移
	//t_now += 60 * 60 * 24;// 增加一天
	//t_now -= 60 * 60 * 1;// 减少一小时
	t_now += 180;// 增加3分钟

	// 3)静态成员函数localtime()将time_t类型转换为tm类型。(本地时间)>VS觉得localtime_s更安全
	tm* tm_now = localtime(&t_now);
	// 4)格式化输出本地时间。
	cout << put_time(tm_now, "%Y-%m-%d %H:%M:%S") << endl;
	cout << put_time(tm_now, "%Y-%m-%d") << endl;
	cout << put_time(tm_now, "%H:%M:%S") << endl;
	cout << put_time(tm_now, "%Y%m%d%H%M%S") << endl;
	cout << "---------------------------" << endl;
	// 可以将时间转换为string类型，做其他操作
	stringstream ss;// 创建stringstream对象,需要头文件<sstream>
	ss << put_time(tm_now, "%Y-%m-%d %H:%M:%S");// 将tm类型转换为string类型
	string timestr = ss.str();// 将stringstream对象转换为string类型
	cout << timestr << endl;
}