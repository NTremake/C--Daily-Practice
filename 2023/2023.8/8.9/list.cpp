#include <iostream>
#include <list>
using namespace std;

//list容器的常用函数
int main() {
	list<int> l1{3, 1, 5, 2, 7, 6};
	for (int &a : l1) {
		cout << a << "  ";
	}
	cout << endl;
	l1.sort();
	for (int& a : l1) {
		cout << a << "  ";
	}
	cout << endl;
	l1.reverse();
	for (int& a : l1) {
		cout << a << "  ";
	}
	cout << endl;
	l1.remove(5);
	for (int& a : l1) {
		cout << a << "  ";
	}
	cout << endl;
	list<int> l2{ 3, 3, 1, 1, 5, 2, 5, 7, 6 };
	l2.unique();
	for (int& a : l2) {
		cout << a << "  ";
	}
}