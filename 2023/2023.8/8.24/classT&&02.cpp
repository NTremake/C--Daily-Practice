#include <iostream>
using namespace std;

void func1(int& a) {
	cout << "��ֵ���ã�" << a << endl;
}
void func1(int&& a) {
	cout << "��ֵ���ã�" << a << endl;
}
template <typename TT>
void func(TT&& a) {
	func1(forward<TT>(a));
}// ����ת�����ܱ�����ֵ����ֵ�ٴ��ݹ����б��ֲ���
int main() {
	int a = 3;
	func1(a);
	func1(3);
	func(a);
	func(3);
}