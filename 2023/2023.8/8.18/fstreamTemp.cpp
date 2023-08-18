#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int main() {
	string path = "D:\\AAcode\\C++\\Project1_test\\Project1_test\\test.txt";
	ifstream ifs(path, ios::in);
	//for (int i = 0; i < 100; ++i) {
	//	ofs << "12345\n";
	//	ofs << "12345" << endl;// endl也能刷新缓冲区
	//	ofs.flush();// 刷新缓冲区
	//	Sleep(100);
	//}
	string buffer;
	while (getline(ifs, buffer)) {
		cout << "eofbit：" << ifs.eof() << "  failbit：" << ifs.fail() << "  badbit：" << ifs.bad() << "  goodbit：" << ifs.good() << endl;
		cout << buffer << endl;
	}
	cout << "eofbit：" << ifs.eof() << "  failbit：" << ifs.fail() << "  badbit：" << ifs.bad() << "  goodbit：" << ifs.good() << endl;
	ifs.close();
}