#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("test.txt", ios:: trunc | ios::binary);
	if (!fout.is_open()) {
		cout << "打开文件失败" << endl;
		return 0;
	}
	//fout << "abcde" << endl;// windows下换行符为\r\n，占两个字节
	char temp[7] = "abcde\n";
	fout.write((char*)&temp, sizeof(temp));// 以二进制形式写入,windows不会自动添加换行符和转换为\r\n
	fout.close();
	ifstream fin("test.txt", ios::binary);
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
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