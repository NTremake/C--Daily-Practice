#include <iostream>
using namespace std;

void print() {
	cout << "�ݹ����" << endl;
}
template <typename T, typename ...Args>
void print(T arg, Args... args) {
	cout << "������" << arg << endl;
	//cout << "����" << sizeof...(args) << "������δչ��" << endl;// sizeof...()����ʣ�����
	print(args...);
}// �ɱ����ģ�壬���Դ��ݶ����ͬ�������ݹ�
template <typename ...Args>
void func(const string& str, Args... args) {
	cout << str << endl;
	print(args...);
	cout << "��׽���" << endl;
}// �ɱ����ģ��Ҳ���Ե�����������ģ��
int main() {
	//print("����", 20, "����", 21);
	func("����˧��", 6, "��ϲ����", 6, "���");
}