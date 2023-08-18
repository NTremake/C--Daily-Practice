#include <iostream>
#include <initializer_list>
using namespace std;

// 1. initializer_list��һ����ģ�壬������<initializer_list>�С�
// 2. initializer_list�е�Ԫ����Զ�ǳ����������޸ġ�
// �����ǰ����в���ͳһΪһ��������Ȼ�󴫲�
float Sum(initializer_list<float> il) {
	float total = 0;
	/*for (auto i : il) {
		total += i;
	}*/
	for (auto i = il.begin(); i != il.end(); ++i) {
		total += *i;
	}
	return total;
}// ͳһ��ʼ���б�
int main() {
	//float a = Sum(1.1, 2.2, 3.3);// ����
	float b = Sum({ 1.1, 2.2, 3.3 });
	cout << b << endl;
}