#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string path = "D:\\AAcode\\C++\\Project1_test\\Project1_test\\test.txt";
	fstream ofs(path, ios::out);
	if (!ofs.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return 0;
	}
	for (int i = 0; i < 5; ++i) {
		cout << "λ��ָ�룺" << ofs.tellp() << endl;// tellp()����дָ���λ��
		ofs << "12345" << endl;
	}
	ofs.close();
	fstream ifs(path, ios::in);
	cout << "tellg()ָ��λ�ã�" << ifs.tellg() << "  tellp()ָ��λ�ã�" << ifs.tellp() << endl;// ����ָ��ʵ����ͬһ��ָ��
	if (!ifs.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return 0;
	}
	string buffer;
	while (getline(ifs, buffer)) {
		cout << ifs.tellg() << endl;// tellg()���ض�ָ���λ��
		cout << buffer << endl;
	}
	ifs.close();
}