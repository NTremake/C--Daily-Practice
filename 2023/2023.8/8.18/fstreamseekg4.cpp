#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// seekg()��seekp()�ĵ�һ��������ƫ�������ڶ���������ƫ����ʼλ��
int main() {
	string path = "D:\\AAcode\\C++\\Project1_test\\Project1_test\\test.txt";
	fstream ofs(path, ios::in | ios::out);
	for (int i = 0; i < 5; ++i) {
		ofs << "12345\n";
	}
	cout << "ָ��λ�ã�" << ofs.tellp() << endl;
	ofs.seekg(3, ios::beg);// �ӿ�ʼλ������ƶ�3���ֽ�
	cout << "ָ��λ�ã�" << ofs.tellg() << endl;
	string buffer;
	while (ofs >> buffer) {
		cout << buffer << endl;
	}
	ofs.close();
	ofstream fout(path, ios::out);
	fout << "12345\n12345\n12345\n12345\n12345\n";
	cout << "ָ��λ�ã�" << fout.tellp() << endl;
	fout.seekp(-2, ios::end);// ��ĩβλ����ǰ�ƶ�2���ֽ�,���ǵ�β�еĻ��з�
	cout << "ָ��λ�ã�" << fout.tellp() << endl;
	fout << "������\n";
	fout.close();
}