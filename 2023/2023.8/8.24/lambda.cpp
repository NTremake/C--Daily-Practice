#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// lambda����
int main() {
	int a = 3;
	double b = 4.2;
	/*auto func1 = [a, b](const int& num) {
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "����Ϊ��" << num << endl;
		};*/
	// []�����������,�������ò���=�ž���ֵ����
	auto func1 = [&](const int& num) {
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "����Ϊ��" << num << endl;
		};
	func1(1);
	// Ҳ���Է��ಶ��
	auto func2 = [=, &b](const int& num) {
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "����Ϊ��" << num << endl;
		};
	func2(2);
	auto show = [](const int& num) {
		cout << "���֣�" << num << endl;
		};
	vector<int> v1 = { 1,2,3,4,5 };
	for_each(v1.begin(), v1.end(), show);
}