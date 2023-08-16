#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//ofstream fout("test.txt", ios::app);
	string path = "D:\\AAcode\\C++\\Project1_test\\Project1_test\\test.txt";
	ofstream fout(path, ios::app);
	if (!fout.is_open()) {
		cout << "打开文件失败" << endl;
		return 0;
	}
	//fout << "Hello World" << endl;
	for(int i = 0; i < 5; ++i) {
		fout << "Hello World" << endl;
	}
	fout.close();
	ifstream fin(path);
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
		return 0;
	}
	string bbuffer;
	while (getline(fin, bbuffer)) {
		cout << bbuffer << endl;
	}
	/*while (fin >> bbuffer) {
		cout << bbuffer << endl;
	}*/
	fin.close();
}