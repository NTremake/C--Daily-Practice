#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string path = "D:\\AAcode\\C++\\Project1_test\\Project1_test\\test.txt";
	fstream ofs(path, ios::out);
	if (!ofs.is_open()) {
		cout << "打开文件失败" << endl;
		return 0;
	}
	for (int i = 0; i < 5; ++i) {
		cout << "位置指针：" << ofs.tellp() << endl;// tellp()返回写指针的位置
		ofs << "12345" << endl;
	}
	ofs.close();
	fstream ifs(path, ios::in);
	cout << "tellg()指针位置：" << ifs.tellg() << "  tellp()指针位置：" << ifs.tellp() << endl;// 两个指针实际是同一个指针
	if (!ifs.is_open()) {
		cout << "打开文件失败" << endl;
		return 0;
	}
	string buffer;
	while (getline(ifs, buffer)) {
		cout << ifs.tellg() << endl;// tellg()返回读指针的位置
		cout << buffer << endl;
	}
	ifs.close();
}