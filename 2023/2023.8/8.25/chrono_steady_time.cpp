#include <iostream>
#include <chrono>
using namespace std;

int main() {
	//静态成员函数chrono::steady_clock::now()获取开始时间
	chrono::steady_clock::time_point starttime = chrono::steady_clock::now();
	//auto starttime = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; i++) {
		//cout << "hello world" << endl;
	}
	//静态成员函数chrono::steady_clock::now()获取结束时间
	chrono::steady_clock::time_point endtime = chrono::steady_clock::now();
	//auto endtime = chrono::steady_clock::now();
	//计算消耗的时间，单位是纳秒
	auto duration1 = endtime - starttime;
	//chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endtime - starttime);
	cout << "耗时：" << duration1.count() << "纳秒(" << (double)duration1.count() / (1000 * 1000 * 1000) << "秒)" << endl;
}