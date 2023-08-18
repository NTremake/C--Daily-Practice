#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// seekg()和seekp()的第一个参数是偏移量，第二个参数是偏移起始位置
int main() {
	string path = "D:\\AAcode\\C++\\Project1_test\\Project1_test\\test.txt";
	fstream ofs(path, ios::in | ios::out);
	for (int i = 0; i < 5; ++i) {
		ofs << "12345\n";
	}
	cout << "指针位置：" << ofs.tellp() << endl;
	ofs.seekg(3, ios::beg);// 从开始位置向后移动3个字节
	cout << "指针位置：" << ofs.tellg() << endl;
	string buffer;
	while (ofs >> buffer) {
		cout << buffer << endl;
	}
	ofs.close();
	ofstream fout(path, ios::out);
	fout << "12345\n12345\n12345\n12345\n12345\n";
	cout << "指针位置：" << fout.tellp() << endl;
	fout.seekp(-2, ios::end);// 从末尾位置向前移动2个字节,覆盖掉尾行的换行符
	cout << "指针位置：" << fout.tellp() << endl;
	fout << "新数据\n";
	fout.close();
}