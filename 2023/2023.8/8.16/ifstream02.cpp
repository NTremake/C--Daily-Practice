#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("test.txt", ios:: trunc | ios::binary);
	if (!fout.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return 0;
	}
	//fout << "abcde" << endl;// windows�»��з�Ϊ\r\n��ռ�����ֽ�
	char temp[7] = "abcde\n";
	fout.write((char*)&temp, sizeof(temp));// �Զ�������ʽд��,windows�����Զ���ӻ��з���ת��Ϊ\r\n
	fout.close();
	ifstream fin("test.txt", ios::binary);
	if (!fin.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return 0;
	}
	char buffer[10];
	memset(buffer, 0, sizeof(buffer));
	fin.read((char*)buffer, sizeof(buffer));
	cout << buffer << endl;
	/*for (auto i : buffer) {
		cout << (int)i << endl;
	}*/
	for (int i = 0; i < sizeof(buffer); ++i) {
		cout << (int)buffer[i] << endl;
	}
	fin.close();
}